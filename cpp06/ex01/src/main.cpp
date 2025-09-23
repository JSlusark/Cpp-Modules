#include <iostream>
#include "../headers/Serializer.hpp"
#include "../headers/utils.hpp"

int main()
{

  Data data;
  data.id = 42;
  data.name = "Hello World";

  std::cout << "Original pointer: " << &data << std::endl;

  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "Serialized (to uintptr_t): \n" << raw << std::endl;

  Data *ptr = Serializer::deserialize(raw);
  std::cout << "Deserializing (back to pointer): \n" << ptr << std::endl;

  // Check equality
  if (ptr == &data)
    logMessage(SUCCESS, "pointers match");
  else
    logMessage(ERROR, "pointers do not match");

  // Verify data integrity
  std::cout << "Deserialized Data.id = " << ptr->id << std::endl;
  std::cout << "Deserialized Data.name = " << ptr->name << std::endl;

  return 0;
}
