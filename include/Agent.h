#ifndef AGENT_H_
#define AGENT_H_
#include "../include/Session.h"
#include <vector>

class Agent{
public:
   /// Agent(Session &session);
Agent (int sestempl);
    virtual void act()=0;
private:
   // Session &session;
   int sestempl;
};

class ContactTracer: public Agent{
public:
    ContactTracer(int session);

    virtual void act();
};


class Virus: public Agent{
public:
    Virus(int nodeInd, int &session);



    virtual void act();
private:
    const int nodeInd;
};

#endif