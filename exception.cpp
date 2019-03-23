#include "exception.hpp"

my_exception::my_exception(int CodeError, int linenum, std::string filename, std::string funcname, std::string message, my_exception *next)
		:CodeError_(CodeError_), linenum_(linenum), filename_(filename), funcname_(funcname), message_(message), next_(nullptr)
{
	if(next)
	{
		next_ = next;
	}
}

my_exception::~my_exception() 
{
	delete this->next_;
}

std::ostream & operator <<(std::ostream & os, const my_exception & except)
{
	os << "In file " << except.filename_ << std::endl;
	os << "In funclion " << except.funcname_ << std::endl;
	os << "Line is " << except.linenum_ << std::endl;
	
	const my_exception *current = &except;
	
	if(current -> message_.length())
		os << "Special message: " << current->message_;
		
	current = current -> next_;
	
	while(current)
	{
		if(current -> message_.length())
			os << ", because " << current->message_ << std::endl;
		
		current = current->next_;
	}
	
	return os;
}

void my_exception::freeException(my_exception * nexttofree)
{
	if(this->next_)
	{
		freeException(this->next_);
		delete this;
	}
	return;
}

