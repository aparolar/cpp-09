/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:25:21 by aparolar          #+#    #+#             */
/*   Updated: 2023/05/06 15:35:33 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc == 1)
	{
		std::cout << "Error: wrong parameters." << std::endl;
	}
	PmergeMe	pm(argc - 1, argv + 1);
	pm.runVectorSort();
	pm.runDequeSort();
}