#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
int maxPoint(vector<vint> points, int n, vector<vint> &dp){
    if(n == 0) return 0;
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(dp[0][0], dp[0][1]);

    for(int i=1; i<n; i++){
        for(int last = 0; last<4; last++){
            for(int task = 0; task<3; task++){
                if(task != last){
                    int point = points[i][task] + dp[i-1][task];
                    dp[i][last] = max(dp[i][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}
int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<vint> points(n, vint(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> points[i][j];
        }
    }
    vector<vint> dp(n, vint(4, -1));
    cout << maxPoint(points, n, dp);
    return 0;
}