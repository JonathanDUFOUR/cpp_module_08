/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:43:23 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/28 16:18:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "class/Span.hpp"

static void	__test0(void)
{
	Span	sp(5);
	int		i;

	for (i = 0; i < 5; i++)
		try
		{
			sp.addNumber(i);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << sp << std::endl;
}

static void	__test1(void)
{
	Span	sp(2);
	int		i;

	for (i = 0; i < 5; i++)
		try
		{
			sp.addNumber(i);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << sp << std::endl;
}

static void	__test2(void)
{
	Span	sp(10);
	uint	range;
	int		i;

	for (i = 0; i < 10; i++)
		try
		{
			sp.addNumber(i * 42);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << sp << std::endl;
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

static void	__test3(void)
{
	Span	sp;
	uint	range;

	std::cout << sp << std::endl;
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void	__test4(void)
{
	Span	sp(1);
	uint	range;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sp << std::endl;
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

static void	__test5(void)
{
	Span	sp(100);
	uint	range;

	try
	{
		sp.randomGenerate(100);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << sp << std::endl;
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
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
	std::cout << "-----------------------------------------------" << std::endl;
	__test4();
	std::cout << "-----------------------------------------------" << std::endl;
	__test5();
	return EXIT_SUCCESS;
}
