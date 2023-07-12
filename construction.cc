#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}
MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_Galactic");
	G4Box *solidWorld = new G4Box("solidWorld", 0.5*m,0.5*m,0.5*m); // (name halfx halfy halfz)
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld,worldMat,"logicWorld"); // (solidworld, matirial, name)
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),  logicWorld,"physWorld",0,false,0,true);
	
	G4Material *absorberMat = nist->FindOrBuildMaterial("G4_Fe");
	G4Tubs 	*solidAbsorber = new G4Tubs("solidAbsorber",0., 4.3/2*cm,25.*cm,0,2.0*pi); // name innerRad Outerrad length start angel delta angle
	G4LogicalVolume *logicAbsorber = new G4LogicalVolume(solidAbsorber,absorberMat,"logicAbsorber");
	G4VPhysicalVolume *physAbsorber = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),  logicAbsorber,"physAbsorber",logicWorld,false,0,true);
	
	return physWorld;
}

