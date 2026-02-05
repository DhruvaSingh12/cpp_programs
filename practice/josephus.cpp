#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
    int n;
    int k;
    cout << "The chosen place is " << josephus(n, k);
    return 0;
}

// recurrance relation: T(n) = T(n-1) + O(1)
// time complexity: O(n)