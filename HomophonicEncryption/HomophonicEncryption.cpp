#include "pch.h"
#include "Homophone.h"
#include <fcntl.h>
#include <io.h>

int main()
{
	locale loc("pl_PL.UTF8");
	string text;
	cout << "Podaj tekst do zaszyfrowania: ";
	getline(cin, text);
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	cout << "\nPodales: " << text << endl;
	Homophone table_pl(text);
	Homophone table_dynamic(text, false);
	cout << table_pl << endl;
	cout << table_dynamic << endl;
	string cipher1_pl, cipher2_pl, cipher3_pl;
	string cipher1, cipher2, cipher3;
	cipher1_pl = table_pl.encrypt(text);
	cipher2_pl = table_pl.encrypt(text);
	cipher3_pl = table_pl.encrypt(text);
	cipher1 = table_dynamic.encrypt(text);
	cipher2 = table_dynamic.encrypt(text);
	cipher3 = table_dynamic.encrypt(text);
	cout << endl << endl << "Szyfrowanie wersja 1 z użyciem polskiego słownika:" << endl << cipher1_pl;
	cout << endl << endl << "Szyfrowanie wersja 2 z użyciem polskiego słownika:" << endl << cipher2_pl;
	cout << endl << endl << "Szyfrowanie wersja 3 z użyciem polskiego słownika:" << endl << cipher3_pl;
	cout << endl << endl << "Szyfrowanie wersja 1:" << endl << cipher1;
	cout << endl << endl << "Szyfrowanie wersja 2:" << endl << cipher2;
	cout << endl << endl << "Szyfrowanie wersja 3:" << endl << cipher3;
	text = table_pl.decrypt(cipher1_pl);
	cout << "\n\nTekst dla wersji 1: " << text;
	text = table_pl.decrypt(cipher2_pl);
	cout << "\n\nTekst dla wersji 2: " << text;
	text = table_pl.decrypt(cipher3_pl);
	cout << "\n\nTekst dla wersji 3: " << text;

	text = table_dynamic.decrypt(cipher1);
	cout << "\n\nTekst dla wersji 1: " << text;
	text = table_dynamic.decrypt(cipher2);
	cout << "\n\nTekst dla wersji 2: " << text;
	text = table_dynamic.decrypt(cipher3);
	cout << "\n\nTekst dla wersji 3: " << text;
	cout << "\n\nWcisnij dowolny klawisz aby zakonczyc...";
	cin.get();
	return 0;
}