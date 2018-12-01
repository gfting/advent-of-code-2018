#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

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

	// the string that is this current number in the file
	std::string thisNum;

	// gets read in all the values from the file
	std::vector<int> values;

	int total = 0;

	while (infile >> thisNum) {

		// get the current number; add to total
		int curNum = 0;
		if (thisNum[0] == '-') {
			curNum = std::stoi(thisNum.substr(1, thisNum.length() - 1));
			curNum = curNum * -1;
			total += curNum;
			values.push_back(curNum);
		} else {
			curNum = std::stoi(thisNum.substr(1, thisNum.length() - 1));
			total += curNum;
			values.push_back(curNum);
		}
	}

	// PART 2 -

	// reads in unique resulting frequencies
	std::set<int> results;

	// keeps track of if a second frequency is found
	bool doubleFound = false;

	int loopTotal = 0;
	while (!doubleFound) {
		for (std::vector<int>::iterator it = values.begin(); it != values.end(); ++it) {
			loopTotal += *it;
			if (results.count(loopTotal) == 0) {
				results.emplace(loopTotal);
			} else {
				doubleFound = true;
				std::cout << loopTotal << std::endl;
				break;
			}

		}
	}

	std::cout << total;
}

//
// Created by Gabriel Ting on 12/1/18.
//

