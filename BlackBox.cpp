// This function is a test blackbox to test some simple MCMC
// methods in python
// Simon M. Mudd
// May 7th, 2015
// Padova, Italy
// Ho caldo

#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include "mathutil.hpp"
using namespace std;


double main (int nNumberofArgs,char *argv[])
{
  //Test for correct input arguments
  if (nNumberofArgs<2)
  {
    cout << "FATAL ERROR: This program needs some inputs!" << endl;
    cout << "The first number should be the standard deviation of the data," << endl;
    cout << "The rest are parameters."  << endl;
    exit(EXIT_SUCCESS);
  }

  float data_standard_deviation = atof(argv[i+1]);
  cout << "Standard deviation of data is: " << data_standard_deviation << endl;

  vector<double> params;

  for(int i = 0: i<nNumberArgs-2; i++)
  {
    params.push_back( atof(argv[i+2])
    cout << "Param["<<i<<"]: " << params[i] << endl;
  }

  // read in the real data
  ifstream real_in;
  real_in.open("Blackbox.data");
  double this_param;
  float this_x;
  float this_data;
  vector<float> x;
  vector<float> data;
  while(real_in >> this_x >> this_data)
  {
    x.push_back(this_x);
    data.push_back(this_data);
  }



}

