#include <bits/stdc++.h>
using namespace std;

class GoodDigitString{
  int n;
public:
  void readInput(){
    cin >> n;
    if(n < 1 || n > 1000){
      cout << "!! Invalid Input !!" << endl;
      exit(1);
    }
  }

  int findGoodStringNo(int num){
    if(num == 0) return 5;
    if(num % 2 == 0) return 5 * findGoodStringNo(num - 1);
    else if(num % 2 != 0) return 4 * findGoodStringNo(num - 1);
  }

  void display(){
    cout << findGoodStringNo(n - 1) << endl;
  }
};
   
int main(){
  GoodDigitString gds;
  gds.readInput();
  gds.display();
  return 0;
}