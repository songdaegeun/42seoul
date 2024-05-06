#include "phonebook.hpp"
#include "iostream"
#include <string>

void	put_field(std::string str)
{
	std::cout << "|";
	if (str.size() > 10)
	{
		str.resize(9);
		std::cout << str;
		std::cout << ".";
	}
	else
		std::cout << str;
}

int	main(void)
{
	PhoneBook PB;
	PB.size = 0;
	std::string	cmd;

	while (1)
	{
		system("clear");
		std::cout << "[ADD / SEARCH / EXIT]" << std::endl;
		std::cin >> cmd;
		
		if (cmd == "ADD")
		{
			system("clear");	
			for (int i = PB.size - 1; i >= 0; i--) {
				if(i+1 == 8)
					continue;
				PB.contact_arr[i+1] = PB.contact_arr[i];
			}	
			if (PB.size < 8)
				PB.size++;
			std::cout << "first name: ";
			std::cin >> PB.contact_arr[0].first_name;
			if(PB.contact_arr[0].first_name.empty()) {
				return (0);
			}
			while (PB.contact_arr[0].first_name.size() < 10)
				PB.contact_arr[0].first_name = " " + PB.contact_arr[0].first_name;
			system("clear");

			std::cout << "last name: ";
			std::cin >> PB.contact_arr[0].last_name;
			if(PB.contact_arr[0].last_name.empty()) {
				return (0);
			}
			while (PB.contact_arr[0].last_name.size() < 10)
				PB.contact_arr[0].last_name = " " + PB.contact_arr[0].last_name;
			system("clear");

			std::cout << "nick name: ";
			std::cin >> PB.contact_arr[0].nickname;
			if(PB.contact_arr[0].nickname.empty()) {
				return (0);
			}
			while (PB.contact_arr[0].nickname.size() < 10)
				PB.contact_arr[0].nickname = " " + PB.contact_arr[0].nickname;
			system("clear");

			std::cout << "phone number: ";
			std::cin >> PB.contact_arr[0].phone_number;
			if(PB.contact_arr[0].phone_number.empty()) {
				return (0);
			}
			while (PB.contact_arr[0].phone_number.size() < 10)
				PB.contact_arr[0].phone_number = " " + PB.contact_arr[0].phone_number;
			system("clear");

			std::cout << "darkest secret: ";
			std::cin >> PB.contact_arr[0].darkest_secret;
			if(PB.contact_arr[0].darkest_secret.empty()) {
				return (0);
			}
			while (PB.contact_arr[0].darkest_secret.size() < 10)
				PB.contact_arr[0].darkest_secret = " " + PB.contact_arr[0].darkest_secret;
		}
		else if (cmd == "SEARCH")
		{
			for (int i = 0; i < PB.size; i++)
			{
				std::cout << "[" << i + 1 << "]";
				put_field(PB.contact_arr[i].first_name);
				put_field(PB.contact_arr[i].last_name);
				put_field(PB.contact_arr[i].nickname);
				std::cout << "|" << std::endl;
			}
			int	idx;
			std::cout << "================select [idx]================\n";
			std::cin >> idx;
			idx--;
			system("clear");

			if (idx >= 0 && idx < PB.size)
			{
				std::cout << "first_name: " << PB.contact_arr[idx].first_name << std::endl;
				std::cout << "last_name: " << PB.contact_arr[idx].last_name << std::endl;
				std::cout << "nickname: " << PB.contact_arr[idx].nickname << std::endl;
				std::cout << "phone_number: " << PB.contact_arr[idx].phone_number << std::endl;
				std::cout << "darkest_secret: " << PB.contact_arr[idx].darkest_secret << std::endl;
			}
			else
			{
				std::cout << "invalid" << std::endl;
				return (0);
			}
			while (1)
			{
				std::cout << "================Type 'b' to back================" << std::endl;
				std::cin >> cmd;
				if (cmd == "b")
					break ;
			}
		}
		else if (cmd == "EXIT" )
			break ;
	}
}