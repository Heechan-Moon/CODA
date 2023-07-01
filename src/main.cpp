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
void save_results(vector<double> DHG, int d_size, string data, double x, string version, int trial);

int main(int argc, char **argv){
    
    double x=stod(argv[1]);
    string data=argv[2];
    string version=argv[3];
    int trial=stoi(argv[4]);

  
    int d_size = 91;

    ofstream myfile;    

    myfile.open("../result/DHG_time/"+data+"_"+version+"_"+to_string((int)(x*100))+".csv");
    
    for(int i=0; i<trial; i++){
        
        int check = 1;
        double start=clock();

        File file(data, d_size, x);

        
        myfile<<"reading,"<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\n";
        start=clock();
        
        if(version=="CODAE"){
            file.exact();  
        }
        else{
            file.get_arc_list();
            file.get_VtA();

            if(version=="CODAA"){
                file.WN2A();
            }
            else if(version=="A2A"){
                file.A2A();
            }else if(version=="DMOCHY"){
                file.uni();
            }
            else{
                check = 0;
            }
        }
        

        myfile<<"counting,"<<(double)(clock()-start)/CLOCKS_PER_SEC<<"\n";

        if(check) save_results(file.DHG, d_size, data, x, version, i);    
    
    }
    myfile.close();
    return 0;
}



void save_results(vector<double> DHG, int d_size, string data, double x, string version, int trial){
    fstream file_out;
    
    if(trial) file_out.open("../result/DHG/"+version+"/"+data+"_"+to_string((int)(x*100))+"_"+to_string(trial)+".txt", ios_base::out);
    else file_out.open("../result/DHG/"+version+"/"+data+"_"+to_string((int)(x*100))+".txt", ios_base::out);
    for(int i=0; i<d_size; i++){
        if(DHG[i]) file_out<<i+1<<" "<<to_string(DHG[i])<<endl;
    }
    file_out.close();

}