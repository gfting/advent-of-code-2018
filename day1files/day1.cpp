#include <string>
#include <iostream>
#include <fstream>

int main () {
	std::ifstream infile;
	std::string inFileName = "day1input.txt";
	infile.open(inFileName.c_str());
	if (infile.fail()) {
		std::cout << "Error opening input data file" << std::endl;
		std::cout << "press enter to exit";
		std::cin.get();
		std::cin.get();
		exit(1);
	}

	std::string thisNum;
	int total = 0;
	while (infile >> thisNum) {
		int curNum = 0;
		if (thisNum[0] == '-') {
			curNum = std::stoi(thisNum.substr(1, thisNum.length() - 1));
			curNum = curNum * -1;
			total += curNum;
		} else {
			curNum = std::stoi(thisNum.substr(1, thisNum.length() - 1));
			total += curNum;
		}
	}

	std::cout << total;
}

//
// Created by Gabriel Ting on 12/1/18.
//

