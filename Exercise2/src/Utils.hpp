#pragma once

#include <iostream>
#include <fstream>
using namespace std;

void read_vectors(ifstream& file, double*&v1, double*&v2,
				unsigned int n);



void stampa_su_file(ofstream& of, string name_v,
					double*&v, unsigned int n);



double get_final_value(double*&v1, double*&v2, const double& S,
						unsigned int n);



double get_rate(const double& S,const double& V);



template<typename T> 
requires disjunction<is_same<T, unsigned int>, is_floating_point<T>>::value
T get_num(ifstream& file) {
	
	string _;
	T num;
	getline(file, _, ';');
	file >> num;
	
	return num;
};
