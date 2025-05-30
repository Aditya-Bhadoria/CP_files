#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define N cout<<endl
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, f, k;
        cin >> n >> f >> k;
        int arr[100];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int strict = 0, equal = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > arr[f-1]){
                strict++;
            }
            else if(arr[i] == arr[f-1]){
                equal++;
            }
        }
        if(strict >= k){
            cout << "NO" << endl;
        }
        else if(strict < k && strict + equal > k){
            cout << "MAYBE" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}