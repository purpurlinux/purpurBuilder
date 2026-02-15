#ifndef KERNEL_BUILDER_H
#define KERNEL_BUILDER_H

#include "config.h"
#include <string>

class KernelBuilder {
public:
    explicit KernelBuilder(const BuildConfig& config);
    
    bool clone_source();
    bool configure();
    bool build();
    bool install(const std::string& dest);
    
private:
    BuildConfig config_;
    std::string source_dir_;
    
    bool clone_git_repo();
    bool checkout_version();
    bool download_tarball();
    bool apply_patches();
};

#endif