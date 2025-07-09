#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

class MagicalBookshelf {
public:
    vector<int> books;
    int target;

    void readInput() {
        cout << "Enter book numbers: ";
        int num;
        while (cin >> num) {
            books.push_back(num);
            if (cin.peek() == '\n') break;
        }

        cout << "Enter the number of the new book: ";
        cin >> target;
    }

    int findInsertPosition() {
        // Use lower_bound for binary search: returns first index >= target
        auto pos = lower_bound(books.begin(), books.end(), target);
        return pos - books.begin();
    }

    void print(int index) {
        cout << "Position: " << index << endl;
    }
};

int main() {
    MagicalBookshelf mb;
    mb.readInput();
    int index = mb.findInsertPosition();
    mb.print(index);
    return 0;
}
