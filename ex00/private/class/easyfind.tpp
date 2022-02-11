/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:53:10 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/11 01:22:25 by jodufour         ###   ########.fr       */
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
		return "element not found";
	}
};

template <typename T>
typename T::iterator	easyfind(T &haystack, int const needle)
{
	typename T::iterator	iter;

	iter = find(haystack.begin(), haystack.end(), needle);
	if (*iter == needle)
		return iter;
	throw elementNotFoundException();
}

#endif
