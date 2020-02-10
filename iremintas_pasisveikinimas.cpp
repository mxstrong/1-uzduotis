#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isWoman(string name) {
  int lastLetterNumber = name.length() - 1;
  if (tolower(name[lastLetterNumber]) == 'a' || tolower(name[lastLetterNumber]) == 'e') {
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
  cout << "Iveskite remelio ploti" << endl;
  int width;
  
  bool validWidth = true;
  do {
    validWidth = true;
    cin >> width;
    if (width < 3) {
      cout << "Remelio plotis turi buti bent 3" << endl;
      validWidth = false;
    }
    if ((width - 3) % 2 != 0) {
      cout << "Remelis turi buti simetriskas" << endl;
      validWidth = false;
    }
  } while (!validWidth);

  std::vector<string> lines;
  for (int i = 0; i < width; i++) {
    lines.push_back("");
  }

  for (int i = 0; i < length; i++) {
    lines[0] += '*';
    lines[width - 1] += '*';
    if (i == 0 || i == length - 1) {
      for (int j = 1; j <= (width - 3) / 2; j++) {
        lines[j] += '*';
        lines[width - j - 1] += '*';
      }
    }
    else {
      for (int j = 1; j <= (width - 3) / 2; j++) {
        lines[j] += ' ';
        lines[width - j - 1] += ' ';
      }
    }
  }
  lines[(width / 2)] = "* " + greeting + name + " *";
  for (const auto line : lines) {
    cout << line << endl;
  }
  return 0;
}
