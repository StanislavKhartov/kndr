#include <iostream>
#include "ForwardList.h"
#include "SortedList.h"
#include "Stack.h"
#include <algorithm>

int main() {
  Forward_listOnNodes<int> a;
  for (int i = 0; i < 20; i++) {
    a.push(i);
  }
  std::cout << a << std::endl;
  a.deleteByIndex(a.findIndex(20));
  SortedList<int> b;
  b.push(4);
  b.push(1);
  b.push(3);
  b.push(8999);
  b.push(2);
  b.push(0);
  b.push(9000);
  std::cout << b << "\n";
  Stack<int> d;
  d.pushBack(0);
  d.pushBack(1);
  d.pushBack(7);
  d.removeFirst();
  d.pushBack(78);
  Iterator<int>* it = a.begin();
  std::cout << (++it);
  return 0;
}
