#include<iostream>
using namespace std;
void naivePatternMatch(string text, string pattern)
{
    int n= text.length();
    int m= pattern.length();
        for (int i = 0; i <= n - m; i++) {
        int j;


        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }


        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}
int main()
{
    string text ;
    string pattern ;
    cin>> text;
    cin>>pattern;

    naivePatternMatch(text, pattern);

    return 0;
}

