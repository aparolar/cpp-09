/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:25:59 by aparolar          #+#    #+#             */
/*   Updated: 2023/04/28 10:19:21 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

RPN::RPN() {};
RPN::RPN(std::string const &operations)
{
	loadOperations(operations);
}
RPN::RPN(RPN const &cpy)
	:	_stack(cpy._stack)
{
	*this = cpy;
}
RPN::~RPN() {};

RPN const	&RPN::operator=(RPN const &cpy) const
{
	(void)cpy;
	return *this;
}

void	RPN::loadOperations(std::string const &operations)
{
	std::stringstream	ss(operations);
	std::string			opr;
	int					a;
	int					b;
	
	while (std::getline(ss, opr, ' '))
	{
		if (isOperand(opr) && _stack.size() > 1)
		{
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			_stack.push(doOperation(a, b, opr));
		}
		else if ((isOperand(opr) && _stack.size() <= 1) || !isNumber(opr))
		{
			std::cout << "Error" << std::endl;
			return;
		}
		else
			_stack.push(std::stol(opr));
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
}

bool	RPN::isOperand(std::string const &opr)
{
	if (opr == "+" || opr == "-" || opr == "*" || opr == "/")
		return true;
	return false;	
}

bool	RPN::isNumber(std::string const &number)
{
	for (std::string::const_iterator it = number.begin(); it != number.end(); it++)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

int		RPN::doOperation(long a, long b, std::string const &operand) const
{
	if (operand == "+")
	{
		return a + b;
	}
	else if (operand == "-")
	{
		return a - b;
	}
	else if (operand == "*")
	{
		return a * b;
	}
	else
	{
		return a / b;
	}
}
