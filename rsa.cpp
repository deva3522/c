#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int p, q, e, n, phi, d = 1, msg;

    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;

    n = p * q;
    phi = (p - 1) * (q - 1);

    cout << "Enter public key exponent (e): ";
    cin >> e;
    while (gcd(e, phi) != 1) {
        cout << "Invalid e. Enter again: ";
        cin >> e;
    }

    while ((d * e) % phi != 1) d++;

    cout << "Enter message to encrypt: ";
    cin >> msg;

    int encrypted = modExp(msg, e, n);
    int decrypted = modExp(encrypted, d, n);

    cout << "Encrypted Message: " << encrypted << endl;
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}
