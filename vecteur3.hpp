#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class vector {
    public :
    double X,Y,Z ;


    vector(){
        X=0;
        Y=0;
        Z=0;
    }

    vector(double x,double y ,double z){
        X=x;
        Y=y;
        Z=z;
    }


    void print(){
        std::cout<<"[ "<<X<<" , "<<Y<<" , "<<Z<<" ]";
    }

    double lenght(){
        return sqrt(pow(X,2)+pow(Y,2)+pow(Z,2));
    };


    vector operator-(vector in ){
        return vector(X-in.X,Y-in.Y,Z-in.Z);
    };


    vector operator+(vector in ){
        return vector(X+in.X,Y+in.Y,Z+in.Z);
    };


    void operator-=(vector in ){
        X-=in.X; Y-=in.Y; Z-=in.Z;
    };

    void operator+=(vector in ){
        X+=in.X; Y+=in.Y; Z+=in.Z;
    };

    void operator=(vector in){
        X=in.X; Y=in.Y; Z=in.Z;
    }

    vector operator*(double scalar){
        return vector(X*scalar,Y*scalar,Z*scalar);
    };
    
    vector operator/(double scalar){
        return vector(X/scalar,Y/scalar,Z/scalar);
    };

    double operator||(vector in ){
        return X*in.X+Y*in.Y+Z*in.Z;
    }

};
