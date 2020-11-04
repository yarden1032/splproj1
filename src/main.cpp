#include <iostream>
//#include "../cmake-build-debug-coverage/Session.h"
#include <string>
#include "../include/Graph.h"
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    cout << argc << endl;

        if (argc != 2) {
            cout << "usage cTrace <config_path>" << endl;
           // std::string path=argv[1];
            vector<std::vector<int>> vec;
            for (int i = 0; i <5; i++){
                vector <int>* vecy= new vector<int>();
                vec.push_back(*vecy);
                for (int j= 0; j < 5; j++)
                {

                    vec[i].push_back((1));
                }
            }

            Graph* g=new Graph (vec);

         //   Graph g(vec);



            //    Session sess(path ); ///
            return 0;
        }
        // Session sess(argv[1]);
        // sess.simulate();
        return 0;
    }
