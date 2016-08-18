#include <memory>
#include <iostream>

class Base{
  public:
    Base(){
      std::cout << "Construct Base" << std::endl;
    }
    ~Base(){
      std::cout << "Destroy Base" << std::endl;
    }
};

int main(int argc, char ** argv)
{
  // Create with new
  std::shared_ptr<Base> b0(new Base);
  std::cout << "b0 use count " << b0.use_count() << std::endl;
  // Create with copy ctor
  std::shared_ptr<Base> b1(b0);
  std::cout << "b0 use count " << b0.use_count() << std::endl;
  // Create with assignment 
  std::shared_ptr<Base> b2 = b1;
  std::cout << "b0 use count " << b0.use_count() << std::endl;
  // Create with std::make_shared
  std::shared_ptr<Base> b3(std::make_shared<Base>());
  std::cout << "b3 use count " << b3.use_count() << std::endl;
  {
    // Create with primitive types
    // Same as this one
    //std::shared_ptr<int> c(std::make_shared<int>(12));
    auto c = std::make_shared<int>(12);
    // Use like a normal pointer
    std::cout << *c << std::endl;
    *c = 100;
    std::cout << *c << std::endl;
  }
  // Destroy with re-assignment, b3 goes out of scope
  b3 = b2;
  std::cout << "b0 use count " << b3.use_count() << std::endl;
  // Destory with out of scope
  {
    // Create with std::make_shared
    std::shared_ptr<Base> b4(std::make_shared<Base>());
  }
  // Destroy with assign to nullptr
  b2 = nullptr;
  std::cout << "b0 use count " << b3.use_count() << std::endl;
  // Destroy with reset 
  b1.reset();
  std::cout << "b0 use count " << b3.use_count() << std::endl;
}
