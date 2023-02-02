#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include"file.h"

using namespace std;

vector<int> File::split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
 
    vector<int> result;
 
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(stoi(buffer));
    }
 
    return result;
}

unordered_set<int> File::convertToSet(vector<int> v)
{
    unordered_set<int> s; // Declaring the set
 
    for (int x : v) { // Traverse the Vector
        s.insert(x);
    }
 
    return s;
}

vector<vector<int>> File::getInfo(string filename, int num){
    ifstream stream(filename.data());
    vector<vector<int>> results;

    if(stream.is_open()){
        string line;
        int count=0;
        while(getline(stream, line, '\n')){
            if (count < num){
                vector<int> result = split(line, ' ');
                results.push_back(result);
            }
            count+=1;
        }
        stream.close();
    }

    return results;
}

vector<unordered_set<int>> File::getInfo(string filename){
    ifstream stream(filename.data());
    vector<unordered_set<int>> results;

    if(stream.is_open()){
        string line;
        while(getline(stream, line, '\n')){
            unordered_set<int> result = convertToSet(split(line, ' '));
            results.push_back(result);
        }
        stream.close();
    }

    return results;
}

unordered_set<int> File::getUnion(unordered_set<int> A, unordered_set<int> B){
    unordered_set<int> union_set;

    for(auto a: A){
        union_set.insert(a);
    }
    for(auto b: B){
        union_set.insert(b);
    }

    return union_set;
}

int File::getMotif(int case1, int case2, int case3, int case4, int case5, int case6, int case7, int case8){
    int motif=0;

    if (case1 != 0)
        motif+=1;
    if (case2 != 0)
        motif+=2;
    if (case3 != 0)
        motif+=4;
    if (case4 != 0)
        motif+=8;
    if (case5 != 0)
        motif+=16;
    if (case6 != 0)
        motif+=32;
    if (case7 != 0)
        motif+=64;
    if (case8 != 0)
        motif+=128;

    return motif;
}

int File::getMotif_symmetric(int case1, int case2, int case3, int case4, int case5, int case6, int case7, int case8){
    int motif=0;

    if (case4 != 0)
        motif+=1;
    if (case2 != 0)
        motif+=2;
    if (case6 != 0)
        motif+=4;
    if (case1 != 0)
        motif+=8;
    if (case8 != 0)
        motif+=16;
    if (case3 != 0)
        motif+=32;
    if (case7 != 0)
        motif+=64;
    if (case5 != 0)
        motif+=128;

    return motif;
}

void File::Intersec(unordered_set<int> head_a, unordered_set<int> tail_a, unordered_set<int> head_b, unordered_set<int> tail_b, int &case2, int &case3, int &case6, int &case7){
    int size_a = head_a.size()+tail_a.size();
    int size_b = head_b.size()+tail_b.size();

    if (size_a > size_b){ // hyperarc b selected
        for (auto h: head_b){
            unordered_set<int>::const_iterator h_a_iter = head_a.find(h);
            unordered_set<int>::const_iterator t_a_iter = tail_a.find(h);
            if (h_a_iter!=head_a.end()){
                case2 += 1;
            }
            if (t_a_iter!=tail_a.end()){
                case6 += 1;
            }
        }
        for(auto t: tail_b){
            unordered_set<int>::const_iterator h_a_iter = head_a.find(t);
            unordered_set<int>::const_iterator t_a_iter = tail_a.find(t);
            if (h_a_iter!=head_a.end()){
                case3 += 1;
            }
            if (t_a_iter!=tail_a.end()){
                case7 += 1;
            }
        }
    }
    else { // hyperarc a selected
        for (auto h: head_a){
            unordered_set<int>::const_iterator h_b_iter = head_b.find(h);
            unordered_set<int>::const_iterator t_b_iter = tail_b.find(h);
            if (h_b_iter!=head_b.end()){
                case2 +=1;
            }
            if (t_b_iter!=tail_b.end()){
                case3 +=1;
            }
        }
        for (auto t: tail_a){
            unordered_set<int>::const_iterator h_b_iter = head_b.find(t);
            unordered_set<int>::const_iterator t_b_iter = tail_b.find(t);
            if (h_b_iter!=head_b.end()){
                case6 +=1;
            }
            if (t_b_iter!=tail_b.end()){
                case7 +=1;
            }
        }
    }
}

int File::getMotif_result(unordered_set<int> head_a, unordered_set<int> tail_a, unordered_set<int> head_b, unordered_set<int> tail_b){
    int case2 = 0;
    int case3 = 0;
    int case6 = 0;
    int case7 = 0;

    Intersec(head_a, tail_a, head_b, tail_b, case2, case3, case6, case7);

    if (case2+case3+case6+case7==0)
        return -1;
        //cout<<"Something Wrong..."<<endl;
                
    int case1 = head_a.size()-case2-case3;
    int case4 = head_b.size()-case2-case6;
    int case5 = tail_b.size()-case3-case7;
    int case8 = tail_a.size()-case6-case7;

    int motif = getMotif(case1, case2, case3, case4, case5, case6, case7, case8);
    int related_motif = getMotif_symmetric(case1, case2, case3, case4, case5, case6, case7, case8);
    int num_motif = min(motif, related_motif);

    return num_motif;
}


