#include "command.h"

void printHelp() {
    cout << "sysinfo-cli" << endl;
    cout << "Usage: sysinfo-cli [options]" << endl;
    cout << endl;
    cout << "Options:" << endl;
    cout << "  -h, --help     Show this help message" << endl;
}

void printVersion() {
    cout << "sysinfo-cli version 1.0.0" << endl;
}

void sysinfo(char arg){
    if(arg == '-h' || arg == "--help") {
        printHelp();
    }
    else if(arg == '-v' || arg == "--version") {
        printVersion();
    }
    else if(arg == '-c' || arg == "--cpu") {
        cout << "CPU Information: [Placeholder for CPU info]" << endl;
    }
    else if(arg == '-m' || arg == "--memory") {
        cout << "Memory Information: [Placeholder for Memory info]" << endl;
    }
    else if(arg == '-d' || arg == "--disk") {
        cout << "Disk Information: [Placeholder for Disk info]" << endl;
    }
    else {
        cerr << "Error: unknown option '" << arg << "'" << endl;
        printHelp();
    }
}