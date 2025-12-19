#include <iostream>
#include <string>

bool isUp(const std::string& s, int& pos){
    if (pos >= s.length())
        return (false);
    char first = s[pos++];
    if (first != 'D' && first != 'E')
        return (false);

    // Must have at least one 'F'
    if (pos >= s.length() || s[pos] != 'F')
        return (false);
    while (pos < s.length() && s[pos] == 'F')
        pos++;

    if (pos >= s.length())
        return (false);
    if (s[pos] == 'G') {
        pos++;
        return (true);
    } else {
        // Recursive UpString
        return (isUp(s, pos));
    }
}

bool isDown(const std::string& s, int& pos) {
    if (pos >= s.length() || s[pos] != 'A')
        return (false);
    pos++;  // consume 'A'

    // Save position right after 'A' for the second branch
    int start_pos = pos;
    // First branch: A B DownString C
    if (pos < s.length() && s[pos] == 'B'){
        pos++;  // consume 'B'
        if (isDown(s, pos)){
            if (pos < s.length() && s[pos] == 'C'){
                pos++;  // consume 'C'
                return (true);
            }
        }
    }

    // If first branch failed, try second branch: A UpString C
    pos = start_pos;  // restore position after 'A'
    if (isUp(s, pos)){
        if (pos < s.length() && s[pos] == 'C'){
            pos++;  // consume 'C'
            return (true);
        }
    }

    // Also check the simple AH case
    pos = start_pos;  // reset again
    if (pos < s.length() && s[pos] == 'H'){
        pos++;
        return (true);
    }

    return (false);
}

int main() {
    std::string str;
    std::cin >> str;
    int pos = 0;

    bool is_down = isDown(str, pos);
    bool is_up = isUp(str, pos);
    if (is_down && is_up && pos == str.length()){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return (0);
}


// Previous version that didn't quite work
// bool isDown(const std::string& s, int& pos){
//     if (pos >= s.length() || s[pos] != 'A')
//         return (false);
//     pos++;   // consume 'A'

//     // Save position right after 'A' for the second branch
//     int start_pos = pos;

//     if (pos >= s.length())
//         return (false);
//     if (s[pos] == 'H'){
//         pos++;
//         return (true);
//     }

//     bool is_b_down_c = false;
//     if (pos < s.length() && s[pos] == 'B'){
//         pos++;
//         is_b_down_c = isDown(s, pos);
//         if (is_b_down_c && pos < s.length() && s[pos] == 'C'){
//             pos++;
//             return (true);
//         }
//     }

//     pos--;
//     bool is_up_c = isUp(s, pos);
//     if (is_up_c && pos < s.length() && s[pos] == 'C'){
//         pos++;
//         return (true);
//     }

//     return (false);
// }
