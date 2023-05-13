/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:27:26 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/13 22:57:35 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : nbrSize(0), nbrs(NULL)
{}

Span::Span(unsigned int N) : nbrSize(N), nbrs(NULL)
{
    nbrs = new std::vector <int>;
}

Span::Span( Span const &obj )
{
    *this = obj;
}

Span    &Span::operator=( Span const &rhs )
{
    this->nbrSize = rhs.nbrSize;
    //memcpy(this->nbrs, &(rhs.nbrs), sizeof(rhs.nbrs));
    std::swap(this->nbrs, rhs.nbrs);
    return (*this);
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


void    Span::addNumber(int const nbr)
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
    EXCEPTION_HANDLER();
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
        if (nbrSize == 0)
            throw std::runtime_error(ERR_MSG_SIZE_LIMIT);
        if (nbrs->size() >= 2 )
        {
            std::sort(nbrs->begin(), nbrs->end());
            span_range = nbrs->at(1) - nbrs->front();
        }
        else
            throw std::runtime_error(ERR_MSG_NO_SPAN);
    }
    EXCEPTION_HANDLER();
    return (span_range);
}



int Span::longestSpan(void)
{
    int span_range = 0;
    try
    {
        if (nbrSize == 0)
            throw std::runtime_error(ERR_MSG_SIZE_LIMIT);
        if (nbrs->size() >= 2)
        {
            std::sort(nbrs->begin(), nbrs->end());
            span_range = nbrs->back() - nbrs->front();
        }
        else
            throw std::runtime_error(ERR_MSG_NO_SPAN);
    }
    EXCEPTION_HANDLER();
    return (span_range);
}

void Span::fillSpan(VEC_INT_IT begin, VEC_INT_IT end)
{
    try
    {
        if (nbrSize == 0)
            throw std::runtime_error(ERR_MSG_SIZE_LIMIT);
        else if (begin == end)
        {
            throw std::runtime_error(ERR_MSG_EMPTY_VEC);
        }
        else
        {
            while (begin != end)
            {
                addNumber(*begin);
                begin++;
            }
        }
    }
   EXCEPTION_HANDLER();
}