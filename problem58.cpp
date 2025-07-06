#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class InputHandler {
public:
    int n;
    int* nums;

    InputHandler() : n(0), nums(nullptr) {}

    void getInput() {
        cout << "Enter the magical stones numbers in non-decreasing order: ";
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<int> temp;
        int num;
        while (ss >> num) {
            temp.push_back(num);
        }

        n = temp.size();
        nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = temp[i];
        }
    }

    ~InputHandler() {
        delete[] nums;
    }
};


class MagicalTransformer {
public:
    static int* transformAndSort(int* nums, int n) {
        int* result = new int[n];
        int left = 0, right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];
            if (leftSq > rightSq) {
                result[pos--] = leftSq;
                ++left;
            } else {
                result[pos--] = rightSq;
                --right;
            }
        }
        return result;
    }
};


class OutputHandler {
public:
    static void printArray(int* arr, int n) {
        cout << "The transformed magical numbers: ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    InputHandler input;
    input.getInput();

    int* squaredSorted = MagicalTransformer::transformAndSort(input.nums, input.n);

    OutputHandler::printArray(squaredSorted, input.n);

    delete[] squaredSorted;

    return 0;
}
