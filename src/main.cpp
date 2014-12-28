#include <iostream>
#include "book.h"

using namespace std;

int main() {
  while (true) {
    cout << "\n"
      "\n"
      "1. Search\n"
      "2. Add\n"
      "3. Delete\n"
      "4. Finish\n"
      "\n"
      "무엇을 하시겠습니까? " << flush;

    string a;
    cin >> a;

    if (a == "1")       { search(); }
    else if (a == "2")  { AddPhone(); }
    else if (a == "3")  { Delete(); }
    else if (a == "4")  { break; }
    else { cout << "유효한 입력이 아닙니다." << endl; }
  }

  cout << endl;
  return 0;
}
