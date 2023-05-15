/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:41 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/15 19:13:49 by cudoh            ###   ########.fr       */
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
# include <string.h>
# include <utility>
# include <typeinfo>


# define COUT std::cout
# define ENDL std::endl
# define COL_BLUE "\033[0;34m"
# define COL_RED "\033[0;31m"
# define COL_YELLOW "\033[0;33m"
# define COL_MAGENTA "\033[0;35m"
# define COL_DEFAULT "\033[0m"
# define SHOW_HEADER(MSG) COUT << ENDL << COL_YELLOW "== "#MSG" ==" COL_DEFAULT << ENDL; 
# define ERR_MSG_FULL COL_RED "Error! Span is full" COL_DEFAULT
# define ERR_MSG_SIZE_LIMIT COL_RED "Error! Span size is limited" COL_DEFAULT
# define ERR_MSG_NO_SPAN COL_RED "Error! No Span possible" COL_DEFAULT
# define ERR_MSG_EMPTY_VEC COL_RED "Error! Init vector iterator is empty" COL_DEFAULT
# define VEC_INT_IT std::vector<int>::iterator
# define MIN_NBR_INT (10000)
# define EXCEPTION_HANDLER()            \
    catch (const std::exception &e)     \
    {\
        std::cerr << e.what() << '\n'; \
    }\


class Span
{
    private:
        unsigned int nbrSize; // size of span
        std::vector< int > *nbrs;

    protected:
    public:
        Span(void);
        Span(unsigned int N);
        Span(Span const &obj);
        Span &operator=(Span const &rhs);
        ~Span(void);
        void                addNumber(int const nbr);
        int                 shortestSpan(void);
        int                 longestSpan(void);
        void                fillSpan(VEC_INT_IT begin, VEC_INT_IT end);
        unsigned int        getSize(void) const;
        std::vector<int>    *getSpanPtr(void) const;

};

std::ostream    &operator<<(std::ostream &o, Span const &s);

#endif // SPAN_HPP
