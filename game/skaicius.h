
#include <iostream>
#include <ctime>
using namespace std;
class skaicius {

protected:
	int sk;
public:
	skaicius() {
		srand(time(NULL));
		sk = rand() % 37 + 1;
	}
	int getsk() {
		return sk;
	}

	~skaicius() {}
};
class spalva: public skaicius
{
public:
	string sp; // spalva kuria poto ivesiu main'e.
	string spR;


public:

	spalva() {
		sp = "";
		spR = "";
	}

	string get_spalva() {
		if (sk == 1) return "J";
		if (sk == 2) return "R";
		if (sk == 3) return "J";
		if (sk == 4) return "R";
		if (sk == 5) return "J";
		if (sk == 6) return "R";
		if (sk == 7) return "J";
		if (sk == 8) return "R";
		if (sk == 9) return "J";
		if (sk == 10) return "R";
		if (sk == 11) return "J";
		if (sk == 12) return "R";
		if (sk == 13) return "J";
		if (sk == 14) return "R";
		if (sk == 15) return "J";
		if (sk == 16) return "R";
		if (sk == 17) return "J";
		if (sk == 18) return "R";
		if (sk == 19) return "J";
		if (sk == 20) return "R";
		if (sk == 21) return "J";
		if (sk == 22) return "R";
		if (sk == 23) return "J";
		if (sk == 24) return "R";
		if (sk == 25) return "J";
		if (sk == 26) return "R";
		if (sk == 27) return "J";
		if (sk == 28) return "R";
		if (sk == 29) return "J";
		if (sk == 30) return "R";
		if (sk == 31) return "J";
		if (sk == 32) return "R";
		if (sk == 33) return "J";
		if (sk == 34) return "R";
		if (sk == 35) return "J";
		if (sk == 36) return "R";
		if (sk == 37) return "O";
	}
	int get_stulp() {
		if (sk == 1) return 1;
	    if (sk == 2) return 2;
		if (sk == 3) return 3;
		if (sk == 4) return 1;
		if (sk == 5) return 2;
		if (sk == 6) return 3;
		if (sk == 7) return 1;
		if (sk == 8) return 2;
		if (sk == 9) return 3;
		if (sk == 10) return 1;
		if (sk == 11) return 2;
		if (sk == 12) return 3;
		if (sk == 13) return 1;
		if (sk == 14) return 2;
		if (sk == 15) return 3;
		if (sk == 16) return 1;
		if (sk == 17) return 2;
		if (sk == 18) return 3;
		if (sk == 19) return 1;
		if (sk == 20) return 2;
		if (sk == 21) return 3;
		if (sk == 22) return 1;
		if (sk == 23) return 2;
		if (sk == 24) return 3;
		if (sk == 25) return 1;
		if (sk == 26) return 2;
		if (sk == 27) return 3;
		if (sk == 28) return 1;
		if (sk == 29) return 2;
		if (sk == 30) return 3;
		if (sk == 31) return 1;
		if (sk == 32) return 2;
		if (sk == 33) return 3;
		if (sk == 34) return 1;
		if (sk == 35) return 2;
		if (sk == 36) return 3;

	}
	int get_eil()
	{
		if (sk >= 1 && sk <= 12) return 1;
		if (sk >= 13 && sk <= 24) return 2;
		if (sk >= 25 && sk <= 36) return 3;
	}
	 

	~spalva() {}
};
class skaiciukomb {
private:
	int kombsk;
public:
	skaiciukomb(int ko) {
		kombsk = ko;
	}
	float get_tikimybe() {
		if (kombsk = 6) return 6;
		if (kombsk = 5) return 7;
		if (kombsk = 4) return 9;
		if (kombsk = 3) return 12;
		if (kombsk = 2) return 18;
	}
	~skaiciukomb(){}

};