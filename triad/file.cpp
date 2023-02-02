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
#include <unordered_set>

#include"file.h"


using namespace std;
    
File::File(string d){

    filepath="../data/"+d+"/"+d;
    //proj="-proj-graph";
    file = filepath+"_clique.txt";
    
    read();
    get_adj();

}


void File::read(){
    ifs.open(file); 
    string str;
    string str2;

    if(ifs.is_open()){

        int cnt = 0;
        while(getline(ifs, str)){
            vector<int> temp;
            istringstream ss(str);
            string s;
            while (getline(ss, s, ','))
            {
                if(s!="\r"){
                    int node = stoi(s);
                    temp.push_back(node);
                    if (V<node) V = node;
                }
            }


            edges.push_back(temp);
        }
    }
    ifs.close(); 
    
    E = edges.size();
    V++;

    return;

}

void File::get_adj(){

    out.resize(V);
    adj.resize(V);

    for(auto &e: edges){
        out[e[0]].insert(e[1]);        
        adj[e[0]].insert(e[1]);        
        adj[e[1]].insert(e[0]);        
    }

    return;

}


void File::get_triad(){
    if(V<3) V=3;

    triad.resize(17, 0); //starting from 1
    vector<int> Tritypes = {1,2,2,3,2,4,6,8,2,6,5,7,3,8,7,11,
                            2,6,4,8,5,9,9,13,6,10,9,14,7,14,12,15,
                            2,5,6,7,6,9,10,14,4,9,9,12,8,13,14,15,
                            3,7,8,11,7,12,14,15,8,14,13,15,11,15,15,16};
    
    for(int v=0; v<V; v++){
        for(auto &u: adj[v]){
            if(v < u){
                int v_in_u = 0;
                int u_in_v = 0;
                int type = 1;
                unordered_set<int> S;
    
                for(auto &a: adj[v]){
                    if(a!=u) S.insert(a);
                }
                for(auto &b: adj[u]){
                    if(b!=v) S.insert(b);
                }
                u_in_v = existence_out(v, u);
                v_in_u = existence_out(u, v);

                if(u_in_v && v_in_u){
                    type = 3;
                }else type = 2;

                triad[type] = triad[type]+V-S.size()-2;
                for(auto &w: S){
                    int check3 = existence_adj(v, w);
                    
                    if(u<w || (v<w && w<u && !check3)){
                        int tricode = u_in_v + 2*(v_in_u+2*(existence_out(v, w)+2*(existence_out(w, v)+2*(existence_out(u, w)+2*(existence_out(w, u))))));
                        triad[Tritypes[tricode]]++;              
                    }

                }
            }    
        
            
        
        }

    }
    
    long long sum = 0;
    for(int i=2; i<17; i++){
        sum +=triad[i];
    }


    triad[1] = V*(V-1)*(V-2)/6-sum; 
    
    return;
}

int File::existence_adj(int a, int b){

    int check = 0;

    unordered_set<int>::const_iterator iter = adj[a].find(b);
    if (iter != adj[a].end()){
        check = 1;
    }
    return check;
}

int File::existence_out(int a, int b){

    int check = 0;

    unordered_set<int>::const_iterator iter = out[a].find(b);
    if (iter != out[a].end()){
        check = 1;

    }
    return check;
}