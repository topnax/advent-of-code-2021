#include <iostream>
#include <string>
#include <bits/stdc++.h>

int main() {
    int increased = 0;
    int measurement;
    int last_measurement = INT_MAX; 
    for (std::string line; std::getline(std::cin, line);) {
        measurement = std::stoi(line);
        if (measurement > last_measurement) {
            increased++;
        }
        last_measurement = measurement;
    }
    std::cout << increased << std::endl;
    return 0;
}
