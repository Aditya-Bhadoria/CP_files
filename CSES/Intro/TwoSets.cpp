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
    int n; cin >> n;
    if(n%4 != 3 && n%4 != 0){ cout << "NO" << endl; return 0;}
    if(n%4 == 0){
        cout << "YES\n" << n/2 << '\n';
        for(int i = 1; i<= n/4; i++){ cout << i << " "; }
        for(int i = 3*n/4 + 1; i<=n; i++){ cout << i << " "; }
        cout << '\n' << n/2 << '\n';
        for(int i = n/4 + 1; i<= 3*n/4; i++){ cout << i << " "; } cout << '\n';
        return 0;
    }
    else if(n == 3){
        cout << "YES\n2\n1 2\n1\n3\n"; return 0;
    }
    else{
        cout <<"YES\n"<<(n+1)/2 << "\n1 2 ";
        for(int i=4; i<=n; i+=4){ cout << i << " " << i+3 << " "; }
        cout << '\n' << n/2 << "\n3 ";
        for(int i=4; i<=n; i+=4){ cout << i+1 << " " << i+2 << " "; } cout << '\n';
    }
    return 0;
}