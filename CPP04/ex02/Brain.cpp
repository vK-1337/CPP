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
    if ( this != &rhs)
    {
        for (int i = 0; i < 100; i++)
        {
            if (!rhs._ideas[i].empty())
                this->_ideas[i] = rhs._ideas[i];
        }
    }
    std::cout << "Brain ideas has been copied with copy assignement operator." << std::endl;
    return *this;
}

const std::string& Brain::getIdea(int index) const
{
    if (index < 0 || index > 100)
    {
        std::cout << "Wrong index ! Possible indexes : [0] ... [100] included." << std::endl;
        return NULL;
    }
    return _ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index < 0 || index > 100)
    {
        std::cout << "Wrong index ! Possible indexes : [0] ... [100] included." << std::endl;
        return;
    }
    _ideas[index] = idea;
    return;
}