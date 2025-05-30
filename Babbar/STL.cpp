#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;
int main(){
    //max heap
    priority_queue<int> maxi;

    //min heap
    priority_queue<int, vector<int>, greater<int> > mini;
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    cout << "Size of maxi -> " << maxi.size() << endl;
    unsigned long n = maxi.size();
    for(int i = 0; i<(int)n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    } cout<<endl;

    mini.push(2);
    mini.push(0);
    mini.push(-1);
    mini.push(9);
    mini.push(6);

    n = mini.size();
    cout<<endl << "Size of mini -> " << mini.size() << endl;
    for(int i = 0; i<n; i++){
        cout << mini.top() << " ";
        mini.pop();
    } cout<<endl;

    set<int> s;
    s.insert(4);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    set<int>:: iterator it = s.begin();
    it++;
    it++; 
    /* s.erase(it);*/ cout << endl;
    for(auto i:s){
        cout << i << " ";
    }
    cout << endl << s.count(5) << endl << endl;
    //insert, find, count, erase = O(log n), for set

    map<int,string> m;
    m[1] = "Aditya";
    m[13] = "Pratap";
    m[2] = "Singh";

    cout << "Before erase: " << endl;
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }
    
    cout <<endl<< "After erase: " << endl;
    m.erase(13);
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}