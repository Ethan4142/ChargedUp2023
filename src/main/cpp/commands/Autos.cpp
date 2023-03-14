// // Copyright (c) FIRST and other WPILib contributors.
// // Open Source Software; you can modify and/or share it under the terms of
// // the WPILib BSD license file in the root directory of this project.

#include "commands/Autos.h"

#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>

#include "Constants.h"

using namespace AutoConstants;

// frc2::CommandPtr autos::SimpleAuto(Drive* drive){
//     return frc2::FunctionalCommand(
//         [drive] {drive -> Reset();},
//         [drive] {drive -> Arcade(0,0);},
//         [drive] (bool interrrupeted) {drive -> Arcade(0, 0);},
//         [drive]{return drive -> GetAverageEncoder()}, {drive})
//         .ToPtr();
// }//Add stuff here later

// frc2::CommandPtr autos::NiceAuto( Intake* intake){
//     return frc2::cmd::Sequence(
//         frc2::FunctionalCommand(
//             [intake] {intake -> IntakeCommand()},
//             {intake})
//     .ToPtr());
//     //Add return here later
// }
