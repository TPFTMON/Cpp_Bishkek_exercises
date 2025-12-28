#include <iostream>
#include <queue>
using namespace std;

void qs(long long a[], int l, int r){
    if (l>=r){
        return;
    }
    long long p=a[(l+r)/2];
    int i=l,j=r;
    while (i<=j){
        while (a[i]<p){
            i++;
        }
        while (a[j]>p){
            j--;
        }
        if (i<=j){
            swap (a[i],a[j]);
            i++;
            j--;
        }
    }
    qs(a,l,j);
    qs(a,i,r);
}

int main(){
    int T;
    cin>>T;
    long long ans[10001];
    for (int tt=0; tt<T; tt++){
        int N;
        long long K;
        cin>>N>>K;
        long long a[200001];
        for (int i=0; i<N; i++){
            cin>>a[i];
        }
        qs(a,0,N-1);
        long long c=a[0]-1;
        int vis=0;
        priority_queue<long long> ex;
        int i=0;
        while (i<N){
            long long h=a[i];
            int f=0;
            while (i<N&&a[i]==h){
                f++;
                i++;
            }
            long long g=h-c-1;
            while (g>0&&!ex.empty()){
                long long eh=ex.top();
                ex.pop();
                long long cs=c+1-eh;
                if (cs>K){
                    ex.push(eh);
                    break;
                }
                K-=cs;
                vis++;
                g--;
                c+=1;
            }
            vis+=1;
            for (int j=1; j<f; j++){
                ex.push(h);
            }
            c = h;
        }
        while (!ex.empty()){
            long long eh=ex.top();
            ex.pop();
            long long cs=c+1-eh;
            if (cs>K){
                break;
            }
            K-=cs;
            vis++;
            c+=1;
        }
        ans[tt]=vis;
    }
    for (int tt=0; tt<T; tt++){
        cout<<ans[tt]<<endl;
    }
}









// #include <iostream>
// #include <queue>

// void	quick_sort(long long array[], int l, int r)
// {
// 	long long	pivot;
// 	int			i, j;
// 	long long	temp;

// 	if (l >= r)
// 		return ;
// 	pivot = array[(l + r) / 2];
// 	i = l, j = r;
// 	while (i <= j)
// 	{
// 		while (array[i] < pivot)
// 			i++;
// 		while (array[j] > pivot)
// 			j--;
// 		if (i <= j)
// 		{
// 			temp = array[i];
// 			array[i] = array[j];
// 			array[j] = temp;
// 			i++;
// 			j--;
// 		}
// 	}
// 	quick_sort(array, l, j);
// 	quick_sort(array, i, r);
// }

// int	main(void)
// {
// 	int			t;
// 	long long	answers[10001];
// 	int n;
// 	long long k;
// 	long long a[200001];
// 	long long	cur_h;
// 	int			visible;
// 	int			i;
// 	long long	h;
// 	int			freq;
// 	long long	gap;
// 	long long	eh;
// 	long long	cost;
// 	long long	eh;
// 	long long	cost;

// 	std::cin >> t;
// 	for (int tt = 0; tt < t; tt++)
// 	{
// 		std::cin >> n >> k;
// 		for (int i = 0; i < n; i++)
// 		{
// 			std::cin >> a[i];
// 		}
// 		quick_sort(a, 0, n - 1);
// 		cur_h = a[0] - 1;
// 		visible = 0;
// 		std::priority_queue<long long> extras;
// 		i = 0;
// 		while (i < n)
// 		{
// 			h = a[i];
// 			freq = 0;
// 			while (i < n && a[i] == h)
// 			{
// 				freq++;
// 				i++;
// 			}
// 			gap = h - cur_h - 1;
// 			while (gap > 0 && !extras.empty())
// 			{
// 				eh = extras.top();
// 				extras.pop();
// 				cost = cur_h + 1 - eh;
// 				if (cost > k)
// 				{
// 					extras.push(eh);
// 					break ;
// 				}
// 				k -= cost;
// 				visible++;
// 				gap--;
// 				cur_h += 1;
// 			}
// 			visible += 1;
// 			for (int j = 1; j < freq; j++)
// 			{
// 				extras.push(h);
// 			}
// 			cur_h = h;
// 		}
// 		while (!extras.empty())
// 		{
// 			eh = extras.top();
// 			extras.pop();
// 			cost = cur_h + 1 - eh;
// 			if (cost > k)
// 			{
// 				break ;
// 			}
// 			k -= cost;
// 			visible++;
// 			cur_h += 1;
// 		}
// 		answers[tt] = visible;
// 	}
// 	for (int tt = 0; tt < t; tt++)
// 	{
// 		std::cout << answers[tt] << std::endl;
// 	}
// 	return (0);
// }


















// #include <iostream>
// #include <queue>
// #include <algorithm>

// void quick_sort(long long array[], int start, int range){
//     if (start >= range)
//         return ;
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

// int main() {
//     int t;
//     std::cin >> t;
//     for (int tt = 0; tt < t; tt++) {
//         int n;
//         long long k;
//         std::cin >> n >> k;
//         long long a[200010];
//         for (int i = 0; i < n; i++) {
//             std::cin >> a[i];
//         }
//         quick_sort(a, 0, n-1);
//         long long cur_h = a[0] - 1;
//         int visible = 0;
//         std::priority_queue<long long> extras;
//         int i = 0;
//         while (i < n) {
//             long long h = a[i];
//             int freq = 0;
//             while (i < n && a[i] == h) {
//                 freq++;
//                 i++;
//             }
//             long long gap = h - cur_h - 1;
//             while (gap > 0 && !extras.empty()) {
//                 long long eh = extras.top();
//                 extras.pop();
//                 long long cost = cur_h + 1 - eh;
//                 if (cost > k) {
//                     extras.push(eh);
//                     break ;
//                 }
//                 k -= cost;
//                 visible++;
//                 gap--;
//             }
//             visible += 1;
//             for (int j = 1; j < freq; j++) {
//                 extras.push(h);
//             }
//             cur_h = h;
//         }
//         while (!extras.empty()) {
//             long long eh = extras.top();
//             extras.pop();
//             long long cost = cur_h + 1 - eh;
//             if (cost > k) {
//                 break ;
//             }
//             k -= cost;
//             visible++;
//             cur_h += 1;
//         }
//         std::cout << visible << std::endl;
//     }
//     return (0);
// }

// #include <iostream>
// #include <algorithm>

// int main(){
//     const int MAXN_A = 200005;
//     int a[MAXN_A];
//     int buffer[MAXN_A];
//     int n;
//     long long k;
//     std::cin >> n >> k;

//     for (int i = 0; i < n; ++i) {
//         std::cin >> a[i];
//     }

//     std::sort(a, a + n);

//     int ans = 0;
//     int last_h = 0; // Current height of the last placed laser
//     int buf_size = 0;

//     for (int i = 0; i < n; ++i) {
//         if (a[i] > last_h) {
//             // Gap detected between last_h and a[i]
//             // Try to fill the gap with the largest available conflicts
//             // The available spots are last_h + 1, last_h + 2, ... a[i] - 1
//             int current_spot = last_h + 1;

//             while (current_spot < a[i] && buf_size > 0) {
//                 // Peek largest from buffer
//                 int val = buffer[buf_size - 1];
//                 long long cost = (long long)current_spot - val;

//                 if (k >= cost) {
//                     k -= cost;
//                     ans++;
//                     current_spot++;
//                     buf_size--; // Pop
//                 } else {
//                     // If we can't afford the cheapest option (largest val),
	// we can't afford any.
//                     // Important: Should we break or keep checking?
//                     break ;
//                 }
//             }

//             // Now place the free laser a[i]
//             last_h = a[i];
//             ans++;
//         } else {
//             // Conflict: a[i] <= last_h
//             // Add to buffer
//             buffer[buf_size++] = a[i];
//         }
//     }

//     // Process remaining buffer with infinite space above last_h
//     int current_spot = last_h + 1;
//     while (buf_size > 0) {
//         int val = buffer[buf_size - 1];
//         long long cost = (long long)current_spot - val;

//         if (k >= cost) {
//             k -= cost;
//             ans++;
//             current_spot++;
//             buf_size--;
//         } else {
//             break ;
//         }
//     }

//     std::cout << ans << std::endl;
//     return (0);
// }

// #include <iostream>
// #include <queue>
// #include <algorithm>

// ...
