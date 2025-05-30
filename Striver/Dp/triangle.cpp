#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
int minSum(vector<vint> tri, int i, int j, int n, vector<vint> &dp){
    if(i == n-1) return tri[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int d = tri[i][j] + minSum(tri, i+1, j, n, dp);
    int dg = tri[i][j] + minSum(tri, i+1, j+1, n, dp);

    return dp[i][j] = min(d, dg);
}
int minSumTab(vector<vint> tri, int n, vector<vint> &dp){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=i; j++){
            if(i == n-1){
                dp[i][j] = tri[i][j];
            }
            else{
                dp[i][j] = tri[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
    }
    return dp[0][0];
}
int minSumSpaceOpt(vector<vint> tri, int n){
    vint front(n);
    for(int i=0; i<n; i++) front[i] = tri[n-1][i];
    vint back(n);
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            back[j] = tri[i][j] + min(front[j], front[j+1]);
        }
        front = back;
    }
    return back[0];
}
int main(){
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<vint> tri(n, vint(n));
    vector<vint> dp(n, vint(n, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> tri[i][j];
        }
    }
    // cout << minSum(tri, 0, 0, n, dp);
    cout << minSumSpaceOpt(tri, n);
    return 0;
}