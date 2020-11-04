#ifndef AGENT_H_
#define AGENT_H_
#include "../include/Session.h"
#include <vector>

class Agent{
public:
    Agent( Session &session);
   // Agent();

    virtual void act()=0;
private:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer(Session& session);

    virtual void act();
};


class Virus: public Agent{
public:
    Virus(Session &session, int nodeInd);




    virtual void act();
private:
    const int nodeInd;
};

#endif