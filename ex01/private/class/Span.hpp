/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:44:24 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/12 11:54:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>

class Span
{
private:
	unsigned int	_size;
	unsigned int	_maxSize;
	std::list<int>	_lst;

	class alreadyFullException : public std::exception
	{
	private:
		// Member functions
		virtual char const	*what(void) const throw();
	};

	class noSpanException : public std::exception
	{
	private:
		// Member functions
		virtual char const	*what(void) const throw();
	};
protected:

public:
	// Constructors
	Span(void);
	Span(Span const &src);
	Span(unsigned int const size);

	// Destructors
	virtual ~Span(void);

	// Accessors
	inline unsigned int			getSize(void) const;
	inline unsigned int			getMaxSize(void) const;
	inline std::list<int> const	&getLst(void) const;

	// Member functions
	void			addNumber(int const nb);
	void			randomGenerate(unsigned int const size);

	unsigned int	longestSpan(void) const;
	unsigned int	shortestSpan(void) const;

	// Operators
	Span	&operator=(Span const &rhs);
};

std::ostream	&operator<<(std::ostream &o, Span const &rhs);

#endif
