//
// Created by Acer V3-772G on 4/2/2020.
//
#include "Medikament.h"
using  namespace std;

Medikament::Medikament(string n, int konz){     /// initializez constructorul
    this->name = n;
    this->konzentration = konz;
    this->menge = 1;
    this->preis = 0;

}

string Medikament::get_name() {
    return this->name;
}

void Medikament::set_name(string n) {
    this->name = n;
}

int Medikament::get_konz() {
    return this->konzentration;
}

void Medikament::set_konz(int k) {
    this->konzentration = k;
}

int Medikament::get_menge() {
    return this->menge;
}

void Medikament::set_menge(int m) {
    this->menge = m;
}

float Medikament::get_preis() {
    return this->preis;
}

void Medikament::set_preis(float p) {
    this->preis = p ;
}

Medikament::~Medikament() = default;    /// destructorul ramane default