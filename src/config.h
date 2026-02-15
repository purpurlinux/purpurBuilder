#ifndef CONFIG_H
#define CONFIG_H

#include <string>

struct BuildConfig {
    std::string kernel_version;
    std::string kernel_url;
    std::string arch;
    std::string output_dir;
    std::string toolchain;
    bool verbose;
    
    BuildConfig();
    bool load(const std::string& path);
    void set_defaults();
};

#endif