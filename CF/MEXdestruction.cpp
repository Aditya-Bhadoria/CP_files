#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], zero = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int index1 = 0, index2 = 0;
        for(int i=0; i<n; i++){
            if(a[i] == 0)
            zero++;
            else{
                index2 = i;
            }
        }
        for(int i=0; i<n; i++){
            if(a[i]){
                index1 = i;
                break;
            }
        }
        if(zero == 0){
            cout << 1 << endl;
            continue;
        }
        else if(zero == n){
            cout << 0 << endl;
            continue;
        }
        int newZero = 0;
        for(int i = index1; i<= index2; i++){
            if(a[i] == 0){
                newZero++;
            }
        }
        if(newZero == 0){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}