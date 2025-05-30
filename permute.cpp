#include <bits/stdc++.h>
using namespace std;
int main(){
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
    return 0;
}