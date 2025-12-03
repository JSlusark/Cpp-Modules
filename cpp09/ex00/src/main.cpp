/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:52:28 by jslusark          #+#    #+#             */
/*   Updated: 2025/12/03 12:52:29 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../headers/BitcoinExchange.hpp"

int main(int argc, char const **argv)
{
    if(argc == 2)
    {
        BitcoinExchange conversion(argv[1]);
    }
    else
    {
        logMessage(WARNING, "Program needs a .csv file to convert");
        return 1;
    }
    return 0;
}
