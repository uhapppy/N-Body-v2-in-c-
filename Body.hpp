#include <iostream>
#include <math.h>
#include "vector.hpp"


class Body{
    public :
    vector Position ;
    vector Speed ;
    vector Force ;
    double Mass  ;


    Body(){};


    
    Body(double X , double Y , double Z , double Vx , double Vy ,double Vz ,double mass){
        Position = vector(X,Y,Z);
        Speed = vector(Vx,Vy,Vz);
        Force = vector();
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

        vector between = Position-other.Position;
        double lenght = between||between ;
        vector force = (between*((-G*Mass*other.Mass)/(pow(lenght+epsilon,1.5))));
        Force+=force;
        other.Force-=force;

    };

    void compute_new_pos(double dt){
        
        vector acceleration = Force/Mass;
        Speed+=acceleration*dt;
        Position+=Speed*dt;
        Force = Force*0;

    };




};