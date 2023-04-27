/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:25:21 by aparolar          #+#    #+#             */
/*   Updated: 2023/04/27 15:47:56 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main(int argc, char	**argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange btc;
	try
	{
		btc.readDB("data.csv");	
		btc.check(std::string(argv[1]));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}

/*
	std::string fname = std::string(argv[1]);
	//std::cout << "Enter the file name: ";
	//std::cin >> fname;
 
	typedef std::vector< std::vector<std::string> >::iterator viter;
	//typedef std::vector<std::string>::iterator siter;
	std::vector< std::vector<std::string> > content;
	std::vector<std::string> row;
	std::string line, word;
 
	std::fstream file (fname, std::ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			row.clear();
 
			std::stringstream str(line);
 
			while(getline(str, word, ','))
				row.push_back(word);
			content.push_back(row);
		}
	}
	else
		std::cout<<"Could not open the file\n";	
	
	for (viter vit = content.begin(); vit != content.end(); vit++)
		std::cout << " -> " << vit.base()->begin().base()->begin().base() << " <> " << std::endl;
}
*/
