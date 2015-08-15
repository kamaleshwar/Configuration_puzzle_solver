/*
* puzzle.h
*
* Authors: Kamaleshwar & Sumedha 
*/

#ifndef PUZZLE_H
#define PUZZLE_H
#include<vector>

using namespace std;

template <class T>
class puzzle
{
	
public:
	typedef T config;
	virtual vector<config> getNextAttempts(config&)=0; 	
	virtual bool goalReached(config&)=0;
	virtual config getInitCongif()=0;
	virtual ~puzzle() {};
	
};
#endif
