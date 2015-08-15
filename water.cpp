/*
* water.cpp
*
* Authors: Kamaleshwar & Sumedha 
*/
#include<iostream>
#include"Solver.h"
#include<cstdlib>
#include "water.h"

using namespace std;

	
	int main(int argc, const char * argv[])
	{		
		if(argc<3)
		{			
			cout<<"Invalid number of inputs"<<endl;
		}
		else
		{
			vector< vector<int> > sol;

			water wt( argv,argc);
			sol=Solver::solve(wt);		
			
			if(!sol.empty())
			{				

				for(int i=0;i<sol.size();i++)
				{
					cout<<"step "<<i<<endl;
					for(int j=0;j<sol.at(i).size();j++)
					{					
						cout<<sol.at(i).at(j)<<" ";
											
					}
					cout<<endl;
				}
			}
			else
			{				
				cout<<"no solution found for the provided configuration"<<endl;
				
			}
		}
		
	};
