#include <iostream>
#include <string>

void quick_sort(std::string w[], int l, int r) {
    if (l >= r)
        return;
    std::string pivot = w[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (w[i] < pivot){
            i++;
        }
        while (w[j] > pivot){
            j--;
        }
        if (i <= j) {
            std::string temp = w[i];
            w[i] = w[j];
            w[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(w, l, j);
    quick_sort(w, i, r);
}

int main(int argc, char const *argv[]){
    int k;
    const int MAX_K = 25;
    std::string words_k[MAX_K];
    if (std::cin >> k){
        std::string dummy;
        std::getline(std::cin, dummy);

        for (int i = 0; i < k; ++i){
            std::string line;
            std::getline(std::cin, line);
            // Format: "1. word"
            size_t dotPos = line.find('.');
            if (dotPos != std::string::npos){
                // Extract word, skip dot and space
                size_t start = dotPos + 1;
                while (start < line.length() && line[start] == ' ') start++;
                words_k[i] = line.substr(start);
            }
        }

        quick_sort(words_k, 0, k - 1);

        for (int i = 0; i < k; ++i){
            std::cout << words_k[i];
            if (i < k - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    return (0);
}

// void solve_K() {
//     int k;
//     const int MAX_K = 25;
//     std::string words_k[MAX_K];
//     if (std::cin >> k) {
//         std::string dummy;
//         std::getline(std::cin, dummy);

//         for (int i = 0; i < k; ++i) {
//             std::string line;
//             std::getline(std::cin, line);
//             // Format: "1. word"
//             size_t dotPos = line.find('.');
//             if (dotPos != std::string::npos) {
//                 // Extract word, skip dot and space
//                 size_t start = dotPos + 1;
//                 while (start < line.length() && line[start] == ' ') start++;
//                 words_k[i] = line.substr(start);
//             }
//         }

//         quick_sort(words_k, 0, k - 1);
//         // std::sort(words_k, words_k + k);

//         for (int i = 0; i < k; ++i) {
//             std::cout << words_k[i];
//             if (i < k - 1) std::cout << ", ";
//         }
//         std::cout << std::endl;
//     }
// }
