#include <iostream>
#include<string>
#define CRT_SECURE_NO_WARNINGS
using namespace std;
//Teodorescu Alexandra->Domeniul este TrAnsporturi

class Automobil {
private:

    static int nrAutomobile;
    const string nrSerie;
    char* marcaModel;
    int nrRoti;
    float* presiuneRoti;
public:

    static int getNrAutomobile() {
        return nrAutomobile;

    }
    Automobil() :nrSerie("0000") {
        nrAutomobile++;
        this->marcaModel = new char[strlen("X") + 1];
        strcpy_s(this->marcaModel, strlen("X") + 1, "X");
        this->presiuneRoti = NULL;
        this->nrRoti = 0;
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
        this->presiuneRoti = new float[nrRoti];
        for (int i = 0; i < nrRoti; i++) {
            this->presiuneRoti[i] = presiuneRoti[i];
        }

    }
    Automobil(const Automobil& a) :nrSerie(a.nrSerie) {
        this->marcaModel = new char[strlen(a.marcaModel) + 1];
        strcpy_s(this->marcaModel, strlen(a.marcaModel) + 1, a.marcaModel);
        this->nrRoti = a.nrRoti;
        if (nrRoti > 0) {
            this->presiuneRoti = new float[a.nrRoti];
            for (int i = 0; i < a.nrRoti; i++) {
                this->presiuneRoti[i] = a.presiuneRoti[i];
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
                cout << presiuneRoti[i] << " ";
            }
        }

    }


    const string& getNrSerie() {
        return this->nrSerie;
    }

    const char* getMarcaModel() {
        return this->marcaModel;

    }

    int getNrRoti() {
        return this->nrRoti;
    }

    float* getPresiuneRoti() {
        return this->presiuneRoti;
    }

    void setMarcaModel(const char* marcaModel) {
        if (this->marcaModel) {
            delete[] this->marcaModel;
        }
        this->marcaModel = new char[strlen(marcaModel) + 1];
        strcpy_s(this->marcaModel, strlen(marcaModel) + 1, marcaModel);


    }

    void setPresiuneRoti(int nrRoti, float* presiuneRoti) {
        this->nrRoti = nrRoti;
        if (nrRoti > 0) {
            if (this->presiuneRoti != NULL) {
                delete[] this->presiuneRoti;
            }
            this->presiuneRoti = new float[nrRoti];
            for (int i = 0; i < nrRoti; i++) {
                this->presiuneRoti[i] = presiuneRoti[i];
            }
        }
    }


    friend float pretRoti(const Automobil& a);
};
int Automobil::nrAutomobile = 0;

float pretRoti(const Automobil& a) {
    return a.nrRoti * 100;
}


class Tren {
private:
    const int nrMaximPasageri;
    static int nrTotalTrenuri;
    char* viteza;
    string model;
public:
    static int getNrTotalTrenuri() {
        return nrTotalTrenuri;
    }

    Tren() : nrMaximPasageri(0) {
        this->model = "N/A";
        this->viteza = new char[strlen("X") + 1];
        strcpy_s(this->viteza, strlen("X") + 1, "X");
        nrTotalTrenuri++;
    }

    Tren(string model, const char* viteza) : nrMaximPasageri(0) {
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

    Tren(const Tren& t) :nrMaximPasageri(t.nrMaximPasageri) {
        this->model = t.model;
        this->viteza = new char[strlen(t.viteza) + 1];
        strcpy_s(this->viteza, strlen(t.viteza) + 1, t.viteza);
    }



    ~Tren() {
        if (viteza != NULL) {
            delete[]this->viteza;
        }
    }

    void afisareInfoTren() {
        cout << "Trenul " << model << " are viteza maxima de: " << viteza << " si numarul maxim de pasageri:  " << nrMaximPasageri << "." << endl;

    }

    int getNrMaximPasageri() {
        return this->nrMaximPasageri;
    }
    char* getViteza() {
        return this->viteza;
    }
    string getModel() {
        return this->model;
    }
    void setViteza(const char* viteza) {
        delete[] this->viteza;
        this->viteza = new char[strlen(viteza) + 1];
        strcpy_s(this->viteza, strlen(viteza) + 1, viteza);
    }
    void setModel(string model) {
        this->model = model;
    }
};

int Tren::nrTotalTrenuri = 0;


class Vapor {
private:
    static int nrVapoare;
    const int anFabricare;
    char* numeVapor;
    string destinatie;
    int capacitatePasageri;
    bool vaporDeMarfa;
public:

    static int getNrVapoare() {
        return nrVapoare;
    }
    Vapor() :anFabricare(0) {
        nrVapoare++;
        this->numeVapor = new char[strlen("X") + 1];
        strcpy_s(this->numeVapor, strlen("X") + 1, "X");
        this->destinatie = "N/A";
        this->capacitatePasageri = 0;
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

    Vapor(const Vapor& v) :anFabricare(v.anFabricare) {
        this->numeVapor = new char[strlen(v.numeVapor) + 1];
        strcpy_s(this->numeVapor, strlen(v.numeVapor) + 1, v.numeVapor);
        this->destinatie = v.destinatie;
        this->capacitatePasageri = v.capacitatePasageri;
        this->vaporDeMarfa = v.vaporDeMarfa;


    }


    ~Vapor() {
        if (numeVapor != NULL) {
            delete[]this->numeVapor;
        }

    }
    int getAnFabricare() {
        return this->anFabricare;
    }
    char* getNumeVapor() {
        return this->numeVapor;
    }
    string getDestinatie() {
        return this->destinatie;
    }
    int getCapacitatePasageri() {
        return this->capacitatePasageri;
    }
    bool getVaporDeMarfa() {
        return this->vaporDeMarfa;
    }
    void setNumeVapor(const char* numeVapor) {
        delete[] this->numeVapor;
        this->numeVapor = new char[strlen(numeVapor) + 1];
        strcpy_s(this->numeVapor, strlen(numeVapor) + 1, numeVapor);
    }
    void setDestinatie(string destinatie) {
        this->destinatie = destinatie;
    }
    void setCapacitatePasageri(int capacitatePasageri) {
        this->capacitatePasageri = capacitatePasageri;
    }
    void setVaporDeMarfa(bool vaporDeMarfa) {
        this->vaporDeMarfa = vaporDeMarfa;
    }

    void afisareVapor() {
        cout << "Vaporul " << numeVapor << " cu destinatia: " << destinatie << " are " << capacitatePasageri << " pasageri. Este fabricat in anul " << anFabricare << " si este : " << (vaporDeMarfa ? "vapor de marfa." : "vapor de pasageri.") << endl;

    }
    friend float costCroaziera(const Vapor& v);
};
int Vapor::nrVapoare = 0;

float costCroaziera(const Vapor& v) {
    return v.capacitatePasageri * 200;
}





void main() {

    Automobil automobil1;

    automobil1.afisareAutomobil();
    Automobil automobil2("Suzuki", "SVR3", 4);
    automobil2.afisareAutomobil();
    float* presiuneRoti = new float[4] { 35.5, 36.0, 34.8, 35.2 };
    Automobil automobil3("Mercedes", "CDR3", 4, presiuneRoti);
    automobil3.afisareAutomobil();
    cout << endl;
    cout << "Numar total de automobile: " << Automobil::getNrAutomobile() << endl;

    cout << endl << endl;

    Tren tren1;
    Tren tren2("CFR", "240 km/h");
    Tren tren3("250 km/h", "Express", 250);
    tren1.afisareInfoTren();
    tren2.afisareInfoTren();
    tren3.afisareInfoTren();

    cout << "Numar total de trenuri este: " << Tren::getNrTotalTrenuri() << endl;


    cout << endl << endl;

    Vapor vapor1;
    vapor1.afisareVapor();
    Vapor vapor2("Aqua Wave", "Insulele Hawaii", 2020);
    vapor2.afisareVapor();
    Vapor vapor3("Magisitc Marine", "Bora Bora", 3467, 2021, false);
    vapor3.afisareVapor();

    cout << "Numar total de vapoare este: " << Vapor::getNrVapoare() << endl;
    cout << endl << endl;


    cout << "================================================================= " << endl;
    cout << "Getteri si setteri:" << endl << endl;

    Automobil auto1 = automobil3;
    auto1.afisareAutomobil();
    cout << endl << endl;
    cout << auto1.getNrSerie() << endl;
    cout << auto1.getMarcaModel() << endl;
    cout << auto1.getNrRoti() << endl;
    for (int i = 0; i < auto1.getNrRoti(); i++) {
        cout << auto1.getPresiuneRoti()[i] << ",";
    }
    cout << endl << endl;
    cout << "Pretul rotilor este de:" << pretRoti(auto1) << " lei." << endl;
    cout << endl;

    auto1.setMarcaModel("Renault Captur");
    float* presiuneR = new float[4] { 37.0, 36.2, 35.6, 36.4 };
    auto1.setPresiuneRoti(4, presiuneR);
    cout << endl;
    auto1.afisareAutomobil();
    cout << endl << endl;
    cout << auto1.getNrSerie() << endl;
    cout << auto1.getMarcaModel() << endl;
    cout << auto1.getNrRoti() << endl;
    for (int i = 0; i < auto1.getNrRoti(); i++) {
        cout << auto1.getPresiuneRoti()[i] << " ";
    }
    cout << endl;
    cout << "==============================================================" << endl;

    Tren t1 = tren3;
    t1.afisareInfoTren();
    cout << endl << endl;
    cout << tren3.getNrMaximPasageri() << endl;
    cout << tren3.getModel() << endl;
    cout << tren3.getViteza() << endl;
    cout << endl;
    tren3.setModel("Travel");
    tren3.setViteza("220 km/h");
    cout << endl;
    tren3.afisareInfoTren();
    cout << endl << endl;
    cout << tren3.getNrMaximPasageri() << endl;
    cout << tren3.getModel() << endl;
    cout << tren3.getViteza() << endl;

    cout << endl;
    cout << "====================================================================" << endl;

    Vapor v1 = vapor3;
    v1.afisareVapor();
    cout << endl << endl;
    cout << v1.getAnFabricare() << endl;
    cout << v1.getCapacitatePasageri() << endl;
    cout << v1.getDestinatie() << endl;
    cout << v1.getNumeVapor() << endl;
    cout << v1.getVaporDeMarfa() << endl;
    cout << endl;
    cout << "Costul croazierei este de: " << costCroaziera(v1) << " euro." << endl;

    cout << endl;
    v1.setCapacitatePasageri(4211);
    v1.setDestinatie("Insula Thassos");
    v1.setNumeVapor("Aqua Star");
    v1.setVaporDeMarfa(false);
    cout << endl;
    v1.afisareVapor();
    cout << endl;
    cout << v1.getAnFabricare() << endl;
    cout << v1.getCapacitatePasageri() << endl;
    cout << v1.getDestinatie() << endl;
    cout << v1.getNumeVapor() << endl;
    cout << v1.getVaporDeMarfa() << endl;

    delete[]presiuneRoti;
    delete[]presiuneR;
}