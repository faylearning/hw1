#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  for (int i = 0; i < 100; i++) {
    stringstream ss;
    ss << i;
    cout << "adding " << ss.str() << " to list" << endl;
    list.push_back(ss.str());
  }

  cout << "val at index 47: " << list.get(47) << endl;
  cout << "val at index 23: " << list.get(23) << endl;

}
