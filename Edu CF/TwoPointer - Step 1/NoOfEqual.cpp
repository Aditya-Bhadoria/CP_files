#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vint vector<int>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vint a(n), b(m);
    map<int, int> am;
    map<int, int> bm;
    for(int i=0; i<n; i++){
        cin >> a[i];
        am[a[i]]++;
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
        bm[b[i]]++;
    }
    auto ita = am.begin();
    auto itb = bm.begin();
    long long ans = 0;
    while(ita != am.end() && itb != bm.end()){
        if((ita->first) == (itb->first)){
            ans+=(((ll)ita->second)*((ll)itb->second));
            ita++; itb++;
        }
        else if(*ita > *itb){
            itb++;
        }
        else{
            ita++;
        }
    }
    cout << ans << endl;
    return 0;
}