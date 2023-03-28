#include <iostream>
#include <string>
#include <vector>

//Headerfile Animal classes
#include "animals.h"

//Functions
void StartScreen();
void StartRegistration(int& aantalOpenRegistraties);
void OverviewBirds();
void SearchBird();

//Object Vector for Class "Bird"
std::vector<Bird> Birds;

//Start Program
int main()
{
	StartScreen();
	return 0;
}

//Startscreen with a choice menu to register or see a overview of all the regeistered birds.
void StartScreen()
{
	int keuze = 0;
	int aantalOpenRegistraties = 10;
	system("cls");

	std::cout << "REGISTRATIE PROGRAMMA VOGELS - DIERENLOT\n\n"
		<< "Dit programma is bedoeld om net binnengekomen vogels te laten registreren voor Dierenlot.\nAantal open registraties: " << aantalOpenRegistraties << ".\n\n"
		<< "Kies een optie:\n"
		<< "1. Registreer vogel\n";
	if (Birds.empty())
	{
		std::cout << "2. Exit\n\n" << "Keuze: ";
		std::cin >> keuze;
		system("cls");

		switch (keuze)
		{
		case 1:
			StartRegistration(aantalOpenRegistraties);
			break;
		case 2:
			break;
		default:
			StartScreen();
		}
	}
	else {
		std::cout << "2. Zie overzicht vogels\n"
			<< "3. Zoek een specifieke vogel\n"
			<< "4. Exit\n\n" << "Keuze: ";
		std::cin >> keuze;
		system("cls");
		
		switch (keuze)
		{
		case 1:
			StartRegistration(aantalOpenRegistraties);
			break;
		case 2:
			OverviewBirds();
			break;
		case 3:
			SearchBird();
			break;
		case 4:
			break;
		default:
			StartScreen();
		}
	}
	system("cls");
}

//Starts the registration process of a bird.
void StartRegistration(int& aantalOpenRegistraties)
{
	int maxRegistraties = 10;
	std::string choice = "";
	Bird b;
	
	if (Birds.empty())
	{
		b.setBird();

		Birds.push_back(b);
	}
		
	for (int i = 0; i < maxRegistraties; i++)
	{
		if (aantalOpenRegistraties != 0) {
			std::cout << "Wilt u een andere vogel registreren? (Ja of Nee)\nKeuze: ";
			std::cin >> choice;

			if ((choice == "Ja") || (choice == "ja"))
			{
				system("cls");
				b.setBird();
				Birds.push_back(b);
				choice = "";
				aantalOpenRegistraties--;
			}
			else break;
		}
	}
	StartScreen();
}

//Views all the registered birds in the vector.
void OverviewBirds()
{
	for (int i = 0; i < Birds.size(); i++)
	{
		Birds[i].getBirds();
	}
				
	StartScreen();
}

void SearchBird()
{
	int ringnummer = 0;
	system("cls");
	std::cout << "Type de ringnummer van de betreffende vogel in om de overzicht te krijgen van deze vogel. Bijvoorbeeld: 123456\nRingnummer:";
	std::cin >> ringnummer;

	for (int i = 0; i < Birds.size(); i++)
	{
		if (Birds[i].getRingNumber() == ringnummer)
		{
			Birds[i].getBirds();
		}
	}
	StartScreen();
}
