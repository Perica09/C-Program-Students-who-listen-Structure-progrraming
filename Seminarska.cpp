#include <iostream> //standardna biblioteka za vlez i izlez
#include <fstream> //biblioteka za kreiranje i koristenje datoteki
#include <string> //biblioteka za koristenje na operaciite so stringovi
using namespace std; //iostream svoite identifikatori gi deklarira da bidat vo prostorot so iminja std

void BubbleSort(string niza1[], string niza2[], int niza3[], int niza4[], int niza5[], int niza6[][50], int niza7[], int n); //Prototip na funkcijata BubbleSort
void Zamena(string niza[], int i, int j); //Prototip na funkcijata Zamena
void Zamenai(int niza[], int i, int j); //Prototip na funkcijata Zamenai

int main()
{
	ofstream SP("Studenti.txt"); //Se kreira datoteka i se otvara tekstualen dokumentot kade ke se zacuvuvaat podatocite

	//Kreiranje promenlivi
	string Ime;
	string Prezime;
	int Broj_na_indeks;
	int Poeni_od_pz;
	int Broj_na_polagani_kol;
	int Poeni_od_kol[4];
	int Poeni_na_kraen_ispit;

	cout << "Za kolku studenti sakas da vneses podatoci?" << endl;
	int Studenti = 0; //Kreiranje na promenlivata Studenti i nejzino inicijaliziranje
	cin >> Studenti; //Vnesuvanje broj za kolku studenti se vnesuvaat podatoci
	while (Studenti > 50) //Ogranicuvanje na brojot na studenti na 50, ako e pogolem od 50 da ispecate ERROR Message i da dade opcija za vnesuvanje povtorno
	{
		cout << "Maksimalen broj na studenti e 50, obidi se povtorno" << endl; //ERROR Message
		cin >> Studenti;
	}
	cin.clear(); //Validacija
	cin.ignore(100, '\n'); //Validacija

	//Kreiranje na promenliva cija vrednost ke se zgolemuva po vnesuvanjeto na podatoci za sekoj student
	//i ke pomogne za vrtenje na ciklusot
	int Broj_na_studenti = 0;
	while (Broj_na_studenti < Studenti) //Ciklusot ke vrti se dodeka da se vnesat podatoci za site studenti
	{
		cout << "Vnesi ime na studentot" << endl;
		getline(cin, Ime); //Za vnesuvanje na imeto, da go prifati i ako se sostoi od 2 zbora (t.e. naide na prazno mesto. Primer:Ana Marija)

		while (Ime.length() > 15) //Se ogranicuva imeto da e maksimum 15 karaktera
		{
			cout << "Maksimalniot broj na bukvi e 15" << endl;
			getline(cin, Ime); //Ako imeto e pogolemo od 15 bukvi, da se vnese povtorno
		}
		SP << Ime << ","; //Vnesuvanje na imeto vo datotekata
		cin.clear(); //Validacija

		cout << "Vnesi prezime na studentot" << endl;
		getline(cin, Prezime); //Vnesuvanje na prezime

		while (Prezime.length() > 15) //Ogranicuvanje na prezimeto na 15 bukvi
		{
			cout << "Maksimalniot broj na bukvi e 15" << endl;
			getline(cin, Prezime); //Ako prezimeto e pogolemo od 15 bukvi, da se vnese povtorno
		}
		SP << Prezime << ","; //Vnesuvanje na prezimeto vo datotekata
		cin.clear(); //Validacija

		cout << "Vnesi broj na indeks na studentot" << endl;
		cin >> Broj_na_indeks; //Vneusvanje broj na indeks
		while (Broj_na_indeks > 999999) //Ogranicuvanje na brojot na indeks na 6 cifri
		{
			cout << "Maksimalniot broj na cifri e 6" << endl;
			cin >> Broj_na_indeks; //Ako e pogolem od 6 cifri, da se vnese povtorno
		}
		SP << Broj_na_indeks << ","; //Vnesuvanje na broj na indeks vo datoteka
		cin.clear(); //Validacija
		cin.ignore(100, '\n'); //Validacija

		cout << "Vnesi poeni od proektna zadaca" << endl;
		cin >> Poeni_od_pz; //Vnesuvanje poeni od proektna zadaca
		while (Poeni_od_pz < 0 || Poeni_od_pz > 100) // Ogranicuvanje na poenite od 0 do 100
		{
			cout << "Poenite se dvizat od 0 do 100" << endl;
			cin >> Poeni_od_pz; //Ako poenite se pod 0 ili nad 100 da se vnese povtorno
		}
		SP << Poeni_od_pz << ","; //Vnesuvanje na poenite od proektnata zadaca vo datotekata
		cin.clear(); //Validacija
		cin.ignore(100, '\n'); //Validacija

		cout << "Vnesi broj na polagani kolokviumi" << endl;
		cin >> Broj_na_polagani_kol; //Vnesuvanje na broj na polagani kolokviumi
		while (Broj_na_polagani_kol < 0 || Broj_na_polagani_kol > 4) //Ogranicuvanje na broj na kolokviumi
		{
			cout << "Brojot na kolokviumi se dvizi od 0 do 4" << endl;
			cin >> Broj_na_polagani_kol; //Ako e pomal od 0 ili pogolem od 4, da se vnese povtorno
		}
		SP << Broj_na_polagani_kol << ","; //Vnesuvanje na broj na polagani kolokviumi vo datotekata
		cin.clear(); //Validacija
		cin.ignore(100, '\n'); //Validacija

		for (int x = 0; x < Broj_na_polagani_kol; x++) //For ciklus za vnesuvanje na poeni od site kolokviumi
		{
			cout << "Vnesi poeni od kolokvium " << x + 1 << endl;
			cin >> Poeni_od_kol[x]; //Vnesuvanje poeni od kolokvium
			while (Poeni_od_kol[x] < 0 || Poeni_od_kol[x] > 100) //Ogranicuvanje na poeni od kolokvium
			{
				cout << "Poenite se dvizat od 0 do 100" << endl;
				cin >> Poeni_od_kol[x]; //Ako poenite ne se izmegu 0 i 100 da se vnesat povtorno
			}
			SP << Poeni_od_kol[x] << ","; //Vnesuvanje na poeni vo datotekata
		}
		cin.clear(); //Validacija
		cin.ignore(100, '\n'); //Validacija

		cout << "Vnesi poeni od kraen ispit" << endl;
		cin >> Poeni_na_kraen_ispit; //Vnesuvanje poeni od kraen ispit
		while (Poeni_na_kraen_ispit < 0 || Poeni_na_kraen_ispit > 100) //Ogranicuvanje na poenite
		{
			cout << "Poenite se dvizat od 0 do 100" << endl;
			cin >> Poeni_na_kraen_ispit; //Ako poenite ne se izmegu 0 i 100, da se vnesat povtorno
		}
		SP << Poeni_na_kraen_ispit; //Vnesuvanje na poenite vo datotekata
		cin.clear(); //Validacija
		cin.ignore(100, '\n'); //Validacija

		SP << endl; //Vnesuvanje nov red vo datotekata za nov student
		cin.clear(); //Validacija


		Broj_na_studenti++; //Se zgolemuva brojot na studenti, za da moze da vrte ciklusot i da se vnesuvat podatoci za sleden student

	}
	SP.close(); //Se zavtora datotekata SP

	ifstream StP("Studenti.txt"); //Vcituvanje na podatocite od fajlot Studenti.txt
	//Kreiranje nizi za vnesuvanje na podatocite
	string Student_ime[50];
	string Student_prezime[50];
	int Student_br_index[50];
	int Studenti_poeni_pz[50];
	int Student_br_kol[50];
	int Student_poeni_kol[50][50];
	int Student_ispit[50];

	string Student_linija; //Promenliva vo koja ke se smesti celata linija podatoci za eden student
	int i = 0; //Kreiranje na brojac
	while (getline(StP, Student_linija)) //Ciklus za podelba na sekoja linija na stringovi
	{
		Student_ime[i] = Student_linija.substr(0, Student_linija.find(",")); //Se zema prviot string (prviot del do prvata zapirka) i se smestuva vo ime
		Student_linija.erase(0, Student_linija.find(",") + 1); // Se brise delot sto se odvoil za prv string zaedno so zapirkata za da moze podocna da se odvoir sledniot del sto ke se smesti vo prezime

		Student_prezime[i] = Student_linija.substr(0, Student_linija.find(","));
		Student_linija.erase(0, Student_linija.find(",") + 1);

		Student_br_index[i] = stoi(Student_linija.substr(0, Student_linija.find(","))); //Se deli brojot na indeks i se smestuva vo soodvetnata niza
		//Stoi se koristi za konvertiranje t.e. funkcijata koja se koristi za podelba na string da moze da se iskoristi za integer
		Student_linija.erase(0, Student_linija.find(",") + 1);

		Studenti_poeni_pz[i] = stoi(Student_linija.substr(0, Student_linija.find(",")));
		Student_linija.erase(0, Student_linija.find(",") + 1);

		Student_br_kol[i] = stoi(Student_linija.substr(0, Student_linija.find(",")));
		Student_linija.erase(0, Student_linija.find(",") + 1);

		for (int y = 0; y < Student_br_kol[i]; y++) //Se delat poenite od site kolokviumi kako i prethodno
		{
			//Vo prvite [] si stoi i bidejki ciklusot vrti za istiot student, a se menuva y vo vtorite [] bidejki se zemaat poeni od razlicen kolokvium
			Student_poeni_kol[i][y] = stoi(Student_linija.substr(0, Student_linija.find(",")));
			Student_linija.erase(0, Student_linija.find(",") + 1);
		}


		Student_ispit[i] = stoi(Student_linija.substr(0, Student_linija.find(",")));
		Student_linija.erase(0, Student_linija.find(",") + 1);

		i++;
	}

	ofstream SortSP("Sort.dat"); //Kreiranje na nova datoteka

	BubbleSort(Student_prezime, Student_ime, Student_br_index, Studenti_poeni_pz, Student_br_kol ,Student_poeni_kol, Student_ispit, Studenti); //Iskoristuvanje na BubbleSort funkcijata za sortiranje na podatocite, t.e. na studentite

	for (int x = 0; x < Studenti; x++) //Ciklus za smestuvanje na podatocite na studentite vo novata datoteka, no veke sortirani
	{
		SortSP << Student_prezime[x] << "," << Student_ime[x] << "," << Student_br_index[x] << "," << Studenti_poeni_pz[x] << "," << Student_br_kol[x] << ",";
		for (int kol = 0; kol < Student_br_kol[x]; kol++) //Ciklus za smestuvanje na site poeni od kolokviumite na studentite vo novata datoteka
		{
			SortSP << Student_poeni_kol[x][kol] << ",";
		}
		SortSP << Student_ispit[x] << endl;
	}
	SortSP.close(); //Zatvoranje na datotekata SortSP
	system("CLS"); //Naredba za cistenje na ekranot od site podatoci koga ja pecati krajnata ocenka na kraj

	ifstream SPS("Sort.dat"); //Vcituvanje na podatocite od fajlot Sort.dat
	string Sort_student; //Promenliva vo koja ke se smesti celata linija podatoci za eden student
	while (getline(SPS, Sort_student))//Ciklus za podelba na sekoja linija na stringovi, no veke sortirani
	{
		//Deklariranje na promenlivi
		string Prezime_student;
		string Ime_student;
		int Index_student;
		int Br_kol_student;
		double Prosek = 0;
		double Prosek_kol = 0;

		Prezime_student = Sort_student.substr(0, Sort_student.find(",")); //Se zema prviot string (prviot del do prvata zapirka) i se smestuva vo ime
		Sort_student.erase(0, Sort_student.find(",") + 1); // Se brise delot sto se odvoil za prv string zaedno so zapirkata za da moze podocna da se odvoir sledniot del sto ke se smesti vo prezime

		Ime_student = Sort_student.substr(0, Sort_student.find(","));
		Sort_student.erase(0, Sort_student.find(",") + 1);

		Index_student = stoi(Sort_student.substr(0, Sort_student.find(","))); //Se deli brojot na indeks i se smestuva vo soodvetnata niza
		//Stoi se koristi za konvertiranje od string vo integer, t.e. funkcijata koja se koristi za podelba na string da moze da se iskoristi za integer
		Sort_student.erase(0, Sort_student.find(",") + 1);

		//Se koristi del od formulata za presmetuvanje prosek, 0.1*(Poeni od proektna zadaca)
		Prosek += 0.1 * stoi(Sort_student.substr(0, Sort_student.find(",")));
		Sort_student.erase(0, Sort_student.find(",") + 1);

		Br_kol_student = stoi(Sort_student.substr(0, Sort_student.find(",")));
		Sort_student.erase(0, Sort_student.find(",") + 1);

		for (int y = 0; y < Br_kol_student; y++) //Se delat poenite od site kolokviumi kako i prethodno
		{
			Prosek_kol += stoi(Sort_student.substr(0, Sort_student.find(",")));
			Sort_student.erase(0, Sort_student.find(",") + 1);
		}
		//Koristenje na formulata za prosek od kolokviumi
		Prosek_kol = (Prosek_kol / Br_kol_student) - ((4 - Br_kol_student) * 5);
		Prosek += 0.4 * Prosek_kol; //Se koristi prodolzetokot od formulata za prosek, 0.4*(Prosek od kolokviumi)
		Prosek += 0.5 * stoi(Sort_student.substr(0, Sort_student.find(","))); // Na kraj se koristi posledniot del od formulata, 0.5*(poeni od ispit)
		Sort_student.erase(0, Sort_student.find(",") + 1);
		int ocena = 5; //Se kreira promenliva ocena 
		bool polozen = false; //Se kreira promenliva polozen od tip bool i se inicijalizira na false
		//Proveruva kolkav e prosekot i spored toa se odreduva ocenata i promenlivata polozen ja menuva vrednosta vo zavisnost so ocenkata i toa dali e polozen predmetot
		if (Prosek >= 90) {
			ocena = 10;
			polozen = true;
		}
		else if (Prosek >= 80) {
			ocena = 9;
			polozen = true;
		}
		else if (Prosek >= 70) {
			ocena = 8;
			polozen = true;
		}
		else if (Prosek >= 60) {
			ocena = 7;
			polozen = true;
		}
		else if (Prosek >= 50) {
			ocena = 6;
			polozen = true;
		}

		//Ako predmetot e polozen, da se otpecati ocenkata na ekran, ako ne e, da otpecati poraka deka ne e polozen predmetot
		if (polozen == true)
		{
			cout << "Student " << Prezime_student << " " << Ime_student << " so index " << Index_student << " Ima ocena " << ocena << endl;
		}
		else
		{
			cout << "Student " << Prezime_student << " " << Ime_student << " so index " << Index_student << " go nema polozeno predmetot" << endl;
		}
		
	}
	return 0;
}

void Zamena(string niza[], int i, int j) //Funkcija koja  vrsi zamena na dva stringa
{
	string pomos = niza[i];
	niza[i] = niza[j];
	niza[j] = pomos;
}
void Zamenai(int niza[], int i, int j) //Funkcija koja vrsi zamena na dva intedzeri
{
	int pomos = niza[i];
	niza[i] = niza[j];
	niza[j] = pomos;
}

//Funkcija za sortiranje na stringovite
void BubbleSort(string niza1[], string niza2[], int niza3[], int niza4[], int niza5[], int niza6[][50], int niza7[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (niza1[j] > niza1[j + 1]) 
				{
					Zamena(niza1, j, j + 1);
					Zamena(niza2, j, j + 1);
					Zamenai(niza3, j, j + 1);
					Zamenai(niza4, j, j + 1);
					Zamenai(niza5, j, j + 1);
					swap(niza6[j], niza6[j + 1]);
					Zamenai(niza7, j, j + 1);
				}
		}
	}
}
