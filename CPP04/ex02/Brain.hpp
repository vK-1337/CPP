#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain &rhs);
        Brain &operator=(const Brain& rhs);
        const std::string& getIdea(int index) const;
        void setIdea(int index, const std::string& idea);
};
#endif