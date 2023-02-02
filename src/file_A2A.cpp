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

void File::A2A(){
    random_device rd;
    mt19937 gen(rd());
    
    int* problem = new int[E]();
    int _E = E;

    for(int i=0; i<V; i++){            
        if(degV[i]==1){
            int e = V_to_arc[i][0];
            int check = 1;
            for(auto &v: arc[e]){
                if(degV[v]!=1){
                    check = 0;
                }
            }
            if(check){
                problem[e] = 1;
                _E--;
            }
        }
    }

    double constant = (double)x/(double)_E;
    vector<unordered_set<int>> local_line_graph;
    local_line_graph.resize(E);

    for(int i=0; i<x; i++){
        //cout<<i<<endl;

        double p = 0;
        uniform_int_distribution<int> dis(0, E-1);
        
        int a; int b;
        while(true){
            a = dis(gen);  
            if(problem[a]==0) break;
        } 

        unordered_set<int> temp2;

        for(auto &v: arc[a]){
            for(auto &e: V_to_arc[v]){
                if(e!=a){
                    temp2.insert(e); //vector
                }
            }
        }

        vector<int> temp(temp2.begin(), temp2.end());
        int na = temp.size();
        uniform_int_distribution<int> dis2(0, na-1);
        b = temp[dis2(gen)];

        unordered_set<int> temp3;
        for(auto &v: arc[b]){
            for(auto &e: V_to_arc[v]){
                if(e!=b){
                    temp3.insert(e);
                }
            }
        }
    
        
        p = constant*(1.0/(double)na+1.0/(double)temp3.size());

        int idx = getMotif_result(convertToSet(head[a]), convertToSet(tail[a]), convertToSet(head[b]), convertToSet(tail[b]));
     
        DHG[DHG_map[idx]] += 1/p;


    }

    return;
}
