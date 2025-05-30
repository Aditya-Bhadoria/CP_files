#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void ispossible(vector<long long> v1, long long v){
    for(int i = 31; i>=0; i--){
        while(v >= pow(2,i) && v1[i]){
            v -= pow(2,i);
            v1[i]--;
        }
        if(!v) break;
    }
    if(v != 0){
        cout << "NO" << endl;
    }
    else{ cout << "YES" << endl; }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> m;
    vector<long long> v1(32, 0);
    while(m--){
        int t; long long v;
        cin >> t >> v;
        if(t == 1){
            v1[v]++;
        }
        else{
            for(int i=0 ; i<31; i++){
                if(v1[i]>1){
                    if(v1[i]&1){
                        v1[i+1] += (v1[i]-1)/2;
                        v1[i]=1;
                    }
                    else{
                        v1[i+1] += (v1[i]-2)/2;
                        v1[i]=2;
                    }
                }
            }
            ispossible(v1, v);
        }
    }
    return 0;
}