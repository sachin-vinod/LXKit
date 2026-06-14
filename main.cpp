#include <iostream>
#include <string>

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
    if (arg == "-h" || arg == "--help") {
        printHelp();
        return 0;
    }
    else if(arg == "-v" || arg == "--version") {
        cout << "sysinfo-cli version 1.0.0" << endl;
        return 0;   
    }

    cerr << "Error: unknown option '" << arg << "'" << endl;
    printHelp();
    return 1;
}