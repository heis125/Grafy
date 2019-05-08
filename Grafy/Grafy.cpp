// 
//

#include "pch.h"

int main()
{
	clock_t start;
	long double czas_trwania;
	srand((int)time(NULL));
	double gestosc = 1; // gestość grafu watrość od 0 do 1 !
	int ile_wierzcholkow = 200; // ilosc wierzchołków grafu
	int ile_krawedzi = (int)((ile_wierzcholkow*(ile_wierzcholkow - 1))*gestosc); // liczenie ile jest krawedzi przy zadanej gęstości 
	int ilosc = 100; // ilosc grafów 
	ofstream sasiedzi("sasiedzi.txt"); // tworzenie nowego pliku do zapisu macierzy sasiedztwa luc listy sasiedztwa
	ofstream wynik("wynik.txt"); // tworzenie nowego pliku do zapisu wyników

	Graf_L* A = new Graf_L[ilosc]; // Graf na liscie sąsiedztwa
	//Graf_M* A = new Graf_M[ilosc];  // Graf na macierzy sasiedztwa 

	pliki(sasiedzi, wynik);

	for (int i = 0; i < ilosc; i++)  // petla tworzeca grafy 
	{

		tworzenie_pliku(ile_krawedzi, ile_wierzcholkow); // Tworzenie pliku z danymi potrabnymi do zbudowania grafu
		wczytywanie_z_pliku(A, i);
		//A[i].zapisz(sasiedzi); // zapisywanie macierzy sąsiedztwa lub listy sąsiedztwa do pliku
		//A[i].wyswietl(); // wyświetlenie macierzy sąsiedztwa lub listy sąsiedztwa

	} 
	start = clock(); // włączenie odliczania czasu
	for (int i = 0; i < ilosc; i++)  // petla wykonujaca główny algorytm
	{
		//A[i].dikstra(wynik);
	}
	czas_trwania = (clock() - start) / (double)CLOCKS_PER_SEC; // przeliczenia cykli zegara na sekundy
	cout << "Czas wykonania " << czas_trwania << "s" << endl; // wyświetlenie ile czasu sortował algorytm
	delete A; // usniecie grafów 


	//system("PAUSE"); // pauza systemu potrzebna przy używaniu pliku wykonawczego 
}

