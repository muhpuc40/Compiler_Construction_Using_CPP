#include <bits/stdc++.h>
using namespace std;
int main() {
  FILE *src = fopen("CCL_1_2211_input.c", "r");
  if (src == nullptr) {
    cout << "Cannot open CCL_1_2211_input.c\n";
    return 1;
  }
  FILE *dest = fopen("CCL_1_2211_output.c", "w");
  int ch;
  while ((ch = fgetc(src)) != EOF) {
    fputc(ch, dest);
  }
  cout << "Copied successfully!\n";
  fclose(src);
  fclose(dest);
  return 0;
}
