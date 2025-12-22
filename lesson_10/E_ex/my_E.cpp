#include <iostream>
#include <string>

int main(){
    std::string path;
    std::getline(std::cin, path);

    int start = 0;
    for (int i = 0; i < path.length(); i++){
        if (path[i] == '/'){
            std::cout << path.substr(start, i - start) << std::endl;
            start = i + 1;
        }
    }
    std::cout << path.substr(start) << std::endl;

    return (0);
}
