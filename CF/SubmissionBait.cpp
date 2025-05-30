#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n; cin>>t;
    for(int i=0;i<t;i++){
        cin >> n;
        int a[n],count=1,x=n-1;
        for(int j=0;j<n;j++){
            cin >> a[j];
        }
        sort(a,a+n);
        for(int k=n-1;k>0;k--){
            if(a[k]==a[k-1]){
                count++;
            }
            else{
                break;
            }
        }
        cout << count << endl;
        if(count%2!=0){
            cout << "YES" << endl;
        }
        else{ cout << "NO" << endl;}
    }
    return 0;
}