/* This is en example for an Analyzer of a Herwig HeoMCProduct
   and looks for muons pairs and fills a histogram
   with the invaraint mass of the four. 
*/

//
// Original Author:  Fabian Stoeckli
//         Created:  Tue Nov 14 13:43:02 CET 2006
// $Id: H4muAnalyzer.cc,v 1.2 2007/02/14 15:51:35 fabstoec Exp $
//
//


// system include files
#include <memory>
#include <iostream>

// user include files
#include "HWWAnalyzer.h"


#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "CLHEP/HepMC/GenEvent.h"
#include "CLHEP/HepMC/GenParticle.h"

#include "SimDataFormats/HepMCProduct/interface/HepMCProduct.h"

#include "TH1D.h"
#include "TFile.h"

HWWAnalyzer::HWWAnalyzer(const edm::ParameterSet& iConfig)
{
  outputFilename=iConfig.getUntrackedParameter<std::string>("OutputFilename","dummy.root");
  invmass_histo = new TH1D("invmass_histo","invmass_histo",100,70,90.);
}


HWWAnalyzer::~HWWAnalyzer()
{
 
}

// ------------ method called to for each event  ------------
void
HWWAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
  
   // get HepMC::GenEvent ...
   Handle<HepMCProduct> evt_h;
   iEvent.getByType(evt_h);
   HepMC::GenEvent * evt = new  HepMC::GenEvent(*(evt_h->GetEvent()));


   // look for W's
   std::vector<HepMC::GenParticle*> Wbosons;   
   for(HepMC::GenEvent::particle_iterator it = evt->particles_begin(); it != evt->particles_end(); ++it) {
     if(abs((*it)->pdg_id())==24 && abs(((*it)->mother())->pdg_id())==25)
       Wbosons.push_back(*it);
   }
   
   std::cout << "Number of W's found: " << Wbosons.size() <<std::endl;
   invmass_histo->Fill(Wbosons[0]->momentum().m());
   std::cout << "Inv. mass of first W: " << Wbosons[0]->momentum().m() <<std::endl;
   invmass_histo->Fill(Wbosons[1]->momentum().m());
   std::cout << "Inv. mass of second W: " << Wbosons[1]->momentum().m() <<std::endl;	

}


// ------------ method called once each job just before starting event loop  ------------
void 
HWWAnalyzer::beginJob(const edm::EventSetup&)
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
HWWAnalyzer::endJob() {
  // save histograms into file
  TFile file(outputFilename.c_str(),"RECREATE");
  invmass_histo->Write();
  file.Close();

}

//define this as a plug-in
DEFINE_FWK_MODULE(HWWAnalyzer);
