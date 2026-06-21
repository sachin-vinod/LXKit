#include <iostream>
#include <string>
#include "command.h"

using namespace std;

void printHelp() {
    cout << "sysinfo-cli" << endl;
    cout << "Usage: sysinfo-cli [options]" << endl;
    cout << endl;
    cout << "Options:" << endl;
    cout << "  -h, --help     Show this help message" << endl;
}

int main(int argc, char* argv[]) {
    // Phase 1 plan:
    // 1. Implement help section and basic argument parsing.
    // 2. Add system info commands.
    // 3. Expand to richer CLI options.

    if (argc == 1) {
        cout<< "No options provided. Use -h or --help for usage information." << endl;
        return 0;
    }

    string arg = argv[1];
    if(arg == "sysinfo") {
        if(argc < 3) {
            sysinfo("");
            return 0;
        }
        sysinfo(argv[2]);
    }
    else {
        cout << "Error: unknown command '" << arg << "'" << endl;
        printHelp();
    }
}