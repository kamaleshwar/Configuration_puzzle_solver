/*
* Clock.h
*
* Authors: Kamaleshwar & Sumedha 
*/

#ifndef CLOCK_H
#define CLOCK_H
#include <vector>
#include<iostream>
#include"puzzle.h"
#include<cstdlib>

using namespace std;

class Clock :public puzzle<int>
{
	
private:
	int num_of_hours;
	int current_time;
	int goal_time;
	
public:

	 Clock(int total,int currtime,int goal):num_of_hours(total),current_time(currtime),
		goal_time(goal){};

	bool goalReached(int&);
	
	int getInitCongif();	

	vector<int> getNextAttempts(int&);
	
};

int Clock::getInitCongif()
	{
		if(this->current_time<=this->num_of_hours && this->current_time>0)
		{
			return (this->current_time);
		}
		else
		{
			cout<<"Invalid input time"<<endl;
			exit(1);
		}
		
	}
bool Clock::goalReached(int& config)
	{
	
		if(this->goal_time==config)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

//similar to the one explained in class 
vector<int>Clock::getNextAttempts(int& config)
	{
		vector<int> trials;
		int subsol1,subsol2;
		if(config>1 && config< num_of_hours)
		{
			subsol1=config-1;
			subsol2=config+1;
		}
		else
		{
			if(config==1)
			{
				subsol1=num_of_hours;
				subsol2=config+1;
			}
			else
			{
				subsol1=config-1;
				subsol2=1;
			}
		}

		trials.push_back(subsol1);
		trials.push_back(subsol2);
		return trials;
	}

#endif
