#include <bits/stdc++.h>
using namespace std;

class MagicalPower{
  int n;
  bool isPowerOfTwo(int num){
    if(num == 1) return true;
    if(num <= 0 || num % 2 != 0) return false;
    return isPowerOfTwo(num / 2);
  }

public:
  void readInput(){
    cin >> n;
  }

  void display(){
    if(isPowerOfTwo(n))
      cout << "true" << endl;
    else
      cout << "false" << endl;
  }
};


int main(){
  MagicalPower mp;
  mp.readInput();
  mp.display();
  return 0;
}