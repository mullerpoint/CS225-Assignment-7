//
//Video Class declaration
//

#ifndef VIDEOS_CLASS_DEF_H_
#define VIDEOS_CLASS_DEF_H_

#include "MediaItems.hpp"
class Videos :
	public MediaItems
{
private:
	std::string director_; //name_ of the director of the video
	double runTime_; //runtime of the video

	//std::string sequel_; //pointer to the sequel video item

public:
	//Constructor Destructor
	Videos();
	virtual ~Videos();

	//Mutators
	virtual int setExecutive(std::string);
	int setrunTime(double);
	//int setSequel(Videos*);
	//int setSequel_str(std::string);

	//accessors
	const std::string getdirector();
	const double getrunTime();
	std::string getSequel();
	//const int toCout();

	//predicate
	const int in_mem();
	int clear();
	std::ostream& output(std::ostream&);

	//serialization implementation
	friend class boost::serialization::access;
	template<class archive>
	void serialize(archive & ar, const unsigned int version)
	{
		//serialize base class information
		ar & boost::serialization::base_object<MediaItems>(*this);
		ar & director_;
		ar & runTime_;
	}

};

#endif 