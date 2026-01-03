#include <fstream>//don't change this line
#include <string>
#include <iostream>
#include <sstream>
#include "header/DataPrep.hpp"//include any other necessary headers like iostream,cmath ect above this line
using namespace std;
//include any other necessary headers like iostream,cmath ect.
void DataPrep(string Material)//don't change this line
{
//Paste or type code here 


//readuserinput
double flowRate, pipeLength, pipeDiameter,temperature;
string fluidName;
    
ifstream readfile("user_input.txt");
if (!readfile.is_open()){
    cout<<"user_input.txt not found";
    return;

}
readfile >> flowRate;
readfile >> pipeLength;
readfile >> pipeDiameter;
readfile >> fluidName;
readfile >> temperature;

readfile.close();
//finsihreaduserinput

//readfluiddatabase
    double viscosity = 0.0;
    double density = 0.0;
    double roughness = 0.0;
    double cost = 0.0;
    double maxPressure = 0.0;
    

ifstream readfluid("fluid.csv");
if (!readfluid.is_open()){
    cout<<"fluid.csv not found";
    return;

}

string line;
getline(readfluid,line);

while(getline(readfluid,line)){
stringstream ss(line);
string name;
double temp;

getline(ss, name, ',');
ss >> temp;
ss.ignore();

if (name == fluidName && temp == temperature) {
            ss >> viscosity;
            ss.ignore();
            ss >> density;
            break;
        }
    }
    readfluid.close();
    //finishreadfluiddatabase
   
//readmaterialdatabase
ifstream readmaterial("materials.csv");
    if (!readmaterial.is_open()) {
        cerr << "materials.csv not found." << endl;
        return;

 }

 getline(readmaterial, line);

while (getline(readmaterial, line)) {

        stringstream ss(line);
        string name;

getline(ss, name, ',');

        if (name == Material) {
            ss >> roughness;
            ss.ignore();
            ss >> cost;
            ss.ignore();
            ss >> maxPressure;
            break;
        }
    }
    readmaterial.close();



ofstream outputfile("clean_data.txt");
if(!outputfile.is_open())
{

    cout<<"clean_data.txt could not be opened."<<endl;
    return;
}
    outputfile << viscosity << endl;
    outputfile << density << endl;
    outputfile << roughness << endl;
    outputfile << cost << endl;
    outputfile << maxPressure << endl;
    outputfile.close();







}