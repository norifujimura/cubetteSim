#pragma once

#include "ofMain.h"
#include "myCar.h"
#include "Plane.h"

class Commands{
public:
    Commands();
    string s;
    int index=0;
    int length=0;
    void set(string s);
    string getCurrent();
    string getNext();
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        enum States{stop,read,exec};

        //String command;
        ofLight light;
        ofEasyCam cam;
        myCar car;
        ofPlanePrimitive plane2;
        Plane plane;
    
        Commands com;
        string comBuffer;
    
        ofBoxPrimitive box;
        ofMaterial material;
};


