#include <iostream>
#include "config.h"
#include "build_orchestrator.h"

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    
    BuildConfig config;
    config.set_defaults();
    
    BuildOrchestrator orchestrator(config);
    orchestrator.run_full_build();
    
    return 0;
}