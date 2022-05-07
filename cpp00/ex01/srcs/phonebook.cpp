#include "phonebook.hpp"

contact::contact(void) : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
    std::cout << "constructor called - contact created" << std::endl;
    return ;
}

contact::~contact(void)
{
    std::cout << "destructor called - contact destroyed" << std::endl;
    return ;
}

std::string contact::getFirstName() const
{
    return this->_firstName;
}

void contact::setFirstName(std::string data)
{
    this->_firstName = data;
}

std::string contact::getLastName() const
{
    return this->_lastName;
}

void contact::setLastName(std::string data)
{
    this->_lastName = data;
}

std::string contact::getNickName() const
{
    return this->_nickname;
}

void contact::setNickName(std::string data)
{
    this->_nickname = data;
}

std::string contact::getPhoneNumber() const
{
    return this->_phoneNumber;
}

void contact::setPhoneNumber(std::string data)
{
    this->_phoneNumber = data;
}

std::string contact::getDarkestSecret() const
{
    return this->_darkestSecret;
}

void contact::setDarkestSecret(std::string data)
{
    this->_darkestSecret = data;
}

PhoneBook::PhoneBook(void) : index(0), _contactNb(0)
{
    std::cout << "constructor called - PhoneBook created" << std::endl;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "destructor called - PhoneBook destroyed" << std::endl;
    return ;
}

void    contact::printContact(std::string str)
{
    int spaces(0);

    spaces = 10 - str.length();
    for (int x = 0; x < spaces; x++)
        std::cout << " ";
    if (str.length() <= 10)
        std::cout << str;
    else
        std::cout << str.substr(0, 9) << ".";
}

void PhoneBook::promptForIndex(std::string input) const
{
    while (!std::cin.eof())
    {
        std::cout << "Please enter index for contact details" << std::endl;
	    getline(std::cin, input);
        if (input.length() == 1 and input != "" and _contactNb > 0 and input.at(0) >= 48 and input.at(0) <= 48 + _contactNb - 1)
        {
            std::cout << "     index|     " << input.at(0) << std::endl;
            std::cout << "first name|     " << this->_ind[input.at(0) - 48].getFirstName() << std::endl;
            std::cout << " last name|     " << this->_ind[input.at(0) - 48].getLastName() << std::endl;
            std::cout << " nickname |     " << this->_ind[input.at(0) - 48].getNickName() << std::endl;
            std::cout << "phone num.|     " << this->_ind[input.at(0) - 48].getPhoneNumber() << std::endl;
            std::cout << "darkest s.|     " << this->_ind[input.at(0) - 48].getDarkestSecret() << std::endl;
            return ;
        }
        else
        {
            std::cout << "Index must range from 0 to " << _contactNb - 1 << std::endl;
            return promptForIndex(input);
        }
    }
}

void PhoneBook::doPrint(PhoneBook *tmp) const
{
    int i = 0;

	
	if (!_contactNb)
	{
    	std::cout << "Phonebook is empty!" << std::endl;
        return ;
    }
	std::cout << "     index|" << "first name|" << " last name|" \
        << "  nickname" << std::endl;
    for (i = 0; i < tmp->_contactNb; i++)
    {
        std::cout << "         " << i << "|";
        tmp->_ind[i].printContact(tmp->_ind[i].getFirstName());
        std::cout << "|";
        tmp->_ind[i].printContact(tmp->_ind[i].getLastName());
        std::cout << "|";
        tmp->_ind[i].printContact(tmp->_ind[i].getNickName());
        std::cout << std::endl;
    }
    promptForIndex("");
}

int PhoneBook::do_add(PhoneBook *ind)
{
    std::string input("");

    if (ind->_contactNb != 8)
        ind->_contactNb++;
    if (ind->index == 8)
        ind->index = 0;
    while (!std::cin.eof() and input == "")
    {
	    std::cout << "Please enter first name" << std::endl;
    	getline(std::cin, input);
    }
    ind->_ind[ind->index].setFirstName(input);
    input = "";
    while (!std::cin.eof() and input == "")
    {
        std::cout << "Please enter last name" << std::endl;
        getline(std::cin, input);
    }
    ind->_ind[ind->index].setLastName(input);
    input = "";
    while (!std::cin.eof() and input == "")
    {
        std::cout << "Please enter nickname" << std::endl;
        getline(std::cin, input);
    }
    ind->_ind[ind->index].setNickName(input);
    input = "";
    while (!std::cin.eof() and input == "")
    {
        std::cout << "Please enter phone number" << std::endl;
        getline(std::cin, input);
    }
    ind->_ind[ind->index].setPhoneNumber(input);
    input = "";
    while (!std::cin.eof() and input == "")
    {
        std::cout << "Please enter darkest secret" << std::endl;
        getline(std::cin, input);
    }
    ind->_ind[ind->index].setDarkestSecret(input);
    ind->index++;
    return 0;
}