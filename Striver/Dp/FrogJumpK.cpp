#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
int frog(int n, vint &heights, vint &dp, int k){
    if(n <= 1) return 0;
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int minStep = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i>=j){
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                minStep = min(minStep, jump);
            }
        }
        dp[i] = minStep;
    }
    return dp[n-1];
}
int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    vint heights(n);
    for(int i=0; i<n; i++){
        cin >> heights[i];
    }
    vint dp(n, -1);
    cout << frog(n, heights, dp, k);
    return 0;
}