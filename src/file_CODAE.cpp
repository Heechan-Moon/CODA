#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<time.h>
#include<omp.h>
#include<random>

#include"file.h"


void File::exact(){
    
    unordered_map<int, vector<int>> VtA;
    ifh.open(file_h); ift.open(file_t);
 
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
                    VtA[node].push_back(cnt);

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
                    VtA[node].push_back(cnt);
                }            
            }       

            head_exact.push_back(convertToSet(h_temp));
            tail_exact.push_back(convertToSet(t_temp));
            arc_exact.push_back(convertToSet(a_temp));
            
            unordered_set<int> temp;
        
            for(auto &v: arc_exact[cnt]){
                for(auto &e: VtA[v]){
                    if(e==cnt) continue;
                  
                    unordered_set<int>::const_iterator iter = temp.find(e);
                    if (iter==temp.end()){
                        int idx = getMotif_result(head_exact[cnt], tail_exact[cnt], head_exact[e], tail_exact[e]);
                        DHG[DHG_map[idx]] += 1;
                        temp.insert(e);
                    }
                    
                }

            }
            cnt++;
        }
    
    }
    ifh.close(); ift.close();

}

