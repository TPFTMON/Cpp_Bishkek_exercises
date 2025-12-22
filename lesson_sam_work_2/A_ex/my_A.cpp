#include <iostream>
#include <queue>
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

// ...
