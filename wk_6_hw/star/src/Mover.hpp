#pragma once
#include "ofMain.h"

class Mover {
	
public:
	
	Mover();
	~Mover(){}
	
	Mover(ofVec3f _pos, float _mass);
	
	void applyForce(ofVec3f force);
	void applyDampingForce(float force);
	
	void update();
	void draw();

	
	ofVec3f pos, vel, acc;
	float mass;
	
};


