#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap one("claptrap_one");
    ClapTrap two(one);

    std::cout << std::endl;
    one.attack(two.getName());
    two.takeDamage(one.getAttackDamage());
    two.beRepaired(two.getEnergyPoints());
    std::cout << std::endl;
    return 0;
}