#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class WordNiceness {
public:
    int n;
    vector<string> words;

    void readInput() {
        cout << "Enter number of words: ";
        cin >> n;
        words.resize(n);
        cout << "Enter words: " << endl;
        for (int i = 0; i < n; ++i)
            cin >> words[i];
    }

    vector<int> computeNiceness() {
        vector<string> inserted;  // sorted order
        vector<int> result;

        for (const string &word : words) {
            // Find how many inserted words are less than word
            auto pos = lower_bound(inserted.begin(), inserted.end(), word);
            result.push_back(pos - inserted.begin());

            // Insert word keeping sorted order
            inserted.insert(pos, word);
        }

        return result;
    }

    void print(const vector<int> &niceness) {
        cout << "Niceness values:" << endl;
        for (int v : niceness)
            cout << v << endl;
    }
};

int main() {
    WordNiceness wn;
    wn.readInput();
    vector<int> niceness = wn.computeNiceness();
    wn.print(niceness);
    return 0;
}
