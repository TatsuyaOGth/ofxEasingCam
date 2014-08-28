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
    mCam.setCamSpeed(0.1); // set camera speed (0 - 1)
}


void testApp::update()
{
    mCam.update();
}

void testApp::draw()
{
    mCam.begin();
 
    // sample drawing
    ofSetColor(255);
    ofFill();
    const int size = 5;
    const int exp = 75;
    for (int i = -size; i < size; i++) {
        for (int j = -size; j < size; j++) {
            for (int k = -size; k < size; k++) {
                ofRect(i * exp, j * exp, k * exp, 2, 2);
            }
        }
    }
    ofDrawAxis(60);
    
    mCam.end();
}

void testApp::keyPressed(int key)
{
    mCam.setRandomPos();
}

void testApp::mouseDragged(int x, int y, int button)
{
    mCam.setPos(x, y, mCam.getPos().z);
}