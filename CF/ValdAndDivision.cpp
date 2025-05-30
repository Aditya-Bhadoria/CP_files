#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int c;
        multiset<int> k;
        for (int i = 0; i < n; i++) {
            cin >> c;
            k.insert(c);
        }
        int count = 0;
        while (!k.empty()) {
            auto it = k.begin(); 
            int complement = INT_MAX - (*it);
            auto j = k.find(complement);
            if (j != k.end()) {
                k.erase(j); 
            }
            k.erase(k.begin()); 
            count++;
        }
        cout << count << endl;
    }

    return 0;
}