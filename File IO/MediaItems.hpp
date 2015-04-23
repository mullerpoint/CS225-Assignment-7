//
//Media Item Class declaration
//
#ifndef MEDIAITEMS_CLASS_DEF_H_
#define MEDIAITEMS_CLASS_DEF_H_



#ifndef MEDIA_DEPENDENCIES_H_
#define MEDIA_DEPENDENCIES_H_
#include "Author.hpp"
#include "Elements.hpp"
#endif

class MediaItems
{
private:

	bool hasData_; // variable to keep track of whether an object has been initialized by the user

protected:
	std::string name_; //name_ of the media item
	int pub_year_; // publication year of the media item
	bool pub_year_def_; // if the publicaiton year is default
	std::string auth_name_; // pointer to the author of the mediaitem object

	double price_; // price of the media item

	std::list<Elements>element_; // list of element pointers that are containend within the media item
	int element_count_;// the element number being worked on

	static int active_; // number of media items active

	std::string sequel_; //sequel string

public:
	//Constructor Destructor
	MediaItems(); // constructor
	virtual ~MediaItems(); // destructor

	//Mutators
	int setName(std::string); //set the name
	int setPubYear(int);// set publication year
	int setPrice(double);// set price
	int addElement(int, int, std::string, int); // add an element to the list
	int setAuthor(Author*);//set author name
	virtual int setSequel(MediaItems*);// set sequel name from pointer
	virtual int setSequel_str(std::string);// set sequel name from string
	virtual int modified(bool); // set modified flag
	
	//Accessors
	const std::string getName(); // get name
	const int getPubYear(); // get pulication year
	const bool getPubYearDef(); // get if the publication year is default
	std::string getAuthor(); // get author name
	const double getPrice(); // get price
	std::list<Elements> getElement();// get the element list
	std::string getSequel(); //get sequel name
	const int toCout(); // print object out

	//Predicate Functions
	const virtual bool isEmpty();// returns if the object is empty
	const int in_mem();//returns number of objects in memory
	virtual int clear();// clears object
	virtual std::ostream& output(std::ostream& out); //custom output function for overloaded output operator

	//serialize implementation
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & hasData_;
		ar & name_;
		ar & pub_year_;
		ar & pub_year_def_;
		ar & auth_name_;
		ar & price_;
		ar & element_;
		ar & element_count_;
		ar & active_;
		ar & sequel_;
	}
};

#endif 