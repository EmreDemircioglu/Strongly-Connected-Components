
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <fstream>
#include "Graph.h"
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Run the code with the following command: ./project3 [input_file] [output_file]" << endl;
        return 1;
    }
    //reading from file starts
    ifstream infile(argv[1]);
    int size;
    infile >> size;
    //initializing graph
    Graph initial(size);
    //filling graph
    for(int i =0;i<size;++i){
        int temp;
        infile >> temp;
        for(int k=0;k<temp;++k){
            int temp2;
            infile>>temp2;
            initial.addElement(i, temp2);
        }
    }
    // reading from file ended
    //calculation
    initial.findSccFillParentNum();
    vector<int> result;
    for(int i=0;i<size;++i){
        if(initial.myParentNum[i]==0){
            result.push_back(i);
        }
    }
    //writing to file starts
    ofstream myfile;
    myfile.open(argv[2]);
    myfile << result.size()<<" ";
    for (auto &i:result) {
        myfile << (i+1)<< " ";
    }
    myfile.close();
    //writing to file ended
    return 0;
}