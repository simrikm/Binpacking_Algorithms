#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project2.h"

using namespace std;

/**
 *Check to see if the current item fits in the current bin. If so, plce it there, otherwise 
 *start a new bin
 */
void next_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space)
{
	assignment.clear();
	free_space.clear();

	double bin_capacity=1;
	int bin_used=1;

	for (int i=0; i <items.size(); ++i){
		if(items[i] > bin_capacity){
			free_space.push_back(bin_capacity);
			bin_used++;
			bin_capacity=1;		
		}
		
		assignment.push_back(bin_used);
		bin_capacity -= items[i];
	}
	
	free_space.push_back(bin_capacity);

}
