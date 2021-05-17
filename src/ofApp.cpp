#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0,0,0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
	ofSetWindowTitle("empty test");
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetCircleResolution(100);
    
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    // initialise member variables to the centre of the screen
    mouseXPercent = 0.5f;
    mouseYPercent = 0.5f;
}

//--------------------------------------------------------------
void ofApp::update(){
  m_radius = ofMap(sin(ofGetElapsedTimef() / 60.0), 0.0, 1.0, 10.0, 500.0);

}

//--------------------------------------------------------------
void ofApp::draw(){
  camera.begin();
  ofSetColor(255, 100, 0);
  ofDrawSphere(ofGetWidth() / 2.0, ofGetHeight() / 4.0, m_radius);
  ofSetColor(100, 200, 20);
  ofDrawSphere(ofGetWidth() / 5.0, ofGetHeight() / 4.0, 300, m_radius / 1.5);
  ofSetColor(200, 200, 20);
  ofDrawBox(ofGetWidth() / 3.0, ofGetHeight() / 4.0, -200, m_radius / 1.5);
  camera.end();
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // update mouse x and y percent when the mouse moves
    mouseXPercent = float(x) / ofGetWidth();
    mouseYPercent = float(y) / ofGetHeight();

    float rotateAmount = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 360);
    glm::vec3 furthestPoint;
      furthestPoint = glm::vec3(x, y, 0);

    glm::vec3 directionToFurthestPoint = (furthestPoint - center);
    glm::vec3 directionToFurthestPointRotated =
        glm::rotate(directionToFurthestPoint, rotateAmount, glm::vec3(0, 1, 0));
    camera.setPosition( + directionToFurthestPointRotated);
    camera.lookAt(center);
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
