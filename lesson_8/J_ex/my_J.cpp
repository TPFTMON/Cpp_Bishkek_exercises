#include <iostream>

struct s_fraction{
    int numerator;
    int divisor;
};

int gcd(int a, int b){
    if (b == 0)
        return (a);
    return (gcd(b, a % b));
}

void quick_sort(s_fraction fraction[], int start, int range){
    if (start >= range)
        return;
    s_fraction pivot = fraction[(start + range) / 2];
    int i = start, j = range;

    while (i <= j){
        while ((long long)fraction[i].numerator * pivot.divisor < (long long)pivot.numerator * fraction[i].divisor) i++;
        while ((long long)fraction[j].numerator * pivot.divisor > (long long)pivot.numerator * fraction[j].divisor) j--;
        if (i <= j){
            s_fraction temp = fraction[i];
            fraction[i] = fraction[j];
            fraction[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort(fraction, start, j);
    quick_sort(fraction, i, range);
}

int main(){
    int num;
    std::cin >> num;
    int max = num * num * num;
    s_fraction fraction[max];
    int cnt = 0;

    for (int divisor = 2; divisor <= num; divisor++){
        for (int num = 1; num < divisor; num++){
            if (gcd(num, divisor) == 1){
                fraction[cnt].numerator = num;
                fraction[cnt].divisor = divisor;
                cnt++;
            }
        }
    }

    quick_sort(fraction, 0, cnt - 1);
    for (int i = 0; i < cnt; i++){
        std::cout << fraction[i].numerator << '/' << fraction[i].divisor << std::endl;
    }

    return (0);
}
