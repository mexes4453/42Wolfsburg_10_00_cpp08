/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:41 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/13 00:38:46 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <exception>
# include <stdexcept>
# include <iterator>
# include <vector>
# include <map>
# include <list>


# define COUT std::cout
# define ENDL std::endl
# define COL_BLUE "\033[0;34m"
# define COL_YELLOW "\033[0;33m"
# define COL_MAGENTA "\033[0;35m"
# define COL_DEFAULT "\033[0m"
# define SHOW_HEADER(MSG) COUT << ENDL << COL_YELLOW #MSG COL_DEFAULT << ENDL; 


class ItemNotFoundException : public std::exception
{
    virtual char const *what() const throw()
    {
        return ("Nbr not found\n");
    }
};



template< typename T >
void    easyFind(T container, int nbr)
{

    typename T::iterator it = std::find(container.begin(), container.end(), nbr);
    try
    {
        if (it == container.end())
            throw std::runtime_error("Number not found");
        else
        {
            COUT << "Integer " << *it << " found. " << ENDL;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

#endif // EASYFIND_HPP
