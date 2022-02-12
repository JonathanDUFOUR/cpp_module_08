/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:14:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/12 18:06:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "class/MutantStack.tpp"

static void	__test0(void)
{
	MutantStack<int>			mut;
	std::list<int>				lst;
	MutantStack<int>::iterator	iter0;
	std::list<int>::iterator	iter1;
	int							i;

	for (i = 0 ; i < 10 ; ++i)
	{
		mut.push(i);
		lst.push_back(i);
	}
	std::cout << "mut: {";
	iter0 = mut.begin();
	while (iter0 != mut.end())
	{
		std::cout << *iter0;
		if (++iter0 != mut.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl
	<< "lst: {";
	iter1 = lst.begin();
	while (iter1 != lst.end())
	{
		std::cout << *iter1;
		if (++iter1 != lst.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

static void	__test1(void)
{
	MutantStack<int>			mut;
	std::vector<int>			vec;
	MutantStack<int>::iterator	iter0;
	std::vector<int>::iterator	iter1;
	int							i;

	for (i = 0 ; i < 10 ; ++i)
	{
		mut.push(i * i);
		vec.push_back(i * i);
	}
	std::cout << "mut: {";
	iter0 = mut.begin();
	while (iter0 != mut.end())
	{
		std::cout << *iter0;
		if (++iter0 != mut.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl
	<< "vec: {";
	iter1 = vec.begin();
	while (iter1 != vec.end())
	{
		std::cout << *iter1;
		if (++iter1 != vec.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

static void	__test2(void)
{
	MutantStack<int>			mut;
	std::deque<int>				deq;
	MutantStack<int>::iterator	iter0;
	std::deque<int>::iterator	iter1;
	int							i;

	for (i = 0 ; i < 10 ; ++i)
	{
		mut.push(i * 3 + 1);
		deq.push_back(i * 3 + 1);
	}
	std::cout << "mut: {";
	iter0 = mut.begin();
	while (iter0 != mut.end())
	{
		std::cout << *iter0;
		if (++iter0 != mut.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl
	<< "deq: {";
	iter1 = deq.begin();
	while (iter1 != deq.end())
	{
		std::cout << *iter1;
		if (++iter1 != deq.end())
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
}

int main(void)
{
	__test0();
	std::cout << "-----------------------------------------------" << std::endl;
	__test1();
	std::cout << "-----------------------------------------------" << std::endl;
	__test2();
	return (0);
}
