#include <iostream>
#include <string>
using namespace std;

class BinaryStringSortingGame {
public:
    int n;
    string s;

    void readInput() {
        cin >> n;
        cin >> s;
    }

    void checkCodeValidity(){
        for(char c : s)
            if(c != '1' && c != '0'){
                cout << "!! Invalid Input !!" << endl;
                exit(1);
            }
    }

    int isValidCode() {
        bool misplacedOne = false;
        bool misplacedZero = false;

        bool foundOne = false;
        for (char c : s) {
            if (c == '1') foundOne = true;
            else if (foundOne && c == '0') {
                misplacedZero = true;
                break;
            }
        }

        bool foundZero = false;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') foundZero = true;
            else if (foundZero && s[i] == '1') {
                misplacedOne = true;
                break;
            }
        }
        return (misplacedOne && misplacedZero) ? 0 : 1;
    }

    int minOperations(){
        int flipCount = 0;
        int i = 0, j = n - 1;
        while (i < j)
        {
            if(isValidCode()) break;
            while(s[i] != '1') i++;
            while(s[j] != '0') j--;
            if(i < j && !isValidCode()){
                swap(s[i], s[j]);
                flipCount++;
            } 
        }
        return flipCount;
    }

    void print(int ops) {
        cout << ops << endl;
    }
};

int main() {
    BinaryStringSortingGame bssg;
    bssg.readInput();
    bssg.checkCodeValidity();
    int ops = bssg.minOperations();
    bssg.print(ops);
    return 0;
}
