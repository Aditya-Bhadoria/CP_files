#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        ll n,x,y, sum = 0;
        cin >> n >> x >> y;
        vector<long long> a;
        for(int i=0; i<n; i++){
            ll p; cin >> p;
            a.push_back(p);
            sum += p;
        }
        int count = 0;
        sort(a.begin(), a.end()); 
        for(int i=0; i<n; i++){
            if(sum - a[i] < x){
                break;
            }
            for(int j=i+1; j<n; j++){
                ll compare = sum - a[i] - a[j];
                // cout << a[i] << " " << a[j] <<" "<< compare << endl;
                if(compare >=x && compare <= y){
                    count ++;
                }
                else if(compare < x){
                    break;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}