/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:16:04 by aparolar          #+#    #+#             */
/*   Updated: 2023/04/27 23:44:03 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <deque>

class RPN
{
	private:
		std::stack<int>		_stack;

		void	loadOperations(std::string const &operations);	
		bool	isOperand(std::string const &opr);
		int		doOperation(long a, long b, std::string const &operand) const;
		
	public:
		RPN();
		RPN(std::string const &operations);
		~RPN();
		RPN(RPN const &cpy);

		RPN const &operator=(RPN const &cpy) const;

		void	calculate();
};

#endif

