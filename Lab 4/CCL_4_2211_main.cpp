#include <bits/stdc++.h>

using namespace std;

int main() {
    string pattern, input;

    cout << "Enter pattern: ";
    getline(cin, pattern);

    cout << "Enter string: ";
    getline(cin, input);

    try {
        regex re(pattern);
        if (regex_match(input, re)) {
            cout << "Matched" << endl;
        } else {
            cout << "Unmatched" << endl;
        }
    }
    catch (regex_error& e) {
        cout << "Invalid regex pattern!" << endl;
    }

    return 0;
}
