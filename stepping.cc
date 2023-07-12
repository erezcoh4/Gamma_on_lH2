#include "stepping.hh" 

MySteppingAction::MySteppingAction(MyEventAction *eventAction, MyRunAction* runAction)
{
    fEventAction = eventAction;
    fRunAction = runAction;
    
    
    }

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{
    const G4VProcess *process = step->GetPostStepPoint()->GetProcessDefinedStep();
    auto  IsFirstStepInVolume = step->IsFirstStepInVolume();
    
    std::cout
    << "Track "                     << step->GetTrack()->GetTrackID()
    << ", particle: "               << step->GetTrack()->GetParticleDefinition()->GetParticleName()
    << std::endl
    << "process: "                  << process->GetProcessName()
    << std::endl
    << "volume: "                   << step->GetTrack()->GetLogicalVolumeAtVertex()->GetName()
    << std::endl
    << "is first step in volume? "  << IsFirstStepInVolume
    << std::endl
    << "Step length: "              << step->GetStepLength()/CLHEP::centimeter << " cm"
    << std::endl;
    
    
    // Count the number of gamma rays that enter the target region
    // Requirements:
    // (1) Primary particle (gamma ray) = track ID == 1
    // (2) Inside the target material
    // (3) First time particle meets this volume
    if (step->GetTrack()->GetTrackID() == 1
        && step->GetTrack()->GetLogicalVolumeAtVertex()->GetName() == "logicAbsorber"
        && step->IsFirstStepInVolume()==1)
    {
        fRunAction->nin+=1;
    }
    
    // Count the number of gamma rays that undergo Compton scattering
    // Requirements:
    // (1) Gamma ray
    // (2) Compton scattering
    // (3) Inside the target material
    if (step->GetTrack()->GetParticleDefinition()->GetParticleName()=="gamma"
        && process->GetProcessName()=="compt"
        && step->GetTrack()->GetLogicalVolumeAtVertex()->GetName() == "logicAbsorber")
    {
        fRunAction->ncompton+=1;
    }
    
    //G4cout << "ProcName: " << step->GetPreStepPoint()->GetProcessDefinedStep()->GetProcessName() << G4endl;
    G4double edep = step->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);
    
}
