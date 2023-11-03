#include "ofApp.h"
#include "PauseState.h"
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetWindowTitle("C++ Game Box");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	gameOverState = new GameOverState();
	// Initial State
	currentState = menuState;
	isPaused = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (!isPaused) {
        if (currentState != nullptr) {
            currentState->tick();
            if (currentState->hasFinished()) {
                if (currentState->getNextState() == "Game") {
                    currentState = gameState;
                } else if (currentState->getNextState() == "Menu") {
                    currentState = menuState;
                } else if (currentState->getNextState() == "GameOver") {
                    currentState = gameOverState;
                }
                currentState->reset();
            }
        }
    }
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr){
		currentState->keyPressed(key);
	}
	//Turn Volume Down (Mute)	
	if( key == '-' ){
		ofSoundSetVolume(0);
	}
	
	//Turn Volume Back Up
	if( key == '=' ){
		ofSoundSetVolume(1);
	}
	if (key == 'p') {
        if (!isPaused) {
            // Pause the game
            isPaused = true;
            // Optionally, store the current state as the paused state
            // This is useful if you want to return to the same state when resuming
            // pausedState = currentState;
            currentState = new PauseState();
        } else {
            // Resume the game
            isPaused = false;
            // If you stored the paused state, return to it
            // currentState = pausedState;
            // If you didn't store the paused state, return to a specific state like menuState
            currentState = menuState;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
