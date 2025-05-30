#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }
    for(int i=1; i<n ; i++){ // round 1 to n-1
        bool swapped = false; // optimise
        for(int j=0; j<n-i ; j++){ //process elements till n-i index
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) // already sorted
        break;
    } // stable algo, best case complexity = O(n), normal = O(n*n)
    for(int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}