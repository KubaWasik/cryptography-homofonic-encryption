#include "pch.h"
#include "Homophone.h"

int main()
{
	//srand(time(NULL));
	string text;
	cout << "Podaj tekst do zaszyfrowania: ";
	getline(cin, text);
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	cout << "\nPodales: " << text << endl;
	Homophone table(text);
	cout << table << endl;
	string cipher1, cipher2, cipher3;
	cipher1 = table.encrypt(text);
	cipher2 = table.encrypt(text);
	cipher3 = table.encrypt(text);
	cout << endl << endl << "Szyfrowanie wersja 1:" << endl << cipher1;
	cout << endl << endl << "Szyfrowanie wersja 2:" << endl << cipher2;
	cout << endl << endl << "Szyfrowanie wersja 3:" << endl << cipher3;
	text = table.decrypt(cipher1);
	cout << "\n\nTekst dla wersji 1: " << text;
	text = table.decrypt(cipher2);
	cout << "\n\nTekst dla wersji 2: " << text;
	text = table.decrypt(cipher3);
	cout << "\n\nTekst dla wersji 3: " << text;
	cout << "\n\nWcisnij dowolny klawisz aby zakonczyc...";
	cin.get();
	return 0;
}