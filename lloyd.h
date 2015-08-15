/*
* lloyd.h
*
* Authors: Kamaleshwar & Sumedha 
*/
#ifndef LLOYD_H
#define LLOYD_H
#include<iostream>
#include<algorithm>
#include"puzzle.h"

using namespace std;

class lloyd:public puzzle< vector< vector<char> > >
{
	
private:
	vector< vector<char> > goal;
	vector< vector<char> > init;

public:
	lloyd();

	lloyd(vector< vector<char> >& initvec,vector< vector<char> >& goalvec)
	{
		this->init=initvec;
		this->goal=goalvec;		
	}

	bool goalReached(vector< vector<char> >&);
	vector< vector<char> > getInitCongif();
	vector< vector<vector<char> > > getNextAttempts(vector< vector<char> >&);

};

vector< vector<char> > lloyd::getInitCongif()
{
	return (this->init);
}

bool lloyd::goalReached(vector< vector<char> >& config)
{
	bool result=true;
	
	for(int i=0;i<goal.size();i++)
	{		
		for(int j=0;j<goal.at(i).size();j++)
		{
			if(config[i][j]!=goal[i][j])
			{
				result=false;
			}
		}
	}	

	return result;
}
vector< vector<vector<char> > > lloyd::getNextAttempts(vector< vector<char> >& config)
{
	
	vector< vector<vector<char> > > nextconfig;	
	vector<vector<char> > current(config);

	for(int i=0;i<config.size();i++)
	{		
		for(int j=0;j<config.at(i).size();j++)
		{	
				if((i-1)>=0)
				{						
					if(config[i][j]=='.')
					{
						current=config;
						swap(current[i][j],current[i-1][j]);					
						nextconfig.push_back(current);
					}
				}
				
				if((i+1)<config.size())
				{					
					if(config[i][j]=='.')
					{
						
						current=config;
						swap(current[i][j],current[i+1][j]);
						nextconfig.push_back(current);
					}
				}

				if((j+1)<config.at(i).size())
				{
					if(config[i][j]=='.')
					{
							current=config;
							swap(current[i][j],current[i][j+1]);
							nextconfig.push_back(current);
					}
				}

					if((j-1)>=0)
					{
						if(config[i][j]=='.')
						{
						current=config;						
						swap(current[i][j],current[i][j-1]);						
						nextconfig.push_back(current);
						}
					}				
			}
		}
		return nextconfig;
	}
	


#endif
