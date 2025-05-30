#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
int uniquePath(int n, int m, vector<vint> dp){
    if(n == 0 || m == 0) return 0;
    // ans = (m+n-2)!/((m-1)! * (n-1)!)
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j) dp[i][j] += dp[i][j-1];
            if(i) dp[i][j] += dp[i-1][j];
        }
    }
    return dp[n-1][m-1];
}
int uniquePath2(int n, int m, vector<vint> dp, vector<vint> grid){
    if(n == 0 || m == 0) return 0;
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            if(j && grid[i][j-1] != -1) dp[i][j] += dp[i][j-1];
            if(i && grid[i-1][j] != -1) dp[i][j] += dp[i-1][j];
        }
    }
    return dp[n-1][m-1];
}
int minPathSum(int n, int m, vector<vint> dp, vector<vint> grid){
    if(n == 0 || m == 0) return 0;
    dp[0][0] = grid[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!j && !i) continue;
            if(j && i){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
            else if(!i)
                dp[i][j] = grid[i][j] + dp[i][j-1];
            else
                dp[i][j] = grid[i][j] + dp[i-1][j];
        }
    }
    return dp[n-1][m-1];
}
int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vint> dp(n, vint(m, 0));
    vector<vint> grid(n, vint(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    }
    // cout << uniquePath(n, m, dp);
    // cout << uniquePath2(n, m, dp, grid);
    cout << minPathSum(n, m, dp, grid);
    return 0;
}