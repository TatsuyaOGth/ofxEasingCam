#pragma once

#include "ofMain.h"

class ofxViewPointRoller
{
public:
    ofxViewPointRoller();
    void setup(float width = ofGetWidth(), float height = ofGetHeight(), float _camSpeed=0.1, float _distance=1.0);
    void update();
    void begin();
    void begin(float _w, float _h);
    void end();
    void setCamSpeed(float _camSpeed);
    void setRandomPos(float _randomAngle=180);
    void setPos(float _x,float _y,float _z);
    void setPos(ofVec3f & pos);
    void setRandomScale(float _min,float _max);
    void setScale(float _dist);

    
    ofVec3f posN,posT,posS;
    ofLight lig;
    float camSpeed;
    float scaleN,scaleT,scaleS;
    
    float mWidth;
    float mHeight;
};

