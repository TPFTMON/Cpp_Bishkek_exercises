#include <iostream>
#include <string>
#include <sstream>

int roman_to_arab(std::string r) {
    int val = 0;
    for (int i = 0; i < r.length(); i++) {
        int v1 = 0;
        if (r[i] == 'I') v1 = 1;
        else if (r[i] == 'V') v1 = 5;
        else if (r[i] == 'X') v1 = 10;
        else if (r[i] == 'L') v1 = 50;
        else if (r[i] == 'C') v1 = 100;
        else if (r[i] == 'D') v1 = 500;
        else if (r[i] == 'M') v1 = 1000;
        int v2 = 0;
        if (i + 1 < r.length()) {
            if (r[i+1] == 'I') v2 = 1;
            else if (r[i+1] == 'V') v2 = 5;
            else if (r[i+1] == 'X') v2 = 10;
            else if (r[i+1] == 'L') v2 = 50;
            else if (r[i+1] == 'C') v2 = 100;
            else if (r[i+1] == 'D') v2 = 500;
            else if (r[i+1] == 'M') v2 = 1000;
        }
        if (v1 < v2) {
            val += v2 - v1;
            i++;
        } else {
            val += v1;
        }
    }
    return val;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string result = "";
    std::string roman = "";
    for (int i = 0; i < s.length(); i++){
        char c = s[i];
        if (c == 'I' || c == 'V' || c == 'X'|| c == 'L'|| c == 'C' || c == 'D'|| c == 'M'){
            roman += c;
        } else {
            if (!roman.empty()) {
                int num = roman_to_arab(roman);
                std::ostringstream oss;
                oss << num;
                result += oss.str();
                roman = "";
            }
            result += c;
        }
    }
    if (!roman.empty()) {
        int num = roman_to_arab(roman);
        std::ostringstream oss;
        oss << num;
        result += oss.str();
    }
    std::cout << result << std::endl;
    return 0;
}
