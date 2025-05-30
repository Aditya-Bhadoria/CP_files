#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector <int> v;
    int arr[n][2];
    for(int i=0;i<n;i++){
        arr[i][0] = i+1;
        arr[i][1] = 1;
    }
    int count = 1; int index = 0;
    while(v.size() != n){
        if(arr[index][1]==1 && count == 1){
            index++;
            count *= -1;
        }
        else if(arr[index][1]==1 && count == -1){
            arr[index][1] = 0;
            count *= -1;
            v.push_back(arr[index][0]);
            index++;
        }
        else if(arr[index][1] == 0){
            index++;
        }
        if(index >= n){
            index -= n;
        }
    }
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    return 0;
}