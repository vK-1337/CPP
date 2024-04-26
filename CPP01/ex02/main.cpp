#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN" ;

    std::string *stringPTR;
    stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Brain variable address : [" << &brain << "]" << std::endl;
    std::cout << "StringPTR address : [" << stringPTR << "]" << std::endl;
    std::cout << "StringREF address : [" << &stringREF << "]" << std::endl << std::endl;

    std::cout << "Brain's variable value : " << brain << std::endl;
    std::cout << "StringPTR's pointed value : " << *stringPTR << std::endl;
    std::cout << "StringREF's pointed value : " << stringREF << std::endl;

    return (0);
}