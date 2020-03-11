#pragma once				//This line prevents circular dependency
#ifndef SAMPLE_CLASS_H		//This is the old way of preventing circular dependancy, be sure to use both ways
#define SAMPLE_CLASS_H		//Define should be class name in all caps, seperated by an underscore, with a capital H at the end

//Do all includes after the lines above
#include <string>

//Make sure to have this line to use strings
using std::string;

//Make sure all classes are inside a namespace to prevent naming conflicts
//Namespaces are similar to packages in Java
namespace Demo				
{
	//Use upper camel case for all class names
	//Capital letter for the beginning of each word
	class SampleClass
	{
	private:
		int myInteger;		//Use camel case for integers
		float myFloat;

	protected:
		double myDouble;
		string myString;

	public:
		SampleClass();
		SampleClass(int myInteger, float myFloat, double myDouble, string myString);
		~SampleClass();		//Make sure to have class destructors, even if not used

		//Use upper camel case for all function names
		//Capital letter for the beginning of each word
		string GetHelloWorld();		
		void TestFunction(int a, int b);
	};
}

#endif