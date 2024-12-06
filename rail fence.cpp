#include <iostream>
using namespace std;

string railFenceEncrypt(string text, int key) {
    if (key == 1) return text;
    string result = "";
    int len = text.length();
    for (int row = 0; row < key; ++row) {
        int i = row;
        bool down = true;
        while (i < len) {
            result += text[i];
            if (row == 0 || row == key - 1) 
                i += 2 * (key - 1);
            else 
                i += down ? 2 * (key - 1 - row) : 2 * row;
            down = !down;
        }
    }
    return result;
}

string railFenceDecrypt(string cipher, int key) {
    if (key == 1) return cipher;
    string result = cipher;
    int len = cipher.length();
    int idx = 0;
    for (int row = 0; row < key; ++row) {
        int i = row;
        bool down = true;
        while (i < len) {
            result[i] = cipher[idx++];
            if (row == 0 || row == key - 1) 
                i += 2 * (key - 1);
            else 
                i += down ? 2 * (key - 1 - row) : 2 * row;
            down = !down;
        }
    }
    return result;
}

int main() {
    string text;
    int key;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter key: ";
    cin >> key;

    string encrypted = railFenceEncrypt(text, key);
    string decrypted = railFenceDecrypt(encrypted, key);

    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
