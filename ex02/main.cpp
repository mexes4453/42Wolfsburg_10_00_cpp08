/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:45 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/15 19:06:52 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include <cstdlib>
# include <ctime>

int    genRandNbr(void);

int main(void)
{
    SHOW_HEADER(1. TEST : SPAN === init: N = 3)
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
    SHOW_HEADER(2. TEST : SPAN === init: N = 0)
    {
        Span numbers(0);
        numbers.addNumber(4);
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(3. TEST : SPAN === init: N = 1)
    {
        Span numbers(1);
        numbers.addNumber(4);
        numbers.addNumber(6);
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(4. TEST : EMPTY SPAN FILL UP => init: with 10000 sized vector)
    {   
        std::vector<int>    _sequence(MIN_NBR_INT, 2);
        Span numbers;
        numbers.fillSpan(_sequence.begin(), _sequence.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }
    

    COUT << ENDL << ENDL;
    SHOW_HEADER(5. TEST : EMPTY SPAN FILL UP => init: with empty sized vector)
    {   
        std::vector<int>    _sequence;
        Span numbers;
        numbers.fillSpan(_sequence.begin(), _sequence.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(6. TEST : 10000 SPAN FILL UP => init: with empty sized vector)
    {   
        std::vector<int>     _sequence;
        Span numbers(MIN_NBR_INT);
        numbers.fillSpan(_sequence.begin(), _sequence.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(7. TEST : 10000 SPAN FILL UP => init: with 10000 sized vector)
    {   
        std::vector<int>     _sequence(MIN_NBR_INT, 2);
        Span numbers(MIN_NBR_INT);
        numbers.fillSpan(_sequence.begin(), _sequence.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(8. TEST : 10000 SPAN FILL UP => init: with 10000 sized vector - random nbrs)
    {
        std::vector<int>    nbrFiller(MIN_NBR_INT, 0);
        Span numbers(MIN_NBR_INT);
        std::srand(unsigned (std::time(0)));
        std::generate(nbrFiller.begin(), nbrFiller.end(), genRandNbr);
        numbers.fillSpan(nbrFiller.begin(), nbrFiller.end());
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(10. TEST : SUBJECT FILE TEST CASE)
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        COUT << sp << ENDL;
        std::cout << sp.shortestSpan() << std::endl;
        COUT << sp << ENDL;
        std::cout << sp.longestSpan() << std::endl;
    }
    return (0);
}


int    genRandNbr(void)
{
    return (std::rand() % 100);
}