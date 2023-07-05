#include <iostream>
#include <sstream>
using std::ostream;
#include <stdexcept>
using std::out_of_range;
#include <string>
using std::to_string;
using std::string;
#include <algorithm>

#include "singlelink.hpp"

SingleLink::SingleLink() {
  head_ = nullptr;
  tail_ = nullptr;
}

SingleLink::SingleLink(int dat) {
  head_ = new Node(dat);
  tail_ = head_;
}

// copy constructor   
SingleLink::SingleLink(const SingleLink &s) {
  head_ = s.head_;
  tail_ = s.tail_;
}

SingleLink::~SingleLink() {
  // auto current =  head_;
  // while (current != nullptr) {
  //   auto next = current -> next_;
  //   delete current;
  //   current = next;
  // }
}


// assignment 
SingleLink& SingleLink::operator=(SingleLink s) {
  head_ = s.head_;
  tail_ = s.tail_;
  return *this;
}

void SingleLink::append_back(int dat) {
  if (head_ == nullptr) {
    head_ = new Node(dat);
    tail_ = head_;
  } else {
    tail_ -> next_ = new Node(dat);
    tail_ = tail_ -> next_;
  }
}

std::ostream& operator<<(std::ostream& out, const SingleLink& s) {
  auto i = s.head_;

  while (i != nullptr) {
    out << i -> data_;
    i = i -> next_;
    if (i != nullptr) {
      out << ", ";
    }
  }
  
  return out;
}

Node& SingleLink::operator[](size_t index) {
  if (index == 0) {
    return *head_;
  }

  auto temp = head_;

  for (int i = 0; i != static_cast<int>(index); ++i) {
    if (temp == nullptr) {
      throw out_of_range("no more nodes");
    }
    temp = temp -> next_;
  }

  if (temp == nullptr) {
    throw out_of_range("no more nodes");
  }
  return *temp;
}

bool SingleLink::del(int val) {
  if (head_ -> data_ == val) {
    head_ = head_ -> next_;
    return true;
  }

  auto i = head_;
  auto prev = i;

  while (i != nullptr) {
    if (i -> data_ == val) {
      prev -> next_ = i -> next_;
      return true;
    } else {
      prev = i;
      i = i -> next_;
    }
  }

  return false;
}