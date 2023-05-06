/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:25:21 by aparolar          #+#    #+#             */
/*   Updated: 2023/04/28 10:17:31 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	RPN	rpn = RPN(std::string(argv[1]));
	return 0;
}
