#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define N cout<<endl
int solve1(string s){ //aq = 1, bq = 1
    for(int i=0; i<10; i++){
        if(i%2 == 0 && s[i] == '?'){
            s[i] = '1';
        }
        else if(i%2 == 1 && s[i] == '?'){
            s[i] = '1';
        }
    }
    int curA = 0, curB = 0, posA, posB;
    for(int i=0; i<10; i++){
        if(i%2 == 0)
        curA += s[i] - '0';
        if(i%2 == 1)
        curB += s[i] - '0';

        posA = curA + (9-i)/2;
        posB = curB + (10-i)/2;
        if(curA > posB){
            return i + 1;
        }
        else if(curB > posA){
            return i + 1;
        }
    }
    return 10;
}
int solve2(string s){ //aq = 1, bq = 0
    for(int i=0; i<10; i++){
        if(i%2 == 0 && s[i] == '?'){
            s[i] = '1';
        }
        else if(i%2 == 1 && s[i] == '?'){
            s[i] = '0';
        }
    }
    int curA = 0, curB = 0, posA, posB;
    for(int i=0; i<10; i++){
        if(i%2 == 0)
        curA += s[i] - '0';
        if(i%2 == 1)
        curB += s[i] - '0';

        posA = curA + (9-i)/2;
        posB = curB + (10-i)/2;
        // cout<<curA<<" "<<posA<<" "<<curB<<" "<<posB<<endl;
        if(curA > posB){
            return i + 1;
        }
        else if(curB > posA){
            return i + 1;
        }
    }
    return 10;
}
int solve3(string s){ //aq = 0, bq = 1
    for(int i=0; i<10; i++){
        if(i%2 == 0 && s[i] == '?'){
            s[i] = '0';
        }
        else if(i%2 == 1 && s[i] == '?'){
            s[i] = '1';
        }
    }
    int curA = 0, curB = 0, posA, posB;
    for(int i=0; i<10; i++){
        if(i%2 == 0)
        curA += s[i] - '0';
        if(i%2 == 1)
        curB += s[i] - '0';

        posA = curA + (9-i)/2;
        posB = curB + (10-i)/2;

        if(curA > posB){
            return i + 1;
        }
        else if(curB > posA){
            return i + 1;
        }
    }
    return 10;
}
int solve4(string s){ //aq = 0, bq = 0
    for(int i=0; i<10; i++){
        if(i%2 == 0 && s[i] == '?'){
            s[i] = '0';
        }
        else if(i%2 == 1 && s[i] == '?'){
            s[i] = '0';
        }
    }
    int curA = 0, curB = 0, posA, posB;
    for(int i=0; i<10; i++){
        if(i%2 == 0)
        curA += s[i] - '0';
        if(i%2 == 1)
        curB += s[i] - '0';

        posA = curA + (9-i)/2;
        posB = curB + (10-i)/2;

        if(curA > posB){
            return i + 1;
        }
        else if(curB > posA){
            return i + 1;
        }
    }
    return 10;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int ans1 = solve1(s);
        int ans2 = solve2(s);
        int ans3 = solve3(s);
        int ans4 = solve4(s);
        // cout << ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
        cout << min( min(ans1, ans2), min(ans3, ans4) ) << endl;
    }
    return 0;
}