/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:17:15 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/08 16:30:24 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::GetFname(void)
{
    return (fname);
}

std::string Contact::GetLname(void)
{
    return (lname);
}

std::string Contact::GetNickname(void)
{
    return (nickname);
}

std::string Contact::GetPhoneNumber(void)
{
    return (phone_number);
}

std::string Contact::GetDarkestSecret(void)
{
    return (darkest_secret);
}

void Contact::SetFname(std::string NewFname)
{
    fname = NewFname;
}

void Contact::SetLname(std::string NewLname)
{
    lname = NewLname;
}

void Contact::SetNickname(std::string NewNickname)
{
    nickname = NewNickname;
}

void Contact::SetPhoneNumber(std::string NewPhoneNumber)
{
    phone_number = NewPhoneNumber;
}

void Contact::SetDarkestSecret(std::string NewDarkestSecret)
{
    darkest_secret = NewDarkestSecret;
}
