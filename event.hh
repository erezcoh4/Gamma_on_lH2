#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "run.hh"
#include "G4AnalysisManager.hh"
class MyEventAction : public G4UserEventAction
{
public:
	MyEventAction(MyRunAction*);
	~MyEventAction();
	
	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);
	
	void AddEdep(G4double edep); 
	void AddEvent();
    
    G4int GetEventID() {return fEventID;};
	
	
private:
	G4double fEdep;
    G4int fEventID;

};



#endif
