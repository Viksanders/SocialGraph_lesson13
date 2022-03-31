#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Chel.h"

class Vertex
{
public:
    Vertex(Chel*& chel);
    ~Vertex();
    void addFriend(Vertex*& v);
    void delFriend(Vertex*& v);
    Chel*& getChel();

    void printFriends();
    std::string getName();
    size_t getFriendsCount();
    Vertex*& getFriend(size_t i);
private:
    bool isAlreadyFriends(Vertex*& v);
    Chel* m_chel;
    std::vector<Vertex*> m_friends;
};

