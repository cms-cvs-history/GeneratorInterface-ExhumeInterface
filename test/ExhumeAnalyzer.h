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
 
  double Ebeam_;
  std::string outputFilename_;     
  TH1D* hist_eta_;
  TH1D* hist_t1_;
  TH1D* hist_xigen1_;
  TH1D* hist_t2_;
  TH1D* hist_xigen2_;	
  TH1D* hist_sHat_;
  TH1D* hist_MX_;

};

#endif
