#include <bits/stdc++.h>
using namespace std;
int partition(int * arr, int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot) cnt++;
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part sambhal lo
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    } 
    return pivotIndex;
}
void quickSort(int*arr, int s, int e){
    //base case
    if(s>=e)
        return;

    //partition karenge
    int p = partition(arr, s, e);

    //left part sort
    quickSort(arr, s, p-1);
    
    //right part sort
    quickSort(arr, p+1, e);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++){ cin >> a[i];}

    quickSort(a, 0, n-1);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    } cout << endl;
    return 0;
    // avg & best case - O(nlogn), worst - O(n^2), in-place, unstable
}