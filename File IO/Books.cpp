//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Books Class Implementation
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BOOKS_CLASS_IMPL_H_
#define BOOKS_CLASS_IMPL_H_

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
#include "Books.hpp"

//defines for default vaules and text output options
#define DEF_NAME ""
#define DEF_PRICE 0.00
#define DEF_PUB 1970
#define ELEMENT_ZERO 0
#define DEF_PAGES 0
#define DEF_PUB 1970
#define DEF_ISBN ""
#define DEF_SEQUEL ""
#define DEF_AUTH ""
#define TEXT_WIDTH 20

#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT(Books);

//Function prototype for insertion operator
std::ostream& operator<<(std::ostream &out, Books &Book);

//constructor
Books::Books() : MediaItems()
{
	setPages(DEF_PAGES);

	setInPrint(false);
	in_print_def_ = true;

	//setSequel(NULL);

	setISBN(DEF_ISBN);
	
	setSequel_str(DEF_SEQUEL);

	modified(false);
}

//destructor
Books::~Books()
{
	active_--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Mutators
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//set book page count - validate that the book doesnt have a negative page count
int Books::setPages(int new_pages)
{
	if (new_pages >= 0)
	{
		Books::pages_ = new_pages;
		Books::modified(true);
		return 0;
	}
	else
	{
		std::cout << "Please enter a valid positive page number.";
		return -1;
	}

}

//set book in print status
int Books::setInPrint(bool printStatus)
{
	in_print_ = printStatus;
	in_print_def_ = false;
	Books::modified(true);
	return 0;
}

//Set Sequel
//int Books::setSequel(Books* new_sequel)
//{
//	sequel_ = (*(new_sequel)).getName();
//
//	MediaItems::modified(true);
//	return 0;
//}
//
//int Books::setSequel_str(std::string new_sequel)
//{
//	Books::sequel_ = new_sequel;;
//
//	MediaItems::modified(true);
//	return 0;
//}

//set book isbn
int Books::setISBN(std::string new_isbn)
{
	Books::isbn_ = new_isbn;
	MediaItems::modified(true);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Accessors
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//get page count
const int Books::getPages()
{
	return pages_;
}

//get in print status
const bool Books::getInPrint()
{
	return in_print_;
}

//get if in print is default
const bool Books::getInPrintDef()
{
	return in_print_def_;
}

//get the sequel pointer
std::string Books::getSequel()
{
	return sequel_;
}

//get the isbn number
const std::string Books::getISBN()
{
	return isbn_;
}

////call overloaded print out function
//const int Books::toCout()
//{
//	std::cout << (*this);
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Predicate Functions
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//return the number of constructed items
const int Books::in_mem()
{
	return active_;
}

//clear book
int Books::clear()
{
	*this = Books();
	Books::active_ = Books::active_ - 2; //active is increased by two when calling the constructor
	return 0;
}


std::ostream& Books::output(std::ostream &out)
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
		if ((*this).getPages() == DEF_PAGES);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Page Count" << " : " << (*this).getPages() << std::endl;
		}

		//display print status if set
		if ((*this).getInPrintDef() == true);
		else if ((*this).getInPrintDef() == false)
		{
			if ((*this).getInPrint() == true)
			{
				out << std::left << std::setw(TEXT_WIDTH) << "  Print Status" << " : " << "In Print" << std::endl;
			}
			else
			{
				out << std::left << std::setw(TEXT_WIDTH) << "  Print Status" << " : " << "Out of Print" << std::endl;
			}
		}

		//display isbn
		if ((*this).getISBN() == DEF_ISBN);
		else if ((*this).getISBN() != DEF_ISBN)
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  ISBN" << " : " << (*this).getISBN() << std::endl;
		}

		//display sequel if set
		if ((*this).getSequel() == DEF_SEQUEL);
		else
		{
			out << std::left << std::setw(TEXT_WIDTH) << "  Sequel" << " : " << (*this).getSequel() << std::endl;
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