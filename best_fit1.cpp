#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project2.h"

using namespace std ;

void best_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space){
	double free_mem[items.size()];
	double bin_capacity=1;
	int bin_used=0;
	
	for(int i=0;i<items.size();++i){
		int j;
		double  min=bin_capacity+1;
		int index=0;
		
		for (j=0; j<bin_used;j++)
		{
			if(free_mem[j] >=items[i] && (free_mem[j]-items[i]) <min){
				index=j;
				min=free_mem[j]-items[i];
			}

		}

		if(min==bin_capacity+1){
			free_mem[bin_used]=bin_capacity-items[i];
			bin_used++;
		}else{
			free_mem[index]-=items[i];
		
		}
		assignment.push_back(j+1);
	}

	for (int i=0; i< bin_used;++i){
		free_space.push_back(free_mem[i]);
	}

}
