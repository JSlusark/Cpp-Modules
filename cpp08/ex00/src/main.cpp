#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <string>
#include <set>
#include "../headers/utils.hpp" // where your testTitle and logMessage are

int main()
{
  // ---------- VECTORS ----------
  std::vector<int> v_sample;
  for (int i = 1; i <= 5; i++)
    v_sample.push_back(i * 10); // 10, 20, 30, 40, 50
  std::vector<int> empty_vector;

  testTitle(1, "VECTOR - Finds existing value");
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

  testTitle(2, "VECTOR - fail with finding non-existing negative value");
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

  testTitle(3, "VECTOR - fail with finding in empty vector");
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
  testTitle(4, "LIST - Finds existing value");
  logMessage(LOG, "To_find: -200  list:[0, -100, -200, -300]");
  std::list<int> l_sample;
  for (size_t i = 0; i < 4; i++)
  {
    l_sample.push_back(i * -100);
  }

  try
  {
    std::list<int>::const_iterator it = easyFind(l_sample, -200);
    logMessage(SUCCESS, "Value found");
    std::cout << C_GREEN << "Value: " << C_RESET << *it << std::endl;
  }
  catch (std::exception &e)
  {
    logMessage(EXCEPTION, e.what());
  }

  testTitle(5, "LIST - fails with finding non-existing value");
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

  testTitle(6, "LIST - fails at finding in empty list");
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
  testTitle(7, "DEQUE - finds existing value");
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
  testTitle(8, "SET - finds existing value");
  logMessage(LOG, "To_find:20  deque:[10, 20, 30]");
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

  return 0;
}
