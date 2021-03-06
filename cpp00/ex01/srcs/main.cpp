#include "phonebook.hpp"

int main(void)
{
    std::string  line;
    PhoneBook individuals;

    while (!std::cin.eof())
    {
        std::cout << "Please type a command" << std::endl;
        getline(std::cin, line);
        if (line == "ADD")
            individuals.do_add(&individuals);
        else if (line == "EXIT")
            return 0;
        else if (line == "SEARCH")
			individuals.doPrint(&individuals);
        else
            std::cout << "Wrong entry" << std::endl;
    }
    return 1;
}
