#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define N cout<<endl
#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull>
int main(){
	#ifndef ONLINE_JUDGE
	freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
	freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		cout << 3*arr[i] << " ";
	}
	return 0;
}