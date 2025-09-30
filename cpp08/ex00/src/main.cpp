#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <set>
#include "../headers/utils.hpp" // where your testTitle and logMessage are

int main()
{
  // ---------- VECTORS ----------
  logMessage(LOG, "Testing Vectors");
  std::vector<int> v_sample;
  for (int i = 1; i <= 5; i++)
    v_sample.push_back(i * 10); // 10, 20, 30, 40, 50
  std::vector<int> empty_vector;

  testTitle(1, "Find existing value in vector");
  logMessage(LOG, "To_find:30  vector:[10, 20, 30, 40, 50]");
  try
  {
    std::vector<int>::const_iterator it = easyFind(v_sample, 30);
    logMessage(SUCCESS, "Value found");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  testTitle(2, "Try finding non-existing value in vector");
  logMessage(LOG, "To_find:-10  vector:[10, 20, 30, 40, 50]");
  try
  {
    std::vector<int>::const_iterator it = easyFind(v_sample, -10);
    logMessage(SUCCESS, "Value found");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  testTitle(3, "Try finding in empty vector");
  logMessage(LOG, "To_find:1  vector:[]");
  try
  {
    std::vector<int>::const_iterator it = easyFind(empty_vector, 1);
    logMessage(SUCCESS, "Value found");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  // ---------- LISTS ----------
  testTitle(4, "Find existing value in list");
  logMessage(LOG, "To_find:200  list:[0, 100, 200, 300]");
  std::list<int> l_sample;
  for (size_t i = 0; i < 4; i++)
  {
    l_sample.push_back(i * 100);
  }

  try
  {
    std::list<int>::const_iterator it = easyFind(l_sample, 200);
    logMessage(SUCCESS, "Value found");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  testTitle(5, "Try finding non-existing value in list");
  logMessage(LOG, "To_find:-1  list:[0, 100, 200, 300]");
  try
  {
    std::list<int>::const_iterator it = easyFind(l_sample, -1);
    logMessage(SUCCESS, "Value found");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  testTitle(6, "Try finding in empty list");
  logMessage(LOG, "To_find:1  list:[]");
  std::list<int> empty_list;
  try
  {
    std::list<int>::const_iterator it = easyFind(empty_list, 0);
    logMessage(SUCCESS, "Value found");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  // ---------- DEQUE ----------
  testTitle(7, "Test with std::deque");
  std::deque<int> deque_sample;
  logMessage(LOG, "To_find:200  deque:[100, 200]");
  deque_sample.push_back(100);
  deque_sample.push_back(200);
  try
  {
    std::deque<int>::const_iterator it = easyFind(deque_sample, 200);
    logMessage(SUCCESS, "Value found in deque");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  // ---------- SET ----------
  testTitle(8, "Test with std::set");
  logMessage(LOG, "To_find:20  set:[10, 20, 30] (sorted)");
  std::set<int> set_sample;
  set_sample.insert(10);
  set_sample.insert(30);
  set_sample.insert(20); // Note: set automatically sorts
  try
  {
    std::set<int>::const_iterator it = easyFind(set_sample, 20);
    logMessage(SUCCESS, "Value found in set");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  // ---------- ARRAY SAMPLE: returns an int *iterator ----------

  testTitle(10, "Test with C-style array using pointers");
  logMessage(LOG, "To_find:30  array:[10, 20, 30, 40, 50]");
  int arr[] = {10, 20, 30, 40, 50};
  int *arr_begin = arr;
  int *arr_end = arr + 5;

  // You'd need a different approach for arrays since they don't have .begin()/.end()
  // But you can use std::find directly:
  int *result = std::find(arr_begin, arr_end, 30);
  if (result != arr_end)
  {
    logMessage(SUCCESS, "Value found in array");
    std::cout << C_GREEN << "Value: " << C_RESET << *result << std::endl;
  }
  else
  {
    logMessage(EXCEPTION, "Value not found in array");
  }

  /*
    Will not work with map or unordered_map because they store key-value pairs (std::pair<Key, Value>),
    and easyFind function is designed to search for ONE single int value.
  */

  return 0;
}
