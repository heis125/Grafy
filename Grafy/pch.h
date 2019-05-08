// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

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
