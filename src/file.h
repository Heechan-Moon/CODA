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

    vector<int> split(string str, char Delimiter);
    unordered_set<int> convertToSet(vector<int> v);
    vector<vector<int>> getInfo(string filename, int num);
    vector<unordered_set<int>> getInfo(string filename);
    unordered_set<int> getUnion(unordered_set<int> A, unordered_set<int> B);
    int getMotif(int case1, int case2, int case3, int case4, int case5, int case6, int case7, int case8);
    int getMotif_symmetric(int case1, int case2, int case3, int case4, int case5, int case6, int case7, int case8);
    void Intersec(unordered_set<int> head_a, unordered_set<int> tail_a, unordered_set<int> head_b, unordered_set<int> tail_b, int &case2, int &case3, int &case6, int &case7);
    int getMotif_result(unordered_set<int> head_a, unordered_set<int> tail_a, unordered_set<int> head_b, unordered_set<int> tail_b);
    
    string filepath;
    string file_h; string file_t;
    ifstream ifh; ifstream ift;
    ifstream ifs; ifstream ifs2; ifstream ifs3; ifstream ifs4;

    void get_map();
    unordered_map<int, int> DHG_map;

    double x = 0;

    vector<unordered_set<int>> arc_exact;
    vector<unordered_set<int>> head_exact;
    vector<unordered_set<int>> tail_exact;

    vector<vector<int>> arc;
    vector<vector<int>> head;
    vector<vector<int>> tail;
    // temp
    //void get_degree();
    vector<int> degV;

 
    vector<int> degree_sum;
    vector<int> node_degree_dist;
    vector<unordered_set<int>> nei;
    int _E;

    public: 
        File(string d, int size, double x);
        vector<vector<int>> V_to_arc;
        int V=0;
        int E=0;
        
        vector<int> cand;
        vector<int> cand_e;

        vector<double> DHG;
        void get_arc_list();
        void get_VtA();
        
        void exact();
        void WN2A();
        void A2WN();
        void A2A();
        void uni();
        
        int C=0;
        
};

#endif


