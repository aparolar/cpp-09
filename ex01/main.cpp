/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:25:21 by aparolar          #+#    #+#             */
/*   Updated: 2023/04/27 23:59:22 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	//std::cout << "building" << std::endl;
	RPN	rpn = RPN(std::string(argv[1]));
	//std::cout << "checking" << std::endl;
	rpn.calculate();
}
