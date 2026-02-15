#ifndef BOOTLOADER_BUILDER_H
#define BOOTLOADER_BUILDER_H

#include "config.h"
#include <string>

class BootloaderBuilder {
public:
    explicit BootloaderBuilder(const BuildConfig& config);
    
    bool build_syslinux();
    bool build_grub();
    bool install_bootloader(const std::string& dest);
    bool create_iso(const std::string& output);
    
private:
    BuildConfig config_;
    std::string bootloader_dir_;
};

#endif