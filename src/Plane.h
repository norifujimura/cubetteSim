//
//  Plane.hpp
//  cubetteSim
//
//  Created by Noriyuki Fujimura on 2018/03/19.
//

#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>
#include <vector>
#include "ofMain.h"

using namespace std;         //  名前空間指定

class Plate: public ofPlanePrimitive{
public:
    Plate();
    void set(int planeW);
    void move(int x,int y);
    void draw();
    ofMaterial material;
    float w;
    void setMaterial(ofMaterial material);
};

class Plane{
public:
    Plane();
    ofNode node;
    void set(int planeW,float plateW);
    void draw();
    void move(float x, float y, float z);
    ofMaterial white,black;
    vector<vector<Plate>> plates;
};



#endif /* Plane_hpp */
