#include <iostream>
#include <string>

struct Name {
    std::string full;
    std::string last_name;
    std::string init;
};

void quick_sort(Name* names, int l, int r) {
    if (l >= r) return;
    Name pivot = names[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        int cmp1 = names[i].last_name.compare(pivot.last_name);
        int cmp2 = 0;
        if (cmp1 == 0) cmp2 = names[i].init.compare(pivot.init);
        while (cmp1 < 0 || (cmp1 == 0 && cmp2 < 0)) {
            i++;
            cmp1 = names[i].last_name.compare(pivot.last_name);
            cmp2 = 0;
            if (cmp1 == 0) cmp2 = names[i].init.compare(pivot.init);
        }
        cmp1 = names[j].last_name.compare(pivot.last_name);
        cmp2 = 0;
        if (cmp1 == 0) cmp2 = names[j].init.compare(pivot.init);
        while (cmp1 > 0 || (cmp1 == 0 && cmp2 > 0)) {
            j--;
            cmp1 = names[j].last_name.compare(pivot.last_name);
            cmp2 = 0;
            if (cmp1 == 0) cmp2 = names[j].init.compare(pivot.init);
        }
        if (i <= j) {
            Name temp = names[i];
            names[i] = names[j];
            names[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(names, l, j);
    quick_sort(names, i, r);
}

int main() {
    int k;
    std::cin >> k;
    std::cin.ignore();
    Name names[20];
    for (int i = 0; i < k; i++) {
        std::string line;
        std::getline(std::cin, line);
        // size_t dot = line.find('.');
        // if (dot != std::string::npos) {
        names[i].full = line.substr();
        size_t space = names[i].full.rfind(' ');
        if (space != std::string::npos) {
            names[i].init = names[i].full.substr(0, space);
            names[i].last_name = names[i].full.substr(space + 1);
        }
        // }
    }
    quick_sort(names, 0, k-1);
    for (int i = 0; i < k; i++) {
        std::cout << names[i].init << " " << names[i].last_name << std::endl;
    }
    return 0;
}

// int main() {
//     int k;
//     std::cin >> k;
//     std::cin.ignore();
//     Name names[20];
//     for (int i = 0; i < k; i++) {
//         std::string line;
//         std::getline(std::cin, line);
//         size_t dot = line.find('.');
//         if (dot != std::string::npos) {
//             names[i].full = line.substr(dot + 2);
//             size_t space = names[i].full.rfind(' ');
//             if (space != std::string::npos) {
//                 names[i].init = names[i].full.substr(0, space);
//                 names[i].last_name = names[i].full.substr(space + 1);
//             }
//         }
//     }
//     quick_sort(names, 0, k-1);
//     for (int i = 0; i < k; i++) {
//         std::cout << names[i].init << " " << names[i].last_name << std::endl;
//     }
//     return 0;
// }
