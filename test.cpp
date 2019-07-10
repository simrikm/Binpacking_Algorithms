#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project2.h"
#include <iostream>
#include  <random>
using namespace std;

void best_fit(const vector<double>& items, vector<int>& assignment, vector<double>& free_space){

	double free_mem[items.size()];	
	double bin_capacity=1;
	int bin_used=0;
	int idx=0;

	for (int i=0;i<items.size();++i){
		int j;
		int min =10;
		for (j=0; j < bin_used ; j++){
			if(free_mem[j] >= items[i])
			{
				if ((free_mem[j]-items[i]) < min){
					min=free_mem[j]-items[i];
					idx=j;
			
				}
				if (j==(bin_used-1)){
					j==0;
					break;

				}
			}
		}


		if (j==bin_used)
		{
			free_mem[j]=bin_capacity-items[i];
			bin_used++;
			assignment.push_back(j+1);
		}else{
			assignment.push_back(idx+1);
			free_mem[idx]=free_mem[idx]-items[i];
		}
	}

	for (int i=0; i< bin_used ;++i){
		free_space.push_back(free_mem[i]);

	}

}


void print_contents(vector<double>& items){
	for(vector<double>::const_iterator i=items.begin(); i!=items.end();++i){
		cout<< *i << ' '<<'\n';
	}
	cout<<"\n";
}

void print_content(vector<int>& items){
	for(vector<int>::const_iterator i=items.begin(); i!=items.end();++i){
		cout<< *i << ' '<<'\n';
	}
	cout<<"\n";
}

double  random_items_n_sum(int n, vector<double>& items){
	items.clear();
	double sum=0;	
	random_device rd;
	mt19937 generator(rd());

	uniform_real_distribution<double> dist(0.1,0.9);
	
	for (int i=0; i < n; ++i){
		double num=dist(generator);
		double rounded=floor((num*10)+.5)/10;
		items.push_back(rounded);
		sum+=rounded;
	}
	return sum;
}

int main(){

	vector<double> items;
	vector<int> assignments;
	vector<double> free_space;
	
	double sum=0;

	for (int n=10 ; n <=10 ; n*=10){
		sum=random_items_n_sum(n,items);
		best_fit(items,assignments,free_space);
		
	}

	print_contents(items);
	print_contents(free_space);
	print_content(assignments);

	return 0;}
