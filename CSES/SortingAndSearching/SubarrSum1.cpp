#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll N, X; cin >> N >> X;
    vector<ll> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    ll start = 0, end = 0, sum = 0, cnt = 0;
    while (end < N) {
        while (end < N && sum < X) {
            sum += arr[end];
            end ++;
        }
        while (start <= end && sum > X) {
            sum -= arr[start];
            start ++;
        }
        if (sum == X) {
            cnt ++; sum -= arr[start]; start ++;
        }
    }
    cout << cnt << endl;
}