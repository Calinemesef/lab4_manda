//
// Created by Acer V3-772G on 4/6/2020.
//
#include "Controller.h"
#include <iostream>
using namespace std;

Controller::Controller()= default;
Controller::~Controller() = default ;


void Controller::comanda(int i, Repository *lista) {

    string name=""; int menge,konz; float preis;
    if(i==1)        /// ADD
    {
        cout<<"Name: ";cin>>name;
        cout<<"(int)Konzentration: ";cin>>konz;
        cout<<"(int)Menge: ";cin>>menge;
        cout<<"(float)Preis: ";cin>>preis;
        Medikament med = Medikament(name,konz);
        med.set_menge(menge);
        med.set_preis(preis);

        lista->einfugen(med);
    } else
        if(i==2)        /// DELETE
        {
            cout<<"Name: ";cin>>name;
            cout<<"(int)Konzentration: ";cin>>konz;
            Medikament med = Medikament(name,konz);

            lista->loschen(med);
        } else
            if(i==3)        /// EDIT
            {
                cout<<"Name: ";cin>>name;
                cout<<"(int)Konzentration: ";cin>>konz;
                Medikament med = Medikament(name,konz);

                lista->bearbeiten(med);
            } else
                if(i==4)        /// ANZEIGEN
                {
                    lista->anzeigen();
                } else
                    if(i==5)    /// Suchen nach Zeichenkette
                    {
                        lista->zeichenkette();
                    } else
                        if(i==6)    /// Anzeigen der Medikamente die knapp sind
                        {
                            lista->knapp();
                        } else
                            if(i==7)    /// Gruppieren nach Preis
                            {
                                lista->nachpreis();
                            } else
                                if(i==8)    /// UNDO
                                {
                                    lista->undo();
                                } else
                                    if(i==9)    /// REDO
                                    {
                                        lista->redo();
                                    }
}