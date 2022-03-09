#ifndef INC_24_02_2022__STACK_H_
#define INC_24_02_2022__STACK_H_

#include "ForwardList.h"

template<typename T>
class Stack : public Forward_listOnNodes<T> {
 private:
  int findIndex(T value);

  void deleteByIndex(int index);

  void insertByIndex(int index, T value);

  void push(T value) override{};

 public:
  Stack() = default;
};

#endif //INC_24_02_2022__STACK_H_
