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
    Automobil() :nrSerie("N/A") {
        nrAutomobile++;
        this->marcaModel = new char[strlen("Skoda") + 1];
        strcpy_s(this->marcaModel, strlen("Skoda") + 1, "Skoda");
        this->presiuneRoti = NULL;
        this->nrRoti = 6;
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

    Automobil& operator=(const Automobil& a) {
        if (this != &a) {
            if (this->marcaModel != NULL) {
                delete[]this->marcaModel;
            }
            this->marcaModel = new char[strlen(a.marcaModel) + 1];
            strcpy_s(this->marcaModel, strlen(a.marcaModel) + 1, a.marcaModel);
            this->nrRoti = a.nrRoti;
            if (this->presiuneRoti != NULL) {
                delete[]this->presiuneRoti;
            }

            this->presiuneRoti = new float[this->nrRoti];
            for (int i = 0; i < this->nrRoti; i++) {
                this->presiuneRoti[i] = a.presiuneRoti[i];
            }
        }
        return *this;
    }
    explicit operator float() {
        float s = 0;
        for (int i = 0; i < this->nrRoti; i++)
        {
            s = s + this->presiuneRoti[i];
        }
        return s;

    }

    float& operator[](int pozitie) {
        if (pozitie >= 0 && pozitie < this->nrRoti) {
            return this->presiuneRoti[pozitie];
        }

    }

    friend ostream& operator<<(ostream& automobil, const Automobil& a) {
        automobil << "Marca: " << a.marcaModel << " ,Serie: " << a.nrSerie << ", Numar roti: " << a.nrRoti;
        if (a.presiuneRoti != NULL && a.nrRoti > 0) {
            for (int i = 0; i < a.nrRoti; i++) {
                automobil << a.presiuneRoti[i] << " ";
            }
        }
        return automobil;
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
        else {
            cout << "-" << endl;;

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
    string model;
    int nrVagoane;
    char* culoare;

public:
    static int getNrTotalTrenuri() {
        return nrTotalTrenuri;
    }

    Tren() : nrMaximPasageri(234) {
        this->model = "Speedy";
        this->nrVagoane = 4;
        this->culoare = new char[strlen("Albastru") + 1];
        strcpy_s(this->culoare, strlen("Albastru") + 1, "Albastru");
        nrTotalTrenuri++;
    }

    Tren(string model, const char* culoare) : nrMaximPasageri(0) {
        this->model = model;
        this->nrVagoane = 4;
        this->culoare = new char[strlen(culoare) + 1];
        strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
        nrTotalTrenuri++;
    }

    Tren(const char* culoare, string model, int nrVagoane, int nrMaximPasageri) : nrMaximPasageri(nrMaximPasageri) {
        this->model = model;
        this->nrVagoane = nrVagoane;
        this->culoare = new char[strlen(culoare) + 1];
        strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
        nrTotalTrenuri++;
    }

    Tren(const Tren& t) :nrMaximPasageri(t.nrMaximPasageri) {
        this->model = t.model;
        this->nrVagoane = t.nrVagoane;
        this->culoare = new char[strlen(t.culoare) + 1];
        strcpy_s(this->culoare, strlen(t.culoare) + 1, t.culoare);
    }

    Tren operator=(const Tren& t) {
        if (this != &t) {
            this->model = t.model;
            this->nrVagoane = t.nrVagoane;
            if (culoare != NULL) {
                delete[]this->culoare;
            }
            this->culoare = new char[strlen(t.culoare) + 1];
            strcpy_s(this->culoare, strlen(t.culoare) + 1, t.culoare);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& tren, const Tren& t) {
        tren << "Model: " << t.model << " ,Numar vagoane: " << t.nrVagoane << ", Culoare: " << t.culoare << " , Numarul maxim de pasageri: " << t.nrMaximPasageri;
        
        return tren;
    }
    bool operator!=(const Tren& t) {
        return this->nrVagoane != t.nrVagoane;
   }
    Tren& operator+=(const Tren& t) {
        this->nrVagoane += t.nrVagoane;
        return *this;
    }

    ~Tren() {
        if (culoare != NULL) {
            delete[]this->culoare;
        }
    }

    void afisareInfoTren() {
        cout << "Trenul " << model << " are:  " << nrVagoane << " vagoane ,culoarea: " << culoare << " si numarul maxim de pasageri : " << nrMaximPasageri << "." << endl;

    }

    int getNrMaximPasageri() {
        return this->nrMaximPasageri;
    }
    char* getCuloare() {
        return this->culoare;
    }
    string getModel() {
        return this->model;
    }
    int getNrVagoane() {
        return this->nrVagoane;
    }
    void setCuloare(const char* culoare) {
        delete[] this->culoare;
        this->culoare = new char[strlen(culoare) + 1];
        strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
    }
    void setModel(string model) {
        this->model = model;
    }
    void setNrVagoane(int nrVagoane) {
        this->nrVagoane = nrVagoane;
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
        this->numeVapor = new char[strlen("Aqua") + 1];
        strcpy_s(this->numeVapor, strlen("Aqua") + 1, "Aqua");
        this->destinatie = "Thassos";
        this->capacitatePasageri = 5454;
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
    Vapor operator=(const Vapor& v) {
        if (this != &v) {
            if (numeVapor != NULL) {
                delete[]this->numeVapor;
            }
            this->numeVapor = new char[strlen(v.numeVapor) + 1];
            strcpy_s(this->numeVapor, strlen(v.numeVapor) + 1, v.numeVapor);
            this->destinatie = v.destinatie;
            this->capacitatePasageri = v.capacitatePasageri;
            this->vaporDeMarfa = v.vaporDeMarfa;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& vapor, const Vapor& v) {
        vapor << "Nume: " << v.numeVapor << " ,Destinatie: " << v.destinatie << ", Capacitate pasageri: " << v.capacitatePasageri << " , An fabricare: " << v.anFabricare << (v.vaporDeMarfa ? " ,Vapor de marfa." : " ,Vapor de pasageri.");

        return vapor;
    }
    
    string operator()(string denumire) {
        return this->destinatie + denumire;
    }
    friend istream& operator>>(istream& ist, Vapor& v) {
        char aux[100];
        cout << "Nume: ";
        ist >> aux;
        if (v.numeVapor != NULL) {
            delete[]v.numeVapor;
        }
        v.numeVapor= new char[strlen(aux) + 1];
        strcpy_s(v.numeVapor, strlen(aux) + 1, aux);
        cout << "Destinatie: ";
        ist >> v.destinatie;
        cout << "Capacitate pasagerilor este de: ";
        ist >> v.capacitatePasageri;
        cout << "Este vapor de marfa (1-Da, 0-Nu): ";
        ist >> v.vaporDeMarfa;
        return ist;
    }
    bool operator>(const Vapor& v) {
        return this->capacitatePasageri > v.capacitatePasageri;
       }

    ~Vapor() {
        if (numeVapor != NULL) {
            delete[]this->numeVapor;
        }

    }
    void afisareVapor() {
        cout << "Vaporul " << numeVapor << " cu destinatia: " << destinatie << " are " << capacitatePasageri << " pasageri. Este fabricat in anul " << anFabricare << " si este : " << (vaporDeMarfa ? "vapor de marfa." : "vapor de pasageri.") << endl;

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
    Tren tren2("CFR", "Rosu");
    Tren tren3("Verde deschis", "Express", 5, 250);
    tren1.afisareInfoTren();
    tren2.afisareInfoTren();
    tren3.afisareInfoTren();

    cout << "Numar total de trenuri este: " << Tren::getNrTotalTrenuri() << endl;


    cout << endl << endl;

    Vapor vapor1;
    vapor1.afisareVapor();
    Vapor vapor2("Aqua Wave", "Hawaii", 2020);
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
    cout << tren3.getNrVagoane() << endl;
    cout << tren3.getCuloare() << endl;
    cout << endl;
    tren3.setModel("Travel");
    tren3.setNrVagoane(6);
    tren3.setCuloare("Mov");
    cout << endl;
    tren3.afisareInfoTren();
    cout << endl << endl;
    cout << tren3.getNrMaximPasageri() << endl;
    cout << tren3.getModel() << endl;
    cout << tren3.getNrVagoane() << endl;
    cout << tren3.getCuloare() << endl;

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
    cout << endl << endl;
    cout << "==========================================================================================================" << endl;
    cout << "Operatorii clasei Automobil:" << endl;
    cout << automobil2 << endl;
    automobil2 = automobil3;
    cout << automobil2 << endl;  
    cout << endl;
    cout << "Suma presiunilor la roti este de: "<< (float)automobil3 << endl;
    cout << automobil3[1] << endl;
    automobil3[1] = 30.2;
    cout << automobil3[1] << endl;
    cout << endl;

    cout << "Operatorii clasei Tren:" << endl;
    cout << tren2 << endl;
    cout << "Trenul3 are numarul de vagoane diferit de trenul2? " << ((tren3 != tren2) ? "Da" : "Nu") << endl;
    cout << "Trenul1 are numarul de vagoane diferit de trenul2? " << ((tren1 != tren2) ? "Da" : "Nu") << endl;
    tren2 = tren3;
    cout << tren2 << endl;
    tren1 += tren2;
    cout << tren1 << endl;
    cout << endl;

    cout << "Operatorii clasei Vapor:" << endl;
    cout << vapor3 << endl;
    vapor1 = vapor2;
    cout << vapor1 << endl;
     cout << vapor2(" Island") << endl;
    cout << endl;
    cout << "Vaporul3 are capacitatea pasagerilor mai mare decat  vaporul2? " << ((vapor3 > vapor2) ? "Da" : "Nu") << endl;
    cout << endl;
    cout << vapor2 << endl;
    cin >> vapor2;
    cout << vapor2;
}