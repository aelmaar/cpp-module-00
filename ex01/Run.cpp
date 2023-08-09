/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Run.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:17:18 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/09 16:45:25 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Please enter a command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.Add();
        else if (command == "SEARCH")
            phonebook.Search();
        else if (command == "EXIT")
            break;
        else
            std::cout << "\nPlease enter a valid command" << std::endl;
    }

    return (0);
}