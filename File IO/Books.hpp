//
//Book Class declaration
//

#ifndef BOOKS_CLASS_DEF_H_
#define BOOKS_CLASS_DEF_H_

#include "MediaItems.hpp"
class Books :
	public MediaItems
{
private:
	std::string isbn_; //string of the book ISBN
	int pages_; //pages in the book
	bool in_print_; // if the book is still in print or not
	bool in_print_def_; // if the in_print variable has been set
	//std::string sequel_; // pointer to the sequel book item


public:
	//Constructor Destructor
	Books();
	virtual ~Books();

	//Mutators
	int setPages(int);
	int setInPrint(bool);
	//int setSequel(Books*);
	//int setSequel_str(std::string);
	int setISBN(std::string);

	//Accessors
	const int getPages();
	const bool getInPrint();
	const bool getInPrintDef();
	std::string getSequel();
	const std::string getISBN();
	//const int toCout();

	//predicate
	const int in_mem();
	int clear();
	std::ostream& output(std::ostream &out);

	//serialization implementation
	friend class boost::serialization::access;
	template<class archive>
	void serialize(archive & ar, const unsigned int version)
	{
		//serialize base class information
		ar & boost::serialization::base_object<MediaItems>(*this);
		ar & isbn_;
		ar & pages_;
		ar & in_print_;
		ar & in_print_def_;
	}

};

#endif 