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
    int n; ll s;
    cin >> n >> s;
    long a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    ll x = 0; int l = 0;
    ll count = 0;
    for(int R = 0; R<n; R++){
        if(x+a[R] > s){
            count += (ll)(pow(2,R-l-1) - 1);
            x += a[R];
            while(x > s){
                x -= a[l];
                l++;
            }
        }
        else{
            x += a[R];
        }
    }
    cout << count << endl;
    return 0;
}