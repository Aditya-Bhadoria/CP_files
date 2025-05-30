#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
int lengthOfPlaylist(vector<int>& s) {
    int n = s.size();
    int i = 0, j = 0;
    int maxLen = 0;
    set<int> ch;
    while (j < n) {
        if (ch.find(s[j]) == ch.end()) {
            ch.insert(s[j]);             
            maxLen = max(maxLen,j - i + 1);
            j++;     
        }
        else{
            ch.erase(s[i]); i++;
        }
    }
    return maxLen;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vint s(n);
    for(int i=0; i<n; i++){ cin >> s[i]; }
    cout << lengthOfPlaylist(s) << endl;
    return 0;
}