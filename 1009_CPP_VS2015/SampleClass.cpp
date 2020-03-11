#include "SampleClass.h"
#include <iostream>

//using namespace std;		//Never do this, only use the items that you need in the iostream library

//Do this instead
using std::cin;
using std::cout;
using std::endl;

namespace Demo
{
	//Assign default values like this
	SampleClass::SampleClass()
		: myInteger(1), myFloat(1.0f), myDouble(1.0), myString("Hello")
	{

	}

	//Always initialise attributes like this, unless they require error checking
	SampleClass::SampleClass(int myInteger, float myFloat, double myDouble, string myString)
		: myFloat(myFloat), myDouble(myDouble), myString(myString)
	{
		//Only set attributes here if they require error checking
		if (myInteger < 0)
			this->myInteger = 0;
		else
			this->myInteger = myInteger;
	}

	SampleClass::~SampleClass()
	{

	}

	/**
	* Returns the string hello world
	*
	* @return			Returns a "Hello world!" string
	*/
	string SampleClass::GetHelloWorld()
	{
		return "Hello world!";
	}

	/**
	* This is a test function
	*
	* @param a			An integer which does nothing
	* @param b			An integer which also does nothing
	*/
	void SampleClass::TestFunction(int a, int b)
	{
		//Use static casts to cast variables
		float exampleCast = static_cast<float>(a);

		//Do not use c style casts
		//float exampleCast = (float)a;

		cout << "Test" << endl;
	}
}
