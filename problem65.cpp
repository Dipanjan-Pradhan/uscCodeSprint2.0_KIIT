#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class ScienceFairClubSplit {
public:
    int n, k;
    vector<int> themes;

    void readInput() {
        cin >> n >> k;
        int theme;
        for (int i = 0; i < n; ++i) {
            cin >> theme;
            themes.push_back(theme);
        }
    }

    bool isPossibleSplit() {
        unordered_set<int> uniqueThemes;
        for (int t : themes) {
            uniqueThemes.insert(t);
        }

        return uniqueThemes.size() >= k;
    }

    void printResult(bool possible) {
        if (possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
};

int main() {
    ScienceFairClubSplit sfcs;
    sfcs.readInput();
    bool possible = sfcs.isPossibleSplit();
    sfcs.printResult(possible);
    return 0;
}
