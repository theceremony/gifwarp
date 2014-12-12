//
//  ofAutoGifFile.h
//  gifwarp
//
//  Created by Jeramy Morrill on 12/2/14.
//
//

#ifndef __gifwarp__ofAutoGifFile__
#define __gifwarp__ofAutoGifFile__

#include "ofMain.h"
#include "ofxGifDecoder.h"

class ofAutoGifFile{
    

    
    public:
        vector<ofxGifFile> files;
        void setup(vector<ofxGifFile> _files);
        void update();
        void draw(float _x,float _y, int _w, int _h);
        void random();
    
        int index;
        ofxGifFile file;
    
    private:
        ofxGifFile pullRandomFile();
};

#endif /* defined(__gifwarp__ofAutoGifFile__) */
