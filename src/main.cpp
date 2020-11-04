#include <iostream>
#include "../include/Session.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    //cout << argc << endl;
 //   cout << *argv[1] << endl;
   // char st= (*argv[1]);

  // cout << st << endl;

    if(argc != 2){
       cout << "usage cTrace <config_path>" << endl;
        //char st= (*argv[1]);
  cout << *argv << endl;
       // char * milky =&argv[1];
      //  char* mil= &milky;
    //    cout << st << endl;
       return 0;
    }
//string st= reinterpret_cast<basic_string<char> &&>(argv);
    //std::string word = argv[1];
  //  std::string word;
  //  print(word,"%s",argv[1]);
    //Session sess(*argv[1]);
    std::string word = argv[1];


    // cout << sess.getTreeType() << endl;
//   sess.simulate();
    return 0;
}