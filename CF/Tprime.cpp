#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int s = pow(10,6);
    vector<bool> prime(s+1, true);
    prime[0] = prime[1] = false;
    for(int i=2; i<s+1; i++){
        if(prime[i]){
            for(int j=2*i; j<s+1; j = j+i){
                prime[j] = 0;
            }
        }
    }
    long long a;
    for(int i=0; i<n; i++){
        cin >> a;
        long long root = sqrt(a);
        long long b = root*root;
        if(b != a){
            cout << "NO" << endl;
        }
        else if(prime[root]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}