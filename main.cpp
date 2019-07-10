#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project2.h"
#include <bits/stdc++.h>
#include <random>

using namespace std;

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

double random_items_n_sum(int n, vector<double>& items){
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

void create_files(string filename)
{
	ofstream f;
	f.open(filename, ios::trunc);
	f<<"n, waste\n";
	f.close();

}

void add_data_to_files(int n, double waste,string filename){
	ofstream f;
	f.open(filename,ios::app);
	f<<" "<<n<<","<<waste<<"\n";
	f.close();
}

void creating_files(){
	create_files("best_fit.csv");
	create_files("first_fit.csv");
	create_files("best_fit_decreasing.csv");
	create_files("first_fit_decreasing.csv");
	create_files("next_fit.csv");

}

void bin_packing_algo(int n,int sum,vector<double>& items, vector<int>& assignments, vector<double>& free_space){

	cout<<"RUN WITH n ="<<" "<<n<<"\n"<<"NEXT_FIT...\n";
	next_fit(items,assignments,free_space);
	add_data_to_files(n,(free_space.size()-sum),"next_fit.csv");

	cout<<"RUN WITH n ="<<" "<<n<<"\n"<<"FIRST_FIT...\n";							
	first_fit(items,assignments,free_space);
	add_data_to_files(n,(free_space.size()-sum),"first_fit.csv");

	cout<<"RUN WITH n ="<<" "<<n<<"\n"<<"BEST_FIT...\n";
	best_fit(items,assignments,free_space);
	add_data_to_files(n,(free_space.size()-sum),"best_fit.csv");

	cout<<"RUN WITH n ="<<" "<<n<<"\n"<<"FIRST_FIT_DECREASING...\n";
	first_fit_decreasing(items,assignments,free_space);
	add_data_to_files(n,(free_space.size()-sum),"first_fit_decreasing.csv");

	cout<<"RUN WITH n ="<<" "<<n<<"\n"<<"BEST_FIT_DECREASING...\n";
	best_fit_decreasing(items,assignments,free_space);
	add_data_to_files(n,(free_space.size()-sum),"best_fit_decreasing.csv");


}

int main(){


	vector<double> items;
	vector<int> assignments;
	vector<double> free_space;
		
	creating_files();

	double sum=0;

	
	for (int n=10 ; n <=100000; n*=10){
		sum=random_items_n_sum(n,items);
		bin_packing_algo(n,sum,items,assignments,free_space);
	
	}

	return 0;
}
