#include <bits/stdc++.h>
using namespace std;

class SecretDecoder {
  string s;
  int idx = 0; // pointer to current index in the string

public:
  void readInput() {
    cin >> s;
    if (s.empty() || s.length() > 1e4) {
      cout << "!! Invalid Input !!" << endl;
      exit(1);
    }
  }

  string decode() {
    return decodeHelper();
  }

private:
  string decodeHelper() {
    string result = "";

    while (idx < s.length() && s[idx] != ']') {
      if (isdigit(s[idx])) {
        int k = 0;
        // Extract full number (could be more than 1 digit like 10[abc])
        while (isdigit(s[idx])) {
          k = k * 10 + (s[idx] - '0');
          idx++;
        }

        idx++; // skip the '['
        string decodedSubstring = decodeHelper();
        idx++; // skip the ']'

        // Append repeated string k times
        while (k--) result += decodedSubstring;
      } 
      else {
        result += s[idx++];
      }
    }

    return result;
  }

public:
  void display() {
    cout << decode() << endl;
  }
};

int main() {
  SecretDecoder sd;
  sd.readInput();
  sd.display();
  return 0;
}
