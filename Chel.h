#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>

struct Chel
{
private:        //сделал всЄ приватным, чтобы скрыть служебную переменную сетј…ƒ»
    std::string name;
    static int setID;
    int ID;
public:
    Chel(std::string name)
    {
        this->name = name;
        ID = setID;
        setID++;
        std::cout << "Chel " << this << " created\n";
    }
    ~Chel()
    {
        std::cout << "Chel " << this << " deleted\n";
    }

    const std::string getName() { return name; }
    int getID() const { return ID; }
};


struct Pair
{
    Chel* first;
    Chel* second;
    Pair(Chel*& first, Chel*& second) : first(first), second(second) {}
};


