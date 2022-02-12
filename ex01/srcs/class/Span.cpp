/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:43:53 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/12 11:57:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <climits>
#include <ctime>
#include "class/Span.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Span::Span(void) :
	_size(0),
	_maxSize(0)
{
	std::cout
	<< "Creating Span"
	<< " (" << this->_size << ")"
	<< " (" << this->_maxSize << ")"
	<< std::endl;
	std::srand(std::time(NULL));
}

Span::Span(Span const &src) :
	_size(src._size),
	_maxSize(src._maxSize)
{
	std::cout
	<< "Creating Span"
	<< " (" << this->_size << ")"
	<< " (" << this->_maxSize << ")"
	<< std::endl;
	*this = src;
	std::srand(std::time(NULL));
}

Span::Span(unsigned int const size) :
	_size(0),
	_maxSize(size)
{
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
	std::cout
	<< "Destroying Span"
	<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

unsigned int	Span::getSize(void) const
{
	return this->_size;
}

unsigned int	Span::getMaxSize(void) const
{
	return this->_maxSize;
}

std::list<int> const	&Span::getLst(void) const
{
	return this->_lst;
}

// ************************************************************************** //
//                          Private Member Functions                          //
// ************************************************************************** //

char const	*Span::alreadyFullException::what() const throw()
{
	return "Span is already full";
}

char const	*Span::noSpanException::what() const throw()
{
	return "too few integers stored in Span";
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Span::addNumber(int const n)
{
	if (this->_size == this->_maxSize)
		throw Span::alreadyFullException();
	this->_lst.push_back(n);
	++this->_size;
}

void	Span::randomGenerate(unsigned int const size)
{
	unsigned int	i;

	for (i = 0 ; i < size ; ++i)
		this->addNumber(std::rand() % INT_MAX);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_size < 2)
		throw Span::noSpanException();
	return *std::max_element(this->_lst.begin(), this->_lst.end())
		- *std::min_element(this->_lst.begin(), this->_lst.end());
}

unsigned int	Span::shortestSpan(void) const
{
	unsigned int					output;
	std::list<int>					tmp(this->_lst);
	std::list<int>::const_iterator	iter;
	int								a;
	int								b;

	if (this->_size < 2)
		throw Span::noSpanException();
	output = UINT_MAX;
	tmp.sort();
	iter = tmp.begin();
	while (iter != tmp.end())
	{
		a = *iter;
		if (++iter != tmp.end())
		{
			b = *iter;
			if (static_cast<unsigned int>(b - a) < output)
				output = static_cast<unsigned int>(b - a);
		}
	}
	return output;
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

Span	&Span::operator=(Span const &rhs)
{
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
		o << *iter ;
		if (++iter != rhs.getLst().end())
			o << ", ";
	}
	o << "}" << std::endl;
	return o;
}
