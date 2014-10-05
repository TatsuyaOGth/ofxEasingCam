/**
 ofxEasingCam.h
 
 The MIT License (MIT)

 Copyright (c) 2014 Tatsuya Ogusu http://ogsn.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */
#pragma once

#include "ofMain.h"

class ofxEasingCam
{
public:
    ofxEasingCam();
    void setup(float width      = ofGetWidth(),
               float height     = ofGetHeight(),
               float camSpeed   = 0.1,
               float distance   = 1.0);
    
    void update();
    
    void begin();
    void begin(float w, float h);
    void end();
    
    void setWindowSize(float width, float height);
    void setCamSpeed(float camSpeed);
    void setRandomPos(float randomAngle = 180);
    void setPos(float x, float y, float z);
    void setPos(ofVec3f & pos);
    void setCurrentPos(float x, float y, float z);
    void setCurrentPos(ofVec3f & pos);
    void setRandomScale(float min, float max);
    void setScale(float dist);
    
    ofVec3f getPos(){ return mPosN; }
    ofVec3f getTargetPos(){ return mPosT; }
    float getScale(){ return mScaleN; }

private:
    ofVec3f mPosN;
    ofVec3f mPosT;
    ofVec3f mPosS;
    float mCamSpeed;
    float mScaleN;
    float mScaleT;
    float mScaleS;

    float mWidth;
    float mHeight;
};

