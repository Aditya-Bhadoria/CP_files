#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
int maxSum(vector<vint> &grid, int i, int j, vector<vint>&dp){
    if(j<0 || j>=grid[0].size()) return -1e8;
    if(i == 0) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int r = grid[i][j] + maxSum(grid, i-1, j-1, dp);
    int u = grid[i][j] + maxSum(grid, i-1, j, dp);
    int l = grid[i][j] + maxSum(grid, i-1, j+1, dp);
    
    return dp[i][j] = max(r, max(u, l));
}
int maxSumTab(vector<vint> &grid, int n, int m){
    vector<vint> dp(n, vint(m,-1));
    for(int i=0; i<m; i++) dp[0][i] = grid[0][i];

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int r = (-1)*1e9, l = (-1)*1e9;
            int u = grid[i][j] + dp[i-1][j];
            if(j) l = grid[i][j] + dp[i-1][j-1];
            if(j<m-1) r = grid[i][j] + dp[i-1][j+1];
            dp[i][j] = max(u,max(r,l));
        }
    }
    return *max_element(dp[n-1].begin(), dp[n-1].end());
}
int maxSumSpaceOpt(vector<vint> &grid, int n, int m){
    vint dp(m,-1);
    vint curr(m,-1);
    for(int i=0; i<m; i++) dp[i] = grid[0][i];

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int r = (-1)*1e9, l = (-1)*1e9;
            int u = grid[i][j] + dp[j];
            if(j) l = grid[i][j] + dp[j-1];
            if(j<m-1) r = grid[i][j] + dp[j+1];
            curr[j] = max(u,max(r,l));
        }
        dp = curr;
    }
    return *max_element(curr.begin(), curr.end());
}
int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vint> grid(n, vint(m));
    vector<vint> dp(n, vint(m,-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin >> grid[i][j];
    }
    int maxi = -1e8;
    // for(int j=0; j<m; j++) maxi = max(maxi, maxSum(grid, n-1, j, dp));
    maxi = maxSumSpaceOpt(grid, n, m);
    cout << maxi;
    return 0;
}