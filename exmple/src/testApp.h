/**
 testApp.h
 
 Copyright (c) 2014 Tatsuya Ogusu http://ogsn.org
 This software is released under the MIT License.
 http://opensource.org/licenses/mit-license.php
 */
#pragma once

#include "ofMain.h"
#include "ofxEasingCam.h"

class testApp : public ofBaseApp
{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void mouseDragged( int x, int y, int button );
    
private:
    ofxEasingCam mCam;
};
