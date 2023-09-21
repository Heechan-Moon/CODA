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

void File::WN2A(){
    random_device rd;
    mt19937 gen(rd());
    vector<long long> degree_dist;
    long long cnt = 0;
    for(int i=0; i<V; i++){
        
        int size = degV[i];            
        if(size>1){
            cand.push_back(i);
            int save = size*(size-1)/2;

            cnt = cnt+save;
            degree_dist.push_back(cnt);
            
        }
    }
    double constant = (double)x/(double)degree_dist.back();

    for(int i=0; i<x; i++){

        double p = 0;

        uniform_int_distribution<long long> dis(0, degree_dist.back()-1);

        long long temp = dis(gen);
        int lo = 0, hi = degree_dist.size() - 1, mid, sampled_idx = 0; // hi=V-1

        while(lo <= hi){
            mid = (lo + hi) >> 1;
            if(temp >= degree_dist[mid]){
                sampled_idx = mid+1; lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }

        int v_temp = cand[sampled_idx];
        int pair[2];
        int size = degV[v_temp];
        
        uniform_int_distribution<int> dis2(0, size-1);
        uniform_int_distribution<int> dis3(0, size-2);
        pair[0] = dis2(gen);
        pair[1] = dis3(gen);

        if(pair[1]>=pair[0]){
            pair[1]++;
        }

        int a = V_to_arc[v_temp][pair[0]];
        int b = V_to_arc[v_temp][pair[1]];

        vector<int> PV;
        
        sort(arc[a].begin(), arc[a].end());
        sort(arc[b].begin(), arc[b].end());
        set_intersection(arc[a].begin(), arc[a].end(), arc[b].begin(), arc[b].end(), back_inserter(PV));
        
        
        p = PV.size()*constant;
        int idx = getMotif_result(convertToSet(head[a]), convertToSet(tail[a]), convertToSet(head[b]), convertToSet(tail[b]));

        DHG[DHG_map[idx]] += 1/p;
    
    }

    return;
}