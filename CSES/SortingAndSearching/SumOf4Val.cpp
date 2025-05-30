#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve(vector<ll>& arr, ll X, ll N)
{
    vector<vector<ll> > vec(N, vector<ll>(2));
    for (int i = 0; i < N; i++) {
        vec[i][0] = arr[i]; vec[i][1] = i + 1;
    }
    sort(vec.begin(), vec.end());
    for (ll ptr1 = 0; ptr1 < N - 3; ptr1++) {
        for (ll ptr2 = ptr1 + 1; ptr2 < N - 2; ptr2++) {
            ll ptr3 = ptr2 + 1, ptr4 = N - 1;
            while (ptr3 < ptr4) {
                ll currentSum = vec[ptr1][0] + vec[ptr2][0] + vec[ptr3][0] + vec[ptr4][0];
                if (currentSum == X) {
                    cout << vec[ptr1][1] << " "<< vec[ptr2][1] << " "<< vec[ptr3][1] << " "<< vec[ptr4][1] << "\n";
                    return;
                }
                else{ (currentSum > X) ? ptr4-- : ptr3++; }
            }
        }
    }
    cout << "IMPOSSIBLE";
}
int main()
{
    ll N, X; cin >> N >> X;
    vector<ll> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    solve(arr, X, N);
    return 0;
}