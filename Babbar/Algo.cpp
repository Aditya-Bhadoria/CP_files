#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    cout << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "Lower bound -> " << lower_bound(v.begin(), v.end(), 6) - v.begin();
    cout << endl<< max(4,10) << endl;
    
    string s = "aditya";
    reverse(s.begin(), s.end());
    cout << s << endl;

    sort(v.begin(), v.end()); //intro sort = quick + heap + insertion
    return 0;
}