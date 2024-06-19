#include <bits/stdc++.h>
using namespace std;

string EvenOrOdd (int n) {
    return (n & 1) ? "Odd" : "Even";
}

// ~0 -> all set bits -> 111....111
int GetIthBit (int n, int i) {
    int mask = 1LL << i;
    return ((n & mask) > 0);
}

int SetIthBit(int n, int i) {
    int mask = 1LL << i;
    n |= mask;
    return n;
}

int ClearIthBit(int n, int i) {
    int mask = ~(1LL << i);
    n &= mask;
    return n;
}

int ClearLastIBits(int n, int i) {
    int mask = (~0) << i;
    n &= mask;
    return n;
}

// [L, R]
int ClearBitsInRange(int n, int l, int r) { 
    int LeftMask = (~0) << (r + 1);
    int rightMask = (1LL << l) - 1;
    n &= (LeftMask | rightMask);
    return n;
}

string IsPowerOf2 (int n) {
    return (n > 0 and (n & (n - 1)) == 0 ? "Yes" : "No");
}

string IsPowerOf4(int n) {
    return ((n > 0 and (n & (n - 1)) == 0 and n % 3 == 1) ? "Yes" : "No");

    // int mask = 0;
    // for (int j = 0; j < 32; j += 2) {
    //     mask |= (1LL << j);
    // }
    // return IsPowerOf2(n & mask);
}

int main() {
    // cout << EvenOrOdd(1) << ' ' << EvenOrOdd(2) << endl;

    // cout << GetIthBit(6, 2) << GetIthBit(6, 1) << GetIthBit(6, 0) << endl;
    // cout << SetIthBit(6, 0) << ' ' << SetIthBit(6, 1) << endl;
    // cout << ClearIthBit(6, 0) << ' ' << ClearIthBit(6, 1) << endl;
    // cout << ClearLastIBits(15, 0) << ' ' << ClearLastIBits(15, 1) << ' ' << ClearLastIBits(15, 2) << endl;
    // cout << ClearBitsInRange(15, 1, 2) << endl;

    // cout << IsPowerOf2(0) << ' ' << IsPowerOf2(1) << ' ' << IsPowerOf2(2) << ' ' << IsPowerOf2(3) << endl;
    // cout << IsPowerOf4(0) << ' ' << IsPowerOf4(1) << ' ' << IsPowerOf4(2) << ' ' << IsPowerOf4(4) << endl;

    return 0;
}