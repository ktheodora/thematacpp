#include <iostream>
#include <fstream>
using namespace std;

int main(char filename[50])
{	
	ifstream myfile;
	filename = "students.txt";
	myfile.open(filename);
	if (myfile.fail()) {
		cerr << "Error opening file!\n";
		exit(1);
	}
	int N;
	myfile >> N;
	cout << "Value of N is: " << N << "\n";
	int *f = new int[N];
	int count = 0, friendornot, sum = 0, i = 0;
	while (count != N) { //o metrhths count anaferetai stis seires
		while (	(myfile >> friendornot) && (i < N)) {//diavazetai h katastash filias
			sum += friendornot;
			i++;
		}
		i=0;
		f[count] = sum;
		sum = 0;
		count += 1;
	}
	int maxfriends = 0, maxstudent1, maxstudent2, maxstudent3;
	for (int i = 0; i < N; i++) {
		if (f[i] > maxfriends) {
			maxfriends = f[i];
			maxstudent3 = i;
		}
	}
	f[maxstudent3] = 0; //kanoume 0 thn timh twn perissoterwn filwn ston pinaka 
	//wste na vroume ton amesws megalytero arithmo filwn
	maxfriends = 0;
	for (int i = 0; i < N; i++) {
		if (f[i] > maxfriends) {
			maxfriends = f[i];
			maxstudent2 = i;
		}
	}
	f[maxstudent2] = 0;
	maxfriends = 0;
	for (int i = 0; i < N; i++) {
		if (f[i] > maxfriends) {
			maxfriends = f[i];
			maxstudent1 = i;
		}
	}
	cout << "Mathites me tis perissoteres filies se ayksoysa seira:";
	cout << "\nMathitis no. " << maxstudent1;
	cout << "\nMathitis no. " << maxstudent2;
	cout << "\nMathitis no. " << maxstudent3;
	delete[]f;
	myfile.close();
    return 0;
	system("pause");
}