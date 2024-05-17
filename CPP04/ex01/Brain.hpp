#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <iterator>
#include <string>

class Brain
{
    private:
    public:
        std::string _ideas[100];
        Brain();
        ~Brain();
        Brain(const Brain &rhs);
        Brain &operator=(const Brain& rhs);
        const std::string& getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};
#endif