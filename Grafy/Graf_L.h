#ifndef Graf_L_H
#define Graf_L_H
#include "pch.h"
#include <fstream>
using namespace std;
class Graf_L // implementacja grafu na liscie sasiedztwa 
{

public:
	struct lista_elementow // struktura listy
	{
	public:
		lista_elementow * next; // nastepny element
		int v, Waga;
	};
	const int MAXINT = 2147483647; // nieskonczonosc ustawiana jako poczatkowy koszt przejscia krawedzi 
	int j, u;
	bool *QS; //Tablica odwiedzonych i nie odwieddzonych wierzcho³ków
	int *d_poprzednik, *d_koszt, *stos, s_stos; // wskaŸniki do algorytmu Dikstry 
	int n, e, poczatek; // liczba wierzcho³ków, krawêdzi oraz indeks poczatkowego wierzcho³ka
	//int v1, v2, waga; // Numery wierzchoków oraz waga krawêdzi miêdzy nimi
	lista_elementow ** L; // WskaŸnik potrzebny do listy s¹siedztwa 
	lista_elementow *p; // wskaŸnik na element 
	Graf_L() {} // konstruktor

	void buduj();
	void dodawanie_krawedzi(int v1, int v2, int waga);
	void wyswietl();
	void zapisz(ofstream &L_sasiedztwa);
	void dikstra(ofstream &wynik);
	void dikstra_zapisz(ofstream &wynik, int stos[], int s_stos, int d_koszt[], int d_poprzednik[]);
};
#endif