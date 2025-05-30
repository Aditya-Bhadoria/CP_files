#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n; cin >> n;
    if(n==1 || n==2){cout << "NO" << endl; return 0;}
    if(n==3){ cout << "2\n1 2\n1\n3\n"; return 0;}
    if(n%2 ==0){
        if(n%4 !=0 ){ cout << "NO" << endl; return 0;}
        else{
            cout << n/2 << endl;
            for(int i=0;i<n/4;i++){
                cout << i+1 << " ";
            }
            for(int i= n*0.75 ; i<n; i++){
                cout << i+1 << " ";
            }
            cout << endl << n/2 << endl;
            for(int i=n/4;i<n*0.75;i++){
                cout << i+1 << " ";
            }
        }
    }
    else{
        if(n%4 != 3){ cout << "NO" << endl; return 0;}
        cout << n/2 + 1 << endl;
        cout << "1 2 ";
        for(int i=0;i<(n-3)/4 ; i++){
            cout << i+4 << " ";
        }
        for(int i=0;i<(n-3)/4 ; i++){
            cout << 4 + (3*(n-3))/4 + i << " ";
        }
        cout << endl << n/2 << endl;
        cout << "3 ";
        for(int i=0;i<(n-3)/2;i++){
            cout << i + 4 + (n-3)/4 << " ";
        }
    }
}
