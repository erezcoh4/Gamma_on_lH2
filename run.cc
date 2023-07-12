#include "run.hh"

MyRunAction::MyRunAction()
{
    auto analysisManager = G4AnalysisManager::Instance();
    // Book histograms, ntuple
    //
    
    // Creating histograms
    analysisManager->SetVerboseLevel(1);
    analysisManager->CreateH1("Eabs","Edep in absorber", 100, 0., 800*MeV);
    
    // Creating ntuple
    //
    analysisManager->CreateNtuple("B4", "Edep and TrackL");
    analysisManager->CreateNtupleDColumn("Eabs");
    analysisManager->FinishNtuple();
    
}
MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    ncompton=0;
    nin=0;
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    G4int runID = run->GetRunID();
    std::stringstream strRunID;
    strRunID << runID;
    G4String fileName = "Output" +strRunID.str() + ".csv";
    //    man->OpenFile(fileName);
}
void MyRunAction::EndOfRunAction(const G4Run*)
{
    
    // print histogram statistics
    //
    //    auto analysisManager = G4AnalysisManager::Instance();
    //    if ( analysisManager->GetH1(0) )
    //    {
    //        G4cout << G4endl << " ----> print histograms statistic ";
    //        if(isMaster) {
    //            G4cout << "for the entire run " << G4endl << G4endl;
    //        }
    //        else {
    //            G4cout << "for the local thread " << G4endl << G4endl;
    //        }
    //
    //        G4cout << " EAbs : mean = "
    //        << G4BestUnit(analysisManager->GetH1(0)->mean(), "Energy")
    //        << " rms = "
    //        << G4BestUnit(analysisManager->GetH1(0)->rms(),  "Energy") << G4endl;
    //
    //    }
    G4cout<< "ncompton" << ncompton << G4endl << "nin:" << nin << G4endl;
    
    //    // save histograms & ntuple
    //    //
    //    analysisManager->Write();
    //    analysisManager->CloseFile();
    //
    
}

