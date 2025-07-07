#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SpellInput {
public:
    int n, m;
    vector<long long> merlin, morgana;

    void readInput() {
        cout << "Enter number of Merlin's spells: ";
        cin >> n;
        merlin.resize(n);
        cout << "Enter Merlin's spell powers: ";
        for (int i = 0; i < n; ++i) cin >> merlin[i];

        cout << "Enter number of Morgana's spells: ";
        cin >> m;
        morgana.resize(m);
        cout << "Enter Morgana's spell powers: ";
        for (int i = 0; i < m; ++i) cin >> morgana[i];
    }

    bool isValidRange() {
        return (n >= 1 && n <= 1e5 && m >= 1 && m <= 1e5);
    }

    bool isValidSpells() {
        for (long long x : merlin)
            if (x < 0 || x > 1e9) return false;
        for (long long x : morgana)
            if (x < 0 || x > 1e9) return false;
        return true;
    }
};

class DuelPreparation {
public:
    static long long calculateMana(const vector<long long>& merlin, const vector<long long>& morgana) {
        long long strongest = *max_element(morgana.begin(), morgana.end());
        long long minPower = strongest + 1;

        long long totalMana = 0;
        for (long long power : merlin) {
            if (power < minPower)
                totalMana += (minPower - power);
        }
        return totalMana;
    }
};

class ManaPrinter {
public:
    static void print(long long mana) {
        cout << "Minimum mana required: " << mana << endl;
    }
};

int main() {
    SpellInput input;
    input.readInput();

    if (!input.isValidRange()) {
        cout << "Number of spells must be in range [1, 1e5]." << endl;
        return 1;
    }

    if (!input.isValidSpells()) {
        cout << "Enter Spell power within the range [0, 1e9]." << endl;
        return 1;
    }

    long long mana = DuelPreparation::calculateMana(input.merlin, input.morgana);
    ManaPrinter::print(mana);

    return 0;
}
