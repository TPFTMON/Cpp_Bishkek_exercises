#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string word;
    std::string max_word;
    int max_len = 0;

    while (iss >> word){
        int len = word.length();
        if (len > max_len) {
            max_len = len;
            max_word = word;
        }
    }
    std::cout << max_word << "\n";
    std::cout << max_len << std::endl;

    return (0);
}
