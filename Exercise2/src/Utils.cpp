#include <Utils.hpp>

#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

void read_vectors(ifstream& file, double*&v1, double*&v2, unsigned int n) {
	
	// il controllo sull'esistenza e correttezza del file è già stato fatto in precedenza
	
	for(unsigned int i = 0; i < n; i++) {
		
		string _;
		getline(file, _, ';');
		v1[i] = stod(_);
		file >> v2[i];
	}
}


/* 
// funzione inserita nell'hpp per presenza di template requires
template<typename T> 
requires disjunction<is_same<T, unsigned int>, is_floating_point<T>>::value
T get_num(ifstream& file) {
	
	string _;
	T num;
	getline(file, _, ';');
	file >> num;
	
	return num;
} */

void stampa_su_file(ofstream& of, string name_v, double*&v,
					unsigned int n) {
	
	of << defaultfloat << name_v << " = [ ";
	for(unsigned int i=0; i<n; i++) {
		of << v[i] << " ";
	}
	of << "]" << endl;
}

double get_final_value(double*&v1, double*&v2, const double& S, unsigned int n) {
	
	double V = 0;
	
	for(unsigned int i=0; i<n; i++)
		V += v1[i]*S*(1+v2[i]);
	
	return V;
}

double get_rate(const double& S,const double& V) {
	
	if(S==0) {
		cerr << "No money invested" << endl;
		return 1;
	}
	else {
		double rate = V/S - 1;
		return rate;
	}
}