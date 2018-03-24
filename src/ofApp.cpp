#include "ofApp.h"

/*
 This tutorial shows how to use the ofNode to build a gerarchy of objects, it was
 originally developed in a workshop held by Arturo Castro at Lacuna Lab.
 Most 3D classes in OF inheritate from ofNode. ofNode is simply a class that defines
 a point in a 3D space and allows to:
 - Chain a point with another point
 - Apply matrices transformation to it
 
 We will never define an ofNode directly in this example, that's why you will 
 not find the word `ofNode` in the code but both ofLight and ofBoxPrimitive
 inherith from ofNode, allowing us to access all its powerful methods.
 
 In this example we want to create a car with 2 headlamps, and we want to move the lights
 together with the car, without re-calculating the position of the 2 light.
 We define only how the car should move into the space, the light just need to stay on the front
 of the car, their movement it's just a consequence of the movement of the car.
 Have a look at the Car.cpp file to see how we attach the lights on the front of the car and how to move
 object using the handy rotate, move and tilt methods, without any need to use ofPushMatrix and ofPopMatrix.
 */



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    //ofSetFrameRate(0);
    
    light.setup();
    light.setPosition(-100, 200,0);
    // we set up a plane on which the car will move
    plane.set(10, 100);
    plane.move(0, -60, 0);
    car.setup();
    
    ofEnableDepthTest();
    com=Commands();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(comBuffer==""){
        //do nothing
        ofLog(OF_LOG_NOTICE,"command empty: read next");
        comBuffer=com.getNext();
    }else{
        ofLog(OF_LOG_NOTICE,"command not empty");
        if(car.state==myCar::ready){
            if(comBuffer=="f"){
                car.set(myCar::fw);
                comBuffer="";
            }else if(comBuffer=="r"){
                car.set(myCar::turnR);
                comBuffer="";
            }else if(comBuffer=="l"){
                car.set(myCar::turnL);
                comBuffer="";
            }
        }
    }
    car.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
        plane.draw();
        car.draw();
    cam.end();
    ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   if (key == ' '){
        string commands= ofSystemTextBoxDialog("Input Sequence","");
        //print(urlAddress)
        ofLog(OF_LOG_NOTICE,commands);
        com.set(commands);
        //browser.loadURL(urlAddress);
    }
    
    switch (key) {
        case OF_KEY_UP:
            //car.accellerate();
            //car.state=car.fw;
            car.set(car.fw);
            break;
        case OF_KEY_DOWN:
            //car.brake();
            //car.state=car.stop;
            car.set(car.stop);
            break;
        case OF_KEY_LEFT:
			//car.steer(+1);
            //car.state=car.turnL;
            car.set(car.turnL);
            break;
        case OF_KEY_RIGHT:
			//car.steer(-1);
            //car.state=car.turnR;
            car.set(car.turnR);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

Commands::Commands(){
}
void Commands::set(string s){
    this->s=s;
    index=(-1);
    length=s.length();
}
string Commands::getCurrent(){
    if (index<length){
        string temp=s.substr(index,1);
        ofLog(OF_LOG_NOTICE,"commands:getCurrent():"+temp);
        return temp;
    }else{
        return "";
    }
}
string Commands::getNext(){
    if (index<(length-1)){
        index++;
        string temp=s.substr(index,1);
        ofLog(OF_LOG_NOTICE,"commands:getNext():"+temp);
        return temp;
    }else{
        return "";
    }
}
