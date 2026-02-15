#include "build_orchestrator.h"
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cerrno>

BuildOrchestrator::BuildOrchestrator(const BuildConfig& config)
    : config_(config)
    , kernel_builder_(config)
    , rootfs_builder_(config)
    , bootloader_builder_(config) {}

bool BuildOrchestrator::run_full_build() {
    (void)prepare_workspace();
    (void)kernel_builder_.clone_source();
    (void)kernel_builder_.configure();
    (void)kernel_builder_.build();
    (void)rootfs_builder_.create_base();
    (void)bootloader_builder_.create_iso(config_.output_dir + "/distro.iso");
    (void)cleanup();
    return true;
}

bool BuildOrchestrator::build_kernel_only() {
    return kernel_builder_.build();
}

bool BuildOrchestrator::build_rootfs_only() {
    return rootfs_builder_.create_base();
}

bool BuildOrchestrator::create_iso() {
    return bootloader_builder_.create_iso(config_.output_dir + "/distro.iso");
}

bool BuildOrchestrator::prepare_workspace() {
    if (config_.verbose) {
        std::cout << "Setting up workspace in: " << config_.output_dir << std::endl;
    }

    const char* dirs[] = {
        config_.output_dir.c_str(),
        (config_.output_dir + "/sources").c_str(),
        (config_.output_dir + "/build").c_str(),
        (config_.output_dir + "/build/linux").c_str(),
        (config_.output_dir + "/build/rootfs").c_str(),
        (config_.output_dir + "/build/boot").c_str(),
        (config_.output_dir + "/cache").c_str(),
        (config_.output_dir + "/logs").c_str(),
        (config_.output_dir + "/output").c_str(),
        nullptr
    };

    for (int i = 0; dirs[i] != nullptr; ++i) {
        if (mkdir(dirs[i], 0755) != 0 && errno != EEXIST) {
            std::cerr << "Failed to create directory: " << dirs[i] << std::endl;
            return false;
        }
        if (config_.verbose) {
            std::cout << "Created: " << dirs[i] << std::endl;
        }
    }

    return true;
}

bool BuildOrchestrator::cleanup() {
    return true;
}