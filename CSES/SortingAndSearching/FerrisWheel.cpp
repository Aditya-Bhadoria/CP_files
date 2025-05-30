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
    int n, x; cin >> n >> x;
    vint p(n); for(int i=0; i<n; i++){ cin >> p[i]; }
    sort(p.begin(), p.end());
    int i = 0, ans = 0, j = n-1;
    while(i<j){
        if(p[i]+p[j] <= x){
            i++; j--; ans++;
        }
        else{ j--; } 
    }
    cout << n - ans << endl;
    return 0;
}