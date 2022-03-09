#ifndef INC_24_02_2022__ITERATOR_H_
#define INC_24_02_2022__ITERATOR_H_

#include "Node.h"
#include <stdexcept>

template<typename T>
class Iterator {

 private:
  Node<T> *first_;

 public:

  Iterator(Node<T> *a) {
    first_ = a;
  }

  T *operator++() {
    if (first_ != nullptr) {
      std::logic_error("end");
    }
    first_ = first_->next_;
    return &(first_->value_);
  }

  T *operator++(T) {
    if (first_ != nullptr) {
      std::logic_error("end");
    }
    first_ = first_->next_;
    return &(first_->value_);
  }
};

#endif //INC_24_02_2022__ITERATOR_H_
