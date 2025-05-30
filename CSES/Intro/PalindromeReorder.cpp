#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int n = s.length(), odd = 0, arr[26] = {0};
    for(int i=0; i<n; i++){
        arr[s[i]-'A']++;
    }
    for(int i=0; i<26; i++){
        if(arr[i]&1){ odd++; }
        // cout << arr[i] <<  " " ;
    }
    // cout << endl;
    if(odd > 1){ cout << "NO SOLUTION"; return 0;}
    else{
        int oddIdx = 0; char ch;
        for(int i=0; i<26; i++){
            if(arr[i]&1){ oddIdx = arr[i]; ch = 'A' + i; arr[i] = 0; }
            else{ arr[i] /= 2; }
        }
        // for(int i=0; i<26; i++){
        //     cout << arr[i] << " ";
        // } cout << endl;
        for(int i=0; i<26; i++){
            if(arr[i]){
                for(int j=0; j<arr[i]; j++)
                    cout << (char)('A' + i);
            }
        }
        for(int i=0; i<oddIdx; i++){ cout << ch;}
        for(int i=25; i>=0; i--){
            if(arr[i]){
                for(int j=0; j<arr[i]; j++)
                    cout << (char)('A' + i);
            }
        }
    }
    return 0;
}