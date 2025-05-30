#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    int arr[(int)(1e6) + 3] = {0};
    for(int i=1; i<(int)(1e6 + 3); i++){
        for(int j = i; j<(int)(1e6 + 3); j += i){
            arr[j]++;
        }
    }
    while(t--){
        int n; cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}