/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:53:07 by ael-maar          #+#    #+#             */
/*   Updated: 2023/08/08 16:28:01 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT
#define CONTACT

#include <string>
class Contact
{
    private:
        std::string fname;
        std::string lname;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        std::string GetFname(void);
        std::string GetLname(void);
        std::string GetNickname(void);
        std::string GetPhoneNumber(void);
        std::string GetDarkestSecret(void);
        void SetFname(std::string NewFname);
        void SetLname(std::string NewLname);
        void SetNickname(std::string NewNickname);
        void SetPhoneNumber(std::string NewPhoneNumber);
        void SetDarkestSecret(std::string NewDarkestSecret);
};

#endif
