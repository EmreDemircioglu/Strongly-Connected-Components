//
// Created by Emre Demircioğlu on 24.11.2018.
//

#ifndef PROJECT3_GRAPH_H
#define PROJECT3_GRAPH_H

using namespace std;
#include <list>
#include <stack>
#include <iostream>
#include <vector>
class Graph {
private:
    //size of the graph
    int size;

    //list that represent graph
    //an element in list is an array. Array elements are the child of that index
    list<int> *adjacenyList;

    //an array has the information of scc root's any element in the graph according to index
    int* mySCCrootNum;

    //helper function of findSccFillParentNum
    // a is element that this function called for
    // disc is array that holds discovery index of every element in the graph at DFS
    // low is array that holds lowest reachable index of every element in the graph
    // parentStack is the stack holds parents of child
    // stackMember is the array that holds the information of an element is in the parentStack or not according to index
    void FSFPNHelperFunc(int a, int *disc, int *low, stack<int> *parentStack, bool *stackMember);
public:
    // constructor
    Graph(int k);

    // destructor
    ~Graph();

    // adds new element to graph
    void addElement(int from, int to);

    // finds scc in the graph
    // and fills myParentNum array
    void findSccFillParentNum();

    // an array that holds the information of any scc root's parent number according to index
    // if an element is not a root it is set -1
    int* myParentNum;
};

#endif //PROJECT3_GRAPH_H
