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
    set<int> x;
    for(int i=0; i<n; i++){
        int u; cin >> u;
        x.insert(u);
    }
    cout << x.size() << endl;
    return 0;
}