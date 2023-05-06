/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:06:44 by aparolar          #+#    #+#             */
/*   Updated: 2023/05/06 16:00:13 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <list>
#include <string>

class PmergeMe
{
		typedef std::vector<unsigned int>	vector_type;
		typedef vector_type::iterator		vector_iter;
		typedef std::deque<unsigned int>	deque_type;
		typedef deque_type::iterator		deque_iter;

	private:
		vector_type			_vector;
		vector_type			_vector_result;
		deque_type			_deque;
		deque_type			_deque_result;
		bool				_debug_mode = false;

		bool				isValidInteger(std::string const &value);
		void		 		_vector_sort(vector_type &toSplit);
		void				_deque_sort(deque_type &toSplit);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &cpy);
		PmergeMe(int count, char **values);
		~PmergeMe();

		PmergeMe const &operator=(PmergeMe const &cpy);

		void	runVectorSort();
		void	runDequeSort();
};

#endif
