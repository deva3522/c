#include <iostream>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main() {
    int a, b, x, y;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int gcd = extendedGCD(a, b, x, y);

    cout << "GCD: " << gcd << endl;
    cout << "x: " << x << ", y: " << y << endl;

    if (gcd == 1) {
        cout << "Modular Inverse: " << (x % b + b) % b << endl;
    } else {
        cout << "No Modular Inverse" << endl;
    }

    return 0;
}
