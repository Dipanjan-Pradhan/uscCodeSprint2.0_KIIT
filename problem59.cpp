#include <iostream>
#include <set>
#include <string>
using namespace std;

class InputReader {
public:
    string steps;

    void readInput() {
        cout << "Enter Benny's movement path: ";
        getline(cin, steps);
    }

    bool isValidPath() {
        for (char c : steps) {
            if (c != 'L' && c != 'R' && c != 'U' && c != 'D')
                return false;
        }
        return true;
    }

    bool isWithinConstraints() {
        int len = steps.length();
        return (len >= 1 && len <= 100000);
    }
};

class PathTracker {
private:
    set<pair<int, int>> visited;
    int x, y;

public:
    PathTracker() : x(0), y(0) {
        visited.insert({0, 0});
    }

    int countSlips(const string& moves) {
        int slips = 0;
        for (char move : moves) {
            switch (move) {
                case 'L': x--; break;
                case 'R': x++; break;
                case 'U': y++; break;
                case 'D': y--; break;
            }
            pair<int, int> pos = {x, y};
            if (visited.count(pos))
                slips++;
            else
                visited.insert(pos);
        }
        return slips;
    }
};

class ResultPrinter {
public:
    static void display(int slips) {
        cout << "Total slips: " << slips << endl;
    }
};

int main() {
    InputReader input;
    input.readInput();

    if (!input.isWithinConstraints()) {
        cout << "String length must be between 1 and 10^5." << endl;
        return 1;
    }

    if (!input.isValidPath()) {
        cout << "Enter only L, R, U, D characters." << endl;
        return 1;
    }

    PathTracker tracker;
    int slips = tracker.countSlips(input.steps);

    ResultPrinter::display(slips);

    return 0;
}
