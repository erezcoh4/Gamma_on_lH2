#ifndef RUN_HH
#define RUN_HH
#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Run.hh"

class MyRunAction : public G4UserRunAction
{
public: 
	MyRunAction();
	~MyRunAction();
	
	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);
	G4int ncompton;
	G4int nin;
};





#endif
