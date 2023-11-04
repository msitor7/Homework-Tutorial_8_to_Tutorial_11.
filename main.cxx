#include <iostream>
#include <string>
#include <getopt.h>

void printHelp() {
    std::cout << "Usage: ./main -i <input_csv_file>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help       Display this help message" << std::endl;
    std::cout << "  -i, --input-file Specify the input CSV file" << std::endl;
}

int main(int argc, char *argv[]) {
    std::string inputCSVFile;

    const char *shortOptions = "hi:";
    const option longOptions[] = {
        {"help", no_argument, nullptr, 'h'},
        {"input-file", required_argument, nullptr, 'i'},
        {nullptr, 0, nullptr, 0}
    };

    int option;
    while ((option = getopt_long(argc, argv, shortOptions, longOptions, nullptr)) != -1) {
        switch (option) {
            case 'h':
                printHelp();
                return 0;
            case 'i':
                inputCSVFile = optarg;
                break;
            case '?':
            default:
                std::cerr << "Invalid option. Use -h or --help for usage information." << std::endl;
                return 1;
        }
    }

    if (inputCSVFile.empty()) {
        std::cerr << "Error: You must specify the input CSV file using -i or --input-file." << std::endl;
        return 1;
    }

    std::cout << "CSV File Name: " << inputCSVFile << std::endl;

    return 0;
}
