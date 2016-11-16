// Problem 15 - Lattice paths

#include <iostream>
#include <algorithm>

#define WIDTH 21
#define HEIGHT 21

long long unsigned f(long long unsigned x,long long unsigned y, int m[][HEIGHT]) {
	if (x == 0 || y == 0) {
		return 1;
	} else {
		if (m[x][y] == 0) {
			return m[x][y] = f(x-1,y,m) + f(x,y-1,m);
		}
		return m[x][y];
	}
}

int main() {
	
	int m[WIDTH][HEIGHT];
	for (int i=0; i<WIDTH; i++) {
		for (int j=0; j<HEIGHT; j++) {
			m[i][j] = 0;
		}
	}
	std::cout << f(20,20,m) << std::endl;
	return 0;
}

//g++ "Problem 15.cpp" -std=c++11 -o problem15 -Wall -pedantic -Ofast
//137846528820