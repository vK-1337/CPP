#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <algorithm>

typedef enum e_errors
{
  OK,
	BAD_FORMAT,
	BAD_DATE,
	NEG_NUMBER,
  OVERFLOW
}						t_errors;

class MyException : public std::exception {
private:
    char *msg;

public:
    MyException(const char *message) {
        msg = new char[std::strlen(message) + 1];
        std::strcpy(msg, message);
    }

    virtual const char* what() const throw() {
        return msg;
    }

    virtual ~MyException() throw() {
        delete[] msg;
    }
};

std::multimap<std::string, float> fillMapWithCsv(void);
std::multimap<std::string, float> fillMapWithInput(char *map_path);
int verify_first_line_input(std::string buffer);
std::string check_input(std::string buffer);
int bad_date(std::string date);
