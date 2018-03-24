//
//  myCar.hpp
//  cubetteSim
//
//  Created by Noriyuki Fujimura on 2018/03/21.
//

#pragma once

#include "ofMain.h"



class myCar{
public:
    
    myCar();
    void setup();
    void draw();
    void update();
    void forward();
    void turnRight();
    void turnLeft();

    enum States{ready,stop,fw,turnR,turnL};
    
    void set(States st);
    
    States state;
    int count;
    
private:
    ofBoxPrimitive geometry;
    ofNode node;
    ofMaterial material;
    ofLight lightR, lightL;
};
