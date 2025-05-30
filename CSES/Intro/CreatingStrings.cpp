#include <bits/stdc++.h>
using namespace std;
int main(){
    string arr;
    vector<string> v;
    cin >> arr;
    sort(arr.begin(), arr.end());
    int count = 0;
    do{
        v.push_back(arr);
        count ++;
    } while(next_permutation(arr.begin(), arr.end()));
    cout << count << '\n';
    for(int i=0; i<count; i++){ cout << v[i] << '\n';}
    return 0;
}