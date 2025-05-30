#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
ll solve(ll N, vector<ll>& cubes)
{
    ll ans = 0;
    multiset<ll> topElements;
    for (int i = 0; i < N; i++) {
        auto it = topElements.upper_bound(cubes[i]);
        if (it == topElements.end()) {
            ans++;
            topElements.insert(cubes[i]);
        }
        else {
            topElements.erase(it);
            topElements.insert(cubes[i]);
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll N; cin >> N;
    vector<ll> cubes(N);
    for(int i=0; i<N; i++){ cin >> cubes[i]; }
    cout << solve(N, cubes) << endl;
    return 0;
}
