/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:52:55 by jslusark          #+#    #+#             */
/*   Updated: 2025/12/03 12:53:09 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "./utils.hpp"
#include <string.h>
#include <sstream> 
#include <stack>
#include <cstdlib> 

void printError(std::string err, const char &token);
void printStack(std::stack<int> &st);
int extractOperand(std::stack<int> &stack);
bool operate(const char &token, std::stack<int> &stack);
int getNumber(const std::string &s, size_t &i);
void printResult(int argc, char **argv);
