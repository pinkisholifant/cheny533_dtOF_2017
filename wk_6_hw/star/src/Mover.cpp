#include "Mover.hpp"

Mover::Mover()
{
	pos.x = ofRandom(ofGetWidth());
	pos.y = ofRandom(ofGetHeight());
	
	mass = ofRandom(5,10);
}

Mover::Mover(ofVec3f _pos, float _mass){
	pos = _pos;
	mass = _mass;
}

void Mover::applyForce(ofVec3f force)
{
	// force = mass * acceleration
	// acc = force / mass
	
	acc += force/mass;
}

void Mover::applyDampingForce(float force)
{
	acc -= vel.getNormalized() * force;
	// we use a "normalized" velocity (i.e. magnitude of 1)
	// because damping force should be constant
	// no matter what our velocity's magnitude (speed)
	
}

void Mover::update()
{
	vel += acc;
	pos += vel;
	
	acc *= 0;
}
void star(float x, float y, float radius1, float radius2, int npoints) {
    float angle = TWO_PI / npoints;
    float halfAngle = angle/2.0;
    ofBeginShape();
    for (float a = 0; a < TWO_PI; a += angle) {
        float sx = x + cos(a) * radius2;
        float sy = y + sin(a) * radius2;
        ofCurveVertex(sx, sy);
        sx = x + cos(a+halfAngle) * radius1;
        sy = y + sin(a+halfAngle) * radius1;
        ofCurveVertex(sx, sy);
    }
    ofEndShape();
}

void Mover::draw()
{
	ofPushStyle();
	float hue = ofMap(mass, 1, 10, 150, 250);
	ofSetColor( ofColor::fromHsb(hue, 150, 250) );
    //ofColorGradient(ofColor::lightBlue, ofColor::darkBlue);
    ofSetColor(0, 20);
    star(pos.x-ofGetMouseX()*.3,pos.y-ofGetMouseY()*.3, mass*2., 40, 7);
	
	ofPopStyle();
}





