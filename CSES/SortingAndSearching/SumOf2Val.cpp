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
    map<ll, ll> m1;
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (m1.find(X - arr[i]) != m1.end()) {
            cout << (*(m1.find(X - arr[i]))).second << " " << i + 1;
            flag = false; break;
        }
        m1.insert({ arr[i], i + 1 });
    }
    if (flag) cout << "IMPOSSIBLE";
}