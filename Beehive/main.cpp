#include <iostream>
#include "beehive.h"
using namespace std;

int main(int argc, char *argv[])
{

    //Beehive b("testID",1000/* num of bees*/,10/* num of boards*/,10000/*swarm/attack number*/,.05/*growth function*/);
    QApplication a(argc, argv);
    Beehive b;



   b.run("example");    //run simulation

    a.exec();

}

