#include <iostream>
#include "../headers/Base.hpp"
#include "../headers/utils.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main()
{
  srand(time(0));

  testHeader(1, "Basic tests with A B C");
  for (int i = 0; i < 5; ++i)
  {
    logMessage(LOG, "Generating new base instance:");
    Base *ptr = generate();
    identify(ptr);
    identify(*ptr);
    std::cout << std::endl;
    delete ptr;
  }

  testHeader(1, "Basic test with unrecognised Base");
  class D : public Base
  {
  };
  Base *obj = new D();
  identify(obj);  // should not match A, B, or C
  identify(*obj); // should reach the "Unknown type" catch block
  std::cout << std::endl;
  delete obj;

  testHeader(1, "Basic test with null ptr");
  logMessage(LOG, "Testing with a null pointer:");
  Base p;
  identify(p); // should handle null pointer gracefully
  // identify(nullptr); // ucommenting as cpp98 does not support nullptr but my code handles it anyway
  std::cout << std::endl;

  return 0;
}
