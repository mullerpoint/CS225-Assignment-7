//
//Elements Class declaration
//

#ifndef ELEMENTS_CLASS_DEF_H_
#define ELEMENTS_CLASS_DEF_H_

class Elements
{
private:
	int start_; //starting location of the element
	int end_; // ending location of the element
	std::string name_; //name of the element

	bool hasData_; // variable to keep track of whether an object has been initialized by the user

	static int active_; // number of elements active

public:
	//Constructor Destructor
	Elements();
	~Elements();

	//Mutators
	void setStart(int); // set start 
	void setEnd(int); // set end
	void setName(std::string); // set element name
	void modified(bool); // set modified flag

	//Accessors
	int getStart(); //get start
	int getEnd(); //get end
	std::string getName(); //get name

	//Predicate Functions
	bool isEmpty(); // get if the element is empty
	int in_mem(); //get number of objects in memory
	void toCout(); // print object out

	//serialization implementation
	friend class boost::serialization::access;
	template<class archive>
	void serialize(archive & ar, const unsigned int version)
	{
		ar & start_;
		ar & end_;
		ar & name_;
		ar & hasData_;
	}
	
};

//Function prototype for overload
std::ostream& operator<<(std::ostream &out, Elements &Elem);

#endif 