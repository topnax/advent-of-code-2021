#include <iostream>
#include <string>

const std::string delim = " ";

int main() {
    int depth = 0;
    int horizontal_pos = 0;

    for (std::string line; std::getline(std::cin, line);) {
        std::string command;
        int value;

        auto start = 0U;
        auto end = line.find(delim);
        if (end != std::string::npos) {
            command = line.substr(start, end - start);
            value = std::stoi(line.substr(end + delim.length(), line.length()));
        }
        if (command == "forward") {
            horizontal_pos += value;
        } else if (command == "up") {
            depth -= value;
        }  else if (command == "down") {
            depth += value;
        }
    }

    std::wcout << depth * horizontal_pos << std::endl;

    return 0;
}
