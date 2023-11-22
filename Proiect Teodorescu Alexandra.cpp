
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

    friend ostream& operator<<(ostream& automobil, const Automobil& a);

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

    friend istream& operator>>(istream& in, Automobil& a) {
        cout << "Introduceti marca automobilului: ";
        char aux[100];
        in >> aux;
        if (a.marcaModel != NULL) {
            delete[] a.marcaModel;
        }

        a.marcaModel = new char[strlen(aux) + 1];
        strcpy_s(a.marcaModel, strlen(aux) + 1, aux);
        cout << "Introduceti numarul de roti: ";
        in >> a.nrRoti;
        if (a.presiuneRoti != NULL) {
            delete[] a.presiuneRoti;
        }
        a.presiuneRoti = new float[a.nrRoti];
        for (int i = 0; i < a.nrRoti; i++) {
            cout << "Introduceti presiunea rotii[" << i + 1 << "]: ";
            in >> a.presiuneRoti[i];
        }
        return in;
    }


};
int Automobil::nrAutomobile = 0;
ostream& operator<<(ostream& automobil, const Automobil& a) {
    automobil << "Marca: " << a.marcaModel << " ,Serie: " << a.nrSerie << ", Numar roti: " << a.nrRoti;
    if (a.presiuneRoti != NULL && a.nrRoti > 0) {
        for (int i = 0; i < a.nrRoti; i++) {
            automobil << a.presiuneRoti[i] << " ";
        }
    }
    return automobil;
}

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


    bool operator!=(const Tren& t) {
        return this->nrVagoane != t.nrVagoane;
    }
    Tren& operator+=(const Tren& t) {
        this->nrVagoane += t.nrVagoane;
        return *this;
    }

    ~Tren() {
        if (this->culoare != NULL) {
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
    friend ostream& operator<<(ostream& tren, const Tren& t);
    friend istream& operator>>(istream& in, Tren& t) {
        cout << "Introduceti modelul trenului: ";
        in >> t.model;
        cout << "Introduceti numarul vagoanelor: ";
        in >> t.nrVagoane;
        cout << "Introduceti culoarea trenului: ";
        char aux[100];
        in >> aux;
        if (t.culoare != NULL) {
            delete[]t.culoare;
        }

        t.culoare = new char[strlen(aux) + 1];
        strcpy_s(t.culoare, strlen(aux) + 1, aux);


        return in;
    }
};

int Tren::nrTotalTrenuri = 0;
ostream& operator<<(ostream& tren, const Tren& t) {
    tren << "Model: " << t.model << " ,Numar vagoane: " << t.nrVagoane << ", Culoare: " << t.culoare << " , Numarul maxim de pasageri: " << t.nrMaximPasageri;

    return tren;
}

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

    friend ostream& operator<<(ostream& vapor, const Vapor& v);


    string operator()(string denumire) {
        return this->destinatie + denumire;
    }
    friend istream& operator>>(istream& ist, Vapor& v) {
        char aux[100];
        cout << "Introduceti numele vaporului: ";
        ist >> aux;
        if (v.numeVapor != NULL) {
            delete[]v.numeVapor;
        }
        v.numeVapor = new char[strlen(aux) + 1];
        strcpy_s(v.numeVapor, strlen(aux) + 1, aux);
        cout << "Introduceti destinatia: ";
        ist >> v.destinatie;
        cout << "Introduceti capacitatea pasagerilor: ";
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
ostream& operator<<(ostream& vapor, const Vapor& v) {
    vapor << "Nume: " << v.numeVapor << " ,Destinatie: " << v.destinatie << ", Capacitate pasageri: " << v.capacitatePasageri << " , An fabricare: " << v.anFabricare << (v.vaporDeMarfa ? " ,Vapor de marfa." : " ,Vapor de pasageri.");

    return vapor;
}

class Parcare {
    int nrLocuri;
    string denumireParcare;
    float pret;
    int nrAutomobile;
    Automobil* automobile;
public:
    Parcare() {
        this->nrLocuri = 56;
        this->denumireParcare = "Zona A";
        this->pret = 3;
        this->nrAutomobile = 0;
        this->automobile = NULL;
    }
    Parcare(int nrLocuri, string denumireParcare, float pret, int nrAutomobile, Automobil* automobile) {
        this->nrLocuri = nrLocuri;
        this->denumireParcare = denumireParcare;
        this->pret = pret;
        this->nrAutomobile = nrAutomobile;
        if (nrAutomobile > 0) {

            this->automobile = new Automobil[nrAutomobile];
            for (int i = 0; i < nrAutomobile; i++) {
                this->automobile[i] = automobile[i];
            }
        }
        else {
            this->automobile = NULL;
        }
    }
    Parcare(const Parcare& p) {
        this->nrLocuri = p.nrLocuri;
        this->denumireParcare = p.denumireParcare;
        this->pret = p.pret;
        this->nrAutomobile = p.nrAutomobile;
        if (p.nrAutomobile > 0) {
            this->automobile = new Automobil[p.nrAutomobile];
            for (int i = 0; i < p.nrAutomobile; i++) {
                this->automobile[i] = p.automobile[i];
            }
        }
        else {
            this->automobile = NULL;

        }
    }

    Parcare& operator=(const Parcare& p) {
        if (this != &p) {
            delete[]automobile;
            this->nrLocuri = p.nrLocuri;
            this->denumireParcare = p.denumireParcare;
            this->pret = p.pret;
            this->nrAutomobile = p.nrAutomobile;
            if (p.nrAutomobile > 0) {
                this->automobile = new Automobil[p.nrAutomobile];
                for (int i = 0; i < p.nrAutomobile; i++) {
                    this->automobile[i] = p.automobile[i];
                }
            }
            else {
                this->automobile = NULL;

            }
        }
        return *this;
    }
    ~Parcare() {
        delete[]this->automobile;
    }

    int getNrLocuri() {
        return this->nrLocuri;
    }
    string getDenumireParcare() {
        return this->denumireParcare;

    }
    float getPret() {
        return this->pret;

    }
    int getNrAutomobile() {
        return this->nrAutomobile;
    }
    Automobil* getAutomobile() {
        return this->automobile;
    }
    void setNrLocuri(int nrLocuri) {
        this->nrLocuri = nrLocuri;
    }
    void setDenumireParcare(string denumireParcare) {
        this->denumireParcare = denumireParcare;

    }
    void setPret(float pret) {
        this->pret = pret;

    }
    void setAutomobile(int nrAutomobile, Automobil* automobile) {
        if (nrAutomobile > 0) {
            delete[]this->automobile;
            this->automobile = new Automobil[this->nrAutomobile];
            for (int i = 0; i < this->nrAutomobile; i++) {
                this->automobile[i] = automobile[i];
            }
        }

    }

    friend ostream& operator<<(ostream& au, const Parcare& p) {
        au << "Numaru locurilor din parcare: " << p.nrLocuri << endl;
        au << "Denumire parcare: " << p.denumireParcare << endl;
        au << "Pret parcare: " << p.pret << " lei/h" << endl;
        au << "Numar automobile: " << p.nrAutomobile << endl;
        au << "Automobile: " << endl;
        for (int i = 0; i < p.nrAutomobile; i++) {
            au << p.automobile[i] << endl;
        }
        return au;
    }

    bool operator>(Parcare p) {
        return(this->denumireParcare.size() > p.denumireParcare.size());
    }
    Parcare& operator+=(float val) {
        this->pret += val;
        return *this;
    }
    explicit operator int() {
        return this->nrLocuri;
    }
};



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
    cout << "Suma presiunilor la roti este de: " << (float)automobil3 << endl;
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
    cout << "Vaporul3 are capacitatea pasagerilor mai mare decat vaporul2? " << ((vapor3 > vapor2) ? "Da" : "Nu") << endl;
    cout << endl;
    cout << vapor2 << endl;
    cin >> vapor2;
    cout << vapor2;

    cout << endl << endl;
    cout << "---------------------------------------------------------" << endl;
    Automobil* vectorAuto = new Automobil[2];
    Tren* vectorTren = new Tren[2];
    Vapor* vectorVapor = new Vapor[2];
    for (int i = 0; i < 2; i++) {
        cin >> vectorAuto[i];
    }
    cout << endl;
    for (int i = 0; i < 2; i++) {
        cout << vectorAuto[i] << endl;
    }

    cout << endl << endl << endl;
    for (int i = 0; i < 2; i++) {
        cin >> vectorTren[i];
    }
    cout << endl;
    for (int i = 0; i < 2; i++) {
        cout << vectorTren[i] << endl;
    }

    cout << endl << endl << endl;

    for (int i = 0; i < 2; i++) {
        cin >> vectorVapor[i];
    }
    cout << endl;
    for (int i = 0; i < 2; i++) {
        cout << vectorVapor[i] << endl;
    }

    cout << endl << endl << endl;

    int randuri = 2;
    int coloane = 2;
    Automobil matriceAutomobil[2][2];
    for (int i = 0; i < randuri; ++i) {
        for (int j = 0; j < coloane; ++j) {
            cout << "Introduceti informatii pentru automobilul[" << i << "]:\n ";
            cin >> matriceAutomobil[i][j];
        }
    }
    for (int i = 0; i < randuri; ++i) {
        for (int j = 0; j < coloane; ++j) {
            cout << "Automobilul [" << i << "][" << j << "]:\n " << matriceAutomobil[i][j] << "\n";

        }
    }


    cout << "----------------------------------------------------------------------------" << endl;
    Parcare p;
    cout << p.getNrLocuri() << endl;
    cout << p.getPret() << endl;
    cout << p.getDenumireParcare() << endl;
    cout << p.getNrAutomobile() << endl;
    for (int i = 0; i < p.getNrAutomobile(); i++) {
        cout << p.getAutomobile()[i] << endl;
    }
    Automobil vectorA[] = { automobil2 };
    Parcare p1(45, "Zona C", 2, 1, vectorA);
    cout << p1.getNrLocuri() << endl;
    cout << p1.getPret() << endl;
    cout << p1.getDenumireParcare() << endl;
    cout << p1.getNrAutomobile() << endl;
    for (int i = 0; i < p1.getNrAutomobile(); i++) {
        cout << p1.getAutomobile()[i] << endl;
    }
    Automobil vectorAu[] = { automobil1 };

    p1.setPret(5);
    p1.setNrLocuri(67);
    p1.setDenumireParcare("Zona S");
    p1.setAutomobile(1, vectorAu);
    cout << endl;
    cout << p1.getNrLocuri() << endl;
    cout << p1.getPret() << endl;
    cout << p1.getDenumireParcare() << endl;
    cout << p1.getNrAutomobile() << endl;
    for (int i = 0; i < p1.getNrAutomobile(); i++) {
        cout << p1.getAutomobile()[i] << endl;
    }
    cout << endl;
    Automobil vectAu[] = { automobil1,automobil3 };

    Parcare p2(78, "Zona K2", 6, 2, vectAu);
    Parcare p3 = p1;
    cout << p3 << endl << endl;
    p = p2;
    cout << p << endl;
    cout << endl << endl;
    if (p2 > p1) {
        cout << "Adevarat";

    }
    else {
        cout << "Fals";
    }

    cout << endl << endl;
    p2 += 2;
    cout << p2 << endl;
    cout << endl;
    cout << (int)p3 << endl;

}