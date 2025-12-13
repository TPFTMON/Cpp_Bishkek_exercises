#include <iostream>
#include <algorithm>

long long bubble_iters(int count, long long *array){
    long long iters = 0;

    for (int i = 0; i < count; i++){
        for (int j = 0; j < count - i - 1; j++){
            if (array[j] > array[j + 1]){
                std::swap(array[j], array[j + 1]);
                iters++;
            }
        }
    }

    return (iters);
}

int main(){
    int count;
    long long array[1005];

    std::cin >> count;
    for (int i = 0; i < count; i++){
        std::cin >> array[i];
    }

    long long iterations = bubble_iters(count, array);
    std::cout << iterations << std::endl;

    return (0);
}

// long long bubble_iters(int count, long long *array){
    // long long iters;
//
    // for (int i = 0; i < count; i++){
        // for (int j = i + 1; j < count - 1; j++){
            // if (j > j + 1){
                // std::swap(array[j], array[j + 1]);
                // iters++;
            // }
        // }
    // }
//
    // return (iters);
// }
