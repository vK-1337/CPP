#include <fstream>
#include <iostream>

int ft_replace(std::fstream &file, std::fstream &new_file, std::string pattern_to_find, std::string replacement, std::string filename);

int	main(int ac, char **av)
{
	std::fstream	my_file;
	std::fstream	new_file;

	if (ac > 4 || ac < 4)
	{
		std::cerr << "Wrong number of arguments." << std::endl;
		std::cerr << "Usage : ./custom_sed <filename> <String_to_replace> <Replacement_string>" << std::endl;
		return (1);
	}
	my_file.open(av[1], std::ios::in);
	if (!my_file)
    {
		std::cout << "File not found";
        new_file.close();
        return (1);
    }
	else
	{
        if (ft_replace(my_file, new_file, av[2], av[3], av[1]))
            return (my_file.close(), 1);
	}
	my_file.close();
	return (0);
}

int ft_replace(std::fstream &file, std::fstream &new_file, std::string pattern_to_find, std::string replacement, std::string filename)
{
    std::string file_content;
    std::string buffer;

    if (pattern_to_find.empty())
    {
        std::cout << "Pattern is empty" << std::endl;
        return (1);
    }
    while (1)
    {
        buffer = file.get();
        if (file.eof())
            break ;
        file_content.append(buffer);
    }
    std::size_t found;
    int i = 0;
    while (1)
    {
        found = file_content.find(pattern_to_find);
        if (found == std::string::npos)
            break ;
        else
        {
            file_content.erase(found, pattern_to_find.length());
            file_content.insert(found, replacement);
        }
        i++;
    }
    if (i > 0)
    {
        new_file.open(filename.append(".replace"), std::ios::out);
        if (!new_file)
        {
            std::cout << "File couldn't be created" << std::endl;
            return (1);
        }
        new_file << file_content;
        new_file.close();
    }
    else
        std::cout << "Pattern not found, replace file not created." << std::endl;
    return (0);
}
