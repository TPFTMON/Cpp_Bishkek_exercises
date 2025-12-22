#include <iostream>
#include <string>
#include <sstream>

int main(){
    std::string s, line;
    std::getline(std::cin, s);
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::string find, replace;
    iss >> find >> replace;

    size_t pos = 0;
    while ((pos = s.find(find, pos)) != std::string::npos){
        s.replace(pos, find.length(), replace);
        pos += replace.length();
    }
    std::cout << s << std::endl;

    return (0);
}
