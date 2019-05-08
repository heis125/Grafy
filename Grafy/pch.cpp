// pch.cpp: plik źródłowy odpowiadający wstępnie skompilowanemu nagłówkowi, niezbędny do powodzenia kompilacji

#include "pch.h"

bool czyBylaWylosowana(int liczba, int tab[], int ile) // sprawdzenie czy liczba była juz wylosowana
{
	int i = 0; // licznik 
	if (ile <= 0)  // w pierwszym przejciu nie ma wyklosowanej żadnej liczby wiec damy odpowwiedz ze nie została wylosowana 
		return false;
	do // przeszukiwanie całej tablicy 
	{
		if (tab[i] == liczba) // jeśli znaleźliśmy znaczy ze zostałą juz wczesniej wylosowana
			return true;

		i++;
	} while (i < ile);

	return false;
}
int laczenie_liczb(int a, int b) // funkcja tworzaca nowa liczbe ulatiwajaca sprawdzenie czy dana para wierzchołków juz wystąpoiła 
{
	// nie używamy liczb wiekszych niż 99 wiec to rozwiazanie działa, przy indeksach wierzchołków powyżej 99 wymagane uzupełnienie funkcji 
	int c;
	c = a * 1000 + b;
	return c;
}
void tworzenie_pliku(int krawedzie, int wierzcholki) // funkcja tworzaca plik z okreslonymi danymi dla grafu
{

	int V1, V2; // indeksy krawedzi 
	int poczatek = rand() % wierzcholki;
	int* tab = new int[krawedzie]; // dablica na juz wykorzystane indeksy wierzchołków 
	int liczba; // zmienna tymczasowa potrzebna do sprawdzania czy dana liczba juz wystąpiła 
	//srand((int)time(0));
	int i = 0;
	ofstream plik("plik.txt"); // tworzenie nowego pliku do tworzenia grafów
	plik << krawedzie << " " << wierzcholki << " " << poczatek << " " << endl; // wczytywanie pierwszych parametrów 
	while (i < krawedzie) // główna petla funkcji 
	{

		V1 = rand() % wierzcholki; // losowanie wierzchołków 
		V2 = rand() % wierzcholki;
		if (V1 != V2) // sprawdzenie czy wierzchołek nie łączy się sam ze sobą 
		{
			liczba = laczenie_liczb(V1, V2); // sprawdzenie czy dana para wierzchołków juz wystąpiła 
			if (czyBylaWylosowana(liczba, tab, i) == false) // jeśli nie wystąpiła 
			{
				plik << V1 << " " << V2 << " " << rand() % 1000 + 1 << " " << endl; // wpisanie parametrów do pliku 
				tab[i] = liczba; // wpisanie wykorzystanej pary wierzchołków do tablicy 
				i++;
			}
		}
	}
}
void wczytywanie_z_pliku(Graf_M A[], int i)
{
	int v1, v2, waga; // indeks wierzchołka poczatkowego, koncowego oraz waga krawedzi miedzy nimi 
	fstream plik; // implementacja pliku
	plik.open("plik.txt", ios::in); // otwieranie pliku 

		plik >> A[i].e >> A[i].n >> A[i].poczatek; // odczytanie ilosci krawedzi, wierzchołków oraz indeksu poczatkowego wierzchołka
		A[i].buduj(); // zbudowanie grafu( wyzreowanie macierzy lub stworzenie pustej listy w zależnosci od wybranej implementacji)
		for (int j = 0; j < A[i].e; j++) // przypisanie sąsiadów do maciezry bądz do listy w zależności od implementacji
		{
			plik >> v1 >> v2 >> waga; // odczytanie z pliku inkeksów wierzchołków oraz wagi krawędzi miedzy nimi
			A[i].dodawanie_krawedzi(v1, v2, waga); // stworzenie krawędzi 
		}

	plik.close(); // zamknięcie pliku
	remove("plik.txt"); // usunięcie pliku 

}
void wczytywanie_z_pliku(Graf_L A[], int i)
{
	int v1, v2, waga; // indeks wierzchołka poczatkowego, koncowego oraz waga krawedzi miedzy nimi 
	fstream plik; // implementacja pliku
	plik.open("plik.txt", ios::in); // otwieranie pliku 

		plik >> A[i].e >> A[i].n >> A[i].poczatek; // odczytanie ilosci krawedzi, wierzchołków oraz indeksu poczatkowego wierzchołka
		A[i].buduj(); // zbudowanie grafu( wyzreowanie macierzy lub stworzenie pustej listy w zależnosci od wybranej implementacji)
		for (int j = 0; j < A[i].e; j++) // przypisanie sąsiadów do maciezry bądz do listy w zależności od implementacji
		{
			plik >> v1 >> v2 >> waga; // odczytanie z pliku inkeksów wierzchołków oraz wagi krawędzi miedzy nimi
			A[i].dodawanie_krawedzi(v1, v2, waga); // stworzenie krawędzi 
		}

	plik.close(); // zamknięcie pliku
	remove("plik.txt"); // usunięcie pliku 

}
void pliki(ofstream &sasiedzi, ofstream &wynik)
{
	sasiedzi.open("sasiedzi.txt", ios::out | ios::app);
	sasiedzi << "Sasiedzi" << endl;
	sasiedzi.close();
	wynik.open("wynik.txt", ios::out | ios::app);
	wynik << "Wynik" << endl;
	wynik.close();
}
// Ogólnie rzecz biorąc, zignoruj ten plik, ale miej go pod ręką, jeśli używasz wstępnie skompilowanych nagłówków.
