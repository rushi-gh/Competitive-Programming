#include <bits/stdc++.h>
using namespace std;

void PrintFactorial(int num, int from, vector <int> &ans) {
    cout << num << " = ";
    for (int k = from; k >= 0; k--) {
        cout << ans[k];
    }
    cout << endl;
}

void Solve () {
    int n;
    cin >> n;

    vector <int> ans(150);

    int multiplyTill = 0, carry = 1;
    for (int i = 1; i <= n; i++) {
        int j = 0;
        for (j = 0; j < multiplyTill; j++) {
            carry += ans[j] * i;
            ans[j] = carry % 10;
            carry /= 10;
        }
        while (carry) {
            ans[j++] = carry % 10;
            carry /= 10;
        }
        multiplyTill = j;
        PrintFactorial(i, multiplyTill - 1, ans);
    }

    cout << endl;
}

int main () {
    Solve();
    return 0;
}