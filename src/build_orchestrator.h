#ifndef BUILD_ORCHESTRATOR_H
#define BUILD_ORCHESTRATOR_H

#include "config.h"
#include "kernel_builder.h"
#include "rootfs_builder.h"
#include "bootloader_builder.h"

class BuildOrchestrator {
public:
    explicit BuildOrchestrator(const BuildConfig& config);
    
    bool run_full_build();
    bool build_kernel_only();
    bool build_rootfs_only();
    bool create_iso();
    
private:
    BuildConfig config_;
    KernelBuilder kernel_builder_;
    RootfsBuilder rootfs_builder_;
    BootloaderBuilder bootloader_builder_;
    
    bool prepare_workspace();
    bool cleanup();
};

#endif