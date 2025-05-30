#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        int a[n];
        long long sum=0;
        for(int j=0; j<n; j++) {
            cin >> a[j];
            sum += a[j];
        }
        sum -= 2*a[n-2];
        cout << sum << endl;
    }
}
