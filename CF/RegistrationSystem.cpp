#include <bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<string, int> m;
    int n; cin >> n;
    string s;
    for(int i=0; i<n; i++){
        cin >> s; 
        if(m[s] == 0){
            cout << "OK" << endl;
            m[s]++;
        }
        else{
            cout << s << m[s] << endl;
            m[s]++;
        }
    }
    return 0;
}