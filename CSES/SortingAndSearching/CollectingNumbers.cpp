#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n]; //contains 1 to n integers
    for( int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    int sort[n],count = 0;
    for(int i=0;i<n;i++){
        sort[arr[i]-1] = i+1;
    }
    for(int i=0;i<n-1;i++){
        if(sort[i+1]<sort[i])
        count++;
    }
    cout << count+1 << endl;
}