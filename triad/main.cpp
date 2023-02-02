#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<time.h>
#include<omp.h>

#include <random>

#include "file.h"

using namespace std;

int main(int argc, char **argv){
    
    string data=argv[1];

    ofstream myfile;    
    
    myfile.open("../result/census_result/"+data+".txt");
    
    
    File file(data);
    
    //counting    
    double start=clock();
    file.get_triad();

    //save result and time
    myfile<<"total time for counting,"<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\n";
    
    for(int i=1; i<17; i++){
        myfile<<i<<","<<file.triad[i]<<"\n";
    }
    
    myfile.close();

    return 0;
}


