#include <bits/stdc++.h>
using namespace std;

class WinterHeater {
    vector<int> houses;
    vector<int> heaters;

public:
    void readInput() {
        string line;
        int x;

        // Read houses
        cout << "houses = ";
        getline(cin, line);
        istringstream hs(line);
        while (hs >> x)
            houses.push_back(x);

        // Read heaters
        cout << "heaters = ";
        getline(cin, line);
        istringstream ht(line);
        while (ht >> x)
            heaters.push_back(x);
    }

    int findMinRadius() {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int radius = 0;

        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            int dist1 = INT_MAX, dist2 = INT_MAX;

            if (it != heaters.end()) dist1 = abs(*it - house);
            if (it != heaters.begin()) dist2 = abs(*prev(it) - house);

            radius = max(radius, min(dist1, dist2));
        }

        return radius;
    }

    void display() {
        cout << findMinRadius() << "\n";
    }
};

int main() {
    WinterHeater wh;
    wh.readInput();
    wh.display();
    return 0;
}
