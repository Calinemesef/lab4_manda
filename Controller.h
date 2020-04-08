//
// Created by Acer V3-772G on 4/6/2020.
//

#ifndef LAB4_CONTROLLER_H
#define LAB4_CONTROLLER_H
#pragma once
#include "Repository.h"

class Controller{
public:
    Controller();
    void comanda(int,Repository*);  /// meniul care apeleaza metode in functie de input

    ~Controller();
};
#endif //LAB4_CONTROLLER_H
