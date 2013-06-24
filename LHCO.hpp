#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <string>

class LHCOParticle
{
    public:
        float type;
        float eta;
        float phi;
        float pt;
        float jmass;
        int ntrk;
        int btag;
        float hademfraction;
        float dummy1;
        float dummy2;
        
    
};

class LHCOEvent
{
    enum TYPE
    {
        PHOTON,
        ELECTRON,
        MUON,
        HADTAU,
        JET,
        MET
    };

    private:
        std::vector<LHCOParticle*> particleList;
        LHCOParticle* met;
        std::map<TYPE,int> types;
        int eventID;
        int triggerInfo;
        
        const std::string SEPARATOR;
        
        
    public:
        
    
        LHCOEvent(): 
            eventID(1), 
            triggerInfo(1),
            SEPARATOR(" ")
        {
            types[PHOTON]=0;
            types[ELECTRON]=1;
            types[MUON]=2;
            types[HADTAU]=3;
            types[JET]=4;
            types[MET]=6;
            
            met=new LHCOParticle();
            setMET();
        }
        
        void updateEventID(int eventID, int triggerInfo=1)
        {
            this->eventID=eventID;
            this->triggerInfo=triggerInfo;
        }
        
        LHCOParticle* addParticle(float type,
                                  float eta=0.0,
                                  float phi=0.0,
                                  float pt=0.0,
                                  float jmass=0.0,
                                  int ntrk=0,
                                  int btag=0,
                                  float hademfraction=0.0,
                                  float dummy1=0.0,
                                  float dummy2=0.0)
        {
            LHCOParticle* particle = new LHCOParticle();
            particle->type=type;
            particle->eta=eta;
            particle->phi=phi;
            particle->pt=pt;
            particle->jmass=jmass;
            particle->ntrk=ntrk;
            particle->btag=btag;
            particle->hademfraction=hademfraction;
            particle->dummy1=dummy1;
            particle->dummy2=dummy2;
            particleList.push_back(particle);
            return particle;
            
        }
        
        LHCOParticle* addMuon(float eta=0.0,
                              float phi=0.0,
                              float pt=0.0,
                              int charge=-1,
                              float dummy1=0.0,
                              float dummy2=0.0)
        {
            LHCOParticle* particle = new LHCOParticle();
            particle->type=types[MUON];
            particle->eta=eta;
            particle->phi=phi;
            particle->pt=pt;
            particle->jmass=0.105;
            particle->ntrk=charge;
            particle->btag=0;
            particle->hademfraction=0.0;
            particle->dummy1=dummy1;
            particle->dummy2=dummy2;
            particleList.push_back(particle);
            return particle;
        }
        
        
        LHCOParticle* addElectron(float eta=0.0,
                              float phi=0.0,
                              float pt=0.0,
                              int charge=-1,
                              float dummy1=0.0,
                              float dummy2=0.0)
        {
            LHCOParticle* particle = new LHCOParticle();
            particle->type=types[ELECTRON];
            particle->eta=eta;
            particle->phi=phi;
            particle->pt=pt;
            particle->jmass=0.000511;
            particle->ntrk=charge;
            particle->btag=0;
            particle->hademfraction=0.0;
            particle->dummy1=dummy1;
            particle->dummy2=dummy2;
            particleList.push_back(particle);
            return particle;
        }
        
        LHCOParticle* addPhoton(float eta=0.0,
                              float phi=0.0,
                              float pt=0.0,
                              float hademfraction=0.0,
                              float dummy1=0.0,
                              float dummy2=0.0)
        {
            LHCOParticle* particle = new LHCOParticle();
            particle->type=types[PHOTON];
            particle->eta=eta;
            particle->phi=phi;
            particle->pt=pt;
            particle->jmass=0.0;
            particle->ntrk=1;
            particle->btag=0;
            particle->hademfraction=hademfraction;
            particle->dummy1=dummy1;
            particle->dummy2=dummy2;
            particleList.push_back(particle);
            return particle;
        }
        
        LHCOParticle* addJet(float eta=0.0,
                              float phi=0.0,
                              float pt=0.0,
                              float mass=0.0,
                              int ntrk=0.0,
                              float dummy1=0.0,
                              float dummy2=0.0)
        {
            LHCOParticle* particle = new LHCOParticle();
            particle->type=types[JET];
            particle->eta=eta;
            particle->phi=phi;
            particle->pt=pt;
            particle->jmass=mass;
            particle->ntrk=ntrk;
            particle->btag=0;
            particle->hademfraction=0.0;
            particle->dummy1=dummy1;
            particle->dummy2=dummy2;
            particleList.push_back(particle);
            return particle;
        }
        
        LHCOParticle* addBJet(float eta=0.0,
                              float phi=0.0,
                              float pt=0.0,
                              float mass=0.0,
                              int ntrk=0.0,
                              float dummy1=0.0,
                              float dummy2=0.0)
        {
            LHCOParticle* particle = new LHCOParticle();
            particle->type=types[JET];
            particle->eta=eta;
            particle->phi=phi;
            particle->pt=pt;
            particle->jmass=mass;
            particle->ntrk=ntrk;
            particle->btag=1;
            particle->hademfraction=0.0;
            particle->dummy1=dummy1;
            particle->dummy2=dummy2;
            particleList.push_back(particle);
            return particle;
        }
        
        LHCOParticle* setMET(float phi=0.0,
                             float pt=0.0,
                             float dummy1=0.0,
                             float dummy2=0.0)
        {
            met->type=types[MET];
            met->eta=0.0;
            met->phi=phi;
            met->pt=pt;
            met->jmass=0.0;
            met->ntrk=0;
            met->btag=0;
            met->hademfraction=0.0;
            met->dummy1=dummy1;
            met->dummy2=dummy2;
            return met;
        }
        
        void writeFloat(std::ostream &stream, float value)
        {
            stream<<std::setw(8)<<std::setprecision(3)<<value;
        }
        
        void writeInteger(std::ostream &stream,int value)
        {
            stream<<std::setw(3)<<std::setprecision(0)<<std::setiosflags(std::ios::left)<<value<<std::resetiosflags(std::ios::left);
        }
        
        void writeParticle(std::ostream &stream, int index, LHCOParticle* particle)
        {
            stream.setf ( std::ios_base::fixed, std::ios_base::floatfield );
            writeInteger(stream,index);
            stream<<SEPARATOR;
            writeInteger(stream,particle->type);
            stream<<SEPARATOR;
            writeFloat(stream,particle->eta);
            stream<<SEPARATOR;
            writeFloat(stream,particle->phi);
            stream<<SEPARATOR;
            writeFloat(stream,particle->pt);
            stream<<SEPARATOR;
            writeFloat(stream,particle->jmass);
            stream<<SEPARATOR;
            writeInteger(stream,particle->ntrk);
            stream<<SEPARATOR;
            writeInteger(stream,particle->btag);
            stream<<SEPARATOR;
            writeFloat(stream,particle->hademfraction);
            stream<<SEPARATOR;
            writeFloat(stream,particle->dummy1);
            stream<<SEPARATOR;
            writeFloat(stream,particle->dummy2);
            stream<<SEPARATOR<<std::endl;
            
           
        }
        
        void writeEvent(std::ostream &stream)
        {   
            //write out the event id & trigger info
            stream<<std::setw(10)<<std::setprecision(0)<<std::setiosflags(std::ios::left)<<0<<std::resetiosflags(std::ios::left)
                  <<std::setw(10)<<std::setprecision(0)<<std::setiosflags(std::ios::left)<<eventID<<std::resetiosflags(std::ios::left)
                  <<std::setw(10)<<std::setprecision(0)<<std::setiosflags(std::ios::left)<<triggerInfo<<std::resetiosflags(std::ios::left)
                  <<std::endl;
            //write out all particles
            for (int i=0; i< particleList.size(); ++i) {
                writeParticle(stream,i+1,particleList[i]);
            }
            //write MET
            writeParticle(stream,particleList.size()+1,met);
            
        }
        
        
        
        ~LHCOEvent()
        {
            particleList.clear();
        }
};

