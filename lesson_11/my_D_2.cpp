// #include <iostream>
// #include <string>

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::cin.ignore();
//     for (int i = 0; i < n; i++) {
//         std::string line;
//         std::getline(std::cin, line);
//     }
//     std::string ans = "";
//     int r = 1;
//     int c = 1;
//     for (int d = 3; d <= n + m; d++) {
//         int min_i = 1;
//         if (d - m > 1) min_i = d - m;
//         int max_i = d - 1;
//         if (max_i > n) max_i = n;
//         int step = 1;
//         int start_i = min_i;
//         std::string within_move = "DL";                          // NOT SURE ABOUT THIS ONE
//         if (d % 2 == 1) {
//             step = -1;
//             start_i = max_i;
//             within_move = "UR";
//         }
//         int first_i = start_i;
//         int first_j = d - first_i;
//         std::string move = "";
//         int dc_r = (first_j - c + m) % m;
//         int dc_l = (c - first_j + m) % m;
//         if (dc_r <= dc_l) {
//             for (int kk = 0; kk < dc_r; kk++) move += 'R';
//         } else {
//             for (int kk = 0; kk < dc_l; kk++) move += 'L';
//         }
//         int dr_d = (first_i - r + n) % n;
//         int dr_u = (r - first_i + n) % n;
//         if (dr_d <= dr_u) {
//             for (int kk = 0; kk < dr_d; kk++) move += 'D';
//         } else {
//             for (int kk = 0; kk < dr_u; kk++) move += 'U';
//         }
//         ans += move;
//         r = first_i;
//         c = first_j;
//         int num = max_i - min_i + 1;
//         for (int s = 1; s < num; s++) {
//             ans += within_move[0];
//             ans += within_move[1];
//             r += step;
//             if (r > n) r = 1;
//             if (r < 1) r = n;
//             c -= step;
//             if (c > m) c = 1;
//             if (c < 1) c = m;
//         }
//     }
//     std::cout << ans << std::endl;
//     return 0;
// }
