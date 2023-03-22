//  #pragma once 
// // #include <frc2/command/CommandBase.h>
// // #include <frc2/command/CommandHelper.h>
// // #include "subsystems/Drive.h"

// class DriveDistance: public frc2::CommandHelper<frc2::CommandBase, DriveDistance> {
//  public:
//   /**
//    * Creates a new DriveDistance.
//    *
//    * @param inches The number of inches the robot will drive
//    * @param speed The speed at which the robot will drive
//    * @param drive The drive subsystem on which this command will run
//    */
//   DriveDistance(Drive* subsystem);

//   void Initialize() override;

//   void Execute() override;

//   void End(bool interrupted) override;

//   bool IsFinished() override;

//  private:
//   Drive* m_drive;
// };