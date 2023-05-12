/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:45 by cudoh             #+#    #+#             */
/*   Updated: 2023/05/13 00:41:02 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

int main(void)
{
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
    return (0);
}