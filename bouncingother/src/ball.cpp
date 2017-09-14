//
//  ball.cpp
//  bouncingBall
//
//  Created by pinkisholifant on 2017/9/7.
//
//

#include "ball.h"

Ball::Ball(){
    ofBackground(0);
    x=ofRandom(0,ofGetWidth()-radius);
    y=ofRandom(0,ofGetHeight()-radius);
    dirx=10;
    diry=10;

}
void Ball::update(){
    x+=dirx;
    
    y+=diry;
    
    
    
    
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)){
        dirx=-1*dirx;
        
    }
    if (y<=radius || y >= ofGetHeight()-radius){
        diry=-1*diry;
        
    }

}
void Ball::draw(){
    ofSetColor(color);
    ofDrawRectangle(x, y, radius,radius);
    radius=50;
    color=ofColor(ofRandom(150,240),ofRandom(150,240),ofRandom(150,240));

}
