/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:25:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/12 17:37:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/MutantStack.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

template <typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout
	<< "Creating MutantStack"
	<< std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src)
{
	std::cout
	<< "Creating MutantStack"
	<< std::endl;
	*this = src;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout
	<< "Destroying MutantStack"
	<< std::endl;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return this->c.end();
}

// ************************************************************************* //
//                                 Operators                                 //
// ************************************************************************* //

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack<T> const &rhs)
{
	return std::stack<T>::operator=(rhs);
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, MutantStack<T> const &rhs)
{
	MutantStack<int>::const_iterator	iter;

	o << "MutantStack:" << std::endl;
	for (iter = rhs.begin(); iter != rhs.end(); ++iter)
		o << "\t" << *iter << ": " << &*iter << std::endl;
	return o;
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, typename MutantStack<T>::iterator const &rhs)
{
	o << "MutantStack::iterator:" << std::endl
	<< "\t" "*rhs: " << *rhs << std::endl
	<< "\t" "&*rhs: " << &*rhs << std::endl;
	return o;
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, typename MutantStack<T>::const_iterator const &rhs)
{
	o << "MutantStack::const_iterator:" << std::endl
	<< "\t" "*rhs: " << *rhs << std::endl
	<< "\t" "&*rhs: " << &*rhs << std::endl;
	return o;
}
