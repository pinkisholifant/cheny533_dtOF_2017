//
//  ball.h
//  bouncingBall
//
//  Created by pinkisholifant on 2017/9/7.
//
//
#pragma once

#include"ofMain.h"

class Ball{
public:
    
    Ball();
    
    void update();
    
    void draw();
    
    float radius;
    ofColor color;
    float x;
    float y;
    float dirx,diry;

};
