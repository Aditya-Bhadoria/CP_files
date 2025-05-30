#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define vint vector<int>
map<int, int>m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vint a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        m[a[i]]++;
        m[b[i]]--;
    }
    map<int, int>::iterator it = m.begin();
    int maxNum = 0;
    int curr = 0;
    while (it != m.end()) {
        curr += it->second;
        maxNum = max(maxNum, curr);
        ++it;
    }
    cout << maxNum << endl;
    return 0;
}