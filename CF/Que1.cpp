#include <bits/stdc++.h>
using namespace std;
int binary(vector<vector<int>>v,int target,int n,int m){
    int s=0;
    int e=n*m-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        int element=v[mid/m][mid%m];
        if(element==target) return 1;
        else if(element<target) s=mid+1;
        else e=mid-1;
        mid=s+(e-s)/2;
     }
     return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int row,col;
    cout<<"enter row and cols";
    cin>>row>>col;
    cout<<"Enter element"<<endl;
    vector<vector<int>> v(row,vector<int>(col));
    for( int i=0 ; i<row; i++){
        // vector<int> k(col);
        for(int j=0; j<col;j++){
            // cout<<i<<endl;
            cin>>v[i][j];
        }
    }
    cout<<"Enter the target value"<<endl;
    int target;
    cin>>target;
    if(binary(v,target,row,col)) cout<<"Element is present";
    else cout<<"NOT PRESENT";
    return 0;
}