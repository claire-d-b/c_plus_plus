#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap()
{
    FragTrap::_hitPoints = 100;
    FragTrap::_energyPoints = 100;
    FragTrap::_attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap(name)
{
    FragTrap::_hitPoints = 100;
    FragTrap::_energyPoints = 100;
    FragTrap::_attackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap const & rhs) : ClapTrap(rhs)
{
    *this = rhs;
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const &rhs)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    _name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;
    return *this;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap destructor called" << std::endl;
}

int const & FragTrap::getAttackDamage( void ) const
{
    return _attackDamage;
}

int const & FragTrap::getEnergyPoints( void ) const
{
    return _energyPoints;
}

int const & FragTrap::getHitPoints( void ) const
{
    return _hitPoints;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " sends a positive high fives request! " << std::endl;
}