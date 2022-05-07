#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    protected:
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    public :
        FragTrap( void );
        FragTrap( std::string name );
        FragTrap( FragTrap const & rhs);
        FragTrap & operator=( FragTrap const &rhs);
        virtual ~FragTrap( void );
        void highFivesGuys(void);
        int const & getAttackDamage( void ) const;
        int const & getEnergyPoints( void ) const;
        int const & getHitPoints( void ) const;
};

#endif
