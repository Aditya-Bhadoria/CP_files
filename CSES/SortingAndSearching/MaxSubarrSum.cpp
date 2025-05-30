#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long maxSubArray(vector<long long>& nums) {
    long long res = nums[0];
    long long maxEnding = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if(maxEnding >= 0){
            maxEnding += nums[i];
        }
        else{
            maxEnding = nums[i];
        }
        res = max(res, maxEnding);
    }
    return res;
}
int main() {
    ll n; cin >> n;
    vector<ll> nums(n);
    for(ll i=0; i<n; i++){ cin >> nums[i]; }
    // ll res = nums[0];
    // ll maxEnding = nums[0];
    // for (ll i = 1; i < nums.size(); i++) {
    //     maxEnding = max(maxEnding + nums[i], nums[i]);
    //     res = max(res, maxEnding);
    // }
    // cout << res << endl;
    cout << maxSubArray(nums);
    return 0;
}