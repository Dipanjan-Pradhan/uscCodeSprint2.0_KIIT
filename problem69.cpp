#include <bits/stdc++.h>
using namespace std;

class ParcelPacking {
  vector<int> parcels;
  int N, K;

public:
  void readInput() {
    cin >> N >> K;

    if (N < 1 || N > 1e5 || K < 1 || K > N) {
      cout << "!! Invalid input range !!" << endl;
      exit(1);
    }

    parcels.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> parcels[i];
      if (parcels[i] < 1 || parcels[i] > 1e4) {
        cout << "!! Invalid parcel weight !!" << endl;
        exit(1);
      }
    }
  }

  bool isPossible(int maxWeight) {
    int count = 1, currentSum = 0;
    for (int w : parcels) {
      if (currentSum + w <= maxWeight) {
        currentSum += w;
      } else {
        count++;
        currentSum = w;
        if (count > K) return false;
      }
    }
    return true;
  }

  int findMinMaxWeight() {
    int left = *max_element(parcels.begin(), parcels.end());
    int right = accumulate(parcels.begin(), parcels.end(), 0);
    int ans = right;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (isPossible(mid)) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }

  void display() {
    cout << findMinMaxWeight() << endl;
  }
};

int main() {
  ParcelPacking pp;
  pp.readInput();
  pp.display();
  return 0;
}
