// #include <iostream>
// #include <string>

// struct Name {
//     std::string full;
//     std::string surname;
//     std::string init;
// };

// void quickSort(Name* names, int l, int r) {
//     if (l >= r) return;
//     Name pivot = names[(l + r) / 2];
//     int i = l, j = r;
//     while (i <= j) {
//         int cmp1 = names[i].surname.compare(pivot.surname);
//         int cmp2 = 0;
//         if (cmp1 == 0) cmp2 = names[i].init.compare(pivot.init);
//         while (cmp1 < 0 || (cmp1 == 0 && cmp2 < 0)) {
//             i++;
//             cmp1 = names[i].surname.compare(pivot.surname);
//             cmp2 = 0;
//             if (cmp1 == 0) cmp2 = names[i].init.compare(pivot.init);
//         }
//         cmp1 = names[j].surname.compare(pivot.surname);
//         cmp2 = 0;
//         if (cmp1 == 0) cmp2 = names[j].init.compare(pivot.init);
//         while (cmp1 > 0 || (cmp1 == 0 && cmp2 > 0)) {
//             j--;
//             cmp1 = names[j].surname.compare(pivot.surname);
//             cmp2 = 0;
//             if (cmp1 == 0) cmp2 = names[j].init.compare(pivot.init);
//         }
//         if (i <= j) {
//             Name temp = names[i];
//             names[i] = names[j];
//             names[j] = temp;
//             i++;
//             j--;
//         }
//     }
//     quickSort(names, l, j);
//     quickSort(names, i, r);
// }

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
//             names[i].full = line.substr(dot + 1);
//             size_t space = names[i].full.rfind(' ');
//             if (space != std::string::npos) {
//                 names[i].init = names[i].full.substr(0, space);
//                 names[i].surname = names[i].full.substr(space + 1);
//             }
//         }
//     }
//     quickSort(names, 0, k-1);
//     for (int i = 0; i < k; i++) {
//         std::cout << names[i].init << " " << names[i].surname << std::endl;
//     }
//     return 0;
// }

// #include <algorithm>

// void quick_sort(std::string w[], int l, int r) {
//     if (l >= r)
//         return;
//     std::string pivot = w[(l + r) / 2];
//     int i = l, j = r;
//     while (i <= j) {
//         while (w[i] < pivot){
//             i++;
//         }
//         while (w[j] > pivot){
//             j--;
//         }
//         if (i <= j) {
//             std::string temp = w[i];
//             w[i] = w[j];
//             w[j] = temp;
//             i++;
//             j--;
//         }
//     }
//     quick_sort(w, l, j);
//     quick_sort(w, i, r);
// }

// struct Person {
//     std::string initials;
//     std::string surname;
//     std::string full;

//     // Operator overloading for sorting
//     bool operator<(const Person& other) const {
//         if (surname != other.surname) {
//             return surname < other.surname;
//         }
//         return initials < other.initials;
//     }
// };

// int main()
// {
//     const int MAX_K = 25;
//     Person people[MAX_K];
//     int k;
//     if (std::cin >> k) {
//         std::string dummy;
//         std::getline(std::cin, dummy);

//         for (int i = 0; i < k; ++i) {
//             std::string line;
//             std::getline(std::cin, line);
//             // Format: "1. A.A. Surname"
//             size_t dotPos = line.find('.');
//             size_t start = dotPos + 1;
//             while (start < line.length() && line[start] == ' ') start++;

//             std::string content = line.substr(start);
//             // Content is "A.A. Surname"
//             // Find the last space to split Initials and Surname
//             size_t lastSpace = content.rfind(' ');

//             people[i].full = content;
//             if (lastSpace != std::string::npos) {
//                 people[i].initials = content.substr(0, lastSpace);
//                 people[i].surname = content.substr(lastSpace + 1);
//             } else {
//                 people[i].surname = content; // Fallback
//             }
//         }

//         // quick_sort();
//         std::sort(people, people + k);

//         for (int i = 0; i < k; ++i) {
//             std::cout << people[i].full << std::endl;
//         }
//     }

//     return (0);
// }

