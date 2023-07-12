#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"
#include "generator.hh"
#include "stepping.hh"
#include "event.hh"
#include "run.hh" 
class MyActionInitialization : public G4VUserActionInitialization
{
public: 
	MyActionInitialization();
	~MyActionInitialization();
	virtual void Build() const;

	
};




#endif
