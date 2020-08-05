#include "exception.h"

Exception::Exception(std::string message) {
	this->message = message;
}

std::string Exception::getMessage()
{
	return message;
}
