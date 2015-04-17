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
	Author* auth_ptr_; // pointer to the author of the mediaitem object

	double price_; // price of the media item

	std::list<Elements>element_; // list of element pointers that are containend within the media item
	int element_count_;// the element number being worked on

	static int active_; // number of media items active

	std::string sequel_;

public:
	//Constructor Destructor
	MediaItems();
	virtual ~MediaItems();

	//Mutators
	int setName(std::string);
	int setPubYear(int);
	int setPrice(double);
	int addElement(int, int, std::string, int);
	int setAuthor(Author*);
	virtual int setSequel(MediaItems*);
	virtual int setSequel_str(std::string);
	virtual int modified(bool);
	
	//Accessors
	const std::string getName();
	const int getPubYear();
	const bool getPubYearDef();
	Author* getAuthor();
	const double getPrice();
	std::list<Elements> getElement();
	std::string getSequel();
	const int toCout();

	//Predicate Functions
	const virtual bool isEmpty();
	const int in_mem();
	virtual int clear();
	virtual std::ostream& output(std::ostream& out);

	//serialize implementation
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & hasData_;
		ar & name_;
		ar & pub_year_;
		ar & pub_year_def_;
		ar & auth_ptr_;
		ar & price_;
		//ar & element_;
		ar & element_count_;
		ar & active_;
		ar & sequel_;
	}
};

#endif 