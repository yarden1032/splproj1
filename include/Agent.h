#ifndef AGENT_H_
#define AGENT_H_
#include "../include/Session.h"
#include "../include/Tree.h"

#include <vector>
class Session; ////////TODO: important!!!! this line was important - to show to Roni
class Agent{
public:
    Agent();
    virtual void act(Session& session)=0;
      int getNodeInd();
private:
    const int nodeInd;

};
class ContactTracer: public Agent{
public:
    ContactTracer();

    virtual void act(Session& session);

private:
    Tree* BFS(int start,Session& session);

};


class Virus: public Agent{
public:
    Virus(int nodeInd);

    virtual void act(Session& session);
private:
    const int nodeInd;

};

#endif

///Notice this is the new Agent file
