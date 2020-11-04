//This is implementation of class Agent
#include "../include/Agent.h"
#include "../include/Session.h"
#include <iostream>
using namespace std;


/*Agent::Agent(){
    session(6);

}*/ //Constructor empty
Agent::Agent(Session & session) : session(session) {//constructor not empty
            this->session = session;

        }

void act() {

}

/*class Virus: public Agent {
    Virus::Agent(int nodeInd, Session &session) {
        nodeInd=0;
        this->session = session;
    }
};*/

/*Virus::Virus(Session &session, int nodeInd) : Agent(session), nodeInd(0) {
nodeInd=0;


}*/

Virus::Virus(Session &session,  int nodeInd) : Agent(session), nodeInd(0) {

}




ContactTracer::ContactTracer(Session &session) : Agent(session) {


}