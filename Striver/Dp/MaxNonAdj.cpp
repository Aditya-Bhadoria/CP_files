// max sum of elements that are not adjacent
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
int ans(vint &nums, int n, vint &dp){
    if (n == 0) return 0;
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i=2; i<n; i++){
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vint nums(n), dp(n,-1);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cout << ans(nums, n, dp);
    return 0;
}