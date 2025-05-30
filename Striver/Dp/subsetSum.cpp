#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
bool sum(int ind, int t, vint &v, vector<vint>&dp){
    if(t == 0) return true;
    if(ind == 0) return (v[0] == t);
    if(dp[ind][t] != -1) return true;

    bool notTake = sum(ind-1, t, v, dp);
    bool take = false;
    if(t >= v[ind]) take = sum(ind-1, t-v[ind], v, dp);

    if(take | notTake) dp[ind][t] = 1;
    return take | notTake;
}
bool sumTab(int t, vint &v, int n){
    vector<vector<bool>> dp(n, vector<bool>(t+1, false));
    for(int i=0; i<n; i++) dp[i][0] = true;
    dp[0][v[0]] = true;
    for(int i=1; i<n; i++){
        for(int target = 1; target <= t; target++){
            bool notTake = dp[i-1][target];
            bool take = false;
            if(target >= v[i]) take = dp[i-1][target-v[i]];
            if(take | notTake) dp[i][target] = true;
        }
    }
    return dp[n-1][t];
}
bool sumSpaceOpt(int t, vint &v, int n){
    vector<bool> dp(t+1, false);
    vector<bool> front(t+1, false);
    dp[0] = true;
    dp[v[0]] = true;
    for(int i=1; i<n; i++){
        front[0] = true; dp[0] = true;
        for(int target = 1; target <= t; target++){
            bool notTake = dp[target];
            bool take = false;
            if(target >= v[i]) take = dp[target-v[i]];
            if(take | notTake) front[target] = true;
        }
        dp = front;
    }
    return dp[t];
}
int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int n, t; cin >> n >> t;
    vint v(n);
    for(int i=0; i<n; i++){ cin >> v[i]; }
    vector<vint> dp(n, vint(t+1,-1));
    // cout << (sum(n-1, t, v, dp) ? "Found" : "Not found");
    // cout << (sumTab(t, v, n) ? "Found" : "Not found");
    cout << (sumSpaceOpt(t, v, n) ? "Found" : "Not found");
    return 0;
}