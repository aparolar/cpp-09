/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:56:22 by aparolar          #+#    #+#             */
/*   Updated: 2023/04/27 16:02:00 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <exception>
#include <ctime>
#include <limits.h>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
	*this = cpy;
}
BitcoinExchange	const	&BitcoinExchange::operator=(BitcoinExchange const &cpy)
{
	this->_db = cpy._db;
	return *this;
}

void	BitcoinExchange::readDB(std::string const &filename)
{
	std::fstream	file(filename, std::ios::in);
	std::string		line;
	std::string		date;
	std::string		value;

	if (file.fail())
		throw std::runtime_error("Error: could not open file.");

	while (getline(file, line))
	{
		std::stringstream ss(line);
		std::getline(file, date, ',');
		getline(file, value, ',');
		_db[date] = std::stof(value);
	}
	
	file.close();
}

void	BitcoinExchange::check( std::string const &input_filename)
{
	std::fstream	file(input_filename, std::ios::in);
	std::string		line;

	if (file.is_open())
	{
		std::getline(file, line);

		while (std::getline(file, line))
			parseLine(line);

		file.close();
	}
	else
		throw std::runtime_error("Error: could not open file.");
}

void	BitcoinExchange::parseLine(std::string const &line)
{
	std::istringstream	iss(line);
	std::string			date;
	std::string			value;
	std::string			separator;

	iss >> date >> separator >> value;
	if (!date.empty() && !separator.compare("|") && !value.empty())
	{
		if (!isValidDate(date) || !isValidValue(value))
			std::cout << "Error: bad input => " << date << std::endl;
		else
		{
			// falta too large number > INT_MAX
			if (std::stol(value) > INT_MAX)
			{
				std::cout << "Error: too large a number." << std::endl;
			}
			// negative number
			else if (std::stol(value) < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
			}
			else
			{
				map_iter it = findNear(date);
				if (it != _db.end())
				{
					std::cout << date << " => " << std::setw(10) << std::fixed << std::setprecision(2) << static_cast<float>(std::stof(value)) << " = " << std::setw(14) << std::fixed << std::setprecision(2) << static_cast<double>(std::stod(value) * (*it).second) << std::endl;
				}
			}
		}
	}
	else
		std::cout << "Error: bad input => " << date << std::endl;
}

bool	BitcoinExchange::isValidDate(std::string const &date)
{
	Date	ddate;

	ddate = getDateFromString(date);

	if (ddate.Day < 1 || ddate.Month < 1 || ddate.Year < 1)
		return (false);
	
	if (ddate.Month == 2 && ((isLeapYear(ddate.Year) && ddate.Day <= 29) || (!isLeapYear(ddate.Year) && ddate.Day <= 28)))
		return (true);
	else if (ddate.Day <= 31 && (ddate.Month == 1 || ddate.Month == 3 || ddate.Month == 5 || ddate.Month == 7 || ddate.Month == 8 || ddate.Month == 10 || ddate.Month == 12))
		return (true);
	else if (ddate.Day <= 30 && (ddate.Month == 4 || ddate.Month == 6 || ddate.Month == 9 || ddate.Month == 11))
		return (true);
		
	return (false);
}

bool	BitcoinExchange::isValidValue(std::string const &value)
{
	try
	{
		std::stof(value);
		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

BitcoinExchange::map_iter 	BitcoinExchange::findNear(std::string const &date)
{
	std::string tmp;
	map_iter	it;
	
	it = _db.find(date);
	tmp = date;
	if (it == _db.end() && (*(++_db.begin())).first > date)
		it = ++_db.begin();
	while (it == _db.end())
	{
		tmp = setDownDateDay(tmp);
		it = _db.find(tmp);
	}
	
	return it;
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

bool	BitcoinExchange::isLeapYear(std::string const &date)
{
	Date Ddate;

	Ddate = getDateFromString(date);
	return isLeapYear(Ddate.Year);
}

std::string BitcoinExchange::setDownDateDay(std::string const &date) const
{
	Date	ret;

	ret = getDateFromString(date);

	ret.Day--;
	if (!ret.Day)
	{
		ret.Month--;
		if (!ret.Month)
		{
			ret.Year--;
			ret.Month = 12;
		}
		if (ret.Month == 2)
		{
			if (isLeapYear(ret.Year))
				ret.Day = 29;
			else
				ret.Day = 28;
		}
		else if (ret.Month == 4 || ret.Month == 6 || ret.Month == 9 || ret.Month == 11)
			ret.Day = 30;
		else
			ret.Day = 31;
	}

    return getStringFromDate(ret);
}

Date const	BitcoinExchange::getDateFromString(std::string const &date) const
{
	Date				ret;
	std::stringstream	ss(date);
	std::string			day;
	std::string			month;
	std::string			year;

	std::getline(ss, year, '-');
	std::getline(ss, month, '-');
	std::getline(ss, day, '-');
	try
	{
		ret.Day = std::stoi(day);
		ret.Month = std::stoi(month);
		ret.Year = std::stoi(year);
	}
	catch(const std::exception& e)
	{
		
	}
	return ret;
}

std::string BitcoinExchange::getStringFromDate(Date const &date) const
{
	std::string			ret;
	std::stringstream	ss;

	ss << date.Year << "-" << std::setfill('0') << std::setw(2) << date.Month << "-" << std::setfill('0') << std::setw(2) << date.Day;
	ss >> ret;
	return ret;
}

Date const	BitcoinExchange::getDateFromValue(std::string const &year, std::string const &month, std::string const &day) const
{
	Date	ret;

	ret.Year = std::stoi(year);
	ret.Month = std::stoi(month);
	ret.Day = std::stoi(day);

	return ret;
}