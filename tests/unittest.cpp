#include <iostream>
#include <unordered_map>
#include "../src/book.h"

using namespace std;

extern unordered_map<string, string> whitebook;

int main() {
  cout << whitebook.size() << endl;

  return 0;
}
