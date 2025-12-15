#include <iostream>

int main()
{
    std::string str;
    int i;

    std::getline(std::cin, str);
    for (i = 0; i < str.size(); i++){
        if (str[i] == 'a'){
            str[i] = 'b';
        } else if (str[i] == 'A'){
            str[i] = 'B';
        } else if (str[i] == 'b'){
            str[i] = 'a';
        } else if (str[i] == 'B'){
            str[i] = 'A';
        }
    }
    std::cout << str << "\n";

    return (0);
}

