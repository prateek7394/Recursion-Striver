#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int idx){
    if(idx == s.size()/2){
        return true;
    }

    if(s[idx]!=s[s.size()-1-idx]){
        return false;
    }

    return checkPalindrome(s, idx+1);
}

int main()
{
    string str = "malayalam";
    cout<<checkPalindrome(str, 0)<<endl;
    return 0;
}