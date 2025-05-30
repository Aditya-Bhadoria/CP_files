#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector<vector<long long> > mat(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        vector<long long> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        int i = 0, j = 0, count = 0;
        while (i < n && j < m && count < (int)s.size()) {
            if (s[count] == 'D') { 
                mat[i][j] = -row[i]; 
                col[j] += mat[i][j]; 
                row[i] = 0;          
                i++;
            } else if (s[count] == 'R') { 
                mat[i][j] = -col[j]; 
                row[i] += mat[i][j]; 
                col[j] = 0;          
                j++;
            }
            count++;
        }
        if (i == n - 1 && j == m - 1) {
            mat[i][j] = -row[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
