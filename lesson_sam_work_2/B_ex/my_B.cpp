#include <iostream>
#include <algorithm>

void quick_sort(long long array[], int start, int range){
    if (start >= range)
        return;
    long long pivot = array[(start + range) / 2];
    int i = start, j = range;

    while (i <= j){
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i <= j) {
            long long temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort(array, start, j);
    quick_sort(array, i, range);
}

void master(){
    const int MAXN_B = 100005;
    long long b[MAXN_B];
    long long b_out[300005]; // Output can be larger
    int N, K;
    if (!(std::cin >> N >> K))
        return;

    bool has_zero = false;
    bool all_same = true;

    for (int i = 0; i < N; ++i) {
        std::cin >> b[i];
        if (b[i] == 0) has_zero = true;
        if (i > 0 && b[i] != b[i-1]) all_same = false;
    }

    // Case 1: Contains Zero
    if (has_zero) {
        std::cout << N + 1 << std::endl;
        for (int i = 0; i < N; ++i) std::cout << b[i] << " ";
        std::cout << "0" << std::endl;
        return;
    }

    // Case 2: Not all same (Permutation is sufficient)
    if (!all_same) {
        // std::sort(b, b + N);
        quick_sort(b, 0, N - 1);
        // The sorted array is guaranteed to be different from input
        // unless the input was ALREADY sorted.
        // We need to check if we just printed the input back.
        // But the task implies we need to output *a* valid array.
        // We store sorted version in b_out to compare.

        bool diff = false;
        // Simple swap logic to guarantee difference if sorted is same as input
        // Since all_same is false, there are at least two distinct values.
        // Swap the first pair of distinct adjacent elements.
        for (int i = 0; i < N - 1; ++i) {
            if (b[i] != b[i+1]) {
                std::swap(b[i], b[i+1]);
                diff = true;
                break;
            }
        }

        std::cout << N << std::endl;
        for (int i = 0; i < N; ++i) std::cout << b[i] << (i == N-1 ? "" : " ");
        std::cout << std::endl;
        return;
    }

    // Case 3: All elements are the same value X
    int val = b[0];

    if (val == 1) {
        std::cout << "-1" << std::endl;
    }
    else if (val == 2) {
        // Replace two 2s with one 4
        if (N >= 2 && K >= 4) {
            std::cout << N - 1 << std::endl;
            for (int i = 0; i < N - 2; ++i) std::cout << "2 ";
            std::cout << "4" << std::endl;
        } else {
            std::cout << "-1" << std::endl;
        }
    }
    else if (val == 4) {
        // Replace one 4 with two 2s
        std::cout << N + 1 << std::endl;
        for (int i = 0; i < N - 1; ++i) std::cout << "4 ";
        std::cout << "2 2" << std::endl;
    }
    else {
        // Composite check for val > 4
        // Try to find factors a * b = val
        int factor = -1;
        for (int i = 2; i * i <= val; ++i) {
            if (val % i == 0) {
                factor = i;
                break;
            }
        }

        if (factor != -1) {
            int d1 = factor;
            int d2 = val / factor;
            // We replace one 'val' with 'd1', 'd2', and enough 1s to balance sum.
            // Old Sum: val. New Sum: d1 + d2.
            // Balance = val - (d1 + d2).
            // Since val is composite > 4, val >= d1+d2 is guaranteed.
            int ones = val - (d1 + d2);

            std::cout << N + 1 + ones << std::endl;
            for (int i = 0; i < N - 1; ++i) std::cout << val << " ";
            std::cout << d1 << " " << d2;
            for (int i = 0; i < ones; ++i) std::cout << " 1";
            std::cout << std::endl;
        } else {
            // Prime > 4 or 3
            std::cout << "-1" << std::endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    master();

    return (0);
}

// #include <iostream>
// #include <algorithm>

// void quick_sort(long long array[], int start, int range){
//     if (start >= range)
//         return;
//     long long pivot = array[(start + range) / 2];
//     int i = start, j = range;

//     while (i <= j){
//         while (array[i] < pivot) i++;
//         while (array[j] > pivot) j--;
//         if (i <= j) {
//             long long temp = array[i];
//             array[i] = array[j];
//             array[j] = temp;
//             i++;
//             j--;
//         }
//     }

//     quick_sort(array, start, j);
//     quick_sort(array, i, range);
// }

// int main() {
//     int N, K;
//     std::cin >> N >> K;
//     long long a[N];
//     long long same = -1;
//     bool all_same = true;

//     for (int i = 0; i < N; i++) {
//         std::cin >> a[i];
//         if (i == 0)
//             same = a[i];
//         if (a[i] != same)
//             all_same = false;
//     }

//     if (N == 1){
//         std::cout << -1 << std::endl;
//     } else if (all_same){
//         if (same == 1){
//             std::cout << -1 << std::endl;
//         } else {
//             std::cout << N + 1 << std::endl;
//             for (int i = 0; i < N; i++){
//                 std::cout << a[i] << " ";
//             }
//             std::cout << same << std::endl;
//         }
//     } else {
//         // swap two different
//         quick_sort(a, 0, N - 1);
//         std::cout << N << std::endl;
//         for (int i = 0; i < N; i++){
//             std::cout << a[i] << " ";
//         }
//         std::cout << std::endl;
//     }

//     return (0);
// }

// #include <iostream>
// #include <algorithm>

// const int MAXN_B = 100005;
// int b[MAXN_B];
// int b_out[300005]; // Output can be larger

// void master(){
//     int N, K;
//     if (!(std::cin >> N >> K)) return;

//     bool has_zero = false;
//     bool all_same = true;

//     for (int i = 0; i < N; ++i) {
//         std::cin >> b[i];
//         if (b[i] == 0) has_zero = true;
//         if (i > 0 && b[i] != b[i-1]) all_same = false;
//     }

//     // Case 1: Contains Zero
//     if (has_zero) {
//         std::cout << N + 1 << std::endl;
//         for (int i = 0; i < N; ++i) std::cout << b[i] << " ";
//         std::cout << "0" << std::endl;
//         return;
//     }

//     // Case 2: Not all same (Permutation is sufficient)
//     if (!all_same) {
//         std::sort(b, b + N);
//         // The sorted array is guaranteed to be different from input
//         // unless the input was ALREADY sorted.
//         // We need to check if we just printed the input back.
//         // But the task implies we need to output *a* valid array.
//         // Let's store sorted version in b_out to compare.
//         // Actually, just try next_permutation.

//         bool diff = false;
//         // Simple swap logic to guarantee difference if sorted is same as input
//         // Since all_same is false, there are at least two distinct values.
//         // Swap the first pair of distinct adjacent elements.
//         for (int i = 0; i < N - 1; ++i) {
//             if (b[i] != b[i+1]) {
//                 // Swap
//                 int temp = b[i];
//                 b[i] = b[i+1];
//                 b[i+1] = temp;
//                 diff = true;
//                 break;
//             }
//         }

//         std::cout << N << std::endl;
//         for (int i = 0; i < N; ++i) std::cout << b[i] << (i == N-1 ? "" : " ");
//         std::cout << std::endl;
//         return;
//     }

//     // Case 3: All elements are the same value X
//     int val = b[0];

//     if (val == 1) {
//         std::cout << "-1" << std::endl;
//     }
//     else if (val == 2) {
//         // Replace two 2s with one 4
//         if (N >= 2 && K >= 4) {
//             std::cout << N - 1 << std::endl;
//             for (int i = 0; i < N - 2; ++i) std::cout << "2 ";
//             std::cout << "4" << std::endl;
//         } else {
//             std::cout << "-1" << std::endl;
//         }
//     }
//     else if (val == 4) {
//         // Replace one 4 with two 2s
//         std::cout << N + 1 << std::endl;
//         for (int i = 0; i < N - 1; ++i) std::cout << "4 ";
//         std::cout << "2 2" << std::endl;
//     }
//     else {
//         // Composite check for val > 4
//         // Try to find factors a * b = val
//         int factor = -1;
//         for (int i = 2; i * i <= val; ++i) {
//             if (val % i == 0) {
//                 factor = i;
//                 break;
//             }
//         }

//         if (factor != -1) {
//             int d1 = factor;
//             int d2 = val / factor;
//             // We replace one 'val' with 'd1', 'd2', and enough 1s to balance sum.
//             // Old Sum: val. New Sum: d1 + d2.
//             // Balance = val - (d1 + d2).
//             // Since val is composite > 4, val >= d1+d2 is guaranteed.
//             int ones = val - (d1 + d2);

//             std::cout << N + 1 + ones << std::endl;
//             for (int i = 0; i < N - 1; ++i) std::cout << val << " ";
//             std::cout << d1 << " " << d2;
//             for (int i = 0; i < ones; ++i) std::cout << " 1";
//             std::cout << std::endl;
//         } else {
//             // Prime > 4 or 3
//             std::cout << "-1" << std::endl;
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     master();

//     return (0);
// }
