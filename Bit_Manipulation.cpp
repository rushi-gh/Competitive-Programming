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

// Approach - Each step clears LSB
int CountSetBits(int n) {
    int cnt = 0;
    while (n) {
        n &= (n - 1);
        cnt++;
    }
    return cnt;
}

// FAQ of Bit Manipulation
// {1, 2, 2, 3, 3}
int Unique_In_2n_1(vector <int> vec) {
    int unique = 0;
    for (int &i : vec) {
        unique ^= i;
    }
    return unique;
}

// {1, 2, 2, 3, 3, 4, 5, 5}
pair <int, int> Unique_In_2n_2(vector <int> vec) {
    // Getting XOR of 2 numbers in _xor
    int _xor = 0;
    for (int &i : vec) {
        _xor ^= i;
    }

    // Finding LSB in _xor
    int lsb = 0;
    for (int i = 0; i < 32; i++) {
        int mask = 1LL << i;
        if (_xor & mask) {
            lsb = mask;
            break;
        }
    }

    // Getting XOR's of no having lsb as setbit to get first unique no
    int firstUnique = _xor;
    for (int &i : vec) {
        if (i & lsb) {
            firstUnique ^= i;
        }
    }

    int secondUnique = (firstUnique ^ _xor);
    return {firstUnique, secondUnique};    
}

// {1, 1, 1, 2, 2, 2, 3, 3, 3, 4}
int Unique_In_3n_1(vector <int> vec) {
    int uniq = 0;
    for (int i = 0; i < 32; i++) {
        int setBitCount = 0;

        int mask = 1LL << i;
        for (int &j : vec) {
            setBitCount += (j & mask) > 0;
        }

        if (setBitCount % 3) {
            uniq |= mask;
        }
    }
    return uniq;
}

// Printing All subsequences using Bit-Masking
void PrintAllSubsequencesUsingBits(string s) {
    int sSize = s.size();
    int maskSize = (1LL << sSize);
    for (int mask = 0; mask < maskSize; mask++) {
        string word;
        for (int j = 0; j < sSize; j++) {
            int subMask = (mask & (1LL << j));
            if (subMask) {
                word.push_back(s[j]);
            }
        }
        cout << word << endl;
    }
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

    // cout << CountSetBits(15) << ' ' << CountSetBits(9) << endl;

    //cout << Unique_In_2n_1({1, 1, 2, 2, 3, 4, 4}) << ' ' << Unique_In_2n_1({1, 1, 2, 3, 3, 4, 4}) << endl;

    // pair <int, int> uniqPair = Unique_In_2n_2({1, 2, 2, 3, 3, 4, 5, 5});
    // cout << uniqPair.first << ' ' << uniqPair.second << endl;

    // cout << Unique_In_3n_1({1, 1, 1, 2, 2, 2, 3, 3, 3, 4}) << endl;

    PrintAllSubsequencesUsingBits("abc");

    return 0;
}