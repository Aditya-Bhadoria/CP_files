#include <bits/stdc++.h>
using namespace std;
#define vint vector<int>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vint a(n), b(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    vint ans;
    int i = 0, j = 0;
    int count = 0;
    while(i<n && j<m){
        if(b[j] > a[i]){
            i++;
            count++;
        }
        else{
            ans.push_back(count);
            j++;
        }
    }
    while(j<m){
        ans.push_back(count);
        j++;
    }
    for(auto &i:ans){ cout << i << " ";}
    return 0;
}