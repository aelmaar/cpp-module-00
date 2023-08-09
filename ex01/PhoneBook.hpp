/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:17:07 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/09 16:03:23 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK

#include "Contact.hpp"
#include <cctype>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook
{
  // data members
  private:
    int contact_size;
    int contact_pos;
    Contact contacts[8];
    void  AddField(std::string message, void (Contact::*AddToContact)(std::string), Contact* contact);
    void  PrintField(std::string field);
    void  PrintContacts(int contact_size);
    void  PrintInfoContact(Contact *contact);
  
  public:
  // constructor
    PhoneBook();
  // function members
    void  Add();
    void  Search();
};

#endif
