/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:40:32 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/16 19:40:32 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <exception>
# include <stdexcept>
# include <iterator>
# include <stack>
# include <deque>


# define COUT std::cout
# define ENDL std::endl
# define COL_BLUE "\033[0;34m"
# define COL_RED "\033[0;31m"
# define COL_YELLOW "\033[0;33m"
# define COL_MAGENTA "\033[0;35m"
# define COL_DEFAULT "\033[0m"
# define SHOW_HEADER(MSG) COUT << ENDL << COL_YELLOW "== "#MSG" ==" COL_DEFAULT << ENDL; 



template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef std::stack<T, Container> stack;
        typedef typename stack::container_type  container;
        typedef typename container::iterator iterator;
        typedef typename container::const_iterator c_iterator;
        typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
        typedef std::reverse_iterator<iterator>		reverse_iterator;


        MutantStack(): stack(){}
        MutantStack(stack const &other) : stack(other) {}
        virtual ~MutantStack(){}
        MutantStack<T, Container> &operator=(stack const &rhs)
        {
            if (this != &rhs)
            {
                *this = rhs;
            }
            return (*this);
        }

        iterator    begin() {return stack::c.begin();}
        iterator    end() {return stack::c.end();}
};


#endif //MUTANTSTACK_HPP