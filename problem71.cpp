#include <bits/stdc++.h>
using namespace std;

class MagicalPotion {
  int n;  // number of days (terms)
public:
  void readInput() {
    cin >> n;
    n = n + 1;
    if (n < 1 || n > 1e5) {
      cout << "!! Invalid Input !!" << endl;
      exit(1);
    }
  }

  double computeSum() {
    double a = 1.0;  // first term
    double r = 1.0 / 3.0;  // common ratio

    // Geometric sum formula: S = a * (1 - r^n) / (1 - r)
    double rn = pow(r, n);
    double sum = a * (1 - rn) / (1 - r);

    return sum;
  }

  void display() {
    cout << computeSum() << endl;
  }
};

int main() {
  MagicalPotion mp;
  mp.readInput();
  mp.display();
  return 0;
}
