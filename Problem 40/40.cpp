#include <iostream>
#include <string>

int main() {
    std::string s;
    int i=1;
    for (int i=0; i<1000000; i++) {
        s += std::to_string(i);   
    }
    std::cout << (int)(s[10]-'0')
                *(int)(s[100]-'0')
                *(int)(s[1000]-'0')
                *(int)(s[10000]-'0')
                *(int)(s[100000]-'0')
                *(int)(s[1000000]-'0') 
    << std::endl;
    return 0;
}


