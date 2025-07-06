#include <iostream>
#include <algorithm>
using namespace std;

class InputHandler{
public:
  int n;
  int *vaccines;
  int *patients;

  InputHandler() : n(0), vaccines(nullptr), patients(nullptr){}

  void getInput(){
    cout << "Enter the no of vaccines (and patients): ";
    cin >> n;

    vaccines = new int[n];
    patients = new int[n];

    cout << "Enter the midichlorians count of each vaccine batch: ";
    for(int i = 0; i < n; i++)
      cin >> vaccines[i];

    cout << "Enter the midichlorians count for each patient: ";
    for(int i = 0; i < n; i++)
      cin >> patients[i];
  }

  ~InputHandler(){
    delete[] vaccines;
    delete[] patients;
  }
};


class CureChecker{
public:
  static bool canCureAll(int *vaccines, int *patients, int n){
    sort(vaccines, vaccines + n);
    sort(patients, patients + n);

    for(int i = 0; i < n; i++){
      if(vaccines[i] <= patients[i]) return false;
    }
    return true;
  }
};

class OutputHandler{
public:
  static void printResult(bool result){
    if(result)
      cout << "Yes" << endl;
    else
      cout << "No" << endl; 
  }
};

int main(){
  InputHandler input;
  input.getInput();

  bool result = CureChecker::canCureAll(input.vaccines, input.patients, input.n);

  OutputHandler::printResult(result);
  return 0;
}
