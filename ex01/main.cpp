/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:45 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/13 22:40:04 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int main(void)
{
    SHOW_HEADER(TEST : SPAN === init: N = 3)
    {
        Span numbers(3);
        numbers.addNumber(1);
        numbers.addNumber(2);
        numbers.addNumber(3);
        numbers.addNumber(4);
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(TEST : SPAN === init: N = 0)
    {
        Span numbers(0);
        numbers.addNumber(4);
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(TEST : SPAN === init: N = 1)
    {
        Span numbers(1);
        numbers.addNumber(4);
        numbers.addNumber(6);
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(TEST : EMPTY SPAN FILL UP => init: with 10000 sized vector)
    {   
        std::vector<int>    _sequence(MIN_NBR_INT, 2);
        Span numbers;
        numbers.fillSpan(_sequence.begin(), _sequence.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }
    

    COUT << ENDL << ENDL;
    SHOW_HEADER(TEST : EMPTY SPAN FILL UP => init: with empty sized vector)
    {   
        std::vector<int>    _sequence;
        Span numbers;
        numbers.fillSpan(_sequence.begin(), _sequence.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(TEST : 10000 SPAN FILL UP => init: with empty sized vector)
    {   
        std::vector<int>     _sequence;
        Span numbers(MIN_NBR_INT);
        numbers.fillSpan(_sequence.begin(), _sequence.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(TEST : 10000 SPAN FILL UP => init: with 10000 sized vector)
    {   
        std::vector<int>     _sequence(MIN_NBR_INT, 2);
        Span numbers(MIN_NBR_INT);
        numbers.fillSpan(_sequence.begin(), _sequence.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(TEST : SUBJECT FILE TEST CASE)
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    return (0);
}