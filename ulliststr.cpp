#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val){

  //empty list 
  //add element to front of the list item
  if (empty()) {
    Item* node = new Item();
    node->val[0] = val;
    node->last = 1;

    head_ = node;
    tail_ = node;
  }

  //not full list
  else if (tail_->last != ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last += 1;
  }

  //full list
  else if (tail_->last == ARRSIZE){
    Item* newTail = new Item();

    newTail->val[0] = val;
    newTail->last = 1;

    newTail->prev = tail_;
    tail_->next = newTail;
    tail_= newTail;
  }

  size_++;
}

void ULListStr::pop_back(){
  if (empty()){
    return;
  }

  if (tail_->size() > 1) {
    (tail_->last)--;
  }
  else if (tail_->size() == 1){
    if (size_ == 1) {
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
    } 
    else {
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next = nullptr;
      delete temp;
    }
  }
  size_--;
}

void ULListStr::push_front(const std::string& val){
  if (empty()){
    //add new element to the back of the list item
    Item* newHead = new Item();
    newHead->val[ARRSIZE-1] = val;
    head_ = newHead;
    tail_ = newHead;

    newHead->first = ARRSIZE-1;
    newHead->last= ARRSIZE;
  } 
  //not full
  else if (head_->first != 0) {
    head_->val[head_->first - 1] = val;
    (head_->first)--;
  }

  else {
    //full
    //allocate a new item and add the element to the last of that new item
    Item* newHead = new Item();

    newHead->val[ARRSIZE - 1] = val;
    head_->prev = newHead;
    newHead->next = head_;
    head_ = newHead;

    newHead->first = ARRSIZE-1;
    newHead->last = ARRSIZE;
  }
  size_++;

  // if (head_ == NULL || head_->first == 0){
  //       Item* newHead = new Item();
  //       newHead->next = head_;
  //       tail_ = newHead;
  //       head_ = newHead;
  //       newHead->last = ARRSIZE;
  //       head_->first = ARRSIZE-1;
  //   }else{
  //       --head_->first;
  //   }
    
  //   if (head_->first < ARRSIZE){
  //       // Item* newHead = new Item();
  //       // head_->prev = newHead;
  //       // (head_--)->first;
  //       head_->val[head_->first] = val; 
  //   }else{
  //       return;
  //   }

  //   size_++;

}


void ULListStr::pop_front() {
  if (empty()){
    return;
  }

  // more than 1 in first element
  if (head_->size() > 1){
    (head_->first)++;
  } 
  // only one in first node's array
  else if (head_->size() == 1){
    // entire list size == 1
    if (size_ == 1) {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    }
    else {
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = nullptr;
      delete temp;
    }
  }
  size_--;
}

std::string const& ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  // if(empty() || loc >= size_){
  //   return nullptr;
  // } 
  
  // Item* temp = head_;
  // size_t counter = 0;
  // size_t arr_loc = temp->first;
  // while (counter <= loc) {
  //   while (arr_loc != ARRSIZE) {
  //     if (counter == loc) {
  //       return temp->val[temp->first + arr_loc];
  //     }
  //     arr_loc++;
  //     counter++;
  //   }
  //   temp = temp->next;
  //   arr_loc = 0;
  // }

  // return nullptr;


 // version 
  if (empty() || loc >= size_){
    return nullptr;
  }

  Item* curr = head_;
  int arr_loc = head_->first;
  for (size_t i = 0; i < loc; i++) {
    arr_loc++;
    if (arr_loc == ARRSIZE) {
      curr = curr->next;
      arr_loc = 0;
    }
  }
  return &(curr->val[arr_loc]);
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::print() const
{
  Item* curr = head_;
  int arr_loc = head_->first;
  for (size_t i = 0; i < size_; i++) {
    std::cout << curr->val[arr_loc] << ' ';
    arr_loc++;
    if (arr_loc == ARRSIZE) {
      curr = curr->next;
      arr_loc = 0;
    }
  }
  std::cout << std::endl;
}