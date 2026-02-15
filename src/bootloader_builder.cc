#include "bootloader_builder.h"

BootloaderBuilder::BootloaderBuilder(const BuildConfig& config)
    : config_(config), bootloader_dir_(config.output_dir + "/build/boot") {}

bool BootloaderBuilder::build_syslinux() {
    return true;
}

bool BootloaderBuilder::build_grub() {
    return true;
}

bool BootloaderBuilder::install_bootloader(const std::string& dest) {
    (void)dest;
    return true;
}

bool BootloaderBuilder::create_iso(const std::string& output) {
    (void)output;
    return true;
}