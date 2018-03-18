#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


void maximum_path(std::vector<std::vector<int>> &pyramid) {
	for (std::vector<std::vector<int>>::reverse_iterator it = pyramid.rbegin(); it != pyramid.rend(); ++it) {
		std::vector<int> pyr = *it;
		int index = 0;
		for (std::vector<int>::iterator p = pyr.begin(); p != pyr.end()-1; p++) {
			int to_add = std::max(*p,*(p+1));
			(*(it+1))[index++] += to_add;
		}
	}
	for (std::vector<std::vector<int>>::reverse_iterator it = pyramid.rbegin(); it != pyramid.rend(); ++it) {
		std::vector<int> pyr = *it;
		for (std::vector<int>::iterator p = pyr.begin(); p != pyr.end(); p++) {
			std::cout << *p << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::vector<std::vector<int>> pyramid;	
	std::ifstream file("pyramid_test.txt");

	std::string line;
	int index = 0;

	while (std::getline(file,line)) {		
		pyramid.resize(index+1);
		std::istringstream iss(line);
		int data;
		while (iss >> data) {
			pyramid[index].push_back(data);
		}
		index++;
	}
	file.close();
	maximum_path(pyramid);
	return 0;
}
