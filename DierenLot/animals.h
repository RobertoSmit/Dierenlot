#include <iostream>
#include <string>

using namespace std;
class Animal {
protected:
	string type, height, weight, age;
	int number = 0;
};

class Afgever {
protected:
	std::string name, phone, email, street, housenumber, postcode, place;

	//Setter
	virtual void setCG()
	{
		std::cout << "CONTACTGEGEVENS - AFGEVER:\n----------------" << std::endl;
		std::cout << "Naam: "; std::cin >> this->name;
		std::cout << "Telefoon: "; std::cin >> this->phone;
		std::cout << "E-Mail: "; std::cin >> this->email;
		std::cout << "Straat: "; std::cin >> this->street;
		std::cout << "Huisnummer: "; std::cin >> this->housenumber;
		std::cout << "Postcode: "; std::cin >> this->postcode;
		std::cout << "Woonplaats: "; std::cin >> this->place;
		system("cls");
	}

	//Getter
	virtual void getCG()
	{
		std::cout << "\nCONTACTGEGEVENS AANMELDER:\n----------------\n"
			<< "Naam: " << this->name << std::endl
			<< "Telefoon: " << this->phone << std::endl
			<< "E-Mail: " << this->email << std::endl
			<< "Adres: " << this->street << " " << this->housenumber << std::endl
			<< "Postcode: " << this->postcode << std::endl
			<< "Woonplaats: " << this->place << std::endl;
		system("pause");
		system("cls");
	}
};

class General{
protected:
	std::string pvb, pvb_street, date;

	//Setter
	virtual void setAI()
	{
		std::cout << "ALGEMENE INFORMATIE:\n--------------------" << std::endl;
		std::cout << "Aanmeld Datum: "; std::cin >> this->date;
		std::cout << "Plaats van bevinding: "; std::cin >> this->pvb;
		std::cout << "Straat: "; std::cin >> this->pvb_street;
		system("cls");
	}

	//Getter
	virtual void getAI()
	{
		std::cout << "ALGEMENE INFORMATIE:\n--------------------\n"
			<< "Aanmeld Datum: " << this->date << std::endl
			<< "Plaats van bevinding: " << this->pvb << std::endl
			<< "Straat: " << this->pvb_street << std::endl;
	}
};

class Bird : Animal, Afgever, General {
private:
	std::string wingSpan, beakLength, tailLength;
	int ringNumber = 0;

	//Setters
	void setKM()
	{
		std::cout << "KENMERKEN:\n--------------" << std::endl;
		std::cout << "Type of vogel: "; std::cin >> this->type;
		std::cout << "Leeftijd (Jaar): "; std::cin >> this->age;
		std::cout << "Ringnummer (123456): "; std::cin >> this->ringNumber;
		std::cout << "Gewicht (Kg): "; std::cin >> this->weight;
		std::cout << "Hoogte (Cm): "; std::cin >> this->height;
		std::cout << "Spanwijdte (Cm): "; std::cin >> this->wingSpan;
		std::cout << "Snavel lengte (Cm): "; std::cin >> this->beakLength;
		std::cout << "Staart lengte (Cm): "; std::cin >> this->tailLength;
		system("cls");
	}
	
	//Getters
	void getKM()
	{
		std::cout << "\nKENMERKEN:\n--------------" << std::endl
			<< "Type of vogel: " << this->type << std::endl
			<< "Leeftijd: " << this->age << " years\n"
			<< "Ringnummer: " << this->ringNumber << std::endl
			<< "Gewicht: " << this->weight << " kg\n"
			<< "Hoogte: " << this->height << " cm\n"
			<< "Spanwijdte: " << this->wingSpan << " cm\n"
			<< "Snavel lengte: " << this->beakLength << " cm\n"
			<< "Staart lengte" << this->tailLength << "cm\n";
	}
	
public:
	void setBird()
	{
		for (int i = 1; i < 4; i++)
		{
			std::cout << "REGISTRATIE VOGEL " << number << std::endl << std::endl;
			this->number = number;
			switch (i)
			{ 
				case 1: 
					setAI();
					break;
				case 2: 
					setKM();
					break;
				case 3: 
					setCG();
					break;
			}
		}
		number++;
	}

	void getBirds()
	{
		std::cout << "\nREGISTRATIE VOGEL " << this->number << std::endl << std::endl;
		getAI();
		getKM();
		getCG();
	};

	int getRingNumber()
	{
		return this->ringNumber;
	}
};
