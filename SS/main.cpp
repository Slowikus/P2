#include <time.h>
#include "Matrix.hpp"
#include "List.hpp"

//Program wczytuje listę oraz macierz z pliku i zapisue wyniki do plikow List.txt oraz Matrix.txt .


int main() {
    int count = 20;
 //   //  MATRIX /////////////////////////////////////
    int sourceT{0};


    int countM = 9;
    Matrix gMatrixT{countM};
    gMatrixT.readFromFile();
    gMatrixT.dijkstra(sourceT);

    //generowanie 100 grafow - macierz
//************************************************************//
//    int source{0};
//    clock_t startDijkstraMatrix = clock();
//
//    for(int i = 0; i < 100; ++i) {
//        Matrix gMatrix{count};
//        gMatrix.createMatrix();
//        gMatrix.dijkstra(source);
//    }
//
//    clock_t stopDijkstraMatrix = clock();
//*************************************************************

   // // LIST /////////////////////////////////////////
    int startT = 0;
    int countL = 9;
    Graph gg{countL};
    gg.readFromFile();
    gg.dijkstra(startT);

    //generownie 100 grafow - lista
//**********************************************************************
//    int start = 0;
//    Graph g[100];
//
//    for(int i = 0; i < 100; ++i) {
//        g[i].addCount(count);
//        g[i].createList();
//    }
//
//    clock_t startDijkstraList = clock();
//
//    for(int i = 0; i < 100; ++i) {
//        g[i].dijkstra(start);
//    }
//
//    clock_t stopDijkstraList = clock();
//
//// Wypisanie czasów w ms ////////////////////////////////////////////
//
//    double elapsedDijkstraMatrix = (double) (stopDijkstraMatrix - startDijkstraMatrix) / CLOCKS_PER_SEC*1000;
//    std::cout << "DIJKSTRA_MATRIX time elapsed: " << elapsedDijkstraMatrix / 100 << std::endl;
//
//    double elapsedDijkstraList = (double) (stopDijkstraList - startDijkstraList) / CLOCKS_PER_SEC*1000;
//    std::cout << "DIJKSTRA_LIST time elapsed: " << elapsedDijkstraList / 100 << std::endl;
//*****************************************************************************
    return 0;
}


