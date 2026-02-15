#ifndef ROOTFS_BUILDER_H
#define ROOTFS_BUILDER_H

#include "config.h"
#include <string>
#include <vector>

class RootfsBuilder {
public:
    explicit RootfsBuilder(const BuildConfig& config);
    
    bool create_base();
    bool install_packages(const std::vector<std::string>& packages);
    bool setup_init();
    bool create_devices();
    bool configure_network();
    
private:
    BuildConfig config_;
    std::string rootfs_dir_;
    
    bool create_directories();
    bool install_busybox();
};

#endif