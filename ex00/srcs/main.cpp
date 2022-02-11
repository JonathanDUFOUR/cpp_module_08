/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:37:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/11 01:36:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstdlib>
#include <list>
#include <iostream>
#include "class/easyfind.tpp"

static void	__test0(void)
{
	try
	{
		std::list<int>							lst;
		std::list<int>::iterator				iter;
		std::list<int>::const_iterator const	end = lst.end();
		int										i;

		for (i = 0; i < 10; i++)
			lst.push_back(i);
		iter = easyfind(lst, 5);
		for (iter = lst.begin(); iter != end; ++iter)
			std::cout << &iter << " | " << *iter << std::endl;
		iter = easyfind(lst, 1);
		std::cout << std::endl;
		std::cout << &iter << " | " << *iter << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void	__test1(void)
{
	
}

static void	__test2(void)
{
	
}

static void	__test3(void)
{
	
}

int	main(void)
{
	__test0();
	std::cout << "-----------------------------------------------" << std::endl;
	__test1();
	std::cout << "-----------------------------------------------" << std::endl;
	__test2();
	std::cout << "-----------------------------------------------" << std::endl;
	__test3();
	return EXIT_SUCCESS;
}
