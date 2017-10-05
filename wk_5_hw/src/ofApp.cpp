#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
#ifdef TARGET_OPENGLES
    shader.load("shadersES2/shader");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shadersGL3/shader");
    }else{
        shader.load("shadersGL2/shader");
    }
#endif

    xPos = 5;  // horizontal start position
    ofBackground(124,179,244);  // black background
}

void ofApp::update(){
    xPos += 2;
    if(ofGetWidth()<xPos*3){  // if horizontal position is off the screen (width)
        xPos = 5;             // reset horizontal position
    }
}

void ofApp::draw(){
    ofSetColor(255);
    
    shader.begin();

    //ofSetColor(ofColor::red);
    ofDrawCircle(500, xPos, xPos);
    
    shader.end();
    
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
