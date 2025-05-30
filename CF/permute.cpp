#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int>arr(n);
    vector<vector<int> > v;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << endl;
    sort(arr.begin(), arr.end());
    int count = 0;
    do{
        v.push_back(arr);
        count ++;
    } while(next_permutation(arr.begin(), arr.end()));
    cout << count;
    return 0;
}