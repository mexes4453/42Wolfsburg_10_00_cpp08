/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:41 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/13 15:13:18 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <exception>
# include <stdexcept>
# include <iterator>
# include <vector>
# include <utility>
# include <typeinfo>


# define COUT std::cout
# define ENDL std::endl
# define COL_BLUE "\033[0;34m"
# define COL_RED "\033[0;31m"
# define COL_YELLOW "\033[0;33m"
# define COL_MAGENTA "\033[0;35m"
# define COL_DEFAULT "\033[0m"
# define SHOW_HEADER(MSG) COUT << ENDL << COL_YELLOW #MSG COL_DEFAULT << ENDL; 
# define ERR_MSG_FULL COL_RED "Error! Span is full" COL_DEFAULT
# define ERR_MSG_NO_SPAN COL_RED "Error! No Span possible" COL_DEFAULT



class Span
{
    private:
        unsigned int nbrSize; // size of span
        std::vector< int > *nbrs;
        Span(void);
        Span(Span const &obj);
        Span &operator=(Span const &rhs);

    protected:
    public:
        Span(unsigned int N);
        ~Span(void);
        void            addNumber(int nbr);
        int             shortestSpan(void);
        int             longestSpan(void);
        void            iterator(void);
        unsigned int    getSize(void) const;


};

#endif // SPAN_HPP
