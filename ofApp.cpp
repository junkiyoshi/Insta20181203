#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (int y = 0; y <= ofGetHeight(); y += 50) {

		float noise_seed = ofRandom(1000);
		
		ofColor color;
		color.setHsb(ofMap(y, 0, ofGetHeight(), 0, 255), 200, 255);

		vector<glm::vec2> vertices;
		for (int x = 0; x <= ofGetWidth(); x += 3) {

			int noise_y = y + ofMap(ofNoise(noise_seed, x * 0.003, ofGetFrameNum() * 0.005), 0, 1, -150, 150);
			ofVertex(glm::vec2(x, noise_y));
			vertices.push_back(glm::vec2(x, noise_y));
		}
		vertices.push_back(glm::vec2(ofGetWidth(), ofGetHeight()));
		vertices.push_back(glm::vec2(0, ofGetHeight()));

		ofSetColor(color);
		ofFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);

		ofSetColor(39);
		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}