//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Video Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VIDEOS_CLASS_IMPL_H_
#define VIDEOS_CLASS_IMPL_H_

//Header files standard libraries and classes
#ifndef MEDIA_DEPENDENCIES_CORE_H_
#define MEDIA_DEPENDENCIES_CORE_H_
#include <iostream> //default include
#include <string> // included to get strings to work
#include <locale> // included to get locale info for output
#include <io.h> // isatty for windows
//#include <unistd.h> // isatty  for linux
#include <iomanip> // included to make pretty output
#include <typeinfo> //included to use typeid()
#include <list> //included for use of list template
#include <vector> //included for use of vector template
#include <algorithm> //included to use sort()
#include <stdexcept> // include to derive from runtime_error
#include <cctype> //for isalpha()
#include <fstream> //for fopen and 
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/list.hpp>
#endif

// include header file
#include "Videos.hpp"

//defines for default vaules and text output options
#define DEF_NAME ""
#define DEF_PRICE 0.00
#define DEF_PUB 1970
#define ELEMENT_ZERO 0
#define DEF_DIRECTOR ""
#define DEF_RUNTIME 0.0
#define DEF_SEQUEL ""
#define DEF_AUTH ""
#define TEXT_WIDTH 20

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT(Videos);

//Function prototype for insertion operator
std::ostream& operator<<(std::ostream &out, Videos &Video);

//constructor
Videos::Videos() : MediaItems()
{
	Videos::setExecutive(DEF_DIRECTOR);
	Videos::setrunTime(DEF_RUNTIME);
	Videos::setSequel_str(DEF_SEQUEL);

	Videos::modified(false);
}

//destructor
Videos::~Videos()
{
	active_--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mutators
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Set video director
int Videos::setExecutive(std::string new_director_)
{
	Videos::director_ = new_director_;
	Videos::modified(true);
	return 0;
}

//Set Video Run time
int Videos::setrunTime(double new_runTime_)
{
	if (new_runTime_ >= 0)
	{
		Videos::runTime_ = new_runTime_;
		Videos::modified(true);
		return 0;
	}
	else
	{
		std::cout << "Please enter a positive run time";
		return -1;
	}
}

//Set Sequel
//int Videos::setSequel(Videos* new_sequel)
//{
//	sequel_ = (*(new_sequel)).getName();
//
//	MediaItems::modified(true);
//	return 0;
//}
//
//int Videos::setSequel_str(std::string new_sequel)
//{
//	sequel_ = new_sequel;;
//
//	MediaItems::modified(true);
//	return 0;
//}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Accessors
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//get director_
const std::string Videos::getdirector()
{
	return director_;
}

//get run time
const double Videos::getrunTime()
{
	return runTime_;
}

//get sequel pointer
std::string Videos::getSequel()
{
	return sequel_;
}

//const int Videos::toCout()
//{
//	std::cout << (*this);
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Predicate Functions
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//return the number of constructed items
const int Videos::in_mem()
{
	return active_;
}

int Videos::clear()
{
	(*this) = Videos();
	Videos::active_ = Videos::active_ - 1;
	return 0;
}

//over ride the base class fuction
std::ostream& Videos::output(std::ostream &out)
{
	//check if the item is empty
	if ((*this).isEmpty() == true); //if empty print nothing
	else if ((*this).isEmpty() == false) //if not empty print data thats available
	{
		// display item name_ if present
		if ((*this).getName() == DEF_NAME)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "Media Item Name" << " : " << "No Name Set" << std::endl;
		}
		else if ((*this).getName() != DEF_NAME)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "Media Item" << " : " << (*this).getName() << std::endl;
		}

		// print out the author object
		if ((*this).getAuthor() == DEF_AUTH);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << (((*this).getAuthor()));
		}

		//display publication year if set; check if the value is default
		if ((*this).getPubYearDef() == true);
		else if ((*this).getPubYearDef() == false)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Pub Year" << " : " << (*this).getPubYear() << std::endl;
		}

		//display price if set
		if ((*this).getPrice() == DEF_PRICE);
		else if ((*this).getPrice() != DEF_PRICE)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Price" << " : $" << std::fixed << (*this).getPrice() << std::endl;
		}

		//display director_ if set
		if ((*this).getdirector() == DEF_DIRECTOR);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Director" << " : " << (*this).getdirector() << std::endl;
		}

		//display runTime_ if set
		if ((*this).getrunTime() == DEF_RUNTIME);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Run Time" << " : " << (*this).getrunTime();
		}

		//display sequel if set
		if ((*this).getSequel() == DEF_SEQUEL);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Sequel" << " : " << (*this).getSequel();
		}

		//open an arbitrary scope for displaying the elements in the item
		{
			//copy the list to allow full access and protect the real list from accedental/intentional modification
			std::list<Elements>local_list = (*this).getElement();

			//display elements if they exist; 
			if (local_list.empty() == true); // check if the list is empty
			else //if ((local_list.empty() == false)
			{
				//for loop to cycle through all the elements in local_list
				for (Elements elem : local_list)
				{
					out << elem;
				}//for

			}//else
		}//close scope
	}//else if
	return out;
}//close overload


#endif 