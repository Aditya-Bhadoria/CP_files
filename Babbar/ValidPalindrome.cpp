#include <iostream>
using namespace std;
void reverse(string s){
    for(int i=0; i<s.length(); i++){
        cout << s[s.length()-1-i];
    }
}
int main()
{
    char s[100];
    string ch = "";
    fgets(s, sizeof(s), stdin);
    int size = 0;
    for(int i=0; ; i++){
        if(s[i]=='\0'){
            size = i-1;
            break;
        }
    }
    for(int i=0; i<size; i++){
        if(s[i] != ' '){
            ch.push_back(s[i]);
        }
        else{
            reverse(ch);
            cout << " ";
            ch = "";
        }
        if(i == size-1){
            reverse(ch);
        }
    }
    
    return 0;
}