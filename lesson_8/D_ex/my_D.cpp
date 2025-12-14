#include <iostream>
#include <algorithm>

const int MAX_SIZE = 10005;  // First when I put 1605 here it wasn't enough...
                             // Well. Here's a bigger number then

void selection_sort(long long arr[], int size) {
    for (int i = 0; i < size; ++i){
        int min_idx = i;
        for (int j = i + 1; j < size; ++j){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    long long rafts[MAX_SIZE];
    int raft_count = N * M;
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> rafts[idx++];
        }
    }

    int K;
    std::cin >> K;
    long long mes[MAX_SIZE];
    for (int i = 0; i < K; ++i) {
        std::cin >> mes[i];
    }

    selection_sort(rafts, raft_count);
    selection_sort(mes, K);

    int count = 0;
    int j = 0;
    for (int i = 0; i < K; ++i){
        while (j < raft_count && rafts[j] < mes[i]){
            ++j;
        }
        if (j < raft_count){
            ++count;
            ++j;
        }
    }

    std::cout << count << std::endl;
    return (0);
}
