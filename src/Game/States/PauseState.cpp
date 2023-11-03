
#include "PauseState.h"

PauseState::PauseState() {
    resumeButton = new Button(ofGetWidth() / 2 - 64, ofGetHeight() / 2, 128, 50, "Resume");
    quitButton = new Button(ofGetWidth() / 2 - 64, ofGetHeight() / 2 + 60, 128, 50, "Quit");
}

PauseState::~PauseState() {
    delete resumeButton;
    delete quitButton;
}

void PauseState::tick() {
    resumeButton->tick();
    quitButton->tick();

    if (resumeButton->wasPressed()) {
        setFinished(true);
    }

    if (quitButton->wasPressed()) {
        setNextState("Menu"); // Replace "Menu" with the appropriate state you want to return to.
        setFinished(true);
    }
}

void PauseState::render() {
    // Render your pause screen here, e.g., background, title, etc.
    // You can also render your buttons here.
    resumeButton->render();
    quitButton->render();
}

void PauseState::keyPressed(int key) {
    if (key == 'p') {
        setFinished(true);
    }
}

void PauseState::mousePressed(int x, int y, int button) {
    resumeButton->mousePressed(x, y);
    quitButton->mousePressed(x, y);
}

void PauseState::reset() {
    setFinished(false);
    setNextState("");
    resumeButton->reset();
    quitButton->reset();
}
