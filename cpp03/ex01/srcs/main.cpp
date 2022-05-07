#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap one("claptrap_one");
    ScavTrap three("scavtrap_one");

    std::cout << std::endl;
    one.attack(three.getName());
    three.takeDamage(one.getAttackDamage());
    three.beRepaired(three.getEnergyPoints());
    std::cout << std::endl;
    return 0;
}