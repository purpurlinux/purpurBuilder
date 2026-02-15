#include "config.h"

BuildConfig::BuildConfig() {
    set_defaults();
}

void BuildConfig::set_defaults() {
    kernel_version = "6.7";
    kernel_url = "https://cdn.kernel.org/pub/linux/kernel/v6.x/";
    arch = "x86_64";
    output_dir = "./build";
    toolchain = "gcc";
    verbose = false;
}

bool BuildConfig::load(const std::string& path) {
    (void)path;
    return true;
}