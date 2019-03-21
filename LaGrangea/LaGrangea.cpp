// LaGrangea.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

class punkt {
public:
	double x, y;
};

double LagrangeInterpolation(const int &n, double p1) {
	double wynik = 0;
	fstream plik;
	plik.open("punkty.txt");
	punkt *tab = new punkt[n];
	if (plik.good())
	{
		for(int i=0;i<n;i++)
			plik >> tab[i].x >> tab[i].y;
	}
	else
		cout << "Blad odczytu z pliku!" << endl;

//	punkt tab[] = { {-2,5},{-1,-2},{0,4},{1,-7},{2,2} };
	for (int i = 0; i < n; i++)
	{
		double temp= tab[i].y;
		for (int j = 0; j < n; j++)
		{
			if (i != j)
				temp=temp*(p1-tab[j].x)/(tab[i].x-tab[j].x);
		}
		wynik = wynik + temp;
	}
	plik.close();
	return wynik;
}

void menu() {
	int wybor = -1;
	int pom = -1;
	double x = 0.;
	do {
		cout << "\n-------------------------------" << endl;
		cout << "Witaj, co chcesz wykonac?" << endl;
		cout << "1. Interpolacja Lagrange'a" << endl;
		cout << "0. Wyjdz z programu" << endl;
		cin >> wybor;
		switch (wybor) {
		case 1:
			cout << "Podaj ilosc pkt:";
			cin >> pom;
			cout << "\nPodaj X:";
			cin >> x;
			cout<<"Wynik dla X="<<x<<" to: "<<LagrangeInterpolation(pom,x);
			break;
		case 2:
			cout << "PLACEHOLDER" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Nie poprawny wybor" << endl;
			break;
		}
	} while (wybor != 0);
}

int main()
{
	menu();
    return 0;
}

