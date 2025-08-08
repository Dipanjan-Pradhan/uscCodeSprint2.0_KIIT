#include <bits/stdc++.h>
using namespace std;

class GardenOfBST {
  int n;
  vector<int> dp;

public:
  void readInput() {
    cin >> n;
    if (n < 1 || n > 19) {
      cout << "!! Invalid Input !!" << endl;
      exit(1);
    }
    dp.assign(n + 1, -1);
  }

  int countBST(int nodes) {
    // Base case
    if (nodes <= 1) return 1;

    // Already computed
    if (dp[nodes] != -1) return dp[nodes];

    int total = 0;
    // Choose each node as root
    for (int root = 1; root <= nodes; ++root) {
      int left = countBST(root - 1);
      int right = countBST(nodes - root);
      total += left * right;
    }
    dp[nodes] = total;
    return total;
  }

  void display() {
    cout << countBST(n) << endl;
  }
};

int main() {
  GardenOfBST garden;
  garden.readInput();
  garden.display();
  return 0;
}
