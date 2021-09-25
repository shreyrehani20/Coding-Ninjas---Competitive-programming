#include <iostream>
#include <string>
using namespace std;

string getString(int d){
    if(d==2)
        return "abc";
    if(d==3)
        return "def";
    if(d==4)
        return "ghi";
    if(d==5)
        return "jkl";
    if(d==6)
        return "mno";
    if(d==7)
        return "pqrs";
    if(d==8)
        return "tuv";
    if(d==9)
        return "wxyz";
    return " ";
}

void printKeypadHelper(int n, string outputsoFar){
    if(n==0){
        cout<<outputsoFar<<endl;
        return;
    }
    int lastDigit = n%10;
    int smallNumber = n/10;

    string options = getString(lastDigit);

    for(int i=0;i<options.size();i++){
        printKeypadHelper(smallNumber, options[i]+outputsoFar);
    }

}

void printKeypad(int n){
    printKeypadHelper(n, "");
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
