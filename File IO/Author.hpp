//
//Author Class declaration
//

#ifndef AUTHOR_CLASS_DEF_H_
#define AUTHOR_CLASS_DEF_H_

class Author
{
private:
	int birthYear_; // birth year of the author
	int deathYear_; // death year of the author
	std::string name_; // name of the author

	bool hasData_; // variable to keep track of whether an object has been initialized by the user

	static int active_; //number of active author objects

public:
	//Constructor Destructor
	Author();
	~Author();

	//Mutators
	void setBirth(int); // set birth year
	void setDeath(int); // set death year
	void setName(std::string);// set name of author
	void modified(bool); // set modified flag

	//Accessors 
	const std::string getName(); // return name

	//Predicate Functions
	bool isEmpty(); // return if the object is empty
	int in_mem();// return number of object in memory
	void toCout(); // print object out

	//serialization implementation
	friend class boost::serialization::access;
	template<class archive>
	void serialize(archive & ar, const unsigned int version)
	{
		ar & birthYear_;
		ar & deathYear_;
		ar & name_;
		ar & hasData_;
	}
};

//Function prototypes for overloads
std::ostream& operator<<(std::ostream &out, Author &Auth);
std::istream& operator>>(std::istream &in, Author &Auth);


#endif 