#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

extern "C" {
    #include "../euler/euler.h"
}

int main() {
    std::string current_product("0");
    std::string actual_product("0");
    std::vector<int> pandigitals;
    long product;
    for (int i=1; i<9999; i++) {
        for (int j=1; ;j++) {
            actual_product = current_product;
            product = std::stoull(actual_product,nullptr); 
            current_product += std::to_string(i*j);                       
            if (current_product.length() > 10) break;
        }
        if (log10(product) > 8) {
            pandigitals.push_back(product);
        }
        current_product = "0";
    }
    std::sort(pandigitals.begin(), pandigitals.end());
    for (std::vector<int>::reverse_iterator i = pandigitals.rbegin(); i != pandigitals.rend(); i++) {
        if (is_pandigital_fast(*i)) {
            std::cout << *i << std::endl;
            break;
        }
    }
    return 0;
}
