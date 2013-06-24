#include <iostream>
#include <stdio.h>

#include "LHCO.hpp"

int main() 
{
    LHCOEvent event;
    event.addMuon(1.9,2.3,5460.1);
    event.addJet(-1.9,2.0,40.4561);
    event.addMuon(1.9,2.3,5460.1);
    event.addJet(-1.9,2.0,40.4561);
    event.addMuon(1.9,2.3,5460.1);
    event.addJet(-1.9,2.0,40.4561);
    event.writeEvent(std::cout);
    //std::cout<<"test"<<std::endl;   
    return 0;
}
