#include <iostream>
using namespace std;

string caesarCipher(string text, int shift) {
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = base + (text[i] - base + shift + 26) % 26;
        }
    }
    return text;
}

int main() {
    string text;
    int shift;

    cout << "Enter text: ";
    cin >> text;
    cout << "Enter shift value: ";
    cin >> shift;

    string encrypted = caesarCipher(text, shift);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = caesarCipher(encrypted, -shift);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
