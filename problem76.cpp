#include <bits/stdc++.h>
using namespace std;

class BinaryTable {
  int n, k;

public:
  void readInput() {
    cin >> n >> k;
    if (n < 1 || n > 30 || k < 1 || k > (1 << (n - 1))) {
      cout << "!! Invalid Input !!" << endl;
      exit(1);
    }
  }

  int getSymbol(int row, int pos) {
    if (row == 1) return 0;

    int parent = getSymbol(row - 1, (pos + 1) / 2);
    bool isRightChild = (pos % 2 == 0);

    if (isRightChild) return parent ^ 1; // flip parent
    else return parent;
  }

  void display() {
    cout << getSymbol(n, k) << endl;
  }
};

int main() {
  BinaryTable bt;
  bt.readInput();
  bt.display();
  return 0;
}
