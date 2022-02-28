/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:43:53 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/28 16:02:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <climits>
#include <ctime>
#include "class/Span.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Span::Span(uint const size) :
	_size(0),
	_maxSize(size),
	_lst()
{
	if (DEBUG)
		std::cout
		<< "Creating Span"
		<< " (" << this->_size << ")"
		<< " (" << this->_maxSize << ")"
		<< std::endl;
	std::srand(std::time(NULL));
}

Span::Span(Span const &src) :
	_size(src._size),
	_maxSize(src._maxSize),
	_lst(src._lst)
{
	if (DEBUG)
		std::cout
		<< "Creating Span"
		<< " (" << this->_size << ")"
		<< " (" << this->_maxSize << ")"
		<< std::endl;
	std::srand(std::time(NULL));
}


// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Span::~Span(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying Span"
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

uint const	&Span::getSize(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Span::getSize()"
		<< std::endl;
	return this->_size;
}

uint const	&Span::getMaxSize(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Span::getMaxSize()"
		<< std::endl;
	return this->_maxSize;
}

std::list<int> const	&Span::getLst(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Span::getLst()"
		<< std::endl;
	return this->_lst;
}

// ************************************************************************** //
//                          Private Member Functions                          //
// ************************************************************************** //

char const	*Span::AlreadyFullException::what() const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling Span::alreadyFullException::what()"
		<< std::endl;
	return "Span is already full";
}

char const	*Span::NoSpanException::what() const throw()
{
	if (DEBUG)
		std::cout
		<< "Calling Span::noSpanException::what()"
		<< std::endl;
	return "too few integers stored in Span";
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Span::addNumber(int const n)
{
	if (DEBUG)
		std::cout
		<< "Calling Span::addNumber()"
		<< std::endl;
	if (this->_size == this->_maxSize)
		throw Span::AlreadyFullException();
	this->_lst.push_back(n);
	++this->_size;
}

void	Span::randomGenerate(uint const size)
{
	uint	i;

	if (DEBUG)
		std::cout
		<< "Calling Span::randomGenerate()"
		<< std::endl;
	for (i = 0 ; i < size ; ++i)
		this->addNumber(std::rand());
}

uint	Span::longestSpan(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Span::longestSpan()"
		<< std::endl;
	if (this->_size < 2)
		throw Span::NoSpanException();
	return *std::max_element(this->_lst.begin(), this->_lst.end())
		- *std::min_element(this->_lst.begin(), this->_lst.end());
}

uint	Span::shortestSpan(void) const
{
	uint							output;
	std::list<int>					tmp(this->_lst);
	std::list<int>::const_iterator	iter;
	int								a;
	int								b;

	if (DEBUG)
		std::cout
		<< "Calling Span::shortestSpan()"
		<< std::endl;
	if (this->_size < 2)
		throw Span::NoSpanException();
	output = UINT_MAX;
	tmp.sort();
	iter = tmp.begin();
	while (iter != tmp.end())
	{
		a = *iter;
		if (++iter != tmp.end())
		{
			b = *iter;
			if (static_cast<uint>(b - a) < output)
				output = static_cast<uint>(b - a);
		}
	}
	return output;
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

Span	&Span::operator=(Span const &rhs)
{
	if (DEBUG)
		std::cout
		<< "Calling Span::operator=()"
		<< std::endl;
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_maxSize = rhs._maxSize;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Span const &rhs)
{
	std::list<int>::const_iterator	iter;

	o << "Span" << std::endl
	<< "\t" "size: " << rhs.getSize() << std::endl
	<< "\t" "maxSize: " << rhs.getMaxSize() << std::endl
	<< "\t" "list: {";
	iter = rhs.getLst().begin();
	while (iter != rhs.getLst().end())
	{
		o << *iter;
		if (++iter != rhs.getLst().end())
			o << ", ";
	}
	o << "}" << std::endl;
	return o;
}
