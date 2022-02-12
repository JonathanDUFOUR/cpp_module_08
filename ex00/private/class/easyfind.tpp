/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:53:10 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/12 09:21:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <algorithm>

class elementNotFoundException : public std::exception
{
public:
	virtual char const	*what(void) const throw()
	{
		return "not found";
	}
};

template <typename T>
typename T::iterator	easyfind(T &haystack, int const needle)
{
	typename T::iterator	iter;

	iter = find(haystack.begin(), haystack.end(), needle);
	if (iter == haystack.end())
		throw elementNotFoundException();
	return iter;
}

#endif
