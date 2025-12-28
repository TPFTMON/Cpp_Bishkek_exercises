#include <iostream>
#include <string>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::cin.ignore();
    for (int i = 0; i < N; i++) {
        std::string ln;
        std::getline(std::cin, ln);
    }
    std::string ans = "";
    int r = 1;
    int c = 1;
    for (int d = 3; d <= N + M; d++) {
        int min_i = 1;
        if (d - M > 1){
            min_i = d - M;
        }
        int max_i = d - 1;
        if (max_i > N){
            max_i = N;
        }
        int stp = 1;
        int strt = min_i;
        std::string wm = "DL";
        if (d % 2 == 0) {
            stp = -1;
            strt = max_i;
            wm = "UR";
        }
        int f_i = strt;
        int f_j = d - f_i;
        std::string mv = "";
        int dr_d = (f_i - r + N) % N;
        int dr_u = (r - f_i + N) % N;
        if (dr_d <= dr_u) {
            for (int kk = 0; kk < dr_d; kk++){
                mv += 'D';
            }
        }
        else{
            for (int kk = 0; kk < dr_u; kk++){
                mv += 'U';
            }
        }
        int dc_r = (f_j - c + M) % M;
        int dc_l = (c - f_j + M) % M;
        if (dc_r <= dc_l) {
            for (int kk = 0; kk < dc_r; kk++){
                mv += 'R';
            }
        }
        else{
            for (int kk = 0; kk < dc_l; kk++){
                mv += 'L';
            }
        }
        ans += mv;
        r = f_i;
        c = f_j;
        int num = max_i - min_i + 1;
        for (int s = 1; s < num; s++) {
            ans += wm[0];
            ans += wm[1];
            r += stp;
            if (r > N){
                r = 1;
            }
            if (r < 1){
                r = N;
            }
            c -= stp;
            if (c > M){
                c = 1;
            }
            if (c < 1){
                c = M;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
