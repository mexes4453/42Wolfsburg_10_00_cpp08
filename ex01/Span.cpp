/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:27:26 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/13 15:26:32 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(unsigned int N) : nbrSize(N), nbrs(NULL)
{
    nbrs = new std::vector <int>;
}

Span::~Span(void)
{
    if (nbrs != NULL)
    {
        nbrs->clear();
        delete nbrs; 
        nbrs = NULL;
    }
    COUT << "Span: size(" << nbrSize << ") destroyed!" << ENDL;
}


void    Span::addNumber(int nbr)
{
    try
    {
        if (nbrs->size() < nbrSize)
        {
            nbrs->push_back(nbr);
        }
        else
        {
            throw std::runtime_error(ERR_MSG_FULL);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}


unsigned int    Span::getSize(void) const
{
    return (nbrSize);
}

int Span::shortestSpan(void)
{
    int span_range = 0;
    try
    {
        if (nbrSize >= 2)
        {
            std::sort(nbrs->begin(), nbrs->end());
            span_range = nbrs->at(1) - nbrs->front();
        }
        else
            throw std::runtime_error(ERR_MSG_NO_SPAN);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return (span_range);
}



int Span::longestSpan(void)
{
    int span_range = 0;
    try
    {
        if (nbrSize >= 2)
        {
            std::sort(nbrs->begin(), nbrs->end());
            span_range = nbrs->back() - nbrs->front();
        }
        else
            throw std::runtime_error(ERR_MSG_NO_SPAN);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return (span_range);
}
