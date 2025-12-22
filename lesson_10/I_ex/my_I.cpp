#include <iostream>
#include <string>

int main() {
    std::string file;
    std::getline(std::cin, file);
    std::string extension;
    std::getline(std::cin, extension);
    size_t dot = file.rfind('.');

    if (dot != std::string::npos) {
        file = file.substr(0, dot);
    }
    file += '.' + extension;

    std::cout << file << std::endl;

    return (0);
}
