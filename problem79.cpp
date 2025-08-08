#include <bits/stdc++.h>
using namespace std;

class PowerSpell {
  double x; // base
  int n;    // exponent

public:
  void readInput() {
    cin >> x >> n;
    if (x <= -100.0 || x >= 100.0) {
      cout << "!! Invalid Base !!" << endl;
      exit(1);
    }
    // Note: n can be any int in valid int range
  }

  double power(double base, int exp) {
    if (exp == 0) return 1.0;

    if (exp < 0) {
      // Handle negative exponent
      return 1.0 / power(base, -exp);
    }

    double half = power(base, exp / 2);

    if (exp % 2 == 0)
      return half * half;
    else
      return half * half * base;
  }

  void display() {
    cout << fixed << setprecision(6) << power(x, n) << endl;
  }
};

int main() {
  PowerSpell ps;
  ps.readInput();
  ps.display();
  return 0;
}
