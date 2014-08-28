/**
 ofxEasingCam.cpp
 
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
#include "ofxEasingCam.h"


ofxEasingCam::ofxEasingCam()
{
    mScaleN = 1.0;
    mScaleT = mScaleN;
    mCamSpeed = 0.1;
    
}
void ofxEasingCam::setup(float width, float height, float camSpeed,float scaleance)
{
    mWidth  = width;
    mHeight = height;
    mScaleN = scaleance;
    mScaleT = mScaleN;
    mCamSpeed = ofClamp(camSpeed,0,1);
}


void ofxEasingCam::update()
{
    mPosS.set(mPosT.x - mPosN.x, mPosT.y - mPosN.y, mPosT.z - mPosN.z);
    mPosS.set(mPosS.x * mCamSpeed, mPosS.y * mCamSpeed, mPosS.z * mCamSpeed);
    mPosN.set(mPosN.x + mPosS.x, mPosN.y + mPosS.y, mPosN.z + mPosS.z);
    
    mScaleS = mScaleT - mScaleN;
    mScaleS = mScaleS * mCamSpeed;
    mScaleN = mScaleN + mScaleS;
}


void ofxEasingCam::begin()
{
    ofPushMatrix();
    ofTranslate(mWidth * 0.5, mHeight * 0.5);
    ofRotateX(mPosN.x);
    ofRotateY(mPosN.y);
    ofRotateZ(mPosN.z);
    ofScale(mScaleN, mScaleN, mScaleN);
}

void ofxEasingCam::begin(float w, float h)
{
    mWidth = w;
    mHeight = h;
    begin();
}

void ofxEasingCam::end(){
    ofPopMatrix();
    
}

void ofxEasingCam::setWindowSize(float width, float height)
{
    mWidth = width;
    mHeight = height;
}


void ofxEasingCam::setCamSpeed(float camSpeed)
{
    mCamSpeed = ofClamp(camSpeed, 0, 1);
}

void ofxEasingCam::setRandomPos(float randomAngle)
{
    ofVec3f ram3f;
    int ramSize = randomAngle;
    ram3f.set(ofRandom(-ramSize, ramSize),
              ofRandom(-ramSize, ramSize),
              ofRandom(-ramSize, ramSize));
    mPosT.set(ofRandom(mPosN.x,(int)(mPosN.x + ram3f.x) % 360),
              ofRandom(mPosN.y,(int)(mPosN.y + ram3f.y) % 360),
              ofRandom(mPosN.z,(int)(mPosN.z + ram3f.z) % 360));
}

void ofxEasingCam::setPos(float x,float y,float z)
{
    mPosT.set(x, y, z);
}

void ofxEasingCam::setPos(ofVec3f & pos)
{
    mPosT.set(pos.x, pos.y, pos.z);
}

void ofxEasingCam::setRandomScale(float min,float max)
{
    mScaleT = ofRandom(min, max);
}

void ofxEasingCam::setScale(float scale)
{
    mScaleT = scale;
}


