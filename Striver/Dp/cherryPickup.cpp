#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define vll vector<ll>
#define vint vector<int>
#define pb push_back
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll pow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

ll pow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % c;
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}

void print(vector<int> &arr) {
    for (auto &it : arr) {
        cout << it << " ";
    }
}
int cherry(vector<vint> grid, int r, int i, int j1, int j2, vector<vector<vint>>&dp){
    int c = grid[0].size();
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -1e8;
    if(i == r-1){
        if(j1 == j2) return grid[r-1][j1];
        else return grid[r-1][j1] + grid[r-1][j2]; 
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = 0;
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            if(j1 == j2){
                maxi = max(maxi, grid[i][j1] + cherry(grid, r, i+1, j1+dj1, j2+dj2, dp));
            }
            else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + cherry(grid, r, i+1, j1+dj1, j2+dj2, dp));
            }
        }
    }
    dp[i][j1][j2] = maxi;
    return maxi;
}
int cherryTab(vector<vint> grid, int n, int c){
    vector<vector<vint>> dp1(n, vector<vint>(c, vint(c, -1)));
    for(int j1 = 0; j1<c; j1++){
        for(int j2 = 0; j2<c; j2++){
            if(j1 == j2) dp1[n-1][j1][j2] = grid[n-1][j2];
            else dp1[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }
    for(int i = n-2; i>=0; i--){
        for(int j1 = 0; j1<c; j1++){
            for(int j2 = 0; j2<c; j2++){
                int maxi = 0;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];

                        if(j1+dj1<0 || j1+dj1>=c || j2+dj2<0 || j2+dj2>=c) value = -1e8;
                        else value += dp1[i+1][j1+dj1][j2+dj2];
                        maxi = max(maxi, value);
                    }
                }
                dp1[i][j1][j2] = maxi;
            }
        }
    }
    return dp1[0][0][c-1];
}
int cherrySpaceOpt(vector<vint> grid, int n, int c){
    vector<vint> dp1(c, vint(c, -1));
    vector<vint> curr(c, vint(c, -1));
    for(int j1 = 0; j1<c; j1++){
        for(int j2 = 0; j2<c; j2++){
            if(j1 == j2) dp1[j1][j2] = grid[n-1][j2];
            else dp1[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }
    for(int i = n-2; i>=0; i--){
        for(int j1 = 0; j1<c; j1++){
            for(int j2 = 0; j2<c; j2++){
                int maxi = 0;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];

                        if(j1+dj1<0 || j1+dj1>=c || j2+dj2<0 || j2+dj2>=c) value = -1e8;
                        else value += dp1[j1+dj1][j2+dj2];
                        maxi = max(maxi, value);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        dp1 = curr;
    }
    return curr[0][c-1];
}
int main() {
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int r, c; cin >> r >> c;
    vector<vint> grid(r, vint(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<vint>> dp(r, vector<vint>(c, vint(c,-1)));
    // cout << cherry(grid, r, 0, 0, c-1, dp);
    // cout << cherryTab(grid, r, c);
    cout << cherrySpaceOpt(grid, r, c);
    return 0;
}