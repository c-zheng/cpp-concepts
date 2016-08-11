#include <iostream>

using namespace std;

class Base{
  public:
    Base(){ cout << "Ctor!" << endl; }
    ~Base(){ cout << "Dtor!" << endl; }
    Base(const Base&){ cout << "Copy!" << endl; }
};

Base foo()
{
  return Base();
}

int main(int argc, char ** argv)
{
  Base b = foo();
}

