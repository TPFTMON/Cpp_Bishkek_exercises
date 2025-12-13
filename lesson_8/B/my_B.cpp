#include <iostream>

void second_place(int count, long long *medals){
    for (int i = 0; i < count; i++){
        int nMax = i;
        for (int j = i + 1; j < count; j++){
            if (medals[j] > medals[nMax]){
                nMax = j;
            }
        }
        std::swap(medals[i], medals[nMax]);
    }

    int i = 1;
    while (medals[0] == medals[i]){
        i++;
    }
    std::cout << medals[i] << std::endl;
}

int main(){
    int count;
    const int MAXN = 1005;
    long long medals[MAXN];

    std::cin >> count;
    for (int i = 0; i < count; i++){
        std::cin >> medals[i];
    }

    second_place(count, medals);

    return (0);
}
