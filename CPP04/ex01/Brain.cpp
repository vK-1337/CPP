#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "A Brain has been created" << std::endl;
    return;
}

Brain::~Brain()
{
    std::cout << "A Brain has been destroyed" << std::endl;
    return;
}

Brain::Brain(const Brain &rhs)
{
    *this = rhs;
    std::cout << "Brain copy constructor called" << std::endl;
    return;
}

Brain&   Brain::operator=( const Brain& rhs ) {
    copy(rhs._ideas->begin(), rhs._ideas->end(), this->_ideas->begin());
    std::cout << "Brain ideas has been copied with copy assignement operator." << std::endl;
    return *this;
}