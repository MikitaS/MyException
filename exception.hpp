#pragma once

#include <string>
#include <iostream>
#include "myCodeError.hpp"

class my_exception
{
public:
	my_exception(int CodeError, int linenum, std::string filename, std::string funcname, std::string message = "", my_exception *next = nullptr);
	~my_exception();
	
	
	friend std::ostream & operator <<(std::ostream & os, const my_exception & except);
	
private:

	void freeException(my_exception * nexttofree); 

	int CodeError_;
	
	std::string message_;
		
	int linenum_;
	std::string filename_;
	std::string funcname_;
	
	my_exception *next_;
};

	
#define THROW(Code, Next, Message)\
	throw new my_exception(Code, __LINE__, __FILE__, __FUNCTION__, Message, Next);
