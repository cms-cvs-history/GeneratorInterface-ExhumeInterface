// system include files
#include <memory>
#include <iostream>

// user include files
#include "PrintEvent.h"


#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "CLHEP/HepMC/GenEvent.h"
#include "CLHEP/HepMC/GenParticle.h"

#include "SimDataFormats/HepMCProduct/interface/HepMCProduct.h"

PrintEvent::PrintEvent(const edm::ParameterSet& iConfig)
{
}


PrintEvent::~PrintEvent()
{
 
}

// ------------ method called to for each event  ------------
void
PrintEvent::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
  
   // get HepMC::GenEvent ...
   Handle<HepMCProduct> evt_h;
   iEvent.getByType(evt_h);
   HepMC::GenEvent * evt = new  HepMC::GenEvent(*(evt_h->GetEvent()));


   // loop over particles
   int count = 0;	
   for(HepMC::GenEvent::particle_iterator it = evt->particles_begin(); it != evt->particles_end(); ++it) {
	std::cout << ++count << "  " << (*it)->pdg_id() << "  " << (*it)->status() << "  " << (*it)->Mother() << "  " << (*it)->momentum().px() << "  " << (*it)->momentum().py() << "  " << (*it)->momentum().pz() << "  " << (*it)->momentum().e() << "  " << std::endl;
   }

}
// ------------ method called once each job just before starting event loop  ------------
void 
PrintEvent::beginJob(const edm::EventSetup&)
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
PrintEvent::endJob() {
  // save histograms into file

}

//define this as a plug-in
DEFINE_FWK_MODULE(PrintEvent);
