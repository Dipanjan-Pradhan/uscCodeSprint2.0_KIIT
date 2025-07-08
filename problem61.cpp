#include <iostream>
#include <vector>
#include <set>
using namespace std;

class CardInput {
public:
    int n;
    vector<long long> cards;

    void readInput() {
        cout << "Enter number of cards: ";
        cin >> n;
        cards.resize(n);
        cout << "Enter card numbers: ";
        for (int i = 0; i < n; i++)
            cin >> cards[i];
    }

    bool isValidRange() {
        return (n >= 2 && n <= 1e5);
    }

    bool isValidCards() {
        for (long long x : cards)
            if (x < 1 || x > 1e9) return false;
        return true;
    }
};

class BeautifulPairsCounter {
public:
    static long long countBeautifulPairs(const vector<long long>& cards) {
        set<long long> unique(cards.begin(), cards.end());
        vector<long long> nums(unique.begin(), unique.end());

        long long count = 0;
        int sz = nums.size();

        // For each possible (first, last) pair:
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                if (nums[i] > nums[j]) count++;
            }
        }

        return count;
    }
};

class ResultPrinter {
public:
    static void print(long long count) {
        cout << "Total beautiful arrangements: " << count << endl;
    }
};

int main() {
    CardInput input;
    input.readInput();

    if (!input.isValidRange()) {
        cout << "Number of cards must be in range [2, 1e5]" << endl;
        return 1;
    }

    if (!input.isValidCards()) {
        cout << "Card numbers must be in range [1, 1e9]" << endl;
        return 1;
    }

    long long result = BeautifulPairsCounter::countBeautifulPairs(input.cards);
    ResultPrinter::print(result);
    return 0;
}
