/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:42:30 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/08 15:52:31 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *argv[])
{
    if (ac > 1)
    {
        argv++;
        while (*argv)
        {
            std::string args = *argv;
            for (size_t i = 0; i < args.length(); i++)
                args[i] = std::toupper(args[i]);
            std::cout << args;
            argv++;
        }
        std::cout << std::endl;
        return (0);
    }
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
