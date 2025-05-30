#include <iostream>
using namespace std;
bool isPossible(int arr[], int n, int k , int mid){
    int PainterCount = 1;
    int timeSum = 0;
    for(int i=0;i<n;i++){
        if(timeSum + arr[i] <= mid){
            timeSum += arr[i];
        }
        else{
            PainterCount++;
            if(PainterCount > k || arr[i] > mid){
                return false;
            }
            timeSum = arr[i];
        }
    }
    return true;
}
int main(){
    int n, k; /* n = blocks, k = painters, minimum time to paint
    all blocks */
    cin >> n >> k;
    int arr[n];

    for(int i=0;i<n;i++){ cin >> arr[i]; }

    int s = 0, ans = -1, sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,k,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    cout << ans << endl;
    return 0;
}