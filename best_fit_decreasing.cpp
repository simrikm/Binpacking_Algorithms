#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project2.h"
#include <bits/stdc++.h>

using namespace std;

void best_fit_decreasing(const vector<double>& items, vector<int>&assignment, vector<double>& free_space){

	assignment.clear();
	free_space.clear();

	vector<double> copy_items;
	
	for (int i=0;i<items.size();i++)
		copy_items.push_back(items[i]);
	
	sort(copy_items.rbegin(),copy_items.rend());

	best_fit(copy_items,assignment,free_space);
	
}
