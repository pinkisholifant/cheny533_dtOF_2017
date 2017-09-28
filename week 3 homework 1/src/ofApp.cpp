#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
//    x=100;
//    y=100;
//    dirx=10;
//    diry=10;
    gravity = ofVec2f(10,10); // start with no gravity force

}

//--------------------------------------------------------------
void ofApp::update(){
    
    gravity.x = ofMap(ofGetMouseX(), 0, ofGetWidth(), -10, 10);
    gravity.y = ofMap(ofGetMouseY(), 0, ofGetHeight(), -10, 10);
    
    ball.update();
    ball2.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball.draw();
    ball2.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
