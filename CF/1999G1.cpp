#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
int ask(int mid){
    cout << "? 1 " << mid << endl;
    int resp; cin >> resp;
    return resp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int l = 2, r = 1000;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int resp = ask(mid);
            if(resp == mid){
                l = mid + 1;
            } 
            else{
                r = mid;
            }
        }
        cout << "! " << l << endl;
    }
    return 0;
}