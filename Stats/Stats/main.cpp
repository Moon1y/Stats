#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <algorithm>
#include "main.h"

class SysInfo {
public:
    SysInfo(std::string file, int n) {

        std::string line;

        if (n == 0) {
            std::string path = "/proc/" + file;
            std::ifstream in(path);
            if (in.is_open())
            {
                bool nl = false;

                while (std::getline(in, line))
                {
                    if (nl) std::cout << line << std::endl;
                    else std::cout << line << "\t ";
                    nl = !nl;
                }

                if (!nl) std::cout << std::endl;
            }
            in.close();
        }

        else if (n == 1) {
            std::ifstream in("/proc/meminfo");
            if (in.is_open())
            {
                bool nl = false;

                while (std::getline(in, line))
                {
                    if (nl) std::cout << line << std::endl;
                    else std::cout << line << "\t ";
                    nl = !nl;
                }

                if (!nl) std::cout << std::endl;
            }
            in.close();
        }
    }
};

void HelpPage() {
    std::cout << "\t\tHelp page" << std::endl;
    std::cout << "-h \t --help \t show this help page" << std::endl;
    std::cout << "-a \t --all \t show all info" << std::endl;
    std::cout << "-mf \t --meminfo \t show info from 'meminfo' file" << std::endl;
    std::cout << "-cf \t --cpuinfo \t show info from 'cpuinfo' file" << std::endl;
    std::cout << "-sf \t --stats \t show info from 'stats' file" << std::endl;
}

int main(int argc, char* argv[]) {

    std::string line;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            HelpPage();
        }
        else if (arg == "-m" || arg == "--meminfo") {
            SysInfo sysinfo("", 1);
        }
        else if (arg == "-c" || arg == "--cpuinfo") {
            SysInfo sysinfo("cpuinfo", 0);
        }
        else if (arg == "-s" || arg == "--stat") {
            SysInfo sysinfo("stat", 0);
        }
        else {
            std::cerr << "Unknow flag: " << arg << "\n" << "For help use: \"stats -h\" or \"stats --help\"" << std::endl;
        }
    }
}