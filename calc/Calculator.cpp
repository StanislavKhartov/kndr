#include "Calculator.h"
#include <fstream>
#include <stack>
#include <sstream>

std::string sorting_station(std::string file_path) {
  std::ifstream file("input.txt");
  if (!file.is_open()) {
    throw std::runtime_error("File not open!");
  }
  std::string word;
  std::stack<std::string> operations;
  std::string answer;
  while (file >> word) {
    if (word == "(") {
      operations.push(word);
    } else if (word == "max") {
      operations.push("x");
    } else if (word == "min") {
      operations.push("n");
    } else if (word == ")") {
      while (operations.top() != "(") {
        answer = answer + " " + operations.top();
        operations.pop();
      }
      operations.pop();
      answer = answer + " " + operations.top();
      operations.pop();
    } else if (word == ",") {
      continue;
    } else {
      answer = answer + " " + word;
    }
  }
  while (!operations.empty()) {
    answer = answer + " " + operations.top();
    operations.pop();
  }
  return answer;
}

bool isDigit(const std::string str) {
  return str == "0" || str == "1" || str == "2" || str == "3" || str == "4" || str == "5" || str == "6" || str == "7"
      || str == "8" || str == "9";
}

int calculating(const std::string str) {
  std::stringstream ss(str);
  std::stack<std::string> store;
  std::string buffer;
  while (ss >> buffer) {
    if (isDigit(buffer)) {
      store.push(buffer);
    } else {
      std::string a = store.top();
      store.pop();
      std::string b = store.top();
      store.pop();
      if (buffer == "n") {
        store.push(std::min(a, b));
      } else {
        store.push(std::max(a, b));
      }
    }
  }
  return stoi(store.top());
}

