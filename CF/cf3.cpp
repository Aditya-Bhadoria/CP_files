#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n,m,l,r;
    char c;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n >> m;
        long a[n];
        for(int j=0; j<n; j++) {
            cin >> a[j];
        }
        long max = a[0];
        for(int j=0;j<n;j++){
            if(a[j]>max)
            max = a[j];
        }
        for(int j=0; j<m; j++) {
            cin >> c >> l >> r;
            if(l <= max && max <=r){
                if(c=='+') max++;
                if(c=='-') max--;
            }
            cout << max << " ";
        }
        cout << endl;
    }
}
