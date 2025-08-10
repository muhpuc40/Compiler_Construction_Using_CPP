using namespace std;

int main() {
    std::string sourcePath = "CCl_3_2211_input.c";
    std::string destPath = "CCl_3_2211_output.c";

    std::ifstream sourceFile(sourcePath);
    if (!sourceFile) {
        std::cerr << "Error: Could not open source file " << sourcePath << "\n";
        return 1;
    }

    std::ofstream destFile(destPath);
    if (!destFile) {
        std::cerr << "Error: Could not open destination file " << destPath << "\n";
        return 1;
    }

    set<string> cKeywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline",
        "int", "long", "register", "restrict", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while", "_Alignas", "_Alignof", "_Atomic", "_Bool",
        "_Complex", "_Generic", "_Imaginary", "_Noreturn", "_Static_assert", "_Thread_local"
    };
    map<string, int> keywordCount;

    int singleLine = 0, multiLine = 0;
    std::string line, out;
    bool a = false;

    while (std::getline(sourceFile, line)) {
        int i = 0;
        while (i < (int)line.length()) {
            if (i + 1 < (int)line.size() && line[i] == '/' && line[i + 1] == '/') {
                singleLine++;
                i += 2;
                break;
            }
            else if (!a && i + 1 < (int)line.size() && line[i] == '/' && line[i + 1] == '*') {
                a = true;
                multiLine++;
                i += 2;
            }
            else if (a && i + 1 < (int)line.size() && line[i] == '*' && line[i + 1] == '/') {
                a = false;
                i += 2;
            }
            else if (!a) {
                out += line[i];
                i++;
            }
            else if (a) {
                i++;
            }
        }
          destFile << out << '\n';

          string token;
          stringstream ss(out);
          bool b = false;
          for (int k = 0; k < out.size(); ++k) {
            char c = out[k];
            if (c == '"') {
                b = true;
                ss << ' ';
            } else if (!b) {
                ss << c;
            } else {
                ss << ' ';
            }
        }
          while (ss >> token) {
          if (cKeywords.count(token) > 0) {
               keywordCount[token]++;
          }
     }
        out.clear();
    }

    std::cout << "Code copied successfully from " << sourcePath << " to " << destPath << "\n";
    std::cout << "Single-line comments : " << singleLine << "\n";
    std::cout << "Multi-line comments : " << multiLine << "\n";

    cout << "Keyword occurrences:\n";
    for (auto &p : keywordCount) {
        cout << p.first << " : " << p.second << "\n";
    }

    return 0;
}
