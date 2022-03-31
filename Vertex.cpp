#include "Vertex.h"

Vertex::Vertex(Chel*& chel)
{
    m_chel = chel;
    std::cout << "Vertex " << this << " created\n";
}

Vertex::~Vertex() { std::cout << "Vertex " << this << " deleted\n"; }

bool Vertex::isAlreadyFriends(Vertex*& v)
{
    for (size_t i = 0; i < m_friends.size(); i++)
    {
        if (m_friends[i] == v) return true;
    }
    return false;
}

void Vertex::addFriend(Vertex*& v)
{
    if (isAlreadyFriends(v)) return;
    m_friends.push_back(v);
}

void Vertex::delFriend(Vertex*& v)
{
    size_t i = 0;
    bool flag = false;
    for (; i < m_friends.size(); i++)
    {
        if (m_friends[i] == v)
        {
            flag = true;
            break;
        }
    }
    if (flag == false) return;
    //здесь операция delete не вызывается, потому что удаляем просто запись из массива о связи с объектом, а не сам объект
    for (; i < m_friends.size() - 1; i++)
    {
        m_friends[i] = m_friends[i + 1];
    }
    m_friends.pop_back();
}

Chel*& Vertex::getChel()
{
    return m_chel;
}

void Vertex::printFriends()
{
    if (m_friends.size() == 0)
    {
        std::cout << "No friends :(\n";
        return;
    }
    for (size_t i = 0; i < m_friends.size(); i++)
    {
        if (m_friends[i] == NULL)
        {
            std::cout << "Error value at: " << m_friends[i] << "\n";
            continue;
        }
        std::cout << m_friends[i]->getChel()->getName() << " ";
    }
    std::cout << "\n";
}

std::string Vertex::getName()
{
    return m_chel->getName();
}

size_t Vertex::getFriendsCount()
{
    return m_friends.size();
}

Vertex*& Vertex::getFriend(size_t i)
{
    return m_friends[i];
}


