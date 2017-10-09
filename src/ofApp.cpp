#include "ofApp.h"
#include <string>
#include <iostream>

using namespace std;

short hunger = 100;
short clean = 100;
short bored = 100;

short timer = 0;

bool dead () {
	if (hunger < 0 || bored < 0 || clean < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//a cute happy face
void happy() {
	ofSetColor(0,0,0);
	ofDrawRectangle(30,30,10,30);
	ofDrawRectangle(70,30,10,30);
	ofDrawRectangle(20,70,10,20);
	ofDrawRectangle(80,70,10,20);
	ofDrawRectangle(20,80,70,10);
}
//a sad face
void sad() {
	ofSetColor(0,0,0);
	ofDrawRectangle(30,30,10,30);
	ofDrawRectangle(70,30,10,30);
	ofDrawRectangle(20,80,10,20);
	ofDrawRectangle(80,80,10,20);
	ofDrawRectangle(20,80,70,10);
}
//Void game is real
void hungry() {
	ofSetColor(0,0,0);
	ofDrawRectangle(30,30,10,30);
	ofDrawRectangle(70,30,10,30);
	ofDrawCircle(70,90,20,20);
}
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(100,100,100);
	ofSetFrameRate(60);		//just to keep track of the timer as being seconds as dunno any cpp time function yet; if i did I'd use it...
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!dead()) {
		timer++;
	}
	if (timer == 60) {
		timer = 0;
	}
	if (timer == 20 || timer == 40 || timer == 0) {		//depricating the stats one time per second
		hunger--;
	}
	if (timer == 30 || timer == 0) {
		clean--;
	}
	if (timer == 15 || timer == 30 || timer == 45 || timer == 0) {
		bored--;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){	//drawing the lovely face and status bars
	if (!dead()) {
		ofSetColor(255,0,0);
		ofFill();
		ofDrawRectangle(10, 10, 100, 100);
		ofSetColor(150,150,150);
		ofDrawRectangle(10, 200, 100, 10);
		ofDrawRectangle(120, 200, 100, 10);
		ofDrawRectangle(230, 200, 100, 10);
		ofSetColor(0,255,0);
		ofDrawRectangle(10, 200, hunger, 10);
		ofSetColor(255,0,0);
		ofDrawRectangle(120, 200, bored, 10);
		ofSetColor(0,0,255);
		ofDrawRectangle(230, 200, clean, 10);
		if (hunger < 50) {
			hungry();
		} else if (clean < 50 || bored < 50){
			sad();
		} else {
			happy();
		}
	}
	if (dead()) {
		ofSetColor(255,0,0);
		ofFill();
		ofDrawBitmapString("DEAD", 10, 10); //O nO hE dEaD
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){	//TAMAGOTCHI buttons (Also I was wrong about the friend thing in Japanese but it sounds cooler in my opinion soooo....)
	if (key == 97 && hunger < 100 - 23) {
		hunger += 23;
		cout << "Fed" << endl;
	} else if (key == 97 && hunger >= 100 - 23) {
		hunger += 100 - hunger;
		cout << "Fed" << endl;
	}
	if (key == 115 && bored < 100 - 10) {
		bored += 10;
		cout << "Entertained" << endl;
	} else if (key == 115 && bored >= 100 - 10) {
		bored += 100 - bored;
		cout << "Entertained" << endl;
	}
	if (key == 100 && clean < 100 - 14) {
		clean += 14;
		cout << "Scrubbed" << endl;
	} else if (key == 100 && clean >= 100 - 14) {
		clean += 100 - clean;
		cout << "Scrubbed" << endl;
	}
	if (dead() && key==114) {	// A reset button for if the thing dies so you dont have to quit and restart
		hunger = bored = clean = 100;
		cout << "RESET" << endl;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
