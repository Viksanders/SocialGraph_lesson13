#include "SocialGraph.h"

SocialGraph::SocialGraph() {}

SocialGraph::~SocialGraph()
{
    for (size_t i = 0; i < m_people.size(); i++)
    {
        delete m_people[i];
    }
}

bool SocialGraph::isAlreadyHere(Vertex*& v)
{
    for (size_t i = 0; i < m_people.size(); i++)
    {
        if (m_people[i] == v) return true;
    }
    return false;
}

void SocialGraph::addVertex(Vertex*& v)
{
    if (isAlreadyHere(v)) return;
    m_people.push_back(v);
}

void SocialGraph::addEdge(Vertex*& v1, Vertex*& v2)
{
    if (!isAlreadyHere(v1) || !isAlreadyHere(v2)) return;

    v1->addFriend(v2);
    v2->addFriend(v1);
}

void SocialGraph::delEdge(Vertex*& v1, Vertex*& v2)
{
    if (!isAlreadyHere(v1) || !isAlreadyHere(v2)) return;

    v1->delFriend(v2);
    v2->delFriend(v1);
}

void SocialGraph::delVertex(Vertex*& v)
{
    if (!isAlreadyHere(v)) return;

    for (size_t i = 0; i < m_people.size(); i++) //сначала удаляем человека у всех из друзей
    {
        m_people[i]->delFriend(v);
    }
    //далее удаляем человека из массива вершин
    size_t j = 0;
    bool flag = false;
    for (; j < m_people.size(); j++)
    {
        if (m_people[j] == v)
        {
            flag = true;
            break;
        }
    }
    if (flag == false) return;

    delete m_people[j];             //МБ И НЕ СТОИТ ТАК ДЕЛАТЬ, А ЛУЧШЕ УДАЛИТЬ ВНЕ КЛАССА, НО ПОКА ТАК
    for (; j < m_people.size() - 1; j++)
    {
        m_people[j] = m_people[j + 1];
    }
    m_people.pop_back();
}

void SocialGraph::threeHandshakesForOne(Vertex*& v, std::vector<Pair*>& pairs, std::vector<Vertex*>& visited_global, int how_deep)
{
    //std::vector<Pair*> pairs;

    Vertex* current = v;
    std::cout << "STARTING TO FIND FRIENDS FOR " << v->getName() << "\n\n";

    std::vector<Vertex*> visited;
    visited.push_back(current);

    visited_global.push_back(current);

    std::vector<Vertex*> wait_visit;

    do
    {
        for (size_t i = 0; i < current->getFriendsCount(); i++)
        {
            bool flag = false;
            for (size_t j = 0; j < visited.size(); j++)
            {
                if (visited[j] == current->getFriend(i))
                {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;

            bool flag_global = false;
            for (size_t k = 0; k < visited_global.size(); k++)
            {
                if (visited_global[k] == current->getFriend(i))
                {
                    flag_global = true;
                    break;
                }
            }
            if (flag_global) continue;

            //вот здесь добавить проверку, что глубина между V и current->getFriend(i) не превышает 3, и только тогда пушбэкать в очередь wait_visit и visited
            if (shortestPath(v, current->getFriend(i)) > how_deep) continue;
            else
            {
                wait_visit.push_back(current->getFriend(i));
                visited.push_back(current->getFriend(i));
                pairs.push_back(new Pair(v->getChel(), current->getFriend(i)->getChel()));
            }
            //wait_visit.push_back(current->getFriend(i));
            //visited.push_back(current->getFriend(i));
            //pairs.push_back(new Pair(v->getChel(), current->getFriend(i)->getChel()));
        }
        if (wait_visit.size() == 0) break;
        current = wait_visit[wait_visit.size() - 1];
        wait_visit.pop_back();
    } while (wait_visit.size() != 0);
}

void SocialGraph::depth(Vertex*& start)
{
    std::vector<Vertex*> visited;
    depthInner(start, visited);
    std::cout << "\n";
}

void SocialGraph::depthInner(Vertex*& start, std::vector<Vertex*>& visited)
{
    std::cout << start->getName() << "   ";
    visited.push_back(start);
    for (size_t i = 0; i < start->getFriendsCount(); i++)
    {
        bool flag = false;
        size_t j = 0;
        for (; j < visited.size(); j++)
        {
            if (visited[j] == start->getFriend(i))
            {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        else depthInner(start->getFriend(i), visited);
    }
}

int SocialGraph::shortestPath(Vertex*& v1, Vertex*& v2)
{
    int path = 0;
    std::vector<int> pathes;
    std::vector<Vertex* > visited;

    shortestPathInner(v1, v2, visited, pathes, path);
    /*
    for (int i = 0; i < pathes.size(); i++)
    {
        std::cout << pathes[i] << " ";
    }
    std::cout << "\n";
    */
    int output = 9999;
    for (size_t i = 0; i < pathes.size(); i++)
    {
        if (pathes[i] < output) output = pathes[i];
    }

    return output;
}

void SocialGraph::shortestPathInner(Vertex*& v1, Vertex*& v2, std::vector<Vertex*>& visited, std::vector<int>& pathes, int& path)
{
    if (v1 == v2)
    {
        int value = path;
        pathes.push_back(value);
        //Удаляем стартовый элемент для данной итерации
        int j = 0;
        bool flag_start = false;
        for (; j < visited.size(); j++)
        {
            if (visited[j] == v1)
            {
                flag_start = true;
                break;
            }
        }
        if (flag_start)
        {
            for (; j < visited.size() - 1; j++)
            {
                visited[j] = visited[j + 1];
            }
            visited.pop_back();
        }
        //path = 0;
        path--;
        //
        return;
    }
    visited.push_back(v1);
    for (size_t i = 0; i < v1->getFriendsCount(); i++)
    {
        bool flag = false;
        size_t j = 0;
        for (; j < visited.size(); j++)
        {
            if (visited[j] == v1->getFriend(i))
            {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        else
        {
            path++;
            shortestPathInner(v1->getFriend(i), v2, visited, pathes, path);
        }
    }
    //Удаляем стартовый элемент для данной итерации
    int j = 0;
    bool flag_start = false;
    for (; j < visited.size(); j++)
    {
        if (visited[j] == v1)
        {
            flag_start = true;
            break;
        }
    }
    if (flag_start)
    {
        for (; j < visited.size() - 1; j++)
        {
            visited[j] = visited[j + 1];
        }
        visited.pop_back();
    }
    //path = 0;
    path--;
    //
}

void SocialGraph::threeHandshakesForEverybody(int how_deep)
{
    std::vector<Pair*> pairs;
    std::vector<Vertex*> visited_global;

    for (size_t i = 0; i < m_people.size(); i++)
    {
        threeHandshakesForOne(m_people[i], pairs, visited_global, how_deep);
    }

    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "Pair of: " << pairs[i]->first->getName() << " and " << pairs[i]->second->getName() << "\n";
    }
}

