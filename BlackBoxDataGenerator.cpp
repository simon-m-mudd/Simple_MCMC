// this takes the parameters, makes up some 'true' parameters,
// and generates some data that includes some noise
// Simon M. Mudd
// May 8th, 2015
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

int main(int nNumberofArgs,char *argv[])
{
  //Test for correct input arguments
  if (nNumberofArgs<2)
  {
    cout << "FATAL ERROR: This program needs some inputs!" << endl;
    cout << "The first number should be the standard deviation of the data," << endl;
    cout << "The rest are parameters. Note parameters are not used in this function, " << endl;
    cout << "the parameter entries are only used to get the number of parameters." << endl;
    exit(EXIT_SUCCESS);
  }


  float data_standard_deviation = atof(argv[i+1]);
  cout << "Standard deviation of data is: " << data_standard_deviation << endl;

  // now randomly assign 'true' parameters
  long seed = time(NULL);
  vector<float> params;
  float this_param;
  for(int i = 0; i<nNumberofArgs-2; i++)
  {
    this_param = ran3(&seed)-0.5;				// just let the parameters vary between 0.5 and 0.5
    cout << "This param is: " << this_param << endl;
    params.push_back( this_param);
  }

  // now generate some data
  int N_Data_points = 51;
  float end_x = 50;
  float dx = end_x/(float(N_Data_points)-1);
  vector<float> data(N_Data_points);
  vector<float> data_location(N_Data_points);


  for(int i = 0; i<N_Data_points; i++)
  {
    data_location[i] = float(i)*dx;
    data[i] = 0;
    for (int p = 0; p<nNumberofArgs-1; p++)
    {
      data[i]+= params[p]*pow(data_location[i],1.0/float(p+1));
    }
    // now add some noise
    data[i] = data[i] + ran3(&seed)*data_standard_deviation-data_standard_deviation/2;
  }

  // now print this stuff to a file
  ofstream data_out;
  data_out.open("Blackbox.data");
  for(int i = 0; i<N_Data_points; i++)
  {
    data_out << data_location[i] << " " << data[i]  << endl;
  }
  data_out.close();

  ofstream true_params_out;
  true_params_out.open("TrueParams_BlackBox.params");
  for (int p = 0; p<nNumberofArgs-1; p++)
  {
    true_params_out << params[p] << endl;
  }
  true_params_out.close();

}

