// cpp2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankCard {
	private:
		string bankName; //onoma trapezas
		string holderName; //onoma katoxou
		int year; //etos lhkshs
	public:
		BankCard(string bankName0 = "" , string holderName0 = "" , int year0 = 2000) {
			bankName = bankName0;
			holderName = holderName0;
			year = year0;
		}
		string GetBank() {
			return bankName;
		}
		string GetHolder() {
			return holderName;
		}
		int GetYear() {
			return year;
		}
		string SendAlert(int curryear) {
			if (curryear == year) {
				return "\nThis card expires this year!\n";
			}
			else {
				return "";
			}
		}
};

class CreditCard : public BankCard {
private:
	int creditLimit;
	int type;
public:
	CreditCard(string bankName1, string holderName1, int year1, int creditLimit0, int type0) {
		BankCard bc(bankName1, holderName1, year1);
		creditLimit = creditLimit0;
		type = type0;
	}
	int GetLimit() {
		return creditLimit;
	}
	int NoDoses() {
		int maxdoses;
		if (type == 1) {
			maxdoses = 60;
		}
		else if (type == 2) {
			maxdoses = 30;
		}
		return maxdoses;
	}
	void Print() {
		cout << "Onoma trapezas: " << GetBank();
		cout << "\nOnoma katoxou: " << GetHolder();
		cout << "\nEtos lhkshs: " << GetYear();
		cout << "\nPistwtiko Orio: " << GetLimit();
		cout << "\nMegistos Arithmos Dosewn: " << NoDoses();
	}
};


int main()
{	
	CreditCard cc1("Bank1", "John Smith", 2017, 3000, 1);
	CreditCard cc2("Bank1", "John Smith", 2019, 1200, 2);
	CreditCard cc3("Bank2", "John Smith", 2020, 4000, 1);
	// den yparxei default constructor 
	//epomenws tha xrhsimopoihsoume vector gia na dhmiourghsoume array antikeimenwn
	vector<CreditCard> css;   //CreditCard* css = new CreditCard[3]; an yphrxe default constructor
	css.push_back(cc1);
	css.push_back(cc2);
	css.push_back(cc3);
	for (CreditCard c: css) {
		if (c.SendAlert(2000) != "") {
			cout << c.SendAlert(2000);
			c.Print();
		}
	}
	//delete[] css;
	int limit1 = cc1.GetLimit();
	int limit2 = cc2.GetLimit();
	int limit3 = cc3.GetLimit();
	int syn_orio = limit1 + limit2 + limit3;
	cout << "\nTo synoliko pistwtiko orio pou exei o " << cc1.GetHolder() << " einai " << syn_orio << " eyrw. ";
	system("pause");
	return 0;
}	

