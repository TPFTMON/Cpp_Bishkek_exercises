#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::getline(std::cin, str);

    for (int i = 0; str[i] && str[i] != ' '; i++){
        std::cout << str[i];
    }

    std::cout << std::endl;
    return (0);
}

