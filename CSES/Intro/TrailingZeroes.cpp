#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x = 0; cin >> n;
    while(n){
        x += n/5;
        n /= 5;
    } cout << x;
    return 0;
}