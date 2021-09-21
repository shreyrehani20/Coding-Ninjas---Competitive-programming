#include <iostream>
#include <string>
using namespace std;

string uniqueChar(string str) {
    // Write your code here
    set<char> s;
    int j=0;
    string temp;
    for(int i=0;str[i] != '\0';i++){
        if(s.find(str[i]) == s.end()){
            s.insert(str[i]);
            temp.push_back(str[i]);
        }
    }
    
    return temp;
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}