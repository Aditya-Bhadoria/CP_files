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
    int n, m, k; cin >> n >> m >> k;
    vint a(n);
    vint b(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    long ans = 0;
    while(i<n && j<m){
        if(b[j] - k <= a[i] && a[i] <= b[j] + k){
            i++; ans++; j++;
        }
        else if(b[j] - k > a[i]){
            i++;
        }
        else if(b[j] + k < a[i]){
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}