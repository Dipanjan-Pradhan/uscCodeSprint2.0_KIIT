#include <bits/stdc++.h>
using namespace std;

class DrugPacketNesting {
  int N;
  vector<int> packets;

public:
  void readInput() {
    cout << "Enter number of packets: ";
    cin >> N;
    if (N < 1 || N > 1e5) {
      cout << "!! Invalid Input !!" << endl;
      exit(1);
    }

    cout << "Enter the highness values (space-separated): ";
    packets.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> packets[i];
      if (packets[i] < 1 || packets[i] > 1e4) {
        cout << "!! Invalid Input !!" << endl;
        exit(1);
      }
    }
  }

  int findMinPacketsToSmuggle() {
    sort(packets.begin(), packets.end());

    // Count frequency of each highness value
    int ans = 0;
    int count = 1;

    for (int i = 1; i < N; i++) {
      if (packets[i] == packets[i - 1]) {
        count++;
      } else {
        ans = max(ans, count);
        count = 1;
      }
    }

    ans = max(ans, count); // check last frequency too
    return ans;
  }

  void display() {
    cout << "Minimum packets to smuggle: " << findMinPacketsToSmuggle() << endl;
  }
};

int main() {
  DrugPacketNesting dpn;
  dpn.readInput();
  dpn.display();
  return 0;
}
