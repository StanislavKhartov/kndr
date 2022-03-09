#ifndef INC_24_02_2022__FORWARDLIST_H_
#define INC_24_02_2022__FORWARDLIST_H_

#include <iostream>
#include "Iterator.h"
#include "Node.h"

template<typename T>
class Forward_listOnNodes {
 protected:
  Node<T> *head_;
  int size_;
 public:
  Forward_listOnNodes() : size_(0) {
    head_ = nullptr;
  }
  ~Forward_listOnNodes() {
    while (size_ != 0) {
      removeFirst();
    }
  };

  virtual void push(T value) {
    Node<T> *a = new(Node<T>);
    a->next_ = nullptr;
    a->value_ = value;
    Node<T> *tmp = head_;
    if (head_ == nullptr) {
      head_ = a;
      size_++;
      return;
    }
    for (int i = 0; i < size_ - 1; i++) {
      tmp = tmp->next_;
    }
    tmp->next_ = a;
    size_++;
  }

  void pushBack(T value){
    Node<T> *a = new(Node<T>);
    a->next_ = head_;
    a->value_ = value;
    head_ = a;
    size_++;
  }

  int findIndex(T value) {
    Node<T> *tmp = head_;
    int index = 0;
    while (tmp && tmp->value_ != value) {
      tmp = tmp->next_;
      index++;
    }
    if (tmp == nullptr) {
      return -1;
    }
    return index;
  }

  void removeFirst() {
    if (head_ == nullptr) {
      return;
    }
    Node<T> *tmp = head_;
    head_ = head_->next_;
    delete tmp;
    size_--;
  }

  bool isEmpty() {
    return !bool(size_);
  }

  void deleteByIndex(int index) {
    Node<T> *tmp = head_;
    if (index < 0) {
      return;
    }
    if (index == 0) {
      removeFirst();
    } else if (index == size_ - 1) {
      for (int i = 0; i < index - 1; i++) {
        tmp = tmp->next_;
      }
      delete tmp->next_;
      size_--;
      tmp->next_ = nullptr;
    } else {
      for (int i = 0; i < index - 1; i++) {
        tmp = tmp->next_;
      }
      Node<T> *tmp2 = tmp->next_->next_;
      delete tmp->next_;
      size_--;
      tmp->next_ = tmp2;
    }
  }

  void insertByIndex(int index, T value) {
    Node<T> *a = new Node<T>;
    a->next_ = nullptr;
    a->value_ = value;
    if (index == 0) {
      a->next_ = head_;
      head_ = a;
      size_++;
    } else if (index == size_) {
      Node<T> *tmp = head_;
      for (int i = 0; i < size_ - 1; i++) {
        tmp = tmp->next_;
      }
      tmp->next_ = a;
      size_++;
    } else {
      Node<T> *tmp = head_;
      for (int i = 0; i < index - 1; i++) {
        tmp = tmp->next_;
      }
      Node<T> *tmp2 = tmp;
      tmp2 = tmp2->next_;
      tmp->next_ = a;
      a->next_ = tmp2;
      size_++;
    }
  }
  friend std::ostream &operator<<(std::ostream &out, const Forward_listOnNodes<T> &old) {
    Node<T> *tmp = old.head_;
    if (old.head_ == nullptr) {
      return out;
    }
    out << tmp->value_ << " ";
    while (tmp->next_ != nullptr) {
      tmp = tmp->next_;
      out << tmp->value_ << " ";
    }
    out << "\n";
    return out;
  }

  T top(){
    return head_->value_;
  }

  Iterator<T>* begin(){
    return new Iterator<T>(this->head_);
  }
  Iterator<T>* end() {
    Node<T> *tmp = head_;
    for (int i = 0; i < size_ - 1; i++) {
      tmp = tmp->next_;
    }
    return new Iterator<T>(tmp);
  }
};

#endif //INC_24_02_2022__FORWARDLIST_H_
