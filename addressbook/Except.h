#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Except: public exception
{
public:

	Except(const string& message):msg(message) {
	}
  virtual const char* what() const throw()
  {
    //return (const char*)&msg;
    return msg.c_str();
    //return &msg;
  }
private:
	string msg;
	//char msg;
};