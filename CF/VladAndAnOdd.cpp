#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>v
#define vint vector<int>v
#define pb push_back
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}

void check(bool b) {
    if (b)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,x;
        cin>>n>>x;
        if(x<=(n/2+n%2)){
            cout<<2*x-1<<endl;
            continue;
        }else{
            x-=(n/2+n%2);
        }
        int i=2;
        while(x){
            int num=n/i;
            int numbers=(num/2+num%2);
            if(x<=numbers){
                cout<<i*(2*x-1)<<endl;
                break;
            }
            else{
                x-=(numbers);
            }
            i*=2;
        }
    }
    return 0;
}