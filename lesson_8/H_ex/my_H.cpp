#include <iostream>

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

int main(){
    int count;
    std::cin >> count;
    long long array[count];
    for (int i = 0; i < count; i++){
        std::cin >> array[i];
    }

    quick_sort(array, 0, count - 1);

    int unique = 0;
    if (count > 0)
        unique = 1;
    for (int i = 1; i < count; i++){
        if (array[i] != array[i-1])
            unique++;
    }

    std::cout << unique << "\n";
    for (int i = 0; i < count; i++){
        std::cout << array[i];
        if (i < count - 1){
            std::cout << " ";
        } else {
            std::cout << std::endl;
        }
    }

    return (0);
}
