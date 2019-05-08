#include "pch.h"
#include "Graf_L.h"

	void Graf_L::buduj()
	{
		L = new lista_elementow *[n]; // Tworzenie tablicy list s¹siedztwa

		//Wype³nianie tablicy pustymi listami

		for (int i = 0; i < n; i++) L[i] = NULL;

	}

	void Graf_L::dodawanie_krawedzi(int v1, int v2, int waga) // dodawanie nowych krawêdzi 
	{
		p = new lista_elementow;    // Tworzenie nowego elementu 
		p->v = v2;          // Okreœlanie elementu jako v2
		p->next = L[v1];	// ustalenie poczatku listy jaki v1
		p->Waga = waga;		// ustalamy wagê
		L[v1] = p;

	}

	void Graf_L::zapisz(ofstream &L_sasiedztwa)
	{
		L_sasiedztwa.open("sasiedzi.txt", ios::out | ios::app); // otwieranie pliku 
		for (int i = 0; i < n; i++)
		{
			L_sasiedztwa << "L[" << i << "] =";
			p = L[i];
			while (p)
			{
				L_sasiedztwa << setw(3) << p->v << " waga: " << p->Waga;
				p = p->next;
			}
			L_sasiedztwa << endl;
		}
		L_sasiedztwa << endl << endl;
		L_sasiedztwa.close(); // zamkniêcie pliku
	}
	// wyœwietlanie listy s¹siedztwa
	void Graf_L::wyswietl()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "L[" << i << "] =";
			p = L[i];
			while (p)
			{
				cout << setw(3) << p->v << " waga: " << p->Waga;
				p = p->next;
			}
			cout << endl;
		}
		cout << endl;
	}
	void Graf_L::dikstra_zapisz(ofstream &wynik,int stos[],int s_stos, int d_koszt[],int d_poprzednik[])
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
	void Graf_L::dikstra(ofstream &wynik)
	{
	
		d_poprzednik = new int[n]; // tablica poprzednich elementów greafu
		d_koszt = new int[n]; // tablica przechowujaca koszt przejscia do danego punktu grafu
		stos = new int[n]; // stos do odtwarzaania drogi
		QS = new bool[n]; // tablica sprawdzajaca czy odwiedziliœmy juz wszystkie wierzcho³ki 
		s_stos = 0; // wskaŸnik stosu
		for (int j = 0; j < n; j++)// Wype³nianie tablic
		{
			d_poprzednik[j] = -1;
			d_koszt[j] = MAXINT;
			QS[j] = false;
		}
		d_koszt[poczatek] = 0; // koszt dojscia do poczatkowego elementu jest zawsze 0

		for (int i = 0; i < n; i++)
		{
			//szukanie wierzcho³ka o najmnijeszym koszcie w tablicy kosztów
			for ( j = 0; QS[j]; j++);
			for ( u = j++; j < n; j++)
				if (!QS[j] && (d_koszt[j] < d_koszt[u])) u = j;

			// Znaleziony wierzcho³ek przenosimy do S

			QS[u] = true;

			// sprawdzamy wszystkich sasiadów wierzcho³ka u
			for (p = L[u]; p; p = p->next)
				if (!QS[p->v] && (d_koszt[p->v] > d_koszt[u] + p->Waga))
				{
					d_koszt[p->v] = d_koszt[u] + p->Waga;
					d_poprzednik[p->v] = u;
				}
		}
		dikstra_zapisz(wynik, stos, s_stos, d_koszt, d_poprzednik); // zapisywanie wyniku do pliku
		
	}
