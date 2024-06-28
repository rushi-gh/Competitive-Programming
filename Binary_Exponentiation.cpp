#include <iostream>
using namespace std;

int Iterative(int a, int b) {
    int result = 1;
    while (b) {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }
    return result;
}

int Recursive(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (b & 1) {
        return a * Recursive(a * a, b / 2);
    } else {
        return Recursive(a * a, b / 2);
    }
}

// Same as Binary Exponentiation, We can also do binary multiplication
// Multiplication of a and b => a * b
int Binary_Multiplication(int a, int b) {
    int ans = 0;
    while (b) {
        if (b & 1) ans += a;
        a += a;
        b >>= 1;
    }
    return ans;
}
 
int main () {
    cout << Iterative(3, 5) << endl;
    cout << Recursive(3, 5) << endl;
    cout << Binary_Multiplication(8, 19) << endl;
    return 0;   
}