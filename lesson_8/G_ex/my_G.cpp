#include <iostream>

void quick_sort(long long arr[], int start, int range, int is_asc){
    if (start >= range)
        return ;
    long long pivot = arr[(start + range) / 2];
    int i = start, j = range;

    while (i <= j){
        if (is_asc == 1){
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
        } else {
            while (arr[i] > pivot) i++;
            while (arr[j] < pivot) j--;
        }
        if (i <= j){
            long long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort(arr, start, j, is_asc);
    quick_sort(arr, i, range, is_asc);
}

int main(){
    int count;
    std::cin >> count;
    long long arr[count];
    for (int i = 0; i < count; i++) {
        std::cin >> arr[i];
    }

    quick_sort(arr, 0, count / 2 - 1, 1);
    quick_sort(arr, count / 2, count - 1, 0);
    for (int i = 0; i < count; i++) {
        std::cout << arr[i];
        if (i < count - 1){
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }

    return (0);
}
