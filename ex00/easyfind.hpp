/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:41 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/18 10:28:20 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <exception>
# include <iterator>
# include <vector>
# include <typeinfo>


# define COUT std::cout
# define ENDL std::endl
# define COL_BLUE "\033[0;34m"
# define COL_YELLOW "\033[0;33m"
# define COL_MAGENTA "\033[0;35m"
# define COL_DEFAULT "\033[0m"
# define SHOW_HEADER(MSG) COUT << ENDL << COL_YELLOW #MSG COL_DEFAULT << ENDL; 
# define SHOW_VAL(X,Y) COUT << "x(" << X << ") : y(" << Y <<  ")\n"


class ItemNotFoundException : public std::exception
{
    virtual char const *what() const throw()
    {
        return ("Item not found\n");
    }
};



template< typename T >
void    easyFind(T container, int item)
{
    //std::vector<int>::iterator it;
    //MyIterator it(container);
    
    //void *it = static_cast<void *>(std::find(container.begin(), container.end(), item));
    if (typeid(container) == typeid(std::vector<int>))
    {
        COUT << "is vector: " << ENDL;
        std::vector<int>::iterator it = std::find(container.begin(), container.end(), item);
        COUT << "Integer " << item << " found at index " << it - container.begin() << " (" << *it << ")" << ENDL;
    }
    /*
    if (it == container.end())
    {
        throw ItemNotFoundException();
    }
    else
    {
        COUT << "Integer " << item << " found at index "
             << it - container.begin() << " (" << *it << ")" << ENDL;
    }
    */
}

#endif // EASYFIND_HPP
