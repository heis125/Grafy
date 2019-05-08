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
	bool *QS; //Tablica odwiedzonych i nie odwieddzonych wierzcho�k�w
	int *d_poprzednik, *d_koszt, *stos, s_stos; // wska�niki do algorytmu Dikstry 
	int n, e, poczatek; // liczba wierzcho�k�w, kraw�dzi oraz indeks poczatkowego wierzcho�ka
	//int v1, v2, waga; // Numery wierzchok�w oraz waga kraw�dzi mi�dzy nimi
	lista_elementow ** L; // Wska�nik potrzebny do listy s�siedztwa 
	lista_elementow *p; // wska�nik na element 
	Graf_L() {} // konstruktor

	void buduj();
	void dodawanie_krawedzi(int v1, int v2, int waga);
	void wyswietl();
	void zapisz(ofstream &L_sasiedztwa);
	void dikstra(ofstream &wynik);
	void dikstra_zapisz(ofstream &wynik, int stos[], int s_stos, int d_koszt[], int d_poprzednik[]);
};
#endif