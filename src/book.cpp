#include <string>
#include <unordered_map>
#include <iostream>
#include "book.h"

using namespace std;


unordered_map<string, string> whitebook;

string get_input() {
  string input;
  cin >> input;
  return input;
}

void Find() {
  cout << "이름을 입력하시오: " << flush;
  const string name = get_input();

  const auto result = whitebook.find(name);
  if (result == whitebook.end()) {
    cout << "전화번호부에서 \"" << name << "\"을 찾지 못했습니다." << endl;
    return;
  }

  cout << '"' << result->first << "\"의 전화번호는 " << result->second << " 입니다." << endl;
}

void Add() {
  cout << "이름을 입력하시오: " << flush;
  const string name = get_input();

  const auto result = whitebook.find(name);
  if (result != whitebook.end()) {
    cout << "전화번호부에 이미 \"" << name << "\"라는 이름의 번호가 저장되어있었습니다." << endl;
    return;
  }

  cout << '"' << name << "\"의 전화번호를 입력해주십시오: " << flush;
  const string number = get_input();

  whitebook.emplace(name, number);
  cout << "저장이 완료되었습니다." << endl;
}

void Delete() {
  cout << "이름을 입력하시오: " << flush;
  const string name = get_input();

  const auto result = whitebook.find(name);
  if (result == whitebook.end()) {
    cout << "전화번호부에 \"" << name << "\"라는 이름의 번호가 없습니다." << endl;
    return;
  }

  whitebook.erase(result);
  cout << "삭제가 완료되었습니다." << endl;
}
