#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isSafe(int x, int y, int n, vector<vector<int> >& visited,
        vector<vector<int> >& mat) {
    return (x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && mat[x][y] == 1;
}

void solve(vector<vector<int> >& mat, int n, vector<string>& ans, int x, int y,
        vector<vector<int> >& visited, string path) {
    //you are in x,y

    //base case
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }
    
    visited[x][y] = 1;

    // Move left
    int newx = x, newy = y - 1;
    if (isSafe(newx, newy, n, visited, mat)) {
        path.push_back('L');
        solve(mat, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Move up
    newx = x - 1, newy = y;
    if (isSafe(newx, newy, n, visited, mat)) {
        path.push_back('U');
        solve(mat, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Move right
    newx = x, newy = y + 1;
    if (isSafe(newx, newy, n, visited, mat)) {
        path.push_back('R');
        solve(mat, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Move down
    newx = x + 1, newy = y;
    if (isSafe(newx, newy, n, visited, mat)) {
        path.push_back('D');
        solve(mat, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int> >& mat) {
    vector<string> ans;
    int n = mat.size();
    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
        return ans;
    }
    vector<vector<int> > visited(n, vector<int>(n, 0));
    string path = "";
    solve(mat, n, ans, 0, 0, visited, path);

    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<vector<int> > m(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    vector<string> ans = findPath(m);

    if(!ans.size()){ cout << "\n-1\n"; }
    for (const string& path : ans) {
        cout << path << '\n';
    }
    return 0;
}
