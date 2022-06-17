#pragma once


class Cell {
private:
    bool curState = false;
    bool newState = false;
public:
    void changeNewState(bool val) {
        newState = val;
    }

    void changeCurState() {
        curState = newState;
    }

    void setState(bool val) {
        curState = val;
    }

    bool getCurState() {
        return curState;
    }
};

