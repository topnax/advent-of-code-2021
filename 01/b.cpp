#include <iostream>
#include <string>
#include <stdint.h>
#include <bits/stdc++.h>

int main() {
    const short number_size_bits = 16;
    // 16 bits (empty)
    // 16 bits (third number)
    // 16 bits (second number)
    // 16 bits (first number)
    unsigned long state = 0;

    int increased = 0;
    int measurement;
    uint16_t read = 0;
    int last_measurement = INT_MAX; 

    for (std::string line; std::getline(std::cin, line);) {
        read++;        
        measurement = std::stoi(line);
        state |= measurement;
        int num = state;
        state = state << number_size_bits;
        if (read >= 3) {
            measurement =(uint16_t) (state >> number_size_bits) 
                + (uint16_t) (state >> number_size_bits * 2) 
                + (uint16_t) (state >> number_size_bits * 3);
            if (measurement > last_measurement) {
                increased++;
            }
            last_measurement = measurement;
        }
    }

    std::cout << increased << std::endl;
    return 0;
}
