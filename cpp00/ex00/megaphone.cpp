/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:45:12 by jslusark          #+#    #+#             */
/*   Updated: 2025/06/20 11:18:18 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // preprocess statement for input/output stream library
#include <cctype>  // instead of (char)toupper which is c style cast

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			char *s = argv[i];
			if (s)
			{
				for (int j = 0; s[j] != '\0'; j++)
					std::cout << static_cast<char>(std::toupper(s[j]));
				if (i < argc - 1 && argv[i][0] != '\0')
					std::cout << " "; /* decided to add  a space if we get more than 1 arg (if not empty) even if not explicitly asked in exercise*/
			}
		}
		std::cout << std::endl;
	}
	return 0;
}


/* 
	Notes:
	std::endl instead of \n - not occupies memory( n is 1 byte) and flushes
	buffer immediately in each process (n only end of program)
	
	namespace - identifier used to avoid ambiguity,
	defines scope(are in which is used),unique, avoids conflicts
*/

/*
Test Commands for ./megaphone
-----------------------------
./megaphone
./megaphone hello
./megaphone hello world
./megaphone "hello world"
./megaphone "" ""
./megaphone 123 abc
./megaphone "Shh..." "it's a secret"
./megaphone A B C
./megaphone a
./megaphone a "" b
./megaphone "one two"
./megaphone ""
./megaphone "" a	
./megaphone a ""	
./megaphone "" ""	
./megaphone a "" b	
*/
