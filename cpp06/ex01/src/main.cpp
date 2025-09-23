#include <iostream>
#include "../headers/Serializer.hpp"
#include "../headers/utils.hpp"
#include <iostream>
#include "../headers/Serializer.hpp"
#include "../headers/utils.hpp"

int main()
{
  Data data;
  data.id = 1;
  data.name = "Simple test";

  std::cout << "\n===== TEST 1: Basic round-trip =====\n";
  std::cout << "Original pointer: " << C_CYAN << &data << C_RESET << std::endl;
  std::cout << "Original Data.id = " << data.id << std::endl;
  std::cout << "Original Data.name = " << data.name << std::endl;

  uintptr_t serialized = Serializer::serialize(&data);
  std::cout << "Serialized(from Data to uintptr_t): " << C_YELLOW << serialized << C_RESET << std::endl;

  Data *deserialized = Serializer::deserialize(serialized);
  std::cout << "Deserialized(from uintptr to pointer): " << C_CYAN << deserialized << C_RESET << std::endl;
  std::cout << "Deserialized Data.id = " << deserialized->id << std::endl;
  std::cout << "Deserialized Data.name = " << deserialized->name << std::endl;

  if (deserialized == &data)
    logMessage(SUCCESS, "pointers match");
  else
    logMessage(ERROR, "pointers do not match");

  return 0;
}
