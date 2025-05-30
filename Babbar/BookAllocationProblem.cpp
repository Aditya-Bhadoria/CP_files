#include <iostream>
using namespace std;
bool isPossible(int arr[], int n , int m , int mid){
    int StudentCount = 1;
    int pageSum = 0;
    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            StudentCount++;
            if(StudentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int main(){
    int n,m; //n = books, m = students
    cin >> n >> m;
    int arr[n];

    for(int i=0; i<n; i++){ cin >> arr[i]; }
    
    int s = 0, sum = 0;
    for(int i=0;i<n;i++){ 
        sum += arr[i]; 
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    cout << ans << endl;
    return 0;
}