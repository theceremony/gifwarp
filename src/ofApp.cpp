#include "ofApp.h"

const string ofApp::GIF_DIRECTORY = "safe_gifs/";
const int ofApp::SCALE = 1;


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    
    gifDir.allowExt("gif");
    gifDir.listDir(GIF_DIRECTORY);
    
    loadAllGifs();

    leftFile = *new ofAutoGifFile();
    leftFile.setup(files);
    
    rightFile = *new ofAutoGifFile();
    rightFile.setup(files);
    
    leftFbo.allocate(ofGetWidth()/2, ofGetHeight());
    rightFbo.allocate(ofGetWidth()/2, ofGetHeight());
    
    warper.setSourceRect(ofRectangle(0, 0,ofGetWidth()/2,ofGetHeight()));
    warper.setTopLeftCornerPosition(ofPoint(0, 0));
    warper.setTopRightCornerPosition(ofPoint(ofGetWidth()/2, 0));
    warper.setBottomLeftCornerPosition(ofPoint(0, ofGetHeight()));
    warper.setBottomRightCornerPosition(ofPoint(ofGetWidth()/2, ofGetHeight()));
    warper.setup();
    warper.load();
}

//--------------------------------------------------------------
void ofApp::update(){
    leftFile.update();
    rightFile.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    leftFbo.begin();
        leftFile.draw(0,0,leftFbo.getWidth(),leftFbo.getHeight());
    leftFbo.end();
    
    rightFbo.begin();
        rightFile.draw(0,0,rightFbo.getWidth(),rightFbo.getHeight());
    rightFbo.end();
    
    ofMatrix4x4 mat = warper.getMatrix();
    
    glPushMatrix();
    glMultMatrixf(mat.getPtr());
    leftFbo.draw(0,0,leftFbo.getWidth()*SCALE,leftFbo.getHeight()*SCALE);
    glPopMatrix();
    
    rightFbo.draw(leftFbo.getWidth()*SCALE,0,rightFbo.getWidth()*SCALE,rightFbo.getHeight()*SCALE);
    
    
    
    //======================== draw quad warp ui.
    
    ofSetColor(ofColor::magenta);
    warper.drawQuadOutline();
    
    ofSetColor(ofColor::yellow);
    warper.drawCorners();
    
    ofSetColor(ofColor::magenta);
    warper.drawHighlightedCorner();
    
    ofSetColor(ofColor::red);
    warper.drawSelectedCorner();
    
    ofSetColor(ofColor::white);

}

void ofApp::loadAllGifs(){
    for(int i=0; i < gifDir.numFiles(); i++){
        decoder.decode(gifDir.getPath(i));
        files.push_back(decoder.getFile());
    }
}

ofxGifFile ofApp::pullRandomGif(){

    leftFile.random();
    rightFile.random();
}

void ofApp::exit() {
    warper.save();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's' || key == 'S') {
        warper.toggleShow();
    }
    
    if(key == 'l' || key == 'L') {
        warper.load();
    }
    
    if(key == 'h' || key == 'H') {
        warper.save();
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
    leftFile.random();
    rightFile.random();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
