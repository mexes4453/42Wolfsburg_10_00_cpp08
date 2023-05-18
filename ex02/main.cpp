/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:45 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/18 22:48:05 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include <vector>
# include <list>

int main(void)
{
    COUT << ENDL;
    SHOW_HEADER(1. TEST
                : MUTANT STACK INIT)
    {
        std::deque<int> mydeque(3, 100);                 // deque with 3 elements
        std::vector<int> myvector(2, 200);               // vector with 2 elements
        std::list<int> mylist(2, 5);                     // list with 2 elements

        std::stack<int> first;                           // empty stack
        std::stack<int> second(mydeque);                 // stack initialized to copy of deque

        std::stack<int, std::vector<int> > third;        // empty stack using vector
        std::stack<int, std::vector<int> > fourth(myvector);

        std::stack<int, std::list<int> > fifth;         // empty stack using list
        std::stack<int, std::list<int> > sixth(mylist); // stack initialized to copy of list

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
        std::cout << "size of fifth: " << fifth.size() << '\n';
        std::cout << "size of sixth: " << sixth.size() << '\n';
        
        MutantStack<int> ms1(first);  
        MutantStack<int> ms2(second); 
        MutantStack<int, std::vector<int> > ms3(third);  
        MutantStack<int, std::vector<int> > ms4(fourth); 
        MutantStack<int, std::list<int> > ms5(fifth); 
        MutantStack<int, std::list<int> > ms6(sixth); 
        MutantStack<int> ms7 = ms2;
        MutantStack<int, std::vector<int> > ms8 = ms4; 
        MutantStack<int, std::list<int> > ms9 = ms6; 
        MutantStack<int> ms10; 
        
        COUT << ENDL;
        SHOW_HEADER( 1a. PUSH OPERATION CHECK )
        ms1.push(999); COUT << "ms1" << ms1 << ENDL;
        ms2.push(999); COUT << "ms2" << ms2 << ENDL;
        ms3.push(999); COUT << "ms3" << ms3 << ENDL;
        ms4.push(999); COUT << "ms4" << ms4 << ENDL;
        ms5.push(999); COUT << "ms5" << ms5 << ENDL;
        ms6.push(999); COUT << "ms6" << ms6 << ENDL;
        ms7.push(999); COUT << "ms7" << ms7 << ENDL;
        ms8.push(999); COUT << "ms8" << ms8 << ENDL;
        ms9.push(999); COUT << "ms9" << ms9 << ENDL;
        ms10.push(999); COUT << "ms10" << ms10 << ENDL;
        
        COUT << ENDL;
        SHOW_HEADER( 1b. POP OPERATION CHECK )
        ms1.pop(); COUT << "ms1" << ms1 << ENDL;
        ms2.pop(); COUT << "ms2" << ms2 << ENDL;
        ms3.pop(); COUT << "ms3" << ms3 << ENDL;
        ms4.pop(); COUT << "ms4" << ms4 << ENDL;
        ms5.pop(); COUT << "ms5" << ms5 << ENDL;
        ms6.pop(); COUT << "ms6" << ms6 << ENDL;
        ms7.pop(); COUT << "ms7" << ms7 << ENDL;
        ms8.pop(); COUT << "ms8" << ms8 << ENDL;
        ms9.pop(); COUT << "ms9" << ms9 << ENDL;
        ms10.pop(); COUT << "ms10" << ms10 << ENDL;

        COUT << ENDL;
        SHOW_HEADER( 1c. POP OPERATION - EMPTY MUTANT STACK MS2 )
        while (!ms2.empty()) 
        {
            std::cout << ms2.top() << std::endl;
            ms2.pop();
        }
        COUT << "ms2" << ms2 << ENDL;
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
