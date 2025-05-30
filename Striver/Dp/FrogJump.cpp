#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
int frog(int n, vint &heights, vint &dp){
    if(n <= 1) return 0;
    dp[0] = 0; dp[1] = abs(heights[1] - heights[0]);
    for(int i=2; i<n; i++){
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(left, right);
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
    int n; cin >> n;
    vint heights(n);
    for(int i=0; i<n; i++){
        cin >> heights[i];
    }
    vint dp(n, -1);
    cout << frog(n, heights, dp);
    return 0;
}