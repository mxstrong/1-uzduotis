#include <iostream>
using namespace std;

bool isWoman(string name) {
  int lastLetterNumber = name.length() - 1;
  if (name[lastLetterNumber] == 'a' || name[lastLetterNumber] == 'e') {
    return true;
  }
  return false;
}

int main() {
  cout << "Iveskite varda" << endl;
  string name;
  cin >> name;
  string greeting = "";
  if (isWoman(name)) {
    greeting = "Sveika, ";
  }
  else {
    greeting = "Sveikas, ";
  }
  
  int length = 2 + greeting.length() + name.length() + 2;
  string first = "", second = "", fourth = "", fifth = "";
  for (int i = 0; i < length; i++) {
    first += '*';
    fifth += '*';
    if (i == 0 || i == length - 1) {
      second += '*';
      fourth += '*';
    }
    else {
      second += ' ';
      fourth += ' ';
    }
  }
  
  string third = "* " + greeting + name + " *";
  cout << first << endl << second << endl << third << endl << fourth << endl << fifth;
  return 0;
}