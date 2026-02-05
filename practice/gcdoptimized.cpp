#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;    
    while(m!=0){   //log(min(n,m)) Euclid's Algorithm
        int temp = m;
        m = n % m;
        n = temp;
    }
    cout << n << endl;
    return 0;
}


// int gcd(int a, int b){
//     if(b==0){
//         return a;   
//     }
//     return gcd(b, a%b);
// }