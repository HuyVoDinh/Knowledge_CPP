/***
 * A simple and very old method of sending secret messages is the substitution cipher
 * You might have used this cipher with your friends when you were a kid
 * Basically each letter of the alphabet gets replaced by another letter of the alphabet
 * For example, every 'a' get replaced with an 'X' and every 'b' gets replaced with a 'Z' etc
 * 
 * Write a program thats ask a user to enter a secret message
 * 
 * Encrypt this message using the substitution cipher and display the encrypted message
 * The decryped the encrypted message back to the original message
 * 
 * You may use the 2 strings below for your substitution
 * For example, to encrypt you can replace the character at position n in alphabet with the character at position n in key
 * 
 * To decrypt you can replace the character at position n in key with the character at position n in alphabet
 * 
 * Have fun! and make the cipher stronger if you wish!
 * Currently the cipher only substitutes letters - you could easily add digits, punctuation, whitespace and so forth.
 * Also, currently the cipher always substitutes a lowercase letter with an uppercase letter and vice-versa.
 * This could also be improved
 * 
 * Remember, the less code you write the less code you have to test!
 * Reuse existing functionality in libraries and in the std::string class!
 * ***/

#include <iostream>
using namespace std;

int main()
{
    string alphabet {"[ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {" [XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqyvtkfuompciasr"};

    string secret_message {};
    cout << "Enter you secret message: ";
    getline(cin, secret_message);

    string encrypted_message {};

    cout << "\nEncrypting message...\n";

    for(char c:secret_message)
    {
        size_t position = alphabet.find(c);
        if(position != string::npos)
        {
            char new_char {key.at(position)};
            encrypted_message += new_char;
        }
        else {
            encrypted_message += c;
        }
    }
    cout << "Encrypted message: " << encrypted_message << endl;

    string decrypter_message {};

    cout << "\nDecrypting message..." << endl;
    for(char c:encrypted_message)
    {
        size_t position = key.find(c);
        if(position != string::npos)
        {
            char new_char {alphabet.at(position)};
            decrypter_message += new_char;
        }
        else {
            decrypter_message += c;
        }
    }

    cout << "Decrypting message: " << decrypter_message << endl;
}