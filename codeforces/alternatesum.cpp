#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string str1, str2;
    cin>>str1>>str2;
    string result="";
    if(str1.size()>str2.size()){
        for(int i=0; i<str2.size(); i++){
            result+=str1[i];
            result+=str2[i];
        }
        result+=str1.substr(str2.size());
    }
    else{
        for(int i=0; i<=str1.size(); i++){
            result+=str1[i];
            result+=str2[i];
        }
        result+=str2.substr(str1.size());
    }
    cout<<result;
    return 0;
}