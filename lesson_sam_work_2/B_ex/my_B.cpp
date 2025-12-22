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

int main() {
    int N, K;
    std::cin >> N >> K;
    long long a[N];
    long long same = -1;
    bool all_same = true;

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        if (i == 0)
            same = a[i];
        if (a[i] != same)
            all_same = false;
    }
    
    if (N == 1){
        std::cout << -1 << std::endl;
    } else if (all_same){
        if (same == 1){
            std::cout << -1 << std::endl;
        } else {
            std::cout << N + 1 << std::endl;
            for (int i = 0; i < N; i++){
                std::cout << a[i] << " ";
            }
            std::cout << same << std::endl;
        }
    } else {
        // swap two different
        quick_sort(a, 0, N - 1);
        std::cout << N << std::endl;
        for (int i = 0; i < N; i++){
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    return (0);
}
