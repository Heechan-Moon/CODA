#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class File {

    // temp
    //void get_degree();
    string filepath;
    string file;
    ifstream ifs;

    void read();
    void get_adj();
    int existence_adj(int a, int b);
    int existence_out(int a, int b);

    public: 
        File(string d);
        vector<vector<int>> edges;
        vector<unordered_set<int>> out;
        vector<unordered_set<int>> adj;

        vector<long long> triad;

        void get_triad();

        long long V=0;
        int E=0;

        
};

#endif


