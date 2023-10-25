#include <iostream>
#include<string>
#include<cstring>
#define CRT_SECURE_NO_WARNINGS
using namespace std;
//Teodorescu Alexandra->Domeniul este TrAnsporturi

class Automobil {
public:
    static int nrAutomobile;
    const string nrSerie;
    char* marcaModel;
    int nrRoti;
    float* presiuneRoti;
    static int getNrAutomobile() {
        return nrAutomobile;

    }
    Automobil() :nrSerie("ASD5") {
        nrAutomobile++;
        this->marcaModel = new char[strlen("Audi") + 1];
        strcpy_s(this->marcaModel, strlen("Audi") + 1, "Audi");
        this->presiuneRoti = NULL;
        this->nrRoti = 4;
    }
    Automobil(const char* marcaModel, string nrSerie, int nrRoti) :nrSerie(nrSerie) {
        nrAutomobile++;
        this->nrRoti = nrRoti;
        this->marcaModel = new char[strlen(marcaModel) + 1];
        strcpy_s(this->marcaModel, strlen(marcaModel) + 1, marcaModel);
        this->presiuneRoti = NULL;

    }
    Automobil(const char* marcaModel, string nrSerie, int nrRoti, float* presiuneRoti) : nrSerie(nrSerie) {
        nrAutomobile++;
        this->marcaModel = new char[strlen(marcaModel) + 1];
        strcpy_s(this->marcaModel, strlen(marcaModel) + 1, marcaModel);
        this->nrRoti = nrRoti;
        if (nrRoti > 0) {
            this->presiuneRoti = new float[nrRoti];
            for (int i = 0; i < nrRoti; i++) {
                this->presiuneRoti[i] = presiuneRoti[i];
            }
        }
        else {
            this->presiuneRoti = NULL;
        }
    }


    ~Automobil() {
        if (this->marcaModel != NULL) {
            delete[] this->marcaModel;
        }
        if (this->presiuneRoti != NULL) {
            delete[] this->presiuneRoti;
        }

    }
    void afisareAutomobil() {

        cout << "Automobilul " << marcaModel << " cu seria " << nrSerie << " are " << nrRoti << " roti." << endl;
        if (presiuneRoti) {
            cout << "Presiunea rotilor este de: ";
            for (int i = 0; i < nrRoti; i++) {
                cout << presiuneRoti[i] << ",";
            }
        }

      
    }

};
int Automobil::nrAutomobile = 0;






class Tren {
public:
    const int nrMaximPasageri;
    static int nrTotalTrenuri;
    char* viteza;
    string model;
    static int getNrTotalTrenuri() {
        return nrTotalTrenuri;
    }

    Tren() : nrMaximPasageri(190) {
        this->model = "Trans";
        this->viteza = new char[strlen("230km/h") + 1];
        strcpy_s(this->viteza, strlen("230km/h") + 1, "230km/h");
        nrTotalTrenuri++;
    }

    Tren(string model, const char* viteza) : nrMaximPasageri(150) {
        this->model = model;
        this->viteza = new char[strlen(viteza) + 1];
        strcpy_s(this->viteza, strlen(viteza) + 1, viteza);
        nrTotalTrenuri++;
    }

    Tren(const char* viteza, string model, int nrMaximPasageri) : nrMaximPasageri(nrMaximPasageri) {
        this->model = model;
        this->viteza = new char[strlen(viteza) + 1];
        strcpy_s(this->viteza, strlen(viteza) + 1, viteza);
        nrTotalTrenuri++;
    }


    ~Tren() {
        if (viteza != NULL) {
            delete[] viteza;
        }
    }

    void afisareInfoTren() {
        cout << "Trenul " << model << " are viteza maxima de: " << viteza << " si numarul maxim de pasageri:  " << nrMaximPasageri << "." << endl;
      
    }
};

int Tren::nrTotalTrenuri = 0;


class Vapor {
public:
    static int nrVapoare;
    const int anFabricare;
    char* numeVapor;
    string destinatie;
    int capacitatePasageri;
    bool vaporDeMarfa;
    static int getNrVapoare() {
        return nrVapoare;
    }
    Vapor() :anFabricare(2018) {
        nrVapoare++;
        this->numeVapor = new char[strlen("Star Ocean") + 1];
        strcpy_s(this->numeVapor, strlen("Star Ocean") + 1, "Star Ocean");
        this->destinatie = "Insulele Caraibe";
        this->capacitatePasageri = 6345;
        this->vaporDeMarfa = false;

    }
    Vapor(const char* numeVapor, string destinatie, int anFabricare) :anFabricare(anFabricare) {
        nrVapoare++;
        this->numeVapor = new char[strlen(numeVapor) + 1];
        strcpy_s(this->numeVapor, strlen(numeVapor) + 1, numeVapor);
        this->destinatie = destinatie;
        this->capacitatePasageri = 8312;
        this->vaporDeMarfa = false;
    }
    Vapor(const char* numeVapor, string destinatie, int capacitatePasageri, int anFabricare, bool vaporDeMarfa) :anFabricare(anFabricare) {
        nrVapoare++;
        this->numeVapor = new char[strlen(numeVapor) + 1];
        strcpy_s(this->numeVapor, strlen(numeVapor) + 1, numeVapor);
        this->destinatie = destinatie;
        this->capacitatePasageri = capacitatePasageri;
        this->vaporDeMarfa = vaporDeMarfa;
    }

    ~Vapor() {
        if (numeVapor != NULL) {
            delete[] numeVapor;
        }

    }
    void afisareVapor() {
        cout << "Vaporul " << numeVapor << " cu destinatia: " << destinatie << " are " << capacitatePasageri <<" pasageri. Este fabricat in anul " << anFabricare << " si este : " << (vaporDeMarfa ? "vapor de marfa." : "vapor de pasageri.") << endl;
 
    }
};
int Vapor::nrVapoare = 0;
void main() {

    Automobil automobil1;

    automobil1.afisareAutomobil();

    Automobil automobil2("Suzuki", "SVR3", 4);
    automobil2.afisareAutomobil();
    float presiuneRoti[] = { 35.5, 36.0,34.8,35.2 };
    Automobil automobil3("Mercedes", "CDR3", 4, presiuneRoti);
    automobil3.afisareAutomobil();
    cout << endl;
    cout << "Numar total de automobile: " << Automobil::getNrAutomobile() << endl;
    cout << endl << endl;

    Tren tren1;
    Tren tren2("CFR", "240km/h");
    Tren tren3("250km/h", "Express", 250);
    tren1.afisareInfoTren();
    tren2.afisareInfoTren();
    tren3.afisareInfoTren();

    cout << "Numar total de trenuri este: " << Tren::nrTotalTrenuri << endl;
    cout << endl << endl;

    Vapor vapor1;
    vapor1.afisareVapor();
    Vapor vapor2("Aqua Wave", "Insulele Hawaii", 2020);
    vapor2.afisareVapor();
    Vapor vapor3("Magisitc Marine", "Bora Bora", 3467, 2021, false);
    vapor3.afisareVapor();

    cout << "Numar total de vapoare este: " << Vapor::getNrVapoare() << endl;


}


