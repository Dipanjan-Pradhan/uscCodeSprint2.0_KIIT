#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class ParadeBadge {
public:
    vector<int> badges;

    // Read badge numbers space-separated
    void readInput() {
        cout << "Enter badge numbers: ";
        int badge;
        while (cin >> badge) {
            badges.push_back(badge);
            if (cin.peek() == '\n') break;
        }
    }

    // Validate input: numbers should be in [0, n-1] and must be unique
    bool isValidInput() {
        unordered_set<int> seen;
        int n = badges.size() + 1; // Because one badge is missing

        for (int badge : badges) {
            if (badge < 0 || badge >= n) {
                cout << "!! Invalid badge number: " << badge << endl;
                return false;
            }
            if (seen.count(badge)) {
                cout << "!! Duplicate badge number found: " << badge << endl;
                return false;
            }
            seen.insert(badge);
        }
        return true;
    }

    // Find the missing badge number
    int findMissing() {
        int n = badges.size() + 1; // Total people = n
        long long expectedSum = 1LL * (n - 1) * n / 2;
        long long actualSum = 0;
        for (int badge : badges) {
            actualSum += badge;
        }
        return expectedSum - actualSum;
    }

    // Print the result
    void print(int missing) {
        cout << "The missing badge number is: " << missing << endl;
    }
};

int main() {
    ParadeBadge pb;
    pb.readInput();

    if (!pb.isValidInput()) {
        cout << "!! Invalid Input !!" << endl;
        return 1;
    }

    int missing = pb.findMissing();
    pb.print(missing);
    return 0;
}
