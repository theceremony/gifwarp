#pragma once

#include "ofMain.h"
#include "ofxQuadWarp.h"
#include "ofxGifDecoder.h"
#include "ofGifControll/ofAutoGifFile.h"

class ofApp : public ofBaseApp{
    
    static const string     GIF_DIRECTORY;
    static const int        SCALE;
    
    
    
	//------------------------------------------------
    public:
    
		void setup();
		void update();
		void draw();
        //------------------------------------------------
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void exit();
    
        vector<ofxGifFile> files;
    
    private:
        ofxGifFile pullRandomGif();
        void loadAllGifs();
        //------------------------------------------------
        ofDirectory gifDir;
        int index = 0;
        //------------------------------------------------
        ofxGifDecoder decoder;
        ofAutoGifFile leftFile;
        ofAutoGifFile rightFile;
    
        ofFbo leftFbo;
        ofFbo rightFbo;
    
        ofxQuadWarp warper;
        ofxQuadWarp warper2;
    
};
