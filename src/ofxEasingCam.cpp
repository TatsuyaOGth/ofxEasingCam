#include "ofxViewPointRoller.h"


ofxViewPointRoller::ofxViewPointRoller(){
    scaleN=1.0;
    scaleT=scaleN;
    camSpeed=0.1;
    
}
void ofxViewPointRoller::setup(float width, float height, float _camSpeed,float _scaleance){
    mWidth = width;
    mHeight = height;
    scaleN=_scaleance;
    scaleT=scaleN;
    camSpeed=ofClamp(_camSpeed,0,1);
}


void ofxViewPointRoller::update(){
    posS.set(posT.x-posN.x,posT.y-posN.y,posT.z-posN.z);
    posS.set(posS.x*camSpeed,posS.y*camSpeed,posS.z*camSpeed);
    posN.set(posN.x+posS.x, posN.y+posS.y,posN.z+posS.z);
    
    scaleS=scaleT-scaleN;
    scaleS=scaleS*camSpeed;
    scaleN=scaleN+scaleS;
}


void ofxViewPointRoller::begin(){
    ofPushMatrix();
    ofTranslate(mWidth * 0.5, mHeight * 0.5);
    ofRotateX(posN.x);
    ofRotateY(posN.y);
    ofRotateZ(posN.z);
    ofScale(scaleN, scaleN,scaleN);
}

void ofxViewPointRoller::begin(float _w, float _h){
    ofPushMatrix();
    ofTranslate(_w * 0.5, _h * 0.5);
    ofRotateX(posN.x);
    ofRotateY(posN.y);
    ofRotateZ(posN.z);
    ofScale(scaleN, scaleN,scaleN);
}


void ofxViewPointRoller::end(){
    ofPopMatrix();
    
}


void ofxViewPointRoller::setCamSpeed(float _camSpeed){
    camSpeed=ofClamp(_camSpeed,0,1);
}

void ofxViewPointRoller::setRandomPos(float _randomAngle){
    ofVec3f ram3f;
    int ramSize=_randomAngle;
    ram3f.set(ofRandom(-ramSize, ramSize),ofRandom(-ramSize, ramSize),ofRandom(-ramSize, ramSize));
    posT.set(ofRandom(posN.x,(int)(posN.x+ram3f.x)%360), ofRandom(posN.y,(int)(posN.y+ram3f.y)%360),ofRandom(posN.z,(int)(posN.z+ram3f.z)%360));
}

void ofxViewPointRoller::setPos(float _x,float _y,float _z){
    posT.set(_x,_y,_z);
}

void ofxViewPointRoller::setPos(ofVec3f & pos){
    posT.set(pos.x, pos.y, pos.z);
}

void ofxViewPointRoller::setRandomScale(float _min,float _max){
    scaleT=ofRandom(_min,_max);
}

void ofxViewPointRoller::setScale(float _scale){
    scaleT=_scale;
}


