/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:53:42 by jslusark          #+#    #+#             */
/*   Updated: 2025/12/03 13:01:33 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stack>
#include <sstream>

#include "../headers/rpn.hpp"
/*
- shows error when is not number or operator
- handles any number besides decimals -> so only int is fine
- sends error when n / 0 at any moment not just end
- handles when writing more args (with or without different "", * without quotes is wildcard )
- avoids starting with an operator and preserves the proper format of rpn
- works only with n < 9
- i decided not to handle negative nums and handle when chars are close to eachother

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
./RPN "7 7 * 7 -"
./RPN "1 2 * 2 / 2 * 2 4 - +"
./RPN "(1 + 1)"


Edgecases:

./RPN 1 #one arg
result = 1

./RPN "    1    " ##one arg with len > 0
result = 1

./RPN "123455"
result = error


./RPN " 1 "  " 2 3+-" 5 8 ++
result =9

./RPN " 1 +-"  " 2 3" 5 8 ++
result = error

./RPN
result = error
*/

int main(int argc, char **argv)
{
    if (argc < 2) // idk
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    else
    {
        printResult(argc, argv);
    }
}