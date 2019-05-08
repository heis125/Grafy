#include "pch.h"
#include "Graf_M.h"

	void Graf_M::buduj() // tworzenie macierzy s¹siedztwa
	{
		M = new int *[n];    // Tworzenie tablicy wskaŸników
		for (int i = 0; i < n; i++)
			M[i] = new int[n]; // Tworzenie wierszy w tablicy

		  // wype³nianie macierzy zerami
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) M[i][j] = 0;

	}
	void Graf_M::dodawanie_krawedzi(int v1, int v2, int waga) // dodawanie krawedzie wraz z jej wag¹
	{
		M[v1][v2] = waga;   // krawêdz miedzy v1->v2 z wag¹
	}

	void Graf_M::zapisz(ofstream &M_sasiedztwa) // wyswietlanie macierzy sasiedztwa
	{
		M_sasiedztwa.open("sasiedzi.txt", ios::out | ios::app); // otwieranie pliku 
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int a = M[i][j];
				M_sasiedztwa << a << " ";
			}
			M_sasiedztwa << endl;
		}
		M_sasiedztwa << endl << endl;
		M_sasiedztwa.close(); // zamkniêcie pliku
	}
	void Graf_M::wyswietl() // wyswietlanie macierzy sasiedztwa
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << M[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

	}
	void Graf_M::dikstra_zapisz(ofstream &wynik, int stos[], int s_stos, int d_koszt[], int d_poprzednik[])
	{
		wynik.open("wynik.txt", ios::out | ios::app); // otwieranie pliku 
//zapisywanie wyniku do pliku 
		for (int i = 0; i < n; i++)
		{
			wynik << setw(3) << i << ": ";


			// Idziemy od koñca do pocatku zapisujac droge w stosie 
			for (int j = i; j > -1; j = d_poprzednik[j]) stos[s_stos++] = j;

			//Odtwarzamy œcieszke za pomoc¹ stosy i wpisujemy j¹ do pliku 
			while (s_stos) wynik << stos[--s_stos] << " ";

			// wpisujemy koszt œcie¿ki 
			wynik << "koszt: " << d_koszt[i] << endl;
		}
		wynik << endl << endl;
		wynik.close(); // zamkniêcie pliku
	}
	void Graf_M::dikstra(ofstream &wynik)
	{
		
		d_poprzednik = new int[n]; // tablica poprzednich elementów greafu
		d_koszt = new int[n]; // tablica przechowujaca koszt przejscia do danego punktu grafu
		stos = new int[n]; // stos do odtwarzaania drogi
		QS = new bool[n]; // tablica sprawdzajaca czy odwiedziliœmy juz wszystkie wierzcho³ki 
		s_stos = 0; // wskaŸnik stosu
		for (int k = 0; k < n; k++) // Wype³nianie tablic
		{
			d_poprzednik[k] = -1;
			d_koszt[k] = MAXINT;
			QS[k] = false;
		}
		d_koszt[poczatek] = 0; // koszt dojscia do poczatkowego elementu jest zawsze 0

		for (int k = 0; k < n; k++)
		{
			j = 0;
			//szukanie wierzcho³ka o najmnijeszym koszcie w tablicy kosztów 
			//for (j = 0; QS[j]; j++); // usunac chyba niepotrzebne
			for (u = j++; j < n; j++)
				if (!QS[j] && (d_koszt[j] < d_koszt[u])) u = j;

			// dany wierzcho³ek oznaczamy jako odwiedzony
			QS[u] = true;

			// sprawdzamy wszystkich sasiadów wierzcho³ka u
			for (int i = 0; i < n; i++)
				if (!QS[i] && M[u][i] != 0 && (d_koszt[i] > d_koszt[u] + M[u][i]))
				{
					d_koszt[i] = d_koszt[u] + M[u][i];
					d_poprzednik[i] = u;
				}
		}
		dikstra_zapisz(wynik, stos, s_stos, d_koszt, d_poprzednik); // zapisywanie wyniku do pliku

	}


	