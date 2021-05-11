#include <iostream>
#include <string>
#include "Body.hpp"
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>


int main() {

    const double G = 30 ;
    const int NUMBER_OF_BODY=1000 ;
    const double EPSILON = 25 ;
    const double DT = 0.3 ;
    const int SIZE = 1000 ;
    const int  ITTERATION = 500 ;




    Body liste[NUMBER_OF_BODY];


    // create Body
    
    srand((unsigned) time(0));
    for(int i = 0 ; i<NUMBER_OF_BODY ; i++ ){

        double X = (rand()%SIZE)-(SIZE/2);
        double Y = (rand()%SIZE)-(SIZE/2);
        double Z = (rand()%SIZE)-(SIZE/2);
        double M = (rand()%9)+1;

        Body body = Body(X,Y,Z,0.,0.,0.,M);
        liste[i]=body;
        
    };

    


    std::ofstream File("gravity.cvs");
    clock_t tStart = clock();
    for(int k = 1 ; k< ITTERATION+1 ; k++){

    // Compute force 
    for(int i = 0; i<NUMBER_OF_BODY ; i++){
        for(int j = i+1 ; j<NUMBER_OF_BODY ; j++){
                liste[i].compute_force(liste[j],EPSILON,G);
            };

        };
    

    // update position

    for(int i = 0; i<NUMBER_OF_BODY ; i++){
        liste[i].compute_new_pos(DT);
        File << liste[i].Position[0]<<','<< liste[i].Position[1]<<','<< liste[i].Position[2]<<"\n" ;
    };
    double tmoy = (double(clock() - tStart) / 1000)/k ;
    double trest =tmoy*(ITTERATION-k);

    std::cout<< "\r"<<"itteration en cours : "<<k<<"/"<<ITTERATION<<" , durer moyenne d'une itteration : "<< tmoy << " , temps restant estimer : "<< trest;
    

    };
    std::cout <<"\r"<<"  temps d'execution  :   "<< (double(clock() - tStart) / 1000) << "  seconde  " <<" ,  durer moyenne d'une itteration  :   "<<(double(clock() - tStart) / 1000)/ITTERATION<<"                         ";

    return 0 ;
}