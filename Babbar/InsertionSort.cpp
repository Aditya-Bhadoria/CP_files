#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }
    for(int i=1; i<n ; i++){ // round 1 to n-1
        int temp = arr[i];
        int j = i-1;
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j]; //shifts
            }
            else{ break; }
            j--;
        }
        arr[j+1] = temp;
    } // adaptable, stable, small array, best - O(n), worst - O(n*n)
    for(int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}