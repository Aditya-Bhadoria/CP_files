#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    vector<pair<ll, ll> > m;
    for(ll i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        m.push_back(make_pair(a,b));
    }
    sort(m.begin(), m.end());
    ll timeElapsed = 0;
    ll reward = 0;
    for(auto i:m){
        timeElapsed += i.first;
        reward += (i.second - timeElapsed);
    }
    cout << reward << '\n';
    return 0;
}