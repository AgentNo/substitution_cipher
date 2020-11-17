# Simple Substitution Cipher
This is a simple substitution cipher implemented in C++. 
The original idea came from an exercise in the Beginning C++ Programming course on Udemy (https://www.udemy.com/course/beginning-c-plus-plus-programming/), which implemented the basic functionality.

## How the cipher works
The encoding is performed by two strings - `alphabet` and `key`. The alphabet is a string of alphanumeric characters (A-Z, a-z and 0-9), each character in which maps to a single character in the key. Any character that is not captured by the alphabet string
is not encoded (such as whitespace or punctuation, for example).

Obviously, this is not a secure cipher. I don't take responsibility if you use this to encrypt sensitive information. 

## Usage
Feel free to use this code, as long as credit is provided. As stated previously, this is an insecure encryption method and I do not take responsiblity for how you use it.

## Current limitations and planned features:
- Only characters A-Z, a-z and 0-9 can be substituted
- Currently no way to modify alphabet or key strings without modifying the source code and rebuilding