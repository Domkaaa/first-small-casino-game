// kursinisv3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Zaidejas.h"
#include "skaicius.h"

using namespace std;

void Menu()
{
	cout << "Sveiki atvyke i DZ Kazino" << endl;
	cout << "1. Zaisti" << endl;
	cout << "2. Iseiti" << endl;
	cout << "3. Taisykles ir zaidimo gidas" << endl;
}
void Menu2()
{
	cout << "1. Statymas ant spalvos(50/50 sansas nugaleti, 2.00 Koeficientas)" << endl;
	cout << "2. Statymas ant stulpelio(33% nugaleti, 3.00 keoficientas)" << endl;
	cout << "3. Statymas ant eilutes(33% nugaleti, 3.00 keoficientas)" << endl;
	cout << "4. Statymas ant 1 skaiciaus(2.78% nugaleti, 36.00 keoficientas)" << endl;
	cout << "5. Statymas ant 2-6 skaiciu(5.4% - 16.2% nugaleti, 6.00-18.00koeficientas)" << endl;
	cout << "6. Iseit is stalo" << endl;
}

void instrukcija()
{
	cout << "Statymai ant stulpeliu tai 1,4,7...34 - 1 stulpelis; 2,5,8...35 - 2 stulpelis; 3,6 ... 36 - 3 stulpelis" << endl;
	cout << "Statymai ant eiluciu tai 1-12 - 1 eilute; 13-24 - 2 eilute; 25-36 - 3 eilute;" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}


int main()
{

	float statymas = 0;
	Zaidejas zaid;
	zaid = Zaidejas();
	skaicius sk;
	spalva spal;
	int pasirinkimas1 = 0;
	int pasirinkimas2 = 0;
	int PasirinkimasFunkcijos = 0;
	string PasirinkimoSpalva;
	int PC_sk = 0;
	int PC_sk2 = 0;
	string PC_sp;

	zaid = Zaidejas();

	int Spek = 0;

	int n;
	int laimejimas = 0; // tik vienam punktui
	int SpekM[100];

	do
	{

		Menu();
		cin >> pasirinkimas1;

		if (pasirinkimas1 == 1)
		{
			cout << "Iveskite jusu slapyvardi: " << endl;
			cin >> zaid.var;
			cout << "Iveskite pinigu suma su kuria norite pradeti: " << endl;
			cin >> zaid.pradzia;
			cout << "Kokio tipo statyma noretumet atlikti? " << endl;
			Menu2();
			cin >> pasirinkimas2;
			zaid.pinigai = zaid.pradzia;

			if (pasirinkimas2 == 1)
			{
				PasirinkimasFunkcijos = 0;
				while (zaid.pinigai > 0 && PasirinkimasFunkcijos != 2 && (zaid.pinigai < zaid.pradzia * 7))
				{


					cout << "Ant kokios spalvos norite pastatyti?(J - Juoda; R - Raudona)" << endl;


					cin >> PasirinkimoSpalva;
					cout << zaid.var << "jus turite " << zaid.pinigai << endl;
					while (statymas == 0 && PasirinkimasFunkcijos == 1 || statymas > zaid.pinigai && PasirinkimasFunkcijos != 2) {
						cout << "Kiek pinigu norite pastatyti? ";
						cin >> statymas;

						if (statymas > zaid.pinigai) {
							cout << "Neturite pakankamai pinigu saskaitoje";
							PasirinkimasFunkcijos = 2;
						}
					}

					spal = spalva();
					sk = skaicius();
					PC_sk = sk.getsk();
					PC_sp = spal.get_spalva();

					if (PC_sp == PasirinkimoSpalva)
					{
						zaid.pinigai = zaid.pinigai + (statymas * 2);
						cout << " " << PC_sk << " " << PC_sp << endl;
						cout << "Sveikiname laimejote" << (statymas * 2) << "$" << endl;
					}
					else
					{
						zaid.pinigai = zaid.pinigai - statymas;
						cout << " " << PC_sk << " " << PC_sp << endl;
						cout << "Deja pralaimejote " << statymas << "$" << endl;
						cout << PC_sp << endl;
					}
					statymas = 0;
					if (zaid.pinigai > 0)
					{
						cout << "1. Testi zaidima toje pacioje kategorijoje" << endl;
						cout << "2. Gryzti atgal" << endl;
						cin >> PasirinkimasFunkcijos;
						if (PasirinkimasFunkcijos == 2)
						{
							Menu2();
							cin >> pasirinkimas2;

						}
					}






				}
			}

			if (pasirinkimas2 == 2)
			{
				PasirinkimasFunkcijos = 0;
				while (zaid.pinigai > 0 && PasirinkimasFunkcijos != 2)
				{
					cout << "Ant kurio stulpelio norite pastatyti?1 - 3 ";
					cin >> Spek;
					cout << zaid.var << "jus turite " << zaid.pinigai << endl;
					while (statymas == 0 && PasirinkimasFunkcijos == 1 || statymas > zaid.pinigai && PasirinkimasFunkcijos != 2) {
						cout << "Kiek pinigu norite pastatyti? ";
						cin >> statymas;

						if (statymas > zaid.pinigai) {
							cout << "Neturite pakankamai pinigu saskaitoje";
							PasirinkimasFunkcijos = 2;
						}
					}

					spal = spalva();
					sk = skaicius();
					PC_sk = sk.getsk();
					PC_sp = spal.get_spalva();
					PC_sk2 = spal.get_stulp();


					if (Spek == PC_sk2)
					{
						zaid.pinigai = zaid.pinigai + (statymas * 3);
						cout << " " << PC_sk << " " << PC_sp << " " << PC_sk2 << endl;
						cout << "Sveikinimai!! " << " Laimejote: " << (statymas * 3) << "$" << endl;

					}
					else
					{
						zaid.pinigai = zaid.pinigai - statymas;
						cout << " " << PC_sk << " " << PC_sp << " " << PC_sk2 << endl;
						cout << "Deja pralaimejote " << statymas << "$" << endl;
						cout << PC_sp << endl;
					}
					statymas = 0;
					if (zaid.pinigai > 0)
					{
						cout << "1. Testi zaidima toje pacioje kategorijoje" << endl;
						cout << "2. Gryzti atgal" << endl;
						cin >> PasirinkimasFunkcijos;
						if (PasirinkimasFunkcijos == 2)
						{
							Menu2();
							cin >> pasirinkimas2;

						}
					}

				}

			}


			if (pasirinkimas2 == 3)
			{

				PasirinkimasFunkcijos = 0;
				while (zaid.pinigai > 0 && PasirinkimasFunkcijos != 2 && (zaid.pinigai < zaid.pradzia * 7))
				{
					cout << "Ant kurios eilutes norite pastatyti?1 - 3 ";
					cin >> Spek;
					cout << zaid.var << "jus turite " << zaid.pinigai << endl;
					while (statymas == 0 && PasirinkimasFunkcijos == 1 || statymas > zaid.pinigai && PasirinkimasFunkcijos != 2) {
						cout << "Kiek pinigu norite pastatyti? ";
						cin >> statymas;

						if (statymas > zaid.pinigai) {
							cout << "Neturite pakankamai pinigu saskaitoje";
							PasirinkimasFunkcijos = 2;
						}
					}

					spal = spalva();
					sk = skaicius();
					PC_sk = sk.getsk();
					PC_sp = spal.get_spalva();
					PC_sk2 = spal.get_eil();


					if (Spek == PC_sk2)
					{
						zaid.pinigai = zaid.pinigai + (statymas * 3);
						cout << " " << PC_sk << " " << PC_sp << " " << PC_sk2 << endl;
						cout << "Sveikinimai!! " << " Laimejote: " << (statymas * 3) << "$" << endl;

					}
					else
					{
						zaid.pinigai = zaid.pinigai - statymas;
						cout << " " << PC_sk << " " << PC_sp << " " << PC_sk2 << endl;
						cout << "Deja pralaimejote " << statymas << "$" << endl;
						cout << PC_sp << endl;
					}
					statymas = 0;
					if (zaid.pinigai > 0)
					{
						cout << "1. Testi zaidima toje pacioje kategorijoje" << endl;
						cout << "2. Gryzti atgal" << endl;
						cin >> PasirinkimasFunkcijos;
						if (PasirinkimasFunkcijos == 2)
						{
							Menu2();
							cin >> pasirinkimas2;

						}
					}



				}
			}

			if (pasirinkimas2 == 4)
			{

				PasirinkimasFunkcijos = 0;
				while (zaid.pinigai > 0 && PasirinkimasFunkcijos != 2 && (zaid.pinigai < zaid.pradzia * 7))
				{
					cout << "Ant kurio skaiciaus norite pastatyti ";
					cin >> Spek;
					cout << zaid.var << " jus turite " << zaid.pinigai << endl;
					while (statymas == 0 && PasirinkimasFunkcijos == 1 || statymas > zaid.pinigai && PasirinkimasFunkcijos != 2) {
						cout << "Kiek pinigu norite pastatyti? ";
						cin >> statymas;

						if (statymas > zaid.pinigai) {
							cout << "Neturite pakankamai pinigu saskaitoje";
							PasirinkimasFunkcijos = 2;
						}
					}

					spal = spalva();
					sk = skaicius();
					PC_sk = sk.getsk();
					PC_sp = spal.get_spalva();



					if (Spek == PC_sk)
					{
						zaid.pinigai = zaid.pinigai + (statymas * 3);
						cout << " " << PC_sk << " " << PC_sp << endl;
						cout << "Sveikinimai!! " << " Laimejote: " << (statymas * 36) << "$" << endl;

					}
					else
					{
						zaid.pinigai = zaid.pinigai - statymas;
						cout << " " << PC_sk << " " << PC_sp << endl;
						cout << "Deja pralaimejote " << statymas << "$" << endl;
						cout << PC_sp << endl;
					}
					statymas = 0;
					if (zaid.pinigai > 0)
					{
						cout << "1. Testi zaidima toje pacioje kategorijoje" << endl;
						cout << "2. Gryzti atgal" << endl;
						cin >> PasirinkimasFunkcijos;
						if (PasirinkimasFunkcijos == 2)
						{
							Menu2();
							cin >> pasirinkimas2;

						}
					}



				}
			}

			if (pasirinkimas2 == 5)
			{

				PasirinkimasFunkcijos = 0;
				while (zaid.pinigai > 0 && PasirinkimasFunkcijos != 2 && (zaid.pinigai < zaid.pradzia * 7))
				{
					cout << "Ant keliu skaiciu norite pastatyti: ";
					cin >> n;
					for (int i = 0; i < n; i++)
					{
						cout << "Ant kurio skaiciaus norite pastatyti " << endl;
						cin >> SpekM[i];
					}
					cout << zaid.var << "jus turite " << zaid.pinigai << endl;
					statymas = 0;
					while (statymas == 0 && PasirinkimasFunkcijos == 1 || statymas > zaid.pinigai && PasirinkimasFunkcijos != 2)
					{
						cout << "Kiek pinigu norite pastatyti? ";
						cin >> statymas;

						if (statymas > zaid.pinigai) {
							cout << "Neturite pakankamai pinigu saskaitoje";
							PasirinkimasFunkcijos = 2;
						}
					}

						spal = spalva();
						sk = skaicius();
						PC_sk = sk.getsk();
						PC_sp = spal.get_spalva();


						for (int i = 0; i < n; i++)
						{
							if (SpekM[i] == PC_sk)
							{
								laimejimas = 1;
							}
						}
						if (laimejimas == 1)
						{
							zaid.pinigai = zaid.pinigai + (statymas * 3 / n);
							cout << " " << PC_sk << " " << PC_sp << endl;
							cout << "Sveikinimai!! " << " Laimejote: " << (statymas * 36 / n) << "$" << endl;


						}

						else
						{
							zaid.pinigai = zaid.pinigai - statymas;
							cout << " " << PC_sk << " " << PC_sp << endl;
							cout << "Deja pralaimejote " << statymas << "$" << endl;
							cout << PC_sp << endl;
						}
						statymas = 0;
						if (zaid.pinigai > 0)
						{
							cout << "1. Testi zaidima toje pacioje kategorijoje" << endl;
							cout << "2. Gryzti atgal" << endl;
							cin >> PasirinkimasFunkcijos;
							if (PasirinkimasFunkcijos == 2)
							{
								Menu2();
								cin >> pasirinkimas2;

							}
						}



					
				}

			}

		}
		if (pasirinkimas1 == 3) 
		{
			instrukcija();
		}
	}
		 while (pasirinkimas1 != 6 && pasirinkimas2 != 6);




		//--------------------------------------------------------------------------//

		//-cia buvo kodas

		//------------------------------------------------------------------------//
		return 0;


	
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
