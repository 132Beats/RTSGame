
//#include <iostream>
//#include <fstream>


#include <memory>
#include "RTS.h"
int main(int argc, char** argv) {
    try {
        RTS rts;
        return rts.start(argc,argv);
    }
    catch (...) {
        return 1;
    }


    return 1;

}


