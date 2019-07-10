#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project2.h"

using namespace std;

bool double_equal(double a, double b, double epsilon=0.001){
	return abs(a-b) < epsilon;

}


void first_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space){

	assignment.clear();
	free_space.clear();


	double free_mem[items.size()];	
	double bin_capacity=1;
	int bin_used=0;

	for (int i=0;i<items.size();++i){
		int j;
		for (j=0; j < bin_used ; j++){
			if((double_equal(free_mem[j],items[i]))||(free_mem[j] > items[i]))
			{
				double free_memory=free_mem[j]-items[j];
				free_memory < 0.001?free_mem[j]=0:free_mem[j]=free_memory;
				break;
			}


		}
		
		if (j==bin_used)
		{
			free_mem[j]=bin_capacity-items[i];
			bin_used++;
		}
		assignment.push_back(j+1);
	}

	for (int i=0; i< bin_used ;++i){
		free_space.push_back(free_mem[i]);

	}

}
