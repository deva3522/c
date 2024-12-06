#include <iostream>
using namespace std;

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
    int p, g, a, b;

    cout << "Enter a prime number (p): ";
    cin >> p;
    cout << "Enter a primitive root of " << p << " (g): ";
    cin >> g;
    cout << "Enter private key for Alice (a): ";
    cin >> a;
    cout << "Enter private key for Bob (b): ";
    cin >> b;

    int A = modExp(g, a, p);
    int B = modExp(g, b, p);

    int sharedKeyAlice = modExp(B, a, p);
    int sharedKeyBob = modExp(A, b, p);

    cout << "Public key of Alice: " << A << endl;
    cout << "Public key of Bob: " << B << endl;
    cout << "Shared key (calculated by Alice): " << sharedKeyAlice << endl;
    cout << "Shared key (calculated by Bob): " << sharedKeyBob << endl;

    return 0;
}
