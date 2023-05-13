/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:45 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/13 15:31:14 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int main(void)
{
    SHOW_HEADER(=== TEST : SPAN === init: N = 3)
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
    SHOW_HEADER(=== TEST : SPAN === init: N = 0)
    {
        Span numbers(0);
        numbers.addNumber(4);
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }

    COUT << ENDL << ENDL;
    SHOW_HEADER(=== TEST : SPAN === init: N = 1)
    {
        Span numbers(1);
        numbers.addNumber(4);
        numbers.addNumber(6);
        COUT << "SIZE: " << numbers.getSize() << ENDL;
        COUT << "SHORTEST : " << numbers.shortestSpan() << ENDL;
        COUT << "LONGEST  : " << numbers.longestSpan() << ENDL;
    }
#if 0
    SHOW_HEADER(=== TEST : VECTOR === vector(5, 20) | Searched: 5)
    {
        std::vector<int> vec(5, 20);
        easyFind< std::vector<int> >(vec, 5);
    }

    SHOW_HEADER(=== TEST : VECTOR === vector(5, 20) | Append: 56 | Searched: 56)
    {
        std::vector<int> vec(5, 20);
        vec.push_back(56);
        easyFind< std::vector<int> >(vec, 56);
    }

    SHOW_HEADER(=== TEST : LIST === list(5, 20) | Searched: 3)
    {
        std::list<int> lists(5, 20);
        easyFind< std::list<int> >(lists, 3);
    }

    SHOW_HEADER(=== TEST : LIST === list(5, 20) | Append: 56 | Searched: 56)
    {
        std::list<int> lists(5, 20);
        lists.push_back(3);
        easyFind< std::list<int> >(lists, 3);
    }
#endif
    return (0);
}