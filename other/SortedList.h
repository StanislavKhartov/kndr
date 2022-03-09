#ifndef INC_24_02_2022__SORTEDLIST_H_
#define INC_24_02_2022__SORTEDLIST_H_

#include "ForwardList.h"

template<typename T>
class SortedList : public Forward_listOnNodes<T> {

 public:
  void push(T value) override {
    if (this->head_ == nullptr) {
      Node<T> *a = new(Node<T> );
      a->next_ = this->head_;
      a->value_ = value;
      this->head_ = a;
      this->size_++;
      return;
    }
    Node<T> *tmp = this->head_;
    for (int i = 0; i < this->size_; i++) {
      if (tmp->value_ <= value) {
        this->insertByIndex(i, value);
        return;
      }
      tmp = tmp->next_;
    }
    this->insertByIndex(this->size_, value);
  }
 public:
  SortedList() = default;
  SortedList(const Forward_listOnNodes<T> &a) {
    Node<T>* tmp = a.head_;
    for(int i = 1; i< a.size_; i++){
      push(tmp->value_);
      tmp = tmp->next_;
    }
  }
};

#endif //INC_24_02_2022__SORTEDLIST_H_
