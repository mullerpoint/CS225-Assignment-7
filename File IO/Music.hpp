//
//Music Class declaration
//

#ifndef MUSIC_CLASS_DEF_H_
#define MUSIC_CLASS_DEF_H_

#include "MediaItems.hpp"



class Music :
	public MediaItems
{
	//need to declare the Genre enum as public so it can be used in comparisons in other functions
	//Genre is declared first so that the atribute musicGENRE will be allowed
public:
	enum GENRE {
		ROC, COU, HIP, TEC, REG, OTHER, UDEF, END
	}; //enum of the music genre

private:
	std::string Producer_; //name_ of the producer of the music
	double minutes_; // time in minutes of the music
	//std::string sequel_;
	GENRE musicGENRE_; //genre enum

public:
	//Constructor Destructor
	Music();
	~Music();

	//Mutators
	virtual int setExecutive(std::string); //set producer
	int setrunTime(double);// set run time
	int setGENRE(GENRE UDEF); //set genre
	//int setSequel(MediaItems*);
	//int setSequel(std::string);

	//Accessors
	const std::string getProducer();// get producer
	const virtual double getrunTime();//get run time
	const Music::GENRE getGENRE();// get the genre
	std::string getSequel(); // get sequel string
	//const virtual int toCout();

	//predicate
	const int in_mem();// get number of items in memory
	int clear();// clear object
	std::string dispGENRE(Music::GENRE = Music::GENRE::OTHER); // return genre as a string
	std::string dispGENRESht(Music::GENRE = Music::GENRE::OTHER); // return genre as a short string
	std::ostream& output(std::ostream&); //custom output function for overloaded output operator

	//serialization implementation
	friend class boost::serialization::access;
	template<class archive>
	void serialize(archive & ar, const unsigned int version)
	{
		//serialize base class information
		ar & boost::serialization::base_object<MediaItems>(*this);
		ar & Producer_;
		ar & minutes_;
		ar & musicGENRE_;
	}

};

#endif 