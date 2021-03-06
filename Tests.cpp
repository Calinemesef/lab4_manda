//
// Created by Acer V3-772G on 4/8/2020.
//

#include <cassert>
#include <Medikament.h>
#include <Repository.h>
#include <iostream>
#include "Tests.h"

Tests::Tests() {
}

void Tests::testAdd(){

    Medikament m1 = Medikament("Paracetamol", 300);
    m1.set_preis(15); m1.set_menge(10);
    Medikament m2 = Medikament("Nurofen",500);
    m2.set_preis(25); m2.set_menge(5);
    Repository repo = Repository();
    repo.einfugen(m1);
    repo.einfugen(m2);
    assert(repo.repo[0].get_preis() == 15);
    assert(repo.repo[1].get_preis() == 25);
    assert(repo.repo[0].get_name() == "Paracetamol");
    assert(repo.repo[1].get_name() == "Nurofen");
    assert(repo.repo[0].get_konz() == 300);
    assert(repo.repo[1].get_konz() == 500);
    assert(repo.repo[0].get_menge() == 10);
    assert(repo.repo[1].get_menge() == 5);
    cout<<"ADD-Test over"<<endl;

}

void Tests::testDel() {
    Medikament m1 = Medikament("Paracetamol", 300);
    m1.set_preis(15); m1.set_menge(10);
    Medikament m2 = Medikament("Nurofen",500);
    m2.set_preis(25); m2.set_menge(5);
    Repository repo = Repository();
    repo.einfugen(m1);
    repo.einfugen(m2);
    repo.loschen(m1);
    assert(repo.repo.size() == 1);
    repo.loschen(m2);
    assert(repo.repo.empty());
    cout<<"DELETE-Test over"<<endl;
}

void Tests::testUndo() {
    Medikament m1 = Medikament("Paracetamol", 300);
    m1.set_preis(15); m1.set_menge(10);
    Medikament m2 = Medikament("Nurofen",500);
    m2.set_preis(25); m2.set_menge(5);
    Repository repo = Repository();
    repo.einfugen(m1);
    repo.einfugen(m2);
    repo.undo();
    assert(repo.repo.size() == 1);
    cout<<"UNDO-Test over"<<endl;
}

void Tests::testRedo() {
    Medikament m1 = Medikament("Paracetamol", 300);
    m1.set_preis(15); m1.set_menge(10);
    Medikament m2 = Medikament("Nurofen",500);
    m2.set_preis(25); m2.set_menge(5);
    Repository repo = Repository();
    repo.einfugen(m1);
    repo.einfugen(m2);
    repo.undo();
    repo.redo();
    assert(repo.repo.size()==2);
    cout<<"REDO-Test over"<<endl;
}

void Tests::FULLTEST(){
    testAdd();
    testDel();
    testUndo();
    testRedo();
    cout<<"ALL Tests over !"<<endl<<endl<<endl<<endl<<endl;
}