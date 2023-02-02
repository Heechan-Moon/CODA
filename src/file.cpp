#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<time.h>
#include<omp.h>
#include <random>

#include"file.h"


using namespace std;
    
File::File(string d, int size, double x){

    this->x = x;
    filepath="../data/"+d+"/"+d;
    file_h = filepath+"_head.txt";
    file_t = filepath+"_tail.txt";


    get_map();
    DHG.resize(size, 0);
}


void File::get_arc_list(){
    ifh.open(file_h); ift.open(file_t);
    int pointer=0;
    string str;
    string str2;

    if(ifh.is_open() & ift.is_open()){

        int cnt = 0;
        while(getline(ifh, str) && getline(ift, str2)){
            vector<int> h_temp;
            vector<int> t_temp;
            vector<int> a_temp;
            istringstream ss(str);
            string s;
            while (getline(ss, s, ' '))
            {
                if(s!="\r"){
                    int node = stoi(s);
                    h_temp.push_back(node);
                    a_temp.push_back(node);
                    if (V<node) V = node;
                }
            }
            istringstream ss2(str2);
            string s2;
            while (getline(ss2, s2, ' '))
            {
                if(s!="\r"){
                    int node = stoi(s2);
                    t_temp.push_back(node);
                    a_temp.push_back(node);
                    if (V<node) V = node;
                }            
            }       


            head.push_back(h_temp);
            tail.push_back(t_temp);
            arc.push_back(a_temp);
        }
    }
    ifh.close(); ift.close();
    
    E = head.size();
    V++;

    x = (double) E* x;
    
    return;

}

void File::get_VtA(){

    V_to_arc.resize(V);
    degV.resize(V, 0);

    for(int i=0; i<E; i++){
        for(auto &item: arc[i]){
            V_to_arc[item].push_back(i);
            degV[item]++;
            
        }
    }


}


void File::get_map(){
    vector<int> DHG_idx{36, 37, 38, 39, 45, 47, 49, 50, 51, 52,
                  53, 54, 55, 57, 58, 59, 60, 61, 62, 63,
                  67, 70, 71, 73, 75, 76, 77, 78, 79,
                  82, 83, 86, 87, 89, 90, 91, 92, 93, 94,
                  95, 100, 101, 102, 103, 109, 111, 113, 114, 115,
                  116, 117, 118, 119, 121, 122, 123, 124, 125, 126,
                  127, 146, 147, 150, 151, 155, 156, 157, 158, 159,
                  180, 181, 182, 183, 189, 191, 210, 211, 214, 215,
                  217, 219, 220, 221, 222, 223, 244, 245, 246, 247,
                  253, 255};

    int cnt = 0;

    for(auto &d: DHG_idx){
        DHG_map[d] = cnt;
        cnt+=1;
    }

    return;
}