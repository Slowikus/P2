#include "Matrix.hpp"

#include <time.h>
#include <fstream>

int Matrix::minDistance() {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < count_; v++)
        if (sptSet[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}

void Matrix::solution(int start) {
    std::cout << "Edges     Vertices      starting Vert" << std::endl;
    std::cout << " " << edgeCount_ << "        " << count_ << "             " << start << std::endl;
    std::cout << "Vertex      Distance from source" << std::endl;
    for(int i = 0; i < count_; i++)
    {
        std::cout << "  " << i << "                  " << distance[i] << std::endl;
    }
}

void Matrix::dijkstra(int source) {
    for(int i = 0; i < count_; i++) {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }
    distance[source] = 0;

    for(int i = 0; i < count_ - 1; i++) {
        int j = minDistance();
        sptSet[j] = true;

        for(int v = 0; v < count_; v++) {
            if(!sptSet[v] && graph[j][v] && distance[j] != INT_MAX && distance[j] + graph[j][v] < distance[v])
                distance[v] = distance[j] + graph[j][v];
        }
    }


// ZAPIS DO PLIKU ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    saveToFile(source);
}

void Matrix::solution2(int source, int end) {
    std::cout << "Distance from vertex: " << source << " to vertex " << end << " is " << distance[end] << std::endl;
}

void Matrix::dijkstra2(int source, int end) {
    for(int i = 0; i < count_; i++) {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }
    distance[source] = 0;

    for(int i = 0; i < count_ - 1; i++) {
        int j = minDistance();
        sptSet[j] = true;

        for(int v = 0; v < count_; v++) {
            if(!sptSet[v] && graph[j][v] && distance[j] != INT_MAX && distance[j] + graph[j][v] < distance[v])
                distance[v] = distance[j] + graph[j][v];
        }
    }

    solution2(source, end);
}

void Matrix::createMatrix() {
    srand(time(NULL));
    for(int i = 0; i < count_; ++i) {
        for(int j = i; j < count_; ++j) {
            if(i == j) {
                graph[i][j] = 0;
            } else {
                int a = rand() % 100;
                //ZMIANA GĘSTOSCI
                if (a < 25) // % <25 / <50  / <75  / albo koment ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
                {
                    graph[i][j] = rand() % 50 + 1;
                    graph[j][i] = graph[i][j];
                    edgeCount_+=1;
                }
            }
        }
    }
}

void Matrix::saveToFile(int start) {
    std::ofstream str("D:/AAA UCZELNIA/SEM4/PAMSI/P2/SS/Matrix.txt");
    if(str) {
        str <<   "Edges     Vertices      starting Vert" << std::endl;
        str << " " << edgeCount_ << "        " << count_ << "             " << start << std::endl;
        str << "Vertex      Distance from source" << std::endl;
        for(int i = 0; i < count_; i++) {
            str << "  " << i << "                  " << distance[i] << std::endl;
        }
    }
    else {
        std::cout << "error" << std::endl;
    }
}

void Matrix::readFromFile() {
    std::ifstream str("D:/AAA UCZELNIA/SEM4/PAMSI/P2/SS/MatrixRead.txt");
    int count;
    if(str) {
        str >> count;
        for(int i = 0; i < count; ++i) {
            for(int j = 0; j < count; ++j) {
                str >> graph[i][j];
            }
        }
    }
    else {
        std::cout << "error" << std::endl;
    }

}
