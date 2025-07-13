#include <iostream>
#include <vector>
using namespace std;

class SuperPrime
{
    int rangeLimit;
    vector<bool> isPrime;
    vector<int> prime;
    vector<int> superPrime;

public:
    void readInput()
    {
        cin >> rangeLimit;
        if (rangeLimit < 1 || rangeLimit > 1e6)
        {
            cout << "!! Invalid Input !!" << endl;
            exit(1);
        }
    }

    void sieve()
    {
        isPrime.assign(rangeLimit + 2, true); // +2 for safety
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= rangeLimit; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= rangeLimit; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i <= rangeLimit; i++)
        {
            if (isPrime[i])
                prime.push_back(i);
        }
    }

    void findSuperPrime()
    {
        for (int i = 0; i < prime.size(); i++)
        {
            // prime index is (i + 1)
            if (isPrime[i + 1])
                superPrime.push_back(prime[i]);
        }
    }

    void display()
    {
        for (auto it : superPrime)
        {
            cout << it << " ";
        }
    }
};

int main()
{
    SuperPrime sp;
    sp.readInput();
    sp.sieve();
    sp.findSuperPrime();
    sp.display();
    return 0;
}
