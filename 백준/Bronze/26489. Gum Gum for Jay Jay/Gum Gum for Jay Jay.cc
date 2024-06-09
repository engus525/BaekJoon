#include <iostream>
#include <string>

int main() {
    std::string line;
    int line_count = 0;

    // Reading from standard input (cin) until EOF (End Of File)
    while (std::getline(std::cin, line)) {
        ++line_count;
    }

    std::cout << line_count << std::endl;

    return 0;
}