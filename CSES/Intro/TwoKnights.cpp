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
    for(int i=1; i<=n; i++){
        cout << (ll)((ll)(i*i)*(i*i - 1)/2 - (ll)4*(i*i - 3*i + 2)) << endl;
    }
    return 0;
}