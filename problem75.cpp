#include <bits/stdc++.h>
using namespace std;

class GrowingString {
  int k;

public:
  void readInput() {
    cin >> k;
    if (k < 1 || k > 1000) {
      cout << "!! Invalid Input !!" << endl;
      exit(1);
    }
  }

  char findLetter() {
    string s = "a";
    while ((int)s.length() < k) {
      string t = "";
      for (char c : s) {
        char nextChar = (c == 'z') ? 'a' : (c + 1);
        t += nextChar;
      }
      s += t;
    }
    // Convert to uppercase as required
    return (s[k - 1]);
  }

  void display() {
    cout << findLetter() << endl;
  }
};

int main() {
  GrowingString gs;
  gs.readInput();
  gs.display();
  return 0;
}
