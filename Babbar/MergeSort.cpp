#include <bits/stdc++.h>
using namespace std;
#define N cout<<endl
int merge(int *arr, int s, int e){
    
    int mid = s + (e-s)/2;
    int res = 0;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrIndex = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainArrIndex++];
    }
    mainArrIndex  = mid + 1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainArrIndex++];
    }
    
    //merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrIndex = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] <= second[index2]){
            arr[mainArrIndex++] = first[index1++];
        }
        else{
            arr[mainArrIndex++] = second[index2++];
            res += len1 - index1;
        }
    }
    while(index1 < len1){
        arr[mainArrIndex++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainArrIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
    return res;
}
int mergeSort(int * arr, int s , int e){
    //base case
    if(s>=e)
    return 0;

    int res = 0;
    int mid = s + (e-s)/2;
    //left part sort
    res += mergeSort(arr, s, mid);

    //right part sort
    res += mergeSort(arr, mid+1 , e);

    // merge
    res += merge(arr,s,e);
    return res;

    //time complexity = O(nLogn)
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    } 
    int res = mergeSort(arr, 0, n-1);
    N;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    N << res;
    return 0;
}