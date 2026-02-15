#include "kernel_builder.h"
#include <iostream>
#include <cstdlib>
#include <sys/stat.h>

KernelBuilder::KernelBuilder(const BuildConfig& config)
    : config_(config), source_dir_(config.output_dir + "/build/linux") {}

bool KernelBuilder::clone_source() {
    if (!clone_git_repo()) {
        std::cerr << "Failed to clone kernel repository" << std::endl;
        return false;
    }
    
    if (!checkout_version()) {
        std::cerr << "Failed to checkout kernel version v" << config_.kernel_version << std::endl;
        return false;
    }
    
    (void)apply_patches();
    return true;
}

bool KernelBuilder::configure() {
    return true;
}

bool KernelBuilder::build() {
    return true;
}

bool KernelBuilder::install(const std::string& dest) {
    (void)dest;
    return true;
}

bool KernelBuilder::download_tarball() {
    return true;
}

bool KernelBuilder::apply_patches() {
    return true;
}

bool KernelBuilder::clone_git_repo() {
    std::string cmd = "git clone --depth 1 --branch v" + config_.kernel_version +
          " https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git " +
          source_dir_ + " 2>&1";

    if (config_.verbose) {
        std::cout << "Cloning kernel: " << cmd << std::endl;
    }

    return std::system(cmd.c_str()) == 0;
}

bool KernelBuilder::checkout_version() {
    struct stat st;
    if (stat(source_dir_.c_str(), &st) != 0) {
        std::cerr << "Source directory does not exist: " << source_dir_ << std::endl;
        return false;
    }
    
    std::string cmd = "cd " + source_dir_ + " && git fetch --tags 2>&1";
    if (config_.verbose) {
        std::cout << "Fetching tags: " << cmd << std::endl;
    }
    int ret = std::system(cmd.c_str());
    (void)ret;
    
    cmd = "cd " + source_dir_ + " && git checkout v" + config_.kernel_version + " 2>&1";
    if (config_.verbose) {
        std::cout << "Checking out version: " << cmd << std::endl;
    }
    
    return std::system(cmd.c_str()) == 0;
}