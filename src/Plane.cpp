//
//  Plane.cpp
//  cubetteSim
//
//  Created by Noriyuki Fujimura on 2018/03/19.
//

#include "Plane.h"

Plane::Plane(){
    white.setDiffuseColor(ofFloatColor::white);
    white.setShininess(0.1);
    black.setDiffuseColor(ofFloatColor::gray);
    black.setShininess(0.01);
}

void Plane::set(int planeW,float plateW){
    
    if(planeW%2==0){
        planeW++;//shoule be odd number
    }
    
    ofLog(OF_LOG_NOTICE,"planeW: %d",planeW);
    plates.resize(planeW);
    
    for (int i=0;i<planeW;i++){
        plates[i].resize(planeW);
        for (int j=0;j<planeW;j++){
            Plate temp=Plate();
            temp.set(plateW);
            if(i%2==0 ){
                if(j%2==0){
                    temp.setMaterial(white);
                }else{
                    temp.setMaterial(black);
                }
            }else{
                if(j%2==1){
                    temp.setMaterial(white);
                }else{
                    temp.setMaterial(black);
                }
            }
            temp.move(-planeW/2, -planeW/2);
            temp.move(i,j);
    
            temp.setParent(node);
            plates[i][j]=temp;
        }
    }
}

void Plane::draw(){
    for (int i=0;i<plates.size();i++){
       for (int j=0;j<plates[i].size();j++){
           plates[i][j].draw();
       }
    }
}

void Plane::move(float x, float y, float z){
    node.move(x,y,z);
}

Plate::Plate(){

}

void Plate::set(int w){
    this->w=w;
    ofPlanePrimitive::set(float(w),float(w));
    rotate(270, 1, 0 , 0);
}
void Plate::move(int x,int y){
    ofPlanePrimitive::move(float(x*w),0.0,float(y*w));
}
void Plate::setMaterial(ofMaterial material){
    this->material=material;
}

void Plate::draw(){
    material.begin();
    ofPlanePrimitive::draw();
    material.end();
}


