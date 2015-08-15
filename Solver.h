/*
* Solver.h
*
* Authors: Kamaleshwar & Sumedha 
*/
#ifndef SOLVER_H
#define SOLVER_H

#include<vector>
#include<queue>
#include<map>
#include"puzzle.h"
using namespace std;


namespace Solver{

	//similar to the one explained in class
	
	template<typename T>	
	vector<T> solve(puzzle<T> &puzzle)
	{
		typedef typename::puzzle<T>::config config; 
		vector<config> current;
		queue< vector<config> > configQueue;
		map<config,config> visited;
		vector<config> nextConfig;
		vector<config> InitConfig;
		InitConfig.push_back(puzzle.getInitCongif());
		vector<config> subsol;
		vector<config> solution;
		
		configQueue.push(InitConfig);
		visited[puzzle.getInitCongif()]=puzzle.getInitCongif();		
		if(puzzle.goalReached(InitConfig.front()))
		{	
			solution.push_back(InitConfig.front());
			return (solution);
		}
		while(!configQueue.empty())
		{
			current=configQueue.front();
			
			configQueue.pop();

			nextConfig=puzzle.getNextAttempts(current.back());
			
			for(typename vector<config>::iterator it=nextConfig.begin();it!=nextConfig.end();++it)
			{
					
				if(visited.find(*it)==visited.end())
				{
					
					visited[*it]=*it;
					subsol.clear();
					
					subsol.insert(subsol.end(),current.begin(),current.end());
						subsol.push_back(*it);
					
					if(puzzle.goalReached(*it))
					{						
						
						solution.insert(solution.end(),subsol.begin(),subsol.end());
						
						return solution;
						
					}
					else
					{	
						configQueue.push(subsol);
						
					}

				}
			}
			
		}		
		
		return solution;
	}
}
#endif
