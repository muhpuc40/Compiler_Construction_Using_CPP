#include <iostream>
#include <string>
using namespace std;

int main() {
    string T, P;
    int INDEX = 0;

    cin >> T;
    cout << " pattern (P): ";
    cin >> P;

    int S = T.length();
    int R = P.length();

    int K = 1;
    int MAX = S - R + 1;

    while (K <= MAX) {
        bool match = true;

        for (int L = 0; L < R; L++) {
            if (P[L] != T[K - 1 + L]) {
                match = false;
                break;
            }
        }

        if (match) {
            INDEX = K;
            break;
        }

        K = K + 1;
    }

    if (INDEX == -1) {
        cout << "Pattern not found. INDEX = 0" << endl;
    } else {
        cout << "Pattern found at position INDEX = " << INDEX << endl;
    }

    return 0;
}
