#include "header/PhysicsEngine.hpp" //don't change this line
//include any other necessary headers like iostream,cmath ect.
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
void PhysicsEngine()//don't change this line
{
//Paste or type code here
int main(){
  double density, viscosity, diameter, roughness, length;
  double velocity;
  double reynolds, frictionFactor, headLoss;
  const double g=9.81;

  // Read clean_data.txt
  ifstream cleanFile("clean_data.txt");
  cleanFile >> density;
  cleanFile >> viscosity;
  cleanFile >> diameter;
  cleanFile >> roughness;
  cleanFile >> length;
  cleanFile.close();
  // Read user_input.txt
  ifstream userFile("user_input.txt");
  userFile >> velocity;
  userFile.close();

  // Calculate Reynolds Number
  reynolds = (density * velocity * diameter)/viscosity;

  // Friction Factor
  if (reynolds < 2300) {

    // Laminar flow
    frictionFactor = 64 / reynolds;

  } 
  else {

  // Turbulent flow (Colebrook equation)
  frictionFactor = 0.02; // initial guess
  double newFriction;
  double error;

  do {
       newFriction =
            1.0 /
            pow(
                -2.0 * log10(
                    (roughness / (3.7 * diameter)) +
                    (2.51 / (reynolds * sqrt(frictionFactor)))
                ),
                2
            );

        error = fabs(newFriction - frictionFactor);
        frictionFactor = newFriction;

    } while (error > 0.000001);

  // Major Head Loss
  headloss = 
    frictionFactor * (length / diameter) * (pow(velocity,2)) / (2 * g)

  // Write output file
  ofstream outputFile("physics_results.txt);
  outputFile << "Fluid Velocity (m/s): " << velocity << endl;
  outputFile << "Reynolds Number: " << reynolds << endl;
  outputFile << "Friction Factor: " << frictionFactor << endl;
  outputFile << "Major Hed Loss (m): " << headLoss << endl;
  outputFile.close();
  // Program end
  cout << "Calculation completed successfully." << endl;
  return 0;
}
  //Paste or type code here
}
