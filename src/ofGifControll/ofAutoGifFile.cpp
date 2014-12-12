//
//  ofAutoGifFile.cpp
//  gifwarp
//
//  Created by Jeramy Morrill on 12/2/14.
//
//

#include "ofAutoGifFile.h"

int loopedAmount = 0;
int loops = 10;

void ofAutoGifFile::setup(vector<ofxGifFile> _files){
    files = _files;
    file = pullRandomFile();
}

void ofAutoGifFile::update(){
    index++;
    if(index > file.getNumFrames()-1){
        index = 0;
        loopedAmount++;
    }
    
    if(loopedAmount >= loops){
        loopedAmount = 0;
        random();
    }
}

void ofAutoGifFile::draw(float _x,float _y, int _w, int _h){
    file.drawFrame(index,_x,_y,_w,_h);
}

ofxGifFile ofAutoGifFile::pullRandomFile(){
    int findex = rand() % ((int)files.size());
    return files[findex];
}

void ofAutoGifFile::random(){
    file = pullRandomFile();
}