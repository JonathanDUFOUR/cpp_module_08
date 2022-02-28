/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:44:24 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/28 16:02:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Span
{
private:
	uint			_size;
	uint			_maxSize;
	std::list<int>	_lst;

	class AlreadyFullException : public std::exception
	{
	private:
		// Member functions
		virtual char const	*what(void) const throw();
	};

	class NoSpanException : public std::exception
	{
	private:
		// Member functions
		virtual char const	*what(void) const throw();
	};

public:
	// Constructors
	Span(uint const size = 0);
	Span(Span const &src);

	// Destructors
	virtual ~Span(void);

	// Accessors
	uint const				&getSize(void) const;
	uint const				&getMaxSize(void) const;
	std::list<int> const	&getLst(void) const;

	// Member functions
	void	addNumber(int const nb);
	void	randomGenerate(uint const size);

	uint	longestSpan(void) const;
	uint	shortestSpan(void) const;

	// Operators
	Span	&operator=(Span const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Span const &rhs);

#endif
