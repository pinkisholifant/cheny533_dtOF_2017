#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
    ofBackground(0);

	ofDisableArbTex();
	
	kinect.setRegistration(true);
	kinect.init();
	kinect.open();
	
	colorPix.allocate(640,480,OF_IMAGE_COLOR);
	depthPix.allocate(1970,1500,OF_IMAGE_GRAYSCALE);
	
	colorTex.allocate(640,480,GL_RGB);
	depthTex.allocate(1970,1500,GL_RGB);
	
	plane.set(1000,1000,1970,1500, OF_PRIMITIVE_TRIANGLES);
	
	kinect.setDepthClipping(1000, 2000);
    
    
    
    fbo.allocate(1970,1500,GL_RGBA);
    
    // clear the fbo's pixels (removes junk data):
    //	fbo.begin();
    //	ofClear(0,0,0,0);
    //	fbo.end();
    
    fboTime = ofGetElapsedTimef();
    
    
    blendmode = OF_BLENDMODE_ADD;

	

}

//--------------------------------------------------------------
void ofApp::update(){
	
	kinect.update();
	
	farThresh = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 200);
	nearThresh = farThresh + 100;
    
    
    
    
    
    if (ofGetElapsedTimef() - fboTime >= 1)
    {
        fbo.begin();
        depthTex.draw(0,0,1970,1500);
        fbo.end();
        
        fboTime = ofGetElapsedTimef();	// reset timer
    }
    
    
    
    
	
	if (kinect.isFrameNew())
	{
		colorPix = kinect.getPixels();
		depthPix = kinect.getDepthPixels();
		
		
		
		for (int i=0; i<depthPix.getTotalBytes(); i++)
		{
			
//			int x = i % depthPix.getWidth();
//			int y = i / depthPix.getWidth();
			
			int depth = depthPix[i];
			if (depth > farThresh && depth < nearThresh)
			{
				plane.getMesh().getVertices()[i].z = depth * 2.;
			}
			else
			{
				plane.getMesh().getVertices()[i].z = 0;
				depthPix[i] = 0;
			}
			
//			plane.getMesh().getVertices()[i].z = kinect.getDistanceAt(x,y) * -.1;
		}
		
		
		colorTex.loadData(colorPix);
		depthTex.loadData(depthPix);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    fbo.draw(0,0);	// draw captured webcam frame
    
    
    
    ofEnableBlendMode(blendmode);			// SET TO CUSTOM BLENDMODE
    
    depthTex.draw(0,0);
    stringstream ss;
    //ss << "choose blendmode: 1 - ADD, 2 - SUBTRACT, 3 - MULTIPLY, 4 - SCREEN, 5 - DEFAULT (ALPHA), 6 - DISABLED" << "\n\n";
    string modeStr;
    switch (blendmode) {
        case OF_BLENDMODE_ADD:			modeStr = "MULTIPLY"; break;
        case OF_BLENDMODE_SUBTRACT:		modeStr = "SUBTRACT"; break;
        case OF_BLENDMODE_MULTIPLY:		modeStr = "MULTIPLY"; break;
        case OF_BLENDMODE_SCREEN:		modeStr = "SCREEN"; break;
        case OF_BLENDMODE_ALPHA:		modeStr = "DEFAULT (ALPHA)"; break;
        case OF_BLENDMODE_DISABLED:		modeStr = "DISABLED"; break;
    }
    //ss << "current blendmode: " << modeStr;
    ofDrawBitmapStringHighlight(ss.str(), 20,500);

    
    
    
    
    
    
	//colorTex.draw(0,0,320,240);
	//depthTex.draw(320,0,320,240);
	
	cam.begin();
	ofEnableDepthTest();
	
	colorTex.bind();
	plane.draw();
	colorTex.unbind();
	
	ofDisableDepthTest();
	cam.end();

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
