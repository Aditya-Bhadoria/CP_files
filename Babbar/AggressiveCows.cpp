#include <iostream>
using namespace std;
bool isPossible(int stall[], int n, int k, int mid){
    int cowCount = 1;
    int lastPos = stall[0];
    for(int i=0; i<n ; i++){
        if(stall[i] - lastPos >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPos = stall[i];
        }
    }
    return false;
}
int main(){
    int s = 0;
    int n, k; cin >> n >> k; /* n = stalls, k = cows, largest min dis
    such that cows do no fight */
    int stall[n];

    for(int i=0; i<n; i++){ cin >> stall[i]; }

    sort(stall, stall + n);
    int e = stall[n-1];
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(stall,n,k,mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    cout << ans << endl;
    return 0;
}