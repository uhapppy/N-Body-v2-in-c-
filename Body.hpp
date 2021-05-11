#include <iostream>
#include <math.h>
#include "vecteur3.hpp"


class Body{
    public :
    vecteur Position ;
    vecteur Speed ;
    vecteur Force ;
    double Mass  ;


    Body(){};


    
    Body(double X , double Y , double Z , double Vx , double Vy ,double Vz ,double mass){
        Position = vecteur(X,Y,Z);
        Speed = vecteur(Vx,Vy,Vz);
        Force = vecteur(0.,0.,0.);
        Mass = mass ;

    };



    void print(){

        std::cout<< "\n"<<"Position,Speed,Force,Mass : ";
        Position.print() ;
        Speed.print();
        Force.print();
        std::cout<< " "<< Mass;

    };


    void compute_force(Body& other , double epsilon , double G ){

        vecteur between = Position-other.Position;
        double lenght = between||between ;
        vecteur force = (between*((-G*Mass*other.Mass)/(pow(lenght+epsilon,1.5))));
        Force+=force;
        other.Force-=force;

    };

    void compute_new_pos(double dt){
        
        vecteur acceleration = Force/Mass;
        Speed+=acceleration*dt;
        Position+=Speed*dt;
        Force = Force*0;

    };




};