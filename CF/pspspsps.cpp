#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s;
        cin >> s;
        int s1 = 0, sindex, pindex, p = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 's'){
                s1++;
                sindex = i;
            }
            else if(s[i] == 'p'){
                p++;
            }
        }
        for(int i=0; i<n; i++){
            if(s[i] == 'p'){
                pindex = i; 
                break;
            }
        }
        if(s1 == 0 || p == 0){
            cout << "YES" << endl;
            continue;
        }
        else if(s[0] == '.' && s[n-1] == '.'){
            cout << "NO" << endl;
            continue;
        }
        else if(s1 > 1 && p>1){
            cout << "NO" << endl;
            continue;
        }
        else if(p==1 && s1 == 1 && (s[n-1]=='p' || s[0] == 's')){
            cout << "YES" << endl;
            continue;
        }
        else if(p == 1 && s[n-1] == 'p'){
            cout << "YES" << endl;
            continue;
        }
        else if(s1 == 1 && s[0] == 's'){
            cout << "YES" << endl;
            continue;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}