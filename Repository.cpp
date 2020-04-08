//
// Created by Acer V3-772G on 4/2/2020.
//
#include "Repository.h"
#include <iostream>
#include <vector>
#include "Medikament.h"
#include <algorithm>
using  namespace std;

Repository::Repository() {  /// initializez vectorul de medicamente gol, la fel si pe cel de undo/redo
    this->repo = {} ;
    this->undo_vector = {};
}


void Repository::einfugen(Medikament m) {
    if(repo.empty()){
        /// daca lista e goala, il adaug
        this->repo.push_back(m);
        undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
        cout<<"Medicament adaugat!"<<endl;
    }
    else
        {
        for(auto it= this->repo.begin();it<this->repo.end(); it++) {
            if(it->get_name() == m.get_name() && it->get_konz() == m.get_konz()) {
                /// daca medicamentul e deja in repo, ii modific cantitatea
                it->set_menge(it->get_menge() + m.get_menge());
                undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
                cout<<"Medicament adaugat!"<<endl;
                return;
            }
        }
            ///daca nu se afla deja in repo, il adaug
            this->repo.push_back(m);
            undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
            cout<<"Medicament adaugat!"<<endl;
        }


}


void Repository::loschen(Medikament m) {
    for(auto it= this->repo.begin();it != this->repo.end(); it++){      /// parcurg lista ca sa gasesc medicamentul m
        if(m.get_name() == it->get_name() && m.get_konz() == it->get_konz()){   /// daca il gasesc
            this->repo.erase(it);                                       /// il sterg din lista
            undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
            cout<<"Medicament sters!"<<endl;
            return;
        }
    }
}


void Repository::bearbeiten(Medikament& m) {
    cout<<"1: schimbare nume"<<endl<<"2: schimbare concentratie"<<endl<<"3: schimbare menge"<<endl;
    cout<<"0: exit"<<endl<<"Alegeti o tasta: ";
    int x; cin>>x;
    string n; int k; int menge;
    if(x == 0)
        return;
    while(x !=0 ) {
        if(x == 1) {       /// pt tasta 1 se schimba numele
            cout<<"Nume nou: ";
            cin >> n;
            for (auto &i : this->repo) {
                if (i.get_name() == m.get_name() &&
                    i.get_konz() == m.get_konz()) {       /// gasesc medicamentul respectiv in lista
                    i.set_name(n);                                                      /// si ii schimb numele
                    m.set_name(n);
                    undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
                    cout<<" Nume schimbat"<<endl;
                }
            }

        }
        else if (x == 2) {      /// pt tasta 2 se schimba concentratia
            cout<<"Concentratie noua: ";
            cin >> k;
            for (auto &i : this->repo) {
                if (i.get_konz() == m.get_konz() &&
                    i.get_name() == m.get_name()) {        /// gasesc medicamentul respectiv in lista
                    i.set_konz(k);                                                       /// si ii schimb concentratia
                    m.set_konz(k);
                    undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
                    cout<<" Concentratie schimbata"<<endl;

                }
            }
        }
        else if (x == 3) {      /// pt tasta 3 se schimba menge
            cout<<"Cantitate noua: ";
            cin >> menge;
            for (auto &i : this->repo) {
                if (i.get_konz() == m.get_konz() &&
                    i.get_name() == m.get_name()) {        /// gasesc medicamentul respectiv in lista
                    i.set_menge(menge);                                                  ///si ii schimb valoarea la menge
                    m.set_menge(menge);
                    undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
                    cout<<" Cantitate schimbata"<<endl;

                }
            }
        }
        cout<<"1: schimbare nume"<<endl<<"2: schimbare concentratie"<<endl<<"3: schimbare menge"<<endl;
        cout<<"0: exit"<<endl<<"Alegeti o tasta: ";
        cin>>x;
    }

}


void Repository::anzeigen() {
    for (auto it = this->repo.begin(); it < this->repo.end(); it++) {
        cout << it->get_name() << "   " << it->get_konz() << '\t' << "Menge: " << it->get_menge() << "   Preis: "
             << it->get_preis();
        cout << endl;
    }
}


bool dupanume(Medikament i , Medikament j){     /// functie pentru sortarea dupa nume
    return(i.get_name() < j.get_name());
}


void Repository:: zeichenkette() {          /// se cauta in lista dupa nume
    cout<<"Suchen nach Name: ";
    string n; getline(std::cin,n);
    if(n.empty()){                      /// daca inputul e gol, se afiseaza sortate dupa nume
        sort(this->repo.begin(), this->repo.end(), dupanume);   /// sorteaza dupa nume
        anzeigen();
    } else
        for(auto &i : this->repo){
            if(i.get_name().find(n) != string::npos)        /// daca se gaseste subsirul n in vreun nume
                cout<<i.get_name()<<endl;                   /// sa se afiseze numele respectiv
        }
}


void Repository::knapp() {
    cout<<"Anzeigen der Medikamente, die knapp sind"<<endl;
    bool ok = false ;
    int x;
    cout<<"Menge weniger als: ";cin>>x;
    for(auto &i : this->repo){
        if(i.get_menge() < x){
            cout<<i.get_name()<<endl;
            ok = true;
        }
    }
    if(!ok) cout<<"Es gibt keine"<<endl;
}


void Repository::nachpreis() {          /// Medikamente gruppiert nach Preis
    bool ok = false;
    cout<<"Nach Preis gruppiert:"<<endl;
    cout<<"Bis in 50 lei:"<<endl;
    for(auto &i : this->repo) {
        if (i.get_preis() <= 50){
            cout << i.get_name() << endl;
            ok = true;
        }
    }if(!ok) cout<<"keine"<<endl;
    ok = false;
    cout<<"Von 51 bis 150 lei:"<<endl;
    for(auto &i : this->repo) {
        if (i.get_preis() <= 150 && i.get_preis() >50){
            cout << i.get_name() << endl;
            ok = true;
        }
    }if(!ok) cout<<"keine"<<endl;
    ok = false;
    cout<<"Teuer als 150 lei: "<<endl;
    for(auto &i : this->repo) {
        if (i.get_preis() > 150){
            cout << i.get_name() << endl;
            ok = true;
        }
    }if(!ok) cout<<"keine"<<endl;
}


void Repository::undo() {
    if(this->undo_vector.empty())
        cout<< "Functia de UNDO nu este posibila"<<endl;
    else{
        this->repo = undo_vector[undo_vector.size() - 2];
        cout<<"UNDO succesful"<<endl;
    }
}


void Repository::redo() {
    if(this->undo_vector.empty())
        cout<< "Functia de REDO nu este posibila"<<endl;
    else
    {
        this->repo = undo_vector[undo_vector.size() - 1];
        cout<<"REDO succesful"<<endl;
    }
}


Repository::~Repository() = default;        /// destructor