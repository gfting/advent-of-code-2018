#include <string>
#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile;
    std::string inFileName = "day2input.txt";
    infile.open(inFileName.c_str());
    if (infile.fail()) {
        std::cout << "Error opening input data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }

    std::string thisLine;
    int count[2];
    while (infile >> thisLine) {
        int alpha[26] = {0};
        for (size_t i = 0; i < thisLine.length(); ++i) {
            // gets a location in an array to put it in
            int index = thisLine[i] - 'a';
            alpha[index]++;
        }
        bool found2 = false;
        bool found3 = false;
        for (size_t j = 0; j < 26; ++j){
            if (alpha[j] == 2) {
                found2 = true;
            }
            if (alpha[j] == 3) {
                found3 = true;
            }
        }
        if (found2) {
            count[0]++;
        }
        if (found3) {
            count[1]++;
        }
    }
    std::cout << count[0] * count[1];

    return 0;
}
