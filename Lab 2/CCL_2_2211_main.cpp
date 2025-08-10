#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    FILE *src = fopen("CCL_2_2211_input.c", "r");
    if (!src) {
        cout << "Cannot open input file\n";
        return 1;
    }

    FILE *dest = fopen("CCL_2_2211_output.c", "w");
    if (!dest) {
        cout << "Cannot create output file\n";
        fclose(src);
        return 1;
    }

    int ch, next_ch;
    bool inSingleLine = false, inMultiLine = false;
    int singleLineCount = 0, multiLineCount = 0;

    while ((ch = fgetc(src)) != EOF) {
        if (!inSingleLine && !inMultiLine) {
            if (ch == '/') {
                next_ch = fgetc(src);
                if (next_ch == EOF) {
                    fputc(ch, dest);
                    break;
                }
                if (next_ch == '/') {
                    inSingleLine = true;
                    singleLineCount++;
                } else if (next_ch == '*') {
                    inMultiLine = true;
                    multiLineCount++;
                } else {
                    fputc(ch, dest);
                    fputc(next_ch, dest);
                }
            } else {
                fputc(ch, dest);
            }
        } else if (inSingleLine) {
            if (ch == '\n') {
                inSingleLine = false;
                fputc('\n', dest);  // keep new lines
            }
            // skip all chars in single-line comment
        } else if (inMultiLine) {
            if (ch == '*') {
                next_ch = fgetc(src);
                if (next_ch == '/') {
                    inMultiLine = false;
                } else if (next_ch != EOF) {
                    ungetc(next_ch, src);
                }
            }
            if (ch == '\n') {
                fputc('\n', dest);  // keep new lines for formatting
            }
            // skip other chars in multi-line comment
        }
    }

    fclose(src);
    fclose(dest);

    cout << "Comments removed!\n";
    cout << "Single-line comments found: " << singleLineCount << "\n";
    cout << "Multi-line comments found: " << multiLineCount << "\n";

    return 0;
}
