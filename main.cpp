#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "header/DataPrep.hpp"
#include "header/PhysicsEngine.hpp"
#include "header/ComponentAnalyzer.hpp"
#include "header/CostCalculator.hpp"
#include "header/Comparator.hpp"
using namespace std;
namespace fs = filesystem;

void clearFile(string filename) {
    ofstream ofs(filename, ios::trunc);
    ofs.close();}

int main() {
  string material[] = {"glass","concrete","wood_stave","rubber","copper","cast_iron","galvanized_iron","wrought_iron","stainless_steel","commercial_steel"};
  for(int i = 0; i<size(material);i++){
    DataPrep(material[i]);
    PhysicsEngine();
    ComponentAnalyzer();
    CostCalculator();
  }
}
