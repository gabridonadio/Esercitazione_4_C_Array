#include <iostream>
#include <fstream>
#include <Utils.hpp>
#include <iomanip>

using namespace std;

int main()
{
	string ifp = "data.txt";
	string ofp = "result.txt";
	ifstream file(ifp);
	ofstream of(ofp);
	
	if(file.fail()) {
		cerr << "Non è stato possibile aprire il file data.txt" << endl;
		return 1;
	}
	
	
	double S = get_num<double>(file);
	
	unsigned int n = get_num<unsigned int>(file);
	
	of << fixed << setprecision(2) << "S = " << S << ", " <<
	"n = " << n << endl;
	cout << fixed << setprecision(2) << "S = " << S << ", " <<
	"n = " << n << endl;
	
	
	string _; 
	file >> _;	//escludo riga con w;r
	
	double *w = new double[n];
	double *r = new double[n];
	
	read_vectors(file, w, r, n);
	
	stampa_su_file(of, "w", w, n);
	stampa_su_file(of, "r", r, n);
	
	double V = get_final_value(w, r, S, n);
	double rate = get_rate(S, V);
	
	of << defaultfloat << setprecision(4) <<
	"Rate of return of the portfolio: " << rate << endl;
	of << fixed << setprecision(2) << "V: " << V << endl; 
	
	cout << defaultfloat << setprecision(4) <<
	"Rate of return of the portfolio: " << rate << endl;
	cout << fixed << setprecision(2) << "V: " << V << endl; 
	
	delete [] w;
	delete [] r;
	
	
    return 0;
}

