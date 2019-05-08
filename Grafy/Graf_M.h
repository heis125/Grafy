#ifndef Graf_M_H
#define Graf_M_H
#include "pch.h"
#include <fstream>
using namespace std;
class Graf_M // implementacja grafu na macierzy sasiedztwa 
{
public:
	const int MAXINT = 2147483647; // nieskonczonosc ustawiana jako poczatkowy koszt przejscia krawedzi 
	int j, u;
	bool *QS; //Tablica odwiedzonych i nie odwieddzonych wierzcho³ków
	int *d_poprzednik, *d_koszt, *stos, s_stos; // wskaŸniki do algorytmu Dikstry 
	int n, e, poczatek;// liczba wierzcho³ków, krawêdzi oraz indeks poczatkowego wierzcho³ka
	//int  v1, v2, waga; // Numery wierzchoków oraz waga krawêdzi miêdzy nimi
	int** M; // WskaŸnik potrzebny do macierzy s¹siedztwa 
	Graf_M() {} // konstruktor

	void buduj();
	void dodawanie_krawedzi(int v1, int v2, int waga);
	void wyswietl();
	void zapisz(ofstream &M_sasiedztwa);
	void dikstra(ofstream &wynik);
	void dikstra_zapisz(ofstream &wynik, int stos[], int s_stos, int d_koszt[], int d_poprzednik[]);
};
#endif