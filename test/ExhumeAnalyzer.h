#ifndef EXHUME_ANALYZER
#define EXHUME_ANALYZER

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

//#include "HepMC/WeightContainer.h"
//#include "HepMC/GenEvent.h"
//#include "HepMC/GenParticle.h"

//#include "SimDataFormats/HepMCProduct/interface/HepMCProduct.h"

#include "TH1D.h"
#include "TFile.h"

//
// class decleration
//

class ExhumeAnalyzer : public edm::EDAnalyzer {
   public:
      explicit ExhumeAnalyzer(const edm::ParameterSet&);
      ~ExhumeAnalyzer();


   private:
      virtual void beginJob(const edm::EventSetup&) ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

      // ----------member data ---------------------------
 
  std::string outputFilename;     
  TH1D* hist_eta;
  TH1D* hist_t1;
  TH1D* hist_xigen1;
  TH1D* hist_t2;
  TH1D* hist_xigen2;	
  TH1D* hist_sHat;
  TH1D* hist_MX;

};

#endif
