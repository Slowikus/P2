#include <iostream>

class Matrix {
private:
    int edgeCount_{0};
    int count_;
    int **graph;

    int *distance;
    bool *sptSet;

public:
    Matrix() = default;
    Matrix(int count) : count_(count) {
        distance = new int[count];
        sptSet = new bool[count];

        graph = new int*[count];
        for(int i = 0; i < count; ++i)
        {
            graph[i] = new int[count];
        }
    }

    void createMatrix();
    void addCount(int count) {
        count_ = count;

        distance = new int[count];
        sptSet = new bool[count];

        graph = new int*[count];
        for(int i = 0; i < count; ++i)
        {
            graph[i] = new int[count];
        }
    }
    int minDistance();
    void saveToFile(int start);
    void readFromFile();
    void solution(int start);
    void solution2(int source, int end);
    void dijkstra(int source);
    void dijkstra2(int source, int end);

};