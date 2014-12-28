#include <string>
#include <unordered_map>
#include <iostream>
#include "main.h"

using namespace std;

unordered_map<string, string> whitebook;

int main() {
  while (true) {
    cout << "무엇을 하시겠습니까\n"
      "1. Search\n"
      "2. Add\n"
      "3. Delete\n"
      "4. Finish\n" << flush;

    string a;
    cin >> a;

    if (a == "1")       { search(); }
    else if (a == "2")  { AddPhone(); }
    else if (a == "3")  { Delete(); }
    else if (a == "4")  { return 0; }
    else { cout << "유효한 입력이 아닙니다." << endl; }
  }

  return 0;
}


string get_input();
void search() {
  const string name = get_input();

  const auto result = whitebook.find(name);
  if (result == whitebook.end()) {
    cout << "전화번호부에서 \"" << name << "\"을 찾지 못했습니다." << endl;
    return;
  }

  cout << '"' << result->first << "\"의 전화번호는 " << result->second << " 입니다." << endl;
}

void AddPhone() {
  const string name = get_input();

  const auto result = whitebook.find(name);
  if (result != whitebook.end()) {
    cout << "전화번호부에 이미 \"" << name << "\"라는 이름의 번호가 저장되어있었습니다." << endl;
    return;
  }

  cout << '"' << name << "\"의 전화번호를 입력해주십시오: " << endl;
  const string number = get_input();

  whitebook.emplace(name, number);
  cout << "저장이 완료되었습니다." << endl;
}

void Delete() {
  const string name = get_input();

  const auto result = whitebook.find(name);
  if (result == whitebook.end()) {
    cout << "전화번호부에 \"" << name << "\"라는 이름의 번호가 없습니다." << endl;
    return;
  }

  whitebook.erase(result);
  cout << "삭제가 완료되었습니다." << endl;
}


string get_input() {
  cout << "이름을 입력하시오: " << flush;

  string input;
  cin >> input;
  return input;
}
