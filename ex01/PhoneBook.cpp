/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:17:10 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/09 18:13:26 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Contructor implementation
PhoneBook::PhoneBook()
{
  contact_size = 0;
  contact_pos = -1;
}

void  PhoneBook::PrintField(std::string field)
{
  if (field.length() > 10) {
      std::cout << std::right << std::setw(9) << field.substr(0, 10 - 1) << ".";
  } else {
      std::cout << std::right << std::setw(10) << field;
  }
  std::cout << "|";
}

void  PhoneBook::PrintContacts(int contact_size)
{
  std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name"
                  << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname"
                  << "|" << std::endl;
  for (int i = 0; i < contact_size; i++)
  {
    std::ostringstream oss;
    oss << i;
    std::cout << "|";
    PrintField(oss.str());
    PrintField(contacts[i].GetFname());
    PrintField(contacts[i].GetLname());
    PrintField(contacts[i].GetNickname());
    std::cout << std::endl;
  }
}

void  PhoneBook::PrintInfoContact(Contact *contact)
{
  std::cout << "The first name: " << contact->GetFname() << std::endl;
  std::cout << "The last name: " << contact->GetLname() << std::endl;
  std::cout << "The nickname: " << contact->GetNickname() << std::endl;
  std::cout << "The phone number: " << contact->GetPhoneNumber() << std::endl;
  std::cout << "The darkest secret: " << contact->GetDarkestSecret() << std::endl;
}

void PhoneBook::AddField(std::string message, void (Contact::*AddToContact)(std::string), Contact* contact)
{
    std::string field;
    while (field.empty())
    {
        std::cout << message << ": ";
        std::getline(std::cin, field);
        if (field.empty())
            std::cout << "Please fill the field" << std::endl;
        else
            (contact->*AddToContact)(field);
    }
}

// ADD COMMAND
void PhoneBook:: Add()
{
    if ((contact_pos + 1) == 8)
        contact_pos = -1;
    contact_pos++;
    AddField("Enter your first name", &Contact::SetFname, &(contacts[contact_pos]));
    AddField("Enter your last name", &Contact::SetLname, &(contacts[contact_pos]));
    AddField("Enter your nickname", &Contact::SetNickname, &(contacts[contact_pos]));
    AddField("Enter your phone number", &Contact::SetPhoneNumber, &(contacts[contact_pos]));
    AddField("Enter your darkest secret", &Contact::SetDarkestSecret, &(contacts[contact_pos]));
    if (contact_size != 8)
      contact_size++;
}

// SEARCH COMMAND
void  PhoneBook:: Search()
{
  std::string contact_index;
  bool  is_valid_index;

  if (contact_size > 0)
  {
    PrintContacts(contact_size);
    is_valid_index = false;
    // check if the input is only numeric or the index is out of range
    while (!is_valid_index)
    {
      std::cout << "Enter the contact index: ";
      getline(std::cin, contact_index);
      if ((contact_index.length() == 1)
        && isdigit(contact_index[0])
        && (int(contact_index[0]) - 48) < contact_size)
        is_valid_index = true;
      if (!is_valid_index)
        std::cout << "Please enter a valid index" << std::endl;
    }
    PrintInfoContact(&(contacts[std::atoi(contact_index.c_str())]));
  }
  else
    std::cout << "There are no contacts in the phone book" << std::endl;
}
