/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:45 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/18 05:46:32 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include <vector>

int main(void)
{
    COUT << ENDL;
    SHOW_HEADER(1. TEST
                : MUTANT STACK INIT)
    {
        std::deque<int> mydeque(3, 100);   // deque with 3 elements
        std::vector<int> myvector(2, 200); // vector with 2 elements

        std::stack<int> first;           // empty stack
        std::stack<int> second(mydeque); // stack initialized to copy of deque

        std::stack<int, std::vector<int> > third; // empty stack using vector
        std::stack<int, std::vector<int> > fourth(myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
        MutantStack<int> ms1(first);
        MutantStack<int> ms2(second);
        MutantStack<int, std::vector<int> > ms3(third);
        MutantStack<int, std::vector<int> > ms4(fourth);
        MutantStack<int> ms5(ms1);
        MutantStack<int> ms6 = ms2;

    }

    COUT << ENDL;
    SHOW_HEADER(2. TEST
                : MUTANT STACK - SUBJECT FILE)
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    return (0);
}
