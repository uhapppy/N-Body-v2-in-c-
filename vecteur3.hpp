#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class vecteur{
    public:
    int size = 3 ;
    double  data[3];


    

    //constructeur de base
    vecteur(){
        data[0]=0.;
        data[1]=0.;
        data[2]=0.;
        
    };


    //construtor avec array et size
    vecteur(double X, double Y,double Z){
        data[0]=X;
        data[1]=Y;
        data[2]=Z;
    };

    // print le contenue du vecteur 
    void print(){
        std::cout <<  "[ ";
        for(int i = 0 ; i<size-1 ; i++){
            std::cout << data[i]<<" , ";
        };
        std::cout << data[size-1];
        std::cout << " ]";
    };



    double operator[] (int N){
        return(data[N]);
    };

    vecteur operator+ (vecteur in){
        vecteur output(data[0]+in.data[0],data[1]+in.data[1],data[2]+in.data[2]) ;
        return (output);
    };

    vecteur operator- (vecteur in){
        vecteur output(data[0]-in.data[0],data[1]-in.data[1],data[2]-in.data[2]) ;
        return (output);
    };


    void operator-= (vecteur in){
        data[0]-=in.data[0];
        data[1]-=in.data[1];
        data[2]-=in.data[2];
        
    };

    void operator+= (vecteur in){
        data[0]+=in.data[0];
        data[1]+=in.data[1];
        data[2]+=in.data[2];
        
    };

    void operator= (vecteur in){
        
        data[0]=in.data[0];
        data[1]=in.data[1]; 
        data[2]=in.data[2];  
        
    };

    vecteur operator* (double scalar){
        vecteur output(data[0]*scalar,data[1]*scalar,data[2]*scalar) ;
        return output;
    };

    
    vecteur operator/ (double scalar){
        vecteur output(data[0]/scalar,data[1]/scalar,data[2]/scalar) ;
        return output;
    };


    double operator|| (vecteur in){
        double output = data[0]*in.data[0]+data[1]*in.data[1]+data[2]*in.data[2]  ;
        return output;
    };

};