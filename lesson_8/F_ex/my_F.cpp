#include <iostream>

void quick_sort(int arr[], int l, int range){
    if (l >= range)
        return ;
    int pivot = arr[(l + range) / 2];
    int i = l, j = range;

    while (i <= j){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort(arr, l, j);
    quick_sort(arr, i, range);
}

int main() {
    int count;
    std::cin >> count;
    int array[count];
    for (int i = 0; i < count; i++){
        std::cin >> array[i];
    }

    quick_sort(array, 0, count - 1);
    for (int i = 0; i < count; i++){
        std::cout << array[i] << std::endl;
    }

    return (0);
}
