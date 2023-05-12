/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:51:45 by cudoh             #+#    #+#             */
/*   Updated: 2023/03/12 15:55:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

int main(void)
{
    /* easyfind */
    SHOW_HEADER(=== TEST : SUBJECT_FILE ===)
    {
        try
        {
            std::vector<int> vec(5, 20);
            vec.push_back(56);
            easyFind< std::vector<int> >(vec, 5);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

     /* easyfind */
    SHOW_HEADER(=== TEST : SUBJECT_FILE ===)
    {
        try
        {
            std::vector<int> vec(5, 20);
            vec.push_back(56);
            easyFind< std::vector<int> >(vec, 56);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return (0);
}