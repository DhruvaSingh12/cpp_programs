#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    vector<string> str1 = {"x", "-", "x", "a", "|", "c"};
    vector<string> str2 = {"y", "-", "b"};
    vector<string> str3 = {"z", "-", "c"};
    vector<string> str4, str5, str6;
    int k;

    if (str1[0] == str1[2]){
        str4 = {"x'", "-"};
        int i = 3;
        while (str1[i] != "|"){
            str4.push_back(str1[i]);
            str1.erase(str1.begin() + i);
        }
        str1.erase(str1.begin() + 2);
        str1.erase(str1.begin() + 2);
        str1.push_back("x'");
        str4.push_back("x'");
        str4.push_back("|");
        str4.push_back("ε");
    }
    if (str2[0] == str2[2]){
        str5 = {"y'", "-"};
        int i = 3;
        while (str1[i] != "|"){
            str5.push_back(str1[i]);
            str1.erase(str1.begin() + i);
        }
        str1.erase(str1.begin() + 2);
        str1.erase(str1.begin() + 2);
        str1.push_back("y'");
        str5.push_back("y'");
        str5.push_back("|");
        str5.push_back("ε");
    }
    if (str3[0] == str3[2]){
        str6 = {"z'", "-"};
        int i = 3;
        while (str1[i] != "|"){
            str6.push_back(str1[i]);
            str1.erase(str1.begin() + i);
        }
        str1.erase(str1.begin() + 2);
        str1.erase(str1.begin() + 2);
        str1.push_back("z'");
        str6.push_back("z'");
        str6.push_back("|");
        str6.push_back("ε");
    }
    for (k = 0; k < str1.size(); k++){
        cout << str1[k] << " ";
    }
    cout << endl;
    if (str4.size() != 0){
        for (k = 0; k < str4.size(); k++){
            cout << str4[k] << " ";
        }
    }
    for (k = 0; k < str2.size(); k++){
        cout << str2[k] << " ";
    }
    cout << endl;
    if (str5.size() != 0){
        for (k = 0; k < str5.size(); k++){
            cout << str5[k] << " ";
        }
    }
    for (k = 0; k < str3.size(); k++){
        cout << str3[k] << " ";
    }
    cout << endl;
    if (str6.size() != 0){
        for (k = 0; k < str6.size(); k++){
            cout << str6[k] << " ";
        }
    }
    return 0;
}