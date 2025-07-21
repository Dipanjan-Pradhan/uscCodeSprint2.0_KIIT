#include <bits/stdc++.h>
using namespace std;

class RoyalSelection {
  int N, r;

public:
  void readInput() {
    cin >> N >> r;
    if (N < 0 || N > 100 || r < 0 || r > N) {
      cout << "!! Invalid Input !!" << endl;
      exit(1);
    }
  }

  int nCr(int n, int k) {
    // Base Cases
    if (k == 0 || k == n)
      return 1;
    // Recursive Step
    return nCr(n - 1, k) + nCr(n - 1, k - 1);
  }

  void display() {
    cout << nCr(N, r) << endl;
  }
};

int main() {
  RoyalSelection rs;
  rs.readInput();
  rs.display();
  return 0;
}
