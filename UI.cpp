//
// Created by Acer V3-772G on 4/6/2020.
//
#include "UI.h"
#include "Repository.h"
#include "Controller.h"
#include <iostream>

UI:: UI()= default;
UI::~UI() = default;


void UI::program() {        /// MENIUL EFECTIV
    Repository repo = Repository();
    Controller ctrl = Controller();

    Medikament m1 = Medikament("Paracetamol", 300);
    m1.set_preis(15); m1.set_menge(10);
    Medikament m2 = Medikament("Nurofen",500);
    m2.set_preis(25); m2.set_menge(5);

    repo.einfugen(m1);
    repo.einfugen(m2);

    cout<<"SMILE- Apotheke"<<endl;
    cout<<"0. EXIT "<<endl;
    cout<<"1. Einfugen Medikament "<<endl;
    cout<<"2. Loschen Medikament "<<endl;
    cout<<"3. Bearbeiten Medikament "<<endl;
    cout<<"4. Anzeigen alle Medikamente "<<endl;
    cout<<"5. Suchen nach einer Zeichenkette "<<endl;
    cout<<"6. Anzeigen der Medikamenten, die knapp sind "<<endl;
    cout<<"7. Medikamente nach Preis gruppieren "<<endl;
    cout<<"8. UNDO"<<endl;
    cout<<"9. REDO"<<endl;

    int x;
    cin>>x;
    while(x) {
        if(x>0 && x<10)
            ctrl.comanda(x, &repo);
        else
            cout<<"Comanda inexistenta, apasati alta tasta: "<<endl;
        cout<<"SMILE- Apotheke"<<endl;
        cout<<"0. EXIT "<<endl;
        cout<<"1. Einfugen Medikament "<<endl;
        cout<<"2. Loschen Medikament "<<endl;
        cout<<"3. Bearbeiten Medikament "<<endl;
        cout<<"4. Anzeigen alle Medikamente "<<endl;
        cout<<"5. Suchen nach einer Zeichenkette "<<endl;
        cout<<"6. Anzeigen der Medikamenten, die knapp sind "<<endl;
        cout<<"7. Medikamente nach Preis gruppieren "<<endl;
        cout<<"8. UNDO"<<endl;
        cout<<"9. REDO"<<endl;

        cin>>x;
    }
}