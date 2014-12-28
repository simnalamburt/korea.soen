#include <string>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

vector<pair<string, string>> whitebook;

void search();
void AddPhone();
void Delete();

int main() {
  while (true) {
    cout << "무엇을 하시겠습니까\n"
      "1. Search\n"
      "2. Add\n"
      "3. Delete\n"
      "4. Finish\n" << flush;

    int a;
    cin >> a;

    switch (a) {
    case 1:
      search();
      break;
    case 2:
      AddPhone();
      break;
    case 3:
      Delete();
      break;
    case 4:
      return 0;
    default:
      puts("유효한 입력이 아닙니다.");
    }
  }

  return 0;
}


void search() {
  cout << "이름을 입력하시오: " << flush;

  string input;
  cin >> input;

  size_t save, count = 0;
  const size_t len = whitebook.size();
  for (size_t i = 0; i < len; ++i) {
    if (whitebook[i].first.compare(input)) { continue; }

    ++count;
    save = i;
  }

  switch (count) {
    case 0:
      cout << "해당 이름의 전화번호는 존재하지 않습니다." << endl;
      break;
    case 1:
      cout << whitebook[save].second << endl;
      break;
    default:
      cout << "error: 해당 이름에 2개 이상의 전화번호가 저장되어 있습니다." << endl;
      break;
  }
}

void AddPhone() {
  cout << "이름을 입력하시오: " << flush;

  string input;
  cin >> input;

  size_t save, count = 0;
  const size_t len = whitebook.size();
  for(size_t i = 0; i < len; ++i) {
    if (whitebook[i].first.compare(input)) { continue; }

    ++count;
    save = i;
  }

  if (count) {
    cout << "해당 이름의 전화번호는 이미 저장되어있습니다." << endl;
  } else {
    cout << "해당 이름의 전화번호를 입력해주십시오: " << endl;

    string number;
    cin >> number;

    pair<string, string> pair1;
    pair1.first = input;
    pair1.second = number;
    whitebook.push_back(pair1);

    cout << "저장이 완료되었습니다." << endl;
  }
}

void Delete() {
  cout << "이름을 입력하시오: " << flush;

  string input;
  cin >> input;

  size_t save, count = 0;
  const size_t len = whitebook.size();
  for(size_t i = 0; i < len; ++i) {
    if (whitebook[i].first.compare(input)) { continue; }

    ++count;
    save = i;
  }

  if (!count) {
    cout << "해당 이름의 전화번호는 존재하지 않습니다." << endl;
  } else if (count == 1) {
    whitebook.erase(whitebook.begin() + save);
    cout << "삭제가 완료되었습니다." << endl;
  }
}
