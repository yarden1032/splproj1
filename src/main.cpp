#include <iostream>
#include "../include/Session.h"
#include <string>


using namespace std;

int main(int argc, char** argv){
    cout << argc << endl;
    if(argc != 2){
        cout << "usage cTrace <config_path>" << endl;
        Session sess(argv[1]);
        return 0;
    }
   // Session sess(argv[1]);
   // sess.simulate();
    return 0;
}