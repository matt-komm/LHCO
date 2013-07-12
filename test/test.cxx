#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "LHCO.hpp"

void randomPtEtaPhi(LHCOParticle* particle)
{
    particle->eta=rand()%1000000/1000000.0*5.0-2.5;
    particle->pt=rand()%1000000/1000000.0*1400.0+20.0;
    particle->phi=rand()%1000000/1000000.0*3.1416;
}

int main() 
{
    srand(1);

    LHCOEvent event;
    
    LHCOParticle* muon = event.addMuon();
    LHCOParticle* el = event.addElectron();
    LHCOParticle* gamma = event.addPhoton();
    LHCOParticle* jet = event.addJet();
    LHCOParticle* bjet = event.addBJet();
    LHCOParticle* met = event.setMET();
    
    std::ofstream ofs("test.lhco", std::ofstream::out);
    
    for (unsigned i=0; i<10; ++i)
    {
        event.setEventID(i);
        randomPtEtaPhi(muon);
        randomPtEtaPhi(el);
        randomPtEtaPhi(gamma);
        randomPtEtaPhi(jet);
        randomPtEtaPhi(bjet);
        randomPtEtaPhi(met);
        
        event.writeEvent(std::cout);
        
        
        event.writeEvent(ofs);
    }
    ofs.close();
    return 0;
}
