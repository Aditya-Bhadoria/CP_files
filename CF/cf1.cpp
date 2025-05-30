#include<iostream>
using namespace std;
int main(){
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        char arr[n][4];
        for( int j=0; j<n ; j++){
            for(int k=0;k<4;k++){
                cin >> arr[j][k];
            }
        }
        for(int j=n-1;j>=0;j--){
            for(int k=0;k<4;k++){
                if (arr[j][k]=='#')
                    cout << k+1<<" ";
            }
        }
        cout << endl;
    }
    return 0;
}
