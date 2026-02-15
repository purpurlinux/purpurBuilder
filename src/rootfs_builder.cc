#include "rootfs_builder.h"

RootfsBuilder::RootfsBuilder(const BuildConfig& config)
    : config_(config), rootfs_dir_(config.output_dir + "/build/rootfs") {}

bool RootfsBuilder::create_base() {
    (void)create_directories();
    (void)install_busybox();
    return true;
}

bool RootfsBuilder::install_packages(const std::vector<std::string>& packages) {
    (void)packages;
    return true;
}

bool RootfsBuilder::setup_init() {
    return true;
}

bool RootfsBuilder::create_devices() {
    return true;
}

bool RootfsBuilder::configure_network() {
    return true;
}

bool RootfsBuilder::create_directories() {
    return true;
}

bool RootfsBuilder::install_busybox() {
    return true;
}