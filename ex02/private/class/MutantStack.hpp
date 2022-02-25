/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:15:50 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/25 00:26:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

# ifndef DEBUG
#  define DEBUG 0
# endif

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

	// Constructors
	MutantStack<T>(void);
	MutantStack<T>(MutantStack<T> const &src);

	// Destructors
	virtual ~MutantStack<T>(void);

	// Member functions
	iterator		begin(void);
	iterator		end(void);

	const_iterator	begin(void) const;
	const_iterator	end(void) const;

	// Operators
	MutantStack<T>	&operator=(MutantStack<T> const &rhs);
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, MutantStack<T> const &rhs);

template <typename T>
std::ostream	&operator<<(std::ostream &o, typename MutantStack<T>::iterator const &rhs);

template <typename T>
std::ostream	&operator<<(std::ostream &o, typename MutantStack<T>::const_iterator const &rhs);

#endif
