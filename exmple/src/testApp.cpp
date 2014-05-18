/**
 testApp.cpp
 
 Copyright (c) 2014 Tatsuya Ogusu http://ogsn.org
 This software is released under the MIT License.
 http://opensource.org/licenses/mit-license.php
 */
#include "testApp.h"


void testApp::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    
    mCam.setup();
}


void testApp::update()
{
    mCam.update();
}

void testApp::draw()
{
    mCam.begin();
    
    ofDrawAxis(60);
    
    mCam.end();
}

void testApp::keyPressed(int key)
{
    mCam.setRandomPos();
}