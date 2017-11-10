
#include "Particle.hpp"

Particle::Particle()
{
}

Particle::Particle(ofVec3f _pos, ofVec3f _vel)
{
	pos = _pos;
	vel = _vel;
}

void Particle::applyForce(ofVec3f force)
{
	acc += force*0.6;
}

void Particle::applyDamping(float strength)
{
	acc -= vel.getNormalized() * strength;
}

void Particle::update()
{
	vel += acc;
	pos += vel;
    if(pos.x < 0 || pos.x > ofGetWidth()){
        vel.x *=-1;
        vel += -acc;
    }
    if(pos.y < 0 || pos.y > ofGetHeight()){
        vel.y *= -1;
        vel += -acc;
            }

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

void Particle::draw(){
                // draw the flow line
            //ofDrawLine(pos, end);
            
            // draw the origin pos as a dot
    
            ofPushStyle();
            ofSetColor(ofRandom(0,255),0,0,95);
            ofDrawCircle(pos,2);
            //ofSetColor(ofColor::fromHsb(200, 255, 200));
            //ofDrawCircle(pos.x, pos.y, 2);
            //star(pos.x,pos.y, 5, 10, 7);
            
            //ofDrawCircle(pos, 1);
            ofPopStyle();

            
        }

//	ofPushStyle();
//	//ofSetColor(ofRandom(0,255),0,0);
//    ofSetColor(ofColor::fromHsb(hue, 255, 200));
//    star(pos.x,pos.y, 4, 8, 7);
//
//	//ofDrawCircle(pos, 1);
//	ofPopStyle();




