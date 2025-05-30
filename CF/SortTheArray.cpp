#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vi v(n); 
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vi copy(v);
    int start = -1, end = n-1;
    int count = 0;
    for(int i=0; i<n-1; i++){
        if( v[i] > v[i+1] && start == -1){
            start = i;
        }
        if(v[i] > v[i+1]){
            count ++;
        }
    }
    end = start + count;
    if(start == -1){
        cout << "yes" << endl << 1 << " " << 1; return 0;
    }
    for(int i=start; i<= end; i++){
        copy[start + end - i] = v[i];
    }
    for(int i=0; i<n-1; i++){
        if(copy[i] > copy[i+1]){
            cout << "no"; return 0;
        }
    }
    cout << "yes" << endl << start+1 << " " << end+1;
    return 0;
}