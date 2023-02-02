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

void File::uni(){
    random_device rd;
    mt19937 gen(rd());

    nei.resize(E);
    long long Omega = 0;

    vector<long long> edge_dist;
    edge_dist.resize(E, 0);

    long long add = 0;

    for(int e=0; e<E; e++){
        unordered_set<int> _temp;
        //sort(arc[e].begin(), arc[e].end()); 
        
        for(auto &v: arc[e]){
            for(auto &b: V_to_arc[v]){
                if(e>b){
                    _temp.insert(b);
                }
               
            }

        }

        nei[e] = _temp;
        edge_dist[e] = _temp.size()+add;
        add = edge_dist[e];
    }

    Omega = edge_dist.back();

    for(int i=0; i<x; i++){

        double p = (double)x/(double)Omega;

        uniform_int_distribution<long long> dis(0, Omega-1);
        int temp = dis(gen);

        long long lo = 0, hi = E, mid, sampled_idx = 0;


        while(lo <= hi){
    
            mid = (lo + hi) >> 1;
            if(temp >= edge_dist[mid]){
                sampled_idx = mid+1; lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        int a = sampled_idx;

        int size = nei[a].size();


        uniform_int_distribution<int> dis2(0, size-1);

        vector<int> neia(nei[a].begin(), nei[a].end());

        int b = neia[dis2(gen)];

       
        int idx = getMotif_result(convertToSet(head[a]), convertToSet(tail[a]), convertToSet(head[b]), convertToSet(tail[b]));


        DHG[DHG_map[idx]] += 1/p;
    
    }

    
    return;
}


