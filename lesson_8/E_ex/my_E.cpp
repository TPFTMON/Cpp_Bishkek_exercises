#include <iostream>
#include <algorithm>

const int MAXN = 105;
long long grades[MAXN];
long long copy_grades[MAXN];

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
    int size;
    std::cin >> size;
    for (int i = 0; i < size; ++i){
        std::cin >> grades[i];
        copy_grades[i] = grades[i];
    }

    // Quadratic selection sort to find min and max
    selection_sort(copy_grades, size);
    long long min_grade = copy_grades[0];
    long long max_grade = copy_grades[size - 1];

    // Replace max with min in original
    for (int i = 0; i < size; ++i){
        if (grades[i] == max_grade){
            std::cout << min_grade << " ";
        } else{
            std::cout << grades[i] << " ";
        }
    }
    std::cout << std::endl;

    return (0);
}
