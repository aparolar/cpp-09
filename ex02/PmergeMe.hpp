/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:06:44 by aparolar          #+#    #+#             */
/*   Updated: 2023/05/05 09:45:45 by aparolar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>

class PmergeMe
{
		typedef std::vector<int>			vector_type;
		typedef vector_type::size_type		vector_size;
		typedef vector_type::const_iterator	vector_citer;
		typedef vector_type::iterator		vector_iter;

	private:
		vector_type			_vector;
		std::list<int>		_list;

		bool				isValidInteger(std::string const &value);
		vector_type 		_vector_sort(vector_type &toSplit);
		vector_type			_vector_merge(vector_type &left, vector_type &rigth);
		void				_vector_insert(vector_type &src, vector_type &dst);
		void				_get_vector_max_iter(vector_type &src, vector_iter &iter);

	public:
		PmergeMe();
		PmergeMe(PmergeMe const &cpy);
		PmergeMe(int count, char **values);
		~PmergeMe();

		PmergeMe const &operator=(PmergeMe const &cpy);

		void	runVectorSort();
		void	runListSort();
};

#endif
