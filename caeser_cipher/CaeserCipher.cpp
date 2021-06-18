#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Encode a string
string encode(string plaintext, int shift){
    string ciphertext;
    for (char c : plaintext){
        if (c >= 'a' && c <= 'z'){
            c += shift;
            if (c > 'z'){
                c = c - 'z' + 'a' - 1;
            }
            ciphertext += c;
        }
        else if (c >= 'A' && c <= 'Z'){
            c += shift;
            if (c > 'Z'){
                // Handle overflow
                c = c - 'Z' + 'A' - 1;
            }
            ciphertext += c;
        }
        else if (isspace(c)){
            ciphertext.append(" ");
        }
        else{
            ciphertext += c;
        }
    }
    return ciphertext;
}

// Decode a string
string decode(string plaintext, int shift){
    string ciphertext;
    for (char c : plaintext){
        if (c >= 'a' && c <= 'z'){
            c -= shift;
            if (c < 'a'){
                c = c + 'z' - 'a' + 1;
            }
            ciphertext += c;
        }
        else if (c >= 'A' && c <= 'Z'){
            c -= shift;
            if (c < 'A'){
                // Handle overflow
                c = c + 'Z' - 'A' + 1;
            }
            ciphertext += c;
        }
        else if (isspace(c)){
            ciphertext.append(" ");
        }
        else{
            ciphertext += c;
        }
    }
    return ciphertext;
}

// Brute force a string, returning all possible decryptions
vector<string> brute_force(string ciphertext){
    vector<string> values;
    for(int i = 0; i < 26; i++){
        string plaintext = decode(ciphertext, i);
        values.push_back(plaintext);
    }
    return values;
}

int main(){
    bool loop = true;
    while (loop)
    {
        // Get the user's input
        cout << "\nCaeser Cipher\n\nEnter 1 to encode a message\nEnter 2 to decode a message\nEnter 3 to brute force\nEnter 4 to exit.\n\n>>> ";
        int option;
        cin >> option;

        // If cin gets unexpected input, it can enter into the fail state and cause an infinite loop. To fix this,
        // cin must be cleared and any bad characters ignored to force it to accept input again.
        if (cin.fail())
        {
            cout << "Please enter an integer";
            cin.clear();
            // discard 'bad' character(s)
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (option) {
            case 1:
                {
                    // Encode a string
                    string plaintext;
                    int shift;
                    cout << "\nEnter a phrase to encode: ";
                    cin.ignore();
                    getline(cin, plaintext);
                    cout << "\nEnter a shift (1-26): ";
                    cin >> shift;
                    plaintext = encode(plaintext, shift);
                    cout << "\n\nThe ciphertext is " + plaintext + "\n";
                    system("pause");
                }
                break;
            case 2:
                {
                    // Decode a string
                    string ciphertext;
                    int shift;
                    cout << "\nEnter a phrase to decode: ";
                    cin.ignore();
                    getline(cin, ciphertext);
                    cout << "\nEnter a shift (1-26): ";
                    cin >> shift;
                    ciphertext = decode(ciphertext, shift);
                    cout << "\n\nThe plaintext is " + ciphertext + "\n";
                    system("pause");
                }
                break;
            case 3:
                {
                    // Brute force a string
                    string ciphertext;
                    cout << "\nEnter ciphertext to brute force: ";
                    cin.ignore();
                    getline(cin, ciphertext);
                    vector<string> values;
                    values = brute_force(ciphertext);  // values is passed by reference to brute_force
                    cout << "\n\nPossible options for ciphertext are:\n" ;
                    for(string plaintext : values){
                        cout << plaintext + "\n";
                    }
                    system("pause");
                }
                break;
            case 4:
                // Exit the application
                cout << "\nThank you, the application will now close.\n";
                loop = false;
                break;
            default:
                // Error - unrecognised input
                cout << "\nError - invalid input. Please enter 1, 2, 3, or 4.\n";
                break;
            }
        }
    // Exit the application
    system("pause");
    cout << endl;
    return 0;
}
