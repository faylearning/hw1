/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
using namespace std;


void split(Node*& in, Node*& odds, Node*& evens){
  if (in == nullptr){
    return; 
  }

  Node* temp = in->next;
  in->next = nullptr;

  if (in->value % 2 == 1){
    if (odds == nullptr){
      odds = in;
      split(temp, odds, evens);
    }else{
      odds->next = in; 
      split(temp, odds->next, evens);
    }
  }else{

    if (evens == nullptr){
      evens = in;
      split(temp, odds, evens);
    }else{
      evens->next = in; 
      split(temp, odds, evens->next);
    }
  }
  in = nullptr;
}

