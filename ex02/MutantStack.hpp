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
        typedef std::stack<T, Container>                    stack;
        typedef typename stack::container_type              container;
        typedef typename container::iterator                iterator;
        typedef typename container::reverse_iterator        reverse_iterator;
        typedef typename container::const_iterator          const_iterator;
        typedef typename container::const_reverse_iterator  const_reverse_iterator;

        MutantStack(void): stack(){}
        MutantStack(stack const &other) : stack(other) {}
        ~MutantStack(void){}
        MutantStack &operator=(MutantStack const &rhs)
        {
            stack::operator=(rhs);
            return (*this);
        }

        iterator                begin(void) {return stack::c.begin();}
        iterator                end(void) {return stack::c.end();}
        reverse_iterator        rbegin(void) { return (stack::c.rbegin()); }
        reverse_iterator        rend(void) { return (stack::c.rend()); }
        const_iterator          begin(void) const { return (stack::c.begin()); }
        const_iterator          end(void) const { return (stack::c.end()); }
        const_reverse_iterator  rbegin(void) const { return (stack::c.rbegin()); }
        const_reverse_iterator  rend(void) const { return (stack::c.rend()); }

};

template <typename T, typename C >
std::ostream &operator<<(std::ostream &o, MutantStack<T, C> const &mstack)
{

        typename MutantStack<T, C>::const_iterator it = mstack.begin();
        typename MutantStack<T, C>::const_iterator ite = mstack.end();
        o << " - SIZE: " << mstack.size() << " : ";
        while (it != ite)
        {
            o << *it << " ";
            ++it;
        }
        return (o);
}

#endif //MUTANTSTACK_HPP