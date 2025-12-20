#include <iostream>

struct s_participant{
    long long id;
    long long score;
};

void merge(s_participant participants[], int start, int median, int range){
    int n1 = median - start + 1;
    int n2 = range - median;
    s_participant left[n1];
    s_participant right[n2];
    for (int i = 0; i < n1; i++){
        left[i] = participants[start + i];
    }
    for (int j = 0; j < n2; j++){
        right[j] = participants[median + 1 + j];
    }
    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2){
        int cond = 0;
        if (left[i].score > right[j].score){
            cond = 1;
        } else if (left[i].score == right[j].score && left[i].id < right[j].id){
            cond = 1;
        }
        if (cond == 1){
            participants[k] = left[i];
            i++;
        } else {
            participants[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        participants[k] = left[i];
        i++;
        k++;
    }
    while (j < n2){
        participants[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(s_participant participants[], int start, int range){
    if (start < range){
        int median = start + (range - start) / 2;
        merge_sort(participants, start, median);
        merge_sort(participants, median + 1, range);
        merge(participants, start, median, range);
    }
}

int main(){
    int count;
    std::cin >> count;
    s_participant participants[count];
    for (int i = 0; i < count; i++) {
        std::cin >> participants[i].id >> participants[i].score;
    }

    merge_sort(participants, 0, count-1);
    for (int i = 0; i < count; i++) {
        std::cout << participants[i].id << " " << participants[i].score << std::endl;
    }

    return (0);
}
