#include <iostream>
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4StepLimiterPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "construction.hh"
#include "physics.hh"
#include "action.hh"
#include "QBBC.hh"

int main(int argc, char** argv)
{
    G4RunManager *runManager = new G4RunManager();
    runManager->SetUserInitialization(new MyDetectorConstruction());
    //runManager->SetUserInitialization(new MyphysicsList());
    
    G4VModularPhysicsList* physicsList = new QBBC;
    //	G4VModularPhysicsList* physicsList = new G4EmStandardPhysics;
    
    //physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(physicsList);
    //G4StepLimiterPhysics* stepLimitPhys = new G4StepLimiterPhysics();
    //runManager->SetUserInitialization(stepLimitPhys);
    runManager->SetUserInitialization(new MyActionInitialization());
    runManager->Initialize();
    G4UIExecutive *ui = 0;
    if (argc == 1)
    {
        ui = new G4UIExecutive(argc, argv);
    }
    G4VisExecutive *visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    if (ui)
    {
        G4UImanager *UImanager = G4UImanager::GetUIpointer();
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
    }
    else
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }
    
    //UImanager->ApplyCommand("/control/cout/ignoreThreadsExcept 0");
    //UImanager->ApplyCommand("/event/verbose 0");
    //UImanager->ApplyCommand("/tracking/verbose 0");
    //UImanager->ApplyCommand("/run/verbose 2");
    //UImanager->ApplyCommand("/control/verbose 2");
    //UImanager->ApplyCommand("/run/printProgress 100");
    //UImanager->ApplyCommand("/run/beamOn 1000");
    
    //
    //job termination
    delete visManager;
    delete runManager;
    delete ui;

    // return
    return 0;
    
}
