#include <iostream>
#include <string>

using namespace std;

string encode(string plaintext, string alphabet, string key) {
    // Encode the user's message with the key - both the key and alphabet strings are of the same length, which allows for 1-1 mapping.
    // Loop through the plaintext string and, for each character, read the corresponding letter in the key and add that to a new string
    string ciphertext;

    for (char c : plaintext) {
        size_t position = alphabet.find(c);
        if (position != string::npos) {
            string key_char = key.substr(position, 1);
            ciphertext.append(key_char);
        } else {
            ciphertext += c;
        }
    }

    return ciphertext;
}

string decode(string ciphertext, string alphabet, string key) {
    string plaintext;
    for (char c : ciphertext) {
        size_t position = key.find(c);
        if (position != string::npos) {
            string alpha_char = alphabet.substr(position, 1);
            plaintext.append(alpha_char);
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    // Alphabet and key strings
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
    string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgghqdyvtkfuompciasr0h3lz8nql3"};
    bool loop = true;

    while (loop == true) {
        // Get the user's initial input
        cout << "\nWelcome to the super secret enconder/decoder!\nEnter an option: \n Enter 1 to encode\n Enter 2 to decode\n Enter 3 to exit.\n\n >>> ";
        int option;
        cin >> option;

        switch(option) {
            case 1:
                {
                    // Encode a string
                    string plaintext;
                    cout << "\nEnter a phrase to encode: ";
                    cin.ignore();
                    getline(cin, plaintext);
                    plaintext = encode(plaintext, alphabet, key);
                    cout << "\nEncoding...\n\nThe ciphertext is " + plaintext + "\n";
                    system("pause");
                }
                break;
            case 2:
                {
                    // Decode a string
                    string ciphertext;
                    cout << "\nEnter a phrase to decode: ";
                    cin.ignore();
                    getline(cin, ciphertext);
                    ciphertext = decode(ciphertext, alphabet, key);
                    cout << "\nDecoding...\n\nThe plaintext is " + ciphertext + "\n";
                    system("pause");
                }
                break;
            case 3:
                // Exit the application
                cout << "\nThank you, the application will now close.\n";
                loop = false;
                break;
            default:
                // Error - unrecognised input
                cout << "\nError - invalid input. Please enter 1, 2 or 3.\n";
        }
    }
    // Exit the application
    system("pause");
    cout << endl;
    return 0;
}