#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
	fEdep = 0.;
    fEventID = 0;
	
}
MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{	
	fEdep = 0.;
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    << std::endl
    << "\t\t Begin of event " << fEventID << ""
    << std::endl
    << std::endl;
	
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
	//G4cout<<fEdep<<G4endl;
//	G4AnalysisManager *man = G4AnalysisManager::Instance();
//	man->FillH1(0, fEdep);
//	man->FillNtupleDColumn(0, fEdep);
//	man->AddNtupleRow();
    fEventID++;
    
    std::cout <<
    std::endl << "\t\t End of event " << fEventID << ""
    << std::endl
    << "---------------------------------------------------------------------------" << std::endl;
}
void MyEventAction::AddEdep(G4double edep)
{
	fEdep +=edep;
}

