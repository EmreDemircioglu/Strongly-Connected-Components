//
// Created by Emre Demircioğlu on 24.11.2018.
//

#include "Graph.h"

Graph::Graph(int k) {
    this->size=k;
    this->adjacenyList= new list<int>[k];
    this->mySCCrootNum= new int[k];
    this->myParentNum= new int[k];
}
Graph::~Graph() {
    if(adjacenyList){
        adjacenyList->clear();
    }
    if(myParentNum){
        delete[] myParentNum;
    }
    if(mySCCrootNum){
        delete[] mySCCrootNum;
    }
}
void Graph::addElement(int from, int to) {
    this->adjacenyList[from].push_back(to-1);
}
void Graph::FSFPNHelperFunc(int a, int *disc, int *low, stack<int> *parentStack, bool *stackMember) {
    static int index = 0;
    disc[a] = low[a] = ++index;
    parentStack->push(a);
    stackMember[a] = true;
    list<int>::iterator i;
    for (i = adjacenyList[a].begin(); i != adjacenyList[a].end(); ++i) {
        int child = *i;
        if (disc[child] == -1) {
            FSFPNHelperFunc(child, disc, low, parentStack, stackMember);
            low[a]  = min(low[a], low[child]);
        }else if (stackMember[child])
            low[a]  = min(low[a], disc[child]);
    }
    int vertex = 0;
    vector<int> sccbox;
    if (low[a] == disc[a]) {
        while (parentStack->top() != a) {
            vertex = parentStack->top();
            stackMember[vertex] = false;
            sccbox.push_back(parentStack->top());
            parentStack->pop();
        }
        vertex = parentStack->top();
        stackMember[vertex] = false;
        sccbox.push_back(parentStack->top());
        parentStack->pop();
        this->myParentNum[vertex]=0;
        for(auto &k: sccbox){
            this->mySCCrootNum[k]=vertex;
        }
        for(auto &k:sccbox){
            for(i = adjacenyList[k].begin(); i != adjacenyList[k].end(); ++i){
                if(this->mySCCrootNum[*i]!=vertex){
                    this->myParentNum[this->mySCCrootNum[*i]]++;
                }
            }
        }
    }
}
void Graph::findSccFillParentNum() {
    for(int i=0;i<this->size;++i){
        this->myParentNum[i]=-1;
    }
    int *disc = new int[this->size];
    int *low = new int[this->size];
    bool *stackMember = new bool[this->size];
    stack<int> *parentStack = new stack<int>();
    for (int i = 0; i < this->size; i++) {
        disc[i] = -1;
        low[i] = -1;
        stackMember[i] = false;
    }
    for (int i = 0; i < this->size; i++) {
        if (disc[i] == -1) {
            FSFPNHelperFunc(i, disc, low, parentStack, stackMember);
        }
    }
    delete[] disc;
    delete[] low;
    delete[] stackMember;
    delete parentStack;
}