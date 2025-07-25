#include <bits/stdc++.h>
using namespace std;

class RoyalScribe {
    int num;
    vector<string> belowTwenty{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                               "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
                               "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                               "Nineteen"};
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
                        "Eighty", "Ninety"};
    vector<string> thousands{"", "Thousand", "Million", "Billion"};

    // Helper: Convert number < 1000
    string helper(int n) {
        if (n == 0) return "";
        else if (n < 20) return belowTwenty[n] + " ";
        else if (n < 100) return tens[n / 10] + " " + helper(n % 10);
        else return belowTwenty[n / 100] + " Hundred " + helper(n % 100);
    }

public:
    void readInput() {
        cin >> num;
        if (num < 0 || num > INT_MAX) {
            cout << "!! Invalid Input !!" << endl;
            exit(1);
        }
    }

    string numberToWords() {
        if (num == 0) return "Zero";

        string res;
        int i = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                res = helper(num % 1000) + thousands[i] + " " + res;
            }
            num /= 1000;
            i++;
        }

        // Remove trailing spaces
        while (!res.empty() && res.back() == ' ') res.pop_back();
        return res;
    }

    void display() {
        cout << numberToWords() << endl;
    }
};

int main() {
    RoyalScribe rs;
    rs.readInput();
    rs.display();
    return 0;
}
