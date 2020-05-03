#include <iostream>
#include <memory>

#include <vector>

struct Node {
    int dest;
    int cost;
};

class ListElement {
public:
    ListElement(const Node& node) {
        node_ = node;
        next_ = nullptr;
    }

    std::shared_ptr<ListElement> returnNextElement() {
        return next_;
    }

    void setNextElement(std::shared_ptr<ListElement> next) {
        next_ = next;
    }

    int getDest() {
        return node_.dest;
    }

    int getCost() {
        return node_.cost;
    }

private:
    Node node_;
    std::shared_ptr<ListElement> next_;
};

class List {
public:
    List(): first_{nullptr} {}
    void addElement(const Node& node) {
        std::shared_ptr<ListElement> temp(new ListElement(node));

        if(first_== nullptr) {
            first_ = temp;
            return;
        }
        std::shared_ptr<ListElement> iterator = first_;
        while(iterator->returnNextElement() != nullptr) {
            iterator = iterator->returnNextElement();
        }
        iterator->setNextElement(temp);
    }

    std::shared_ptr<ListElement> returnFirstElement() {
        return first_;
    }

private:
    std::shared_ptr<ListElement> first_;
};

class Graph {
private:
    int edgeCount_{0};
    int count_{};
    int findMin();
    bool areAllRemoved();
    int *temp;
    List *list;

public:
    Graph() = default;
    Graph(int count) : count_(count) {
        temp = new int[count];
        list = new List[count];
    }

    void addCount(int count) {
        count_ = count;
        temp = new int[count];
        list = new List[count];
    }
    void solution(int start, int final[]);
    void saveToFile(int start, int final[]);
    void readFromFile();

    void createList();

    void addEdge(int source, int dest, int cost);
    void dijkstra(int start);
    void dijkstra2(int start, int end);
};
