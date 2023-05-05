/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:06:40 by aparolar          #+#    #+#             */
/*   Updated: 2023/05/05 15:45:50 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <type_traits>
#include <iostream>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &cpy)
	:	_vector(cpy._vector),
		_list(cpy._list)
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
			_list.push_back(std::stoi(value));
			_vector.push_back(std::stoi(value));
		}
		else
		{
			std::cout << "Error" << std::endl;
			throw std::runtime_error("number error");
		}
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe const &PmergeMe::operator=(PmergeMe const &cpy)
{
	this->_vector = cpy._vector;
	this->_list = cpy._list;
	return *this;
}

void	PmergeMe::runVectorSort()
{
	vector_type	ret;
	//vector_size	n = _vector.size();
	//int			k = n / 2;

	ret = _vector_sort(_vector);
	

	std::cout << std::endl;
	std::cout << "Resultado:" << std::endl;
	std::cout << std::endl;
	for (vector_iter it = ret.begin(); it != ret.end(); it++)
		std::cout << *it << " ";
}

void	PmergeMe::runListSort()
{
	
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

PmergeMe::vector_type	PmergeMe::_vector_sort(vector_type &toSplit)
{
	vector_type	ret;
	vector_type left;
	vector_type rigth;
	vector_iter	middle;

	//std::cout << "n = " << n << " k = " << k << " k / 2 = " << k / 2 << " i = " << i << std::endl;
	std::cout << "toSplit: " << toSplit.size() << std::endl;
	middle = toSplit.begin() + toSplit.size() / 2;
	if (toSplit.size() > 2)
	{
		for (vector_iter it = toSplit.begin(); it != middle; it++)
			left.push_back(*it);
		for (vector_iter it = middle; it != toSplit.end(); it++)
			rigth.push_back(*it);
		left = _vector_sort(left);
		rigth = _vector_sort(rigth);
	}
	else if (toSplit.size() <= 2)
	{
		for (vector_iter it = toSplit.begin(); it != middle; it++)
			left.push_back(*it);
		for (vector_iter it = middle; it != toSplit.end(); it++)
			rigth.push_back(*it);
	}
	ret = _vector_merge(left, rigth);
	std::cout << "retourning ret size: " << ret.size() << std::endl;
	for (vector_iter it = ret.begin(); it != ret.end(); it++)
		std::cout << *it << " - ";
	std::cout << std::endl << std::endl;
	return ret;

		
	// idea, el subject te dice que solo puedes usar dos contenedores, "pero no te dice cuantas veces cada uno"
	// despues de dividir merge lo que hace es reordenar en un solo vector los cumulados de los dos vectores resultantes
}

PmergeMe::vector_type PmergeMe::_vector_merge(vector_type &left, vector_type &rigth)
{
	vector_type	ret;

	_vector_insert(left, ret);
	_vector_insert(rigth, ret);

	std::cout << "post merge size: " << ret.size() << std::endl;
	return ret;
}

void	PmergeMe::_vector_insert(vector_type &src, vector_type &dst)
{
		if  (!dst.size() && src.size())
		{
			dst.insert(dst.begin(), *src.begin());
			src.erase(src.begin());
			if (src.size() == 1)
			{
				if (*dst.begin() < *src.begin())
					dst.push_back(*src.begin());
				else
					dst.insert(dst.begin(), *src.begin());
				src.clear();
			}
		}

		vector_iter it = src.begin();

		while (src.size() > 0)
		{
			std::cout << "it = " << *it << std::endl;
			std::cout << "src.size = " << src.size() << std::endl;
			std::cout << "ret.size = " << dst.size() << std::endl;
			//vector_iter rit = dst.begin();

			if ((dst.size() > 0 || dst.size() == 0) && src.size() == 1)
			{
				if (src.begin() != src.end())
					dst.push_back(*src.begin());
				break;
			}
			else
			{
				for (vector_iter dit = dst.begin(); it != dst.end(); it++)
				{
					if (*it > *dit)
					{
						dst.insert(dit, *it);
						src.erase(it);
						break;
					}
				}
			}
			//vector_iter lrit = dst.begin();
			/*
			if (src.size() < 2)
			{
				std::cout << "stage 2" << std::endl;
				dst.push_back(*it);
				src.erase(it);
				break;
			}
			if (dst.size() == 0)
			{
				dst.push_back(*it);
				src.erase(it);
				std::cout << "dst.begin() = " << *dst.begin() << std::endl;
			}
			for (rit = dst.begin(); rit != dst.end(); rit++)
			{
				std::cout << *rit << " - " << *it << std::endl;
				int	value = *it;
				if (*rit > value)
				{
					std::cout << "stage 1" << std::endl;
					dst.insert(rit, value);
					if (*it)
						src.erase(it);
					break;
				}
				else
				{
					dst.push_back(value);
					src.erase(it);
					break;
				}

			}*/
			/*else
			{
				dst.push_back(*it);
				break;
			}*/

			++it;
			if (src.size() == 0)
				break;
/*
			while (rit != dst.end())
			{
				if (*it > *rit)
				{
					lrit = rit;
				}
				else
					break;
				++rit;
			}
			if (lrit != dst.end())
			{
				std::cout << "lrit = " << *lrit <<" it = " << *it << std::endl;
				if (*lrit > *it)
				{
					std::cout << "insert" << std::endl;
					dst.insert(lrit, *it);
					src.erase(it);
				}
				else
				{
					std::cout << "push_back" << std::endl;
					dst.push_back(*it);
					src.erase(it);
				}
			}*/
			/*else
			{
				dst.insert(dst.end(), *it);
				src.erase(it);
			}*/
			/*
			for (vector_iter rit = dst.begin(); rit != dst.end(); rit++)
			{
				std::cout << "it = " << *it << " rit = " << *rit << std::endl;
				if (*it < *rit)
				{
					std::cout << "stage 1" << std::endl;
					dst.insert(rit, *it);
					src.erase(it);
					break;
				}
				else if (*it > *rit)
				{
					std::cout << "stage 3" << std::endl;
					dst.insert(rit + 1, *it);
					src.erase(it);
					break;
				}
			}
			*/
		}
		//std::cout << "vector_inset result : "
}

void	PmergeMe::_get_vector_max_iter(vector_type &src, vector_iter &iter)
{
	int	max = 0;
	for (vector_iter it = src.begin(); it != src.end(); it++)
		if (max < *it)
			iter = it;
}



