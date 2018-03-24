//
//  myCar.cpp
//  cubetteSim
//
//  Created by Noriyuki Fujimura on 2018/03/21.
//

#include "myCar.h"

myCar::myCar(){
}

void myCar::setup(){
    state=ready;
    count=0;
    
    material.setDiffuseColor(ofFloatColor::green);
    // This is how we append the 2 headlamps to the car.
    // Calling setParent, we are telling to the lights that they are
    // a child of the object car, and that teir movement are relative to
    // the movement of the car
    
    geometry.set(100,100,100);
    
    lightL.move(-45,20,-51);
    lightR.move(45,20,-51);
    lightL.tilt(-20);
    lightR.tilt(-20);
    lightL.setSpotlight();
    lightR.setSpotlight();
    lightL.setDiffuseColor(ofFloatColor::yellow);
    lightR.setDiffuseColor(ofFloatColor::yellow);
    lightL.setup();
    lightR.setup();
    
    lightL.setParent(geometry);
    lightR.setParent(geometry);
    
}

void myCar::draw(){
    material.begin();
    geometry.draw();
    material.end();
    
    lightR.draw();
    lightL.draw();
}

void myCar::set(States st){
    if(st==state){
        return;
    }else{
        state=st;
        count=0;
    }
}

void myCar::update(){

    
    if(count==60){
        state=ready;
        count=0;
    }
    
    if(state==ready){
        ofLog(OF_LOG_NOTICE,"Ready %d", count);
    }else if(state==stop){
        ofLog(OF_LOG_NOTICE,"ST %d", count);
        count++;
    }else if(state==fw){
        ofLog(OF_LOG_NOTICE,"FW %d", count);
        geometry.dolly(-100.0/60.0);
        count++;
    }else if(state==turnR){
        ofLog(OF_LOG_NOTICE,"TR %d", count);
        geometry.rotate(-90.00/60.00,0,1,0);
        geometry.dolly(0);
        count++;
    }else if(state==turnL){
        ofLog(OF_LOG_NOTICE,"TL %d", count);
        geometry.rotate(90.00/60.00,0,1,0);
        geometry.dolly(0);
        count++;
    }
}
