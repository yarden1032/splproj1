#include <iostream>
#include <fstream>
#include "../include/Session.h"
#include <string>
#include "../include/Graph.h"
#include <vector>
#include <regex>
#include "../include/json.hpp"

using namespace std;
using json = nlohmann::json;
int main(int argc, char** argv) {
    cout << argc << endl;

    std::string st=*argv;
   st=st.replace(st.find("/splproj1"),sizeof("/splproj1")-1,"");
 // st=st.replace(0,1,"");
    st=("/tmp/tmp.c5RtcnDezT/cmake-build-debug");
    st=(st+"/config1.json");

 //   st=("C:/Users/Milky/CLionProjects/splproj1/cmake-build-debug/config1.json");
    cout << st << endl;
        if (argc != 2) {
            cout << "usage cTrace <config_path>" << endl;

            vector<std::vector<int>> vec;

            for (int a = 0; a <5; a++){
                vector <int>* vecy= new vector<int>();
                vec.push_back(*vecy);
                for (int j= 0; j < 5; j++)
                {

                    vec[a].push_back((1));
                }
            }

            std::ifstream i(st);
            json j;
            i >>j;
            std::string s=j.dump();
            if(j.contains("graph"))
            cout <<"yes"<<endl;
            std::string s2=j.at("tree");
            //cout <<s<<endl;
            //cout <<s2<<endl;

            Graph* g=new Graph (vec);
            Session* sessi =new Session (*argv,vec);


            ///Session sess(argv*);
         //   Graph g(vec);



            //    Session sess(path ); ///
            return 0;
        }
        // Session sess(argv[1]);
        // sess.simulate();
        return 0;
    }
