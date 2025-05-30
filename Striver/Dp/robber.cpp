// max sum of elements not adjacent, and 1st and last are adjacent
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vll vector<ll>
#define vint vector<int>
int ans(vint &nums, int n){
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    int prev2 = nums[0];
    int prev = max(nums[0], nums[1]);
    int curi;
    for(int i=2; i<n; i++){
        curi = max(nums[i] + prev2, prev);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main(){
    ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("D:/Aditya/Downloads/CP/input.txt", "r", stdin);
    freopen("D:/Aditya/Downloads/CP/output.txt", "w", stdout);
    #endif
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vint money(n), money2(n-1);
    for(int i=0; i<n; i++){
        cin >> money[i];
        if(i) money2[i-1] = money[i];
    }
    cout << max(ans(money, n-1), ans(money2, n-1));
    return 0;
}