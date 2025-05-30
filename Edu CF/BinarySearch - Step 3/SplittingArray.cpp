#include <iostream>
using namespace std;
using ll = long long;
bool isPossible(int arr[], int n , int m , int mid){
    int segCount = 1;
    ll currSum = 0;
    for(int i=0; i<n; i++){
        if(currSum + (ll)arr[i] <= mid){
            currSum += (ll)arr[i];
        }
        else{
            segCount++;
            if(segCount > m || arr[i] > mid){
                return false;
            }
            currSum = (ll)arr[i];
        }
    }
    return true;
}
int main(){
    int n,m; cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++){ cin >> arr[i]; }
    int s = 0;
    int e = 1e15;
    int mid = s + (e-s)/2;
    while(e-s>1){
        if(isPossible(arr,n,m,mid)){
            e = mid;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    if(isPossible(arr,n,m,mid)) cout<<s;
    else cout<<e;
    return 0;
}