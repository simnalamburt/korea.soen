#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include "../src/book.h"

using namespace std;

extern unordered_map<string, string> whitebook;


template<typename T>
void assert_eq(const T& lhs, const T& rhs) {
  if (lhs == rhs && rhs == lhs) { return; }

  exit(1);
}

int main() {
  assert_eq(whitebook.size(), 0ul);
  Add();
  assert_eq(whitebook.size(), 1ul);
  assert_eq(whitebook[string("아이유")], string("01012341234"));
  Add();
  assert_eq(whitebook.size(), 2ul);
  assert_eq(whitebook[string("윤하")], string("01042314213"));
  Add();
  assert_eq(whitebook.size(), 2ul);
  Delete();
  assert_eq(whitebook.size(), 2ul);
  Delete();
  assert_eq(whitebook.size(), 1ul);

  return 0;
}
