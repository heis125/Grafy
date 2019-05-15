

#ifndef PCH_H
#define PCH_H
#include "Graf_L.h"
#include "Graf_M.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;
bool czyBylaWylosowana(int liczba, int tab[], int ile);
int laczenie_liczb(int a, int b);
void tworzenie_pliku(int krawedzie, int wierzcholki);
void wczytywanie_z_pliku(Graf_M A[], int i);
void wczytywanie_z_pliku(Graf_L A[], int i);
void pliki(ofstream &sasiedzi, ofstream &wynik);
#endif //PCH_H
