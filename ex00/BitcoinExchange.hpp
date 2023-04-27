/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:56:30 by aparolar          #+#    #+#             */
/*   Updated: 2023/04/27 13:35:12 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <map>

class Date
{
	public:
		int	Day = 0;
		int	Month = 0;
		int	Year = 0;

		Date(){}
		~Date(){}
};

class BitcoinExchange
{
	private:
		typedef				std::map<std::string, float>	map_type;
		typedef				map_type::iterator				map_iter;
		
		map_type			_db;

		void				parseLine(std::string const &line);
		bool				isValidDate(std::string const &date);
		bool				isValidValue(std::string const &value);
		map_iter			findNear(std::string const &date);
		bool				isLeapYear(std::string const &date);
		bool				isLeapYear(int year) const;
		std::string			setDownDateDay(std::string const &date) const;
		Date const			getDateFromString(std::string const &date) const;
		Date const			getDateFromValue(std::string const &year, std::string const &month, std::string const &day) const;
		std::string 		getStringFromDate(Date const &date) const;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &cpy);
		~BitcoinExchange();

		BitcoinExchange const &operator=(BitcoinExchange const &cpy);

		void				readDB(std::string const &filename);
		void				check(std::string const &input_filename);
};

#endif