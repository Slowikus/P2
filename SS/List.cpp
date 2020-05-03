#include "List.hpp"

#include<iostream>
#include <time.h>
#include <fstream>

void Graph::addEdge(int source, int dest, int cost) {
    Node node{};
    node.dest = dest;
    node.cost = cost;

    if(list[source].returnFirstElement() == nullptr) {
        List b{};
        b.addElement(node);
        list[source] = b;
        return;
    }
    list[source].addElement(node);
}

void Graph::createList() {
    srand(time(NULL));
    for(int i = 0; i < count_; ++i) {
        if (i == (count_ - 1)) {
            int dest = rand() % count_;
            while (dest == i) {
                dest = rand() % count_;
            }

            auto iterator = list[dest].returnFirstElement();
            while (iterator != nullptr) {
                if (iterator->getDest() == i) {
                    auto cost = iterator->getCost();
                    addEdge(i, dest, cost);
                    edgeCount_+=1;

                    return;
                }
                iterator = iterator->returnNextElement();
            }

            int cost = rand() % 50 +1;
            addEdge(i, dest, cost);
            edgeCount_+=1;

            return;
        }
        //ZMIANA GESTOSCI
        // +=1 - 100% / +=1.5 - 75% / +=2 - 50% / +=4 - 25% ///////////////////////////////////////////////////////////////////////////////////////////////////////
        for(float j = i+1; j < count_; j+=4 ) {
            int dest = rand() % count_;
            while (dest <= i)
            {
                dest = rand() % count_;
            }

            int cost = rand() % 50 +1;

            addEdge(i, dest, cost);
            edgeCount_+=1;
        }


    }
}

int Graph::findMin() {
    int min = INT_MAX;
    int id = 0;
    for(int i = 0; i < count_; ++i) {
        if (temp[i] == -1)
            continue;

        if(temp[i] <= min) {
            min = temp[i];
            id = i;
        }
    }

    return id;
}

bool Graph::areAllRemoved() {
    for (int i = 0; i < count_; ++i) {
        if (temp[i] != -1)
            return false;
    }
    return true;
}

void Graph::dijkstra(int start) {
    for(int i = 0; i < count_; ++i) {
        temp[i] = INT_MAX;
    }

    temp[start] = 0;
    int final[count_];

    while(!areAllRemoved()) {
        auto minID = findMin();
        auto cost = temp[minID];
        temp[minID] = -1;

        List adjVert = list[minID];

        int temporaryId = 0;
        for(int i = 0; i < count_; ++i) {
            auto it = list[i].returnFirstElement();

            while (it != nullptr) {
                if(it->getDest() == minID && temp[temporaryId] != -1)
                {
                    Node node{};
                    node.dest = temporaryId;
                    node.cost = it->getCost();
                    adjVert.addElement(node);
                }
                it = it->returnNextElement();
            }
            ++temporaryId;
        }


        auto it = adjVert.returnFirstElement();

        while (it != nullptr) {
            if(temp[it->getDest()] != -1)// jeslui jest w tempie
            {
                if(temp[it->getDest()] > it->getCost() + cost) {
                    temp[it->getDest()] = it->getCost() + cost;
                }
            }
            it = it->returnNextElement();
        }
        final[minID] = cost;
    }

// ZAPIS DO PLIKU ///////////////////////////////////////////////////////////////////////////////////////////////////////////

   saveToFile(start, final);
}


void Graph::dijkstra2(int start, int end)
{
    for(int i = 0; i < count_; ++i)
    {
        temp[i] = INT_MAX;
    }

    temp[start] = 0;
    int final[count_];

    while(!areAllRemoved())
    {
        auto minID = findMin();
        auto cost = temp[minID];
        temp[minID] = -1;

        List adjVert = list[minID];

//        std::cout << "PRZED: " << adjVert.size() << ", ";
        int temporaryId = 0;
        for(int i = 0; i < count_; ++i)
        {
            auto it = list[i].returnFirstElement();

            while (it != nullptr)
            {
                if(it->getDest() == minID && temp[temporaryId] != -1)
                {
                    Node node{};
                    node.dest = temporaryId;
                    node.cost = it->getCost();
                    adjVert.addElement(node);
                }
                it = it->returnNextElement();
            }
            ++temporaryId;
        }
//        std::cout << "PO: " << adjVert.size() << std::endl;


        auto it = adjVert.returnFirstElement();

        while (it != nullptr)
        {
            if(temp[it->getDest()] != -1)// jeslui jest w tempie
            {
                if(temp[it->getDest()] > it->getCost() + cost)
                {
                    temp[it->getDest()] = it->getCost() + cost;
//                    std::cout << "UPDATE -> ID: " << it->dest << " COST: "<< it->cost + cost << std::endl;
                }
            }
            it = it->returnNextElement();
        }
        final[minID] = cost;
    }
    std::cout << "Distance from vertex: " << start << " to vertex " << end << " is " << final[end] << std::endl;

}

void Graph::solution(int start, int final[])
{
    std::cout << "Edges     Vertices      starting Vert" << std::endl;
    std::cout << " " << edgeCount_ << "        " << count_ << "             " << start << std::endl;
    std::cout << "start ID" << "      cost" << std::endl;
    for(int i = 0; i < count_; ++i)
    {
        std::cout << "  " << i << "        " << final[i] <<std::endl;
    }
}

void Graph::saveToFile(int start, int final[])
{
    std::ofstream str("D:/AAA UCZELNIA/SEM4/PAMSI/P2/SS/List.txt");
    if(str)
    {
        str << "Edges     Vertices      starting Vert" << std::endl;
        str << " " << edgeCount_ << "        " << count_ << "             " << start << std::endl;
        str << "start ID" << "      cost" << std::endl;
        for(int i = 0; i < count_; ++i)
        {
            str << "  " << i << "        " << final[i] <<std::endl;
        }
    }
    else
    {
        std::cout << "error" << std::endl;
    }
}

void Graph::readFromFile()
{
    std::ifstream str("D:/AAA UCZELNIA/SEM4/PAMSI/P2/SS/ListRead.txt");
    int a, b, c;
    if(str)
    {
        while(!str.eof())
        {
            str >> a;
            str >> b;
            str >> c;

            addEdge(a, b, c);
        }
    }
    else
    {
        std::cout << "error" << std::endl;
    }
}
