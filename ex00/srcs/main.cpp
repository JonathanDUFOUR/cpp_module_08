/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:37:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 23:12:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "easyfind.tpp"

static void	__test0(void)
{
	std::list<int>					lst;
	std::list<int>::const_iterator	iter;
	int								i;

	try
	{
		for (i = 0 ; i < 10 ; ++i)
			lst.push_back(i);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (iter = lst.begin() ; iter != lst.end() ; ++iter)
		std::cout << *iter << ": " << &*iter << std::endl;
	std::cout << std::endl;
	i = 5;
	try
	{
		iter = easyfind(lst, i);
		std::cout << *iter << ": " << &*iter << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << i << ": " << e.what() << std::endl;
	}
}

static void	__test1(void)
{
	std::vector<int>					vec;
	std::vector<int>::const_iterator	iter;
	int									i;

	try
	{
		for (i = 0 ; i < 10 ; ++i)
			vec.push_back(i);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (iter = vec.begin() ; iter != vec.end() ; ++iter)
		std::cout << *iter << ": " << &*iter << std::endl;
	std::cout << std::endl;
	i = 9;
	try
	{
		iter = easyfind(vec, i);
		std::cout << *iter << ": " << &*iter << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << i << ": " << e.what() << std::endl;
	}
}

static void	__test2(void)
{
	std::deque<int>					deq;
	std::deque<int>::const_iterator	iter;
	int								i;

	try
	{
		for (i = 0 ; i < 10 ; ++i)
			deq.push_back(i);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (iter = deq.begin() ; iter != deq.end() ; ++iter)
		std::cout << *iter << ": " << &*iter << std::endl;
	std::cout << std::endl;
	i = 404;
	try
	{
		iter = easyfind(deq, i);
		std::cout << *iter << ": " << &*iter << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << i << ": " << e.what() << std::endl;
	}
}

int	main(void)
{
	__test0();
	std::cout << "-----------------------------------------------" << std::endl;
	__test1();
	std::cout << "-----------------------------------------------" << std::endl;
	__test2();
	return EXIT_SUCCESS;
}
