#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project2.h"
#include <iostream>

using namespace std;

bool double_equals(double a, double b, double epsilon=0.001){
	return abs(a-b) < epsilon;

}


void best_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space){

	assignment.clear();
	free_space.clear();

	double free_mem[items.size()];	
	double bin_capacity=1;
	int bin_used=0;
	int idx=0;

	for (int i=0;i<items.size();++i){
		int j=bin_used;
		double min =10;

		for (int k=0; k < bin_used ; k++){
			if( double_equals(free_mem[k], items[i])|| (free_mem[k]>items[i]))
			{
				double check=free_mem[k]-items[i];
				if ( double_equals(check, min) || (check <min)){
					min=check;
					idx=k;
			
				}
				j=0;
			}

		}

		if (j==bin_used)
		{
			free_mem[j]=bin_capacity-items[i];
			bin_used++;
			assignment.push_back(j+1);
		}else{
			assignment.push_back(idx+1);
			double free_memory=abs(free_mem[idx]-items[i]);
			free_memory < 0.001? free_mem[idx]=0:free_mem[idx]=free_memory;
		
		}
	}

	for (int i=0; i< bin_used ;++i){
		free_space.push_back(free_mem[i]);

	}

}
