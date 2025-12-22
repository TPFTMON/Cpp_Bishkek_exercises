#include <iostream>
#include <algorithm>

int main(){
    const int MAXN_A = 200005;
    int a[MAXN_A];
    int buffer[MAXN_A];
    int n;
    long long k;
    std::cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    int ans = 0;
    int last_h = 0; // Current height of the last placed laser
    int buf_size = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] > last_h) {
            // Gap detected between last_h and a[i]
            // Try to fill the gap with the largest available conflicts
            // The available spots are last_h + 1, last_h + 2, ... a[i] - 1
            int current_spot = last_h + 1;

            while (current_spot < a[i] && buf_size > 0) {
                // Peek largest from buffer
                int val = buffer[buf_size - 1];
                long long cost = (long long)current_spot - val;

                if (k >= cost) {
                    k -= cost;
                    ans++;
                    current_spot++;
                    buf_size--; // Pop
                } else {
                    // If we can't afford the cheapest option (largest val), we can't afford any.
                    // Important: Should we break or keep checking?
                    break;
                }
            }

            // Now place the free laser a[i]
            last_h = a[i];
            ans++;
        } else {
            // Conflict: a[i] <= last_h
            // Add to buffer
            buffer[buf_size++] = a[i];
        }
    }

    // Process remaining buffer with infinite space above last_h
    int current_spot = last_h + 1;
    while (buf_size > 0) {
        int val = buffer[buf_size - 1];
        long long cost = (long long)current_spot - val;

        if (k >= cost) {
            k -= cost;
            ans++;
            current_spot++;
            buf_size--;
        } else {
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}


// #include <iostream>
// #include <queue>
// #include <algorithm>

// void quick_sort(long long array[], int start, int range){
//     if (start >= range)
//         return;
//     long long pivot = array[(start + range) / 2];
//     int i = start, j = range;

//     while (i <= j){
//         while (array[i] < pivot) i++;
//         while (array[j] > pivot) j--;
//         if (i <= j) {
//             long long temp = array[i];
//             array[i] = array[j];
//             array[j] = temp;
//             i++;
//             j--;
//         }
//     }

//     quick_sort(array, start, j);
//     quick_sort(array, i, range);
// }

// ...
