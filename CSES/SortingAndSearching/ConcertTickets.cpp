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
    int n, m; cin >> n >> m;
    multiset<int> a;
    vint b(m);
    for(int i=0; i<n; i++){
        int x; cin >> x;
        a.insert(x);
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    for(int i=0; i<m; i++){
        auto it1 = a.find(b[i]);
        auto it = a.lower_bound(b[i]);
        if(it1 != a.end()){
            cout << *it << endl;
            a.erase(it);
        }
        else if(it == a.begin()){
            cout << -1 << endl;
        }
        else{
            it--;
            cout << *it << endl;
            a.erase(it);
        }
    }
    return 0;
}