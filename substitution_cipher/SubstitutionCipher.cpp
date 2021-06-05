#include <iostream>
#include <string>

using namespace std;

// Encode the user's message with the key via substitution
string encode(string plaintext, string alphabet, string key) {
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

// Decode the user's message with the key via substitution
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
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"};
    string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgghqdyvtkfuompciasr0h3lz8nql3"};
    bool loop = true;

    while (loop == true) {
        // Get the user's input
        cout << "\nSubstitution Cipher\n\nEnter 1 to encode a message\nEnter 2 to decode a message\nEnter 3 to exit.\n\n>>> ";
        int option;
        cin >> option;

        // If cin gets unexpected input, it can enter into the fail state and cause an infinite loop. To fix this, 
        // cin must be cleared and any bad characters ignored to force it to accept input again.
        if (cin.fail()) {
            cout << "Please enter an integer";
            cin.clear();
            // discard 'bad' character(s)
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch(option) {
            case 1:
                {
                    // Encode a string
                    string plaintext;
                    cout << "\nEnter a phrase to encode: ";
                    cin.ignore();
                    getline(cin, plaintext);
                    plaintext = encode(plaintext, alphabet, key);
                    cout << "\n\nThe ciphertext is " + plaintext + "\n";
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
                    cout << "\n\nThe plaintext is " + ciphertext + "\n";
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
                break;
        }
    }
    // Exit the application
    system("pause");
    cout << endl;
    return 0;
}
