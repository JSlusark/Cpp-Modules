/*
PhoneBook
◦ It has an array of contacts.
◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.
◦ Please note that dynamic allocation is forbidden.

Program waits for the following commands:
1. add: saves a new contact once all information is prompted to the user one by one
- question
- answer

2. search: displays a specific contact (by index) and all its information.
- 9x4 grid
- each grid is truncated to 10 characters(c index 10 becomes .) and separated by |
- if index is out of range, define a relevant behavior (i think i will reprompt the user)

3. exit: exits the program and frees all allocated memory

4. Any other input is ignored.
exit:
*/

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class phonebook
{
private:
	/* data */
public:
    void add();
	void search();
	void exit();

}


#endif