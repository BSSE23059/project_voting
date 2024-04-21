#include "Candidate.h"

Candidate::Candidate() {}

bool Candidate::getWonStatus() {
    return isWon;
}

const int Candidate::getVoteCount() const {
    return voteCount;
}

int Candidate::getPosition() {
    return position;
}

void Candidate::setVoteCount(int count) {
    voteCount = count;
}

void Candidate::setWonStatus(bool status) {
    isWon = status;
}

void Candidate::setPosition(int canPos) {
    position = canPos;
}