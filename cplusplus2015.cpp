// cplusplus2015.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class Karta {
private:
	string code;
	float pontoi;
	float km;
public:
	Karta(string codee = "", float pontoii = 0, float kmm = 0) {
		code = codee;
		pontoi = pontoii;
		km = kmm;
	}
	string getCode() {
		return code;
	}
	float getPontoi() {
		return pontoi;
	}
	float getKm() {
		return km;
	}
	void setPontoi(float new_pontoi) {
		pontoi = new_pontoi;
	}
	void setKm(float new_km) {
		km = new_km;
	}
	void print() {
		if (pontoi < 5000) {
			cout << "Den dikaioyste akomh dwro!!" <<endl;
		}
		else if (pontoi < 10000) {
			cout << "Anavathmisi theshs!!" << endl;
		}
		else {
			cout << "FREE TRIP!!" << endl;
		}
	}
	void Agora(float euro) {
		int extra_points = 10 * euro;
		pontoi += extra_points;
		cout << "Agorasate " << extra_points<< " pontous!" << endl;
	}
};
int main()
{
	Karta aeromiles("ab123", 2000, 2000);
	aeromiles.Agora(250.5);
	aeromiles.print();
	system("pause");
    return 0;
}

