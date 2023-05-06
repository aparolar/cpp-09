/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:06:40 by aparolar          #+#    #+#             */
/*   Updated: 2023/05/06 16:00:34 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &cpy)
	:	_vector(cpy._vector),
		_deque(cpy._deque)
{
}

PmergeMe::PmergeMe(int count, char **values)
{
	(void)count;
	(void)values;
	for (int i = 0; i < count; i++)
	{
		std::string value = std::string(values[i]);
		if (isValidInteger(value))
		{
			_vector.push_back(std::stoi(value));
			_deque.push_back(std::stoi(value));
		}
		else
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe const &PmergeMe::operator=(PmergeMe const &cpy)
{
	this->_vector = cpy._vector;
	this->_deque = cpy._deque;
	return *this;
}

void	PmergeMe::runVectorSort()
{
	clock_t start = clock();
	_vector_sort(_vector);
	clock_t end = clock();

	std::cout << "Time to process a range of " << this->_vector.size();
    std::cout << " elements with std::vector<unsigend int> : ";
    std::cout << std::fixed << std::setprecision(5) << (static_cast<double>(end - start) / CLOCKS_PER_SEC);
    std::cout << " us" << std::endl;

	if (_debug_mode)
	{
		std::cout << std::endl;
		std::cout << "Resultado vector:" << std::endl;
		std::cout << std::endl;
		std::cout << "Total returned = " << _vector_result.size() << std::endl;
		for (vector_iter it = _vector_result.begin(); it != _vector_result.end(); it++)
			std::cout << *it << " ";
	}
}

void	PmergeMe::runDequeSort()
{
	clock_t start = clock();
	_deque_sort(_deque);
	clock_t end = clock();

	std::cout << "Time to process a range of " << this->_deque.size();
    std::cout << " elements with std::deque<unsigend int> : ";
    std::cout << std::fixed << std::setprecision(5) << (static_cast<double>(end - start) / CLOCKS_PER_SEC);
    std::cout << " us" << std::endl;

	if (_debug_mode)
	{
		std::cout << std::endl;
		std::cout << "Resultado deque:" << std::endl;
		std::cout << std::endl;
		std::cout << "Total returned = " << _deque_result.size() << std::endl;
		for (deque_iter it = _deque_result.begin(); it != _deque_result.end(); it++)
			std::cout << *it << " ";
	}
}

bool	PmergeMe::isValidInteger(std::string const &value)
{
	for (std::string::const_iterator it = value.begin(); it != value.end(); it++)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

void	PmergeMe::_vector_sort(vector_type &toSplit)
{
	vector_iter	middle;
	vector_type left;
	vector_type rigth;

	if (toSplit.size() > 1)
	{
		middle = toSplit.begin() + toSplit.size() / 2;
		left.assign(toSplit.begin(), middle);
		rigth.assign(middle, toSplit.end());
		_vector_sort(left);
		_vector_sort(rigth);
	}
	else if (_vector_result.size() > 0)
	{
		for (vector_iter sit = toSplit.begin(); sit != toSplit.end(); sit++)
		{
			for (vector_iter rit = _vector_result.begin(); rit != _vector_result.end(); rit++)
			{
				if (*rit > *sit)
				{
					_vector_result.insert(rit, *sit);
					break;
				}
				else
				{
					for (vector_iter rrit = _vector_result.end() - 1; rrit >= _vector_result.begin(); rrit--)
					{
						if (*rrit < *sit)
						{
							_vector_result.insert(rrit + 1, *sit);
							break;
						}
					}
					break;
				}
			}
		}
	}
	else if (_vector_result.size() == 0 && toSplit.size() == 1)
	{
		_vector_result.push_back(*toSplit.begin());
	}
}

void	PmergeMe::_deque_sort(deque_type &toSplit)
{
	deque_iter	middle;
	deque_type left;
	deque_type rigth;

	if (toSplit.size() > 1)
	{
		middle = toSplit.begin() + toSplit.size() / 2;
		left.assign(toSplit.begin(), middle);
		rigth.assign(middle, toSplit.end());
		_deque_sort(left);
		_deque_sort(rigth);
	}
	else if (_deque_result.size() > 0)
	{
		for (deque_iter sit = toSplit.begin(); sit != toSplit.end(); sit++)
		{
			for (deque_iter rit = _deque_result.begin(); rit != _deque_result.end(); rit++)
			{
				if (*rit > *sit)
				{
					_deque_result.insert(rit, *sit);
					break;
				}
				else
				{
					for (deque_iter rrit = _deque_result.end() - 1; rrit >= _deque_result.begin(); rrit--)
					{
						if (*rrit < *sit)
						{
							_deque_result.insert(rrit + 1, *sit);
							break;
						}
					}
					break;
				}
			}
		}
	}
	else if (_deque_result.size() == 0 && toSplit.size() == 1)
	{
		_deque_result.push_back(*toSplit.begin());
	}
}
