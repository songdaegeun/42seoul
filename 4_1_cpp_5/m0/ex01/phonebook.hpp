/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_numberbook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:35:06 by prossi            #+#    #+#             */
/*   Updated: 2024/03/05 18:37:11 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

class Contact
{
public:
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;
	std::string		darkest_secret;
	std::string		phone_number;
};

class PhoneBook
{
public:
	Contact contact_arr[8];
	int		size;
};

#endif
