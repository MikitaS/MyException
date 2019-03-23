#include <iostream>
#include <fstream>

#include "exception.hpp"

using namespace std;

void First();
void Second();
void Third();
void Last();

void First()
{
    try
    {
        Second();
    }
    catch (my_exception *exception)
    {
		THROW(1, exception, " first reason ");
    }
}

void Second()
{
    try
    {
        Third();
    }
    catch (my_exception *exception)
    {
		THROW(1, exception, " second reason ");
    }
}


void Third()
{
    try
    {
        Last();
    }
    catch (my_exception *exception)
    {
		THROW(1, exception, " third reason ");
    }
}

void Last()
{
	THROW(1, nullptr, " last reason ");
}

int main()
{
    try
    {
        First();
    }
    catch (my_exception *exception)
    {
        cout << *exception;
        delete exception;
    }

    return 0;
}
