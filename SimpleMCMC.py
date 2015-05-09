# -*- coding: utf-8 -*-
"""
Created on Thu May 07 16:25:29 2015

@author: smudd
"""

#==============================================================================
#
# These are some functions for running a simple metropolis algorithm
# 
#
#==============================================================================
import numpy as np
import subprocess

# this runs the blackbox function and returns the liklihood
def RunBlackBox(params,BlackBoxName):
    
    # get the number of parameters
    #n_params = params.len
    
    # now form the vall
    this_call= []
    this_call.append(BlackBoxName)
    for p in params:
        this_call.append(str(p))
    print "This call is: "
    print this_call
    
    # Call the process
    p_process = subprocess.Popen(this_call,stdin=subprocess.PIPE,stdout=subprocess.PIPE) 
    
    # This gets all the output. It saves the last thing printed to screen
    # The black box should print the likelihood to screen
    for line in iter(p_process.stdout.readline,''):
        latest_line = line.rstrip()        
        #print line.rstrip()       
    likelihood = float(latest_line)    
       
    return likelihood

    

def ReadChainFile(FileName):
    
    from os.path import exists
    
    # check to see if the chain file exists
    if exists(FileName) is False:
        raise Exception('[Errno 2] No such file or directory: \'' + FileName + '\'')     
    
    # open the file, getting all the data
    f = open(FileName,'r')  # open file
    lines = f.readlines()   # read in the data
    n_lines = len(lines)   # get the number of lines (=number of data)
    
    # now get the header
    Header_Data = lines[0].split(",")
    
    # the data minus the header
    Chain_data = lines[1:]
    
    # the chain file is in csv
    # the format is
    # i,params_new, params_old,new_likelihood,test_likelihood,n_accepted,n_rejected
    # Thus the number of parameters is the number of items in the Header, 
    # minus 5, divided by 2
    n_params = (len(Header_Data)-5)/2
    
    np.zeros(n_lines,n_params)


#==============================================================================
# This function generates new parameters based on the old parameters  
#==============================================================================  
def GenerateNextStepParams(sigma_vec, old_params_vec):
    import random
    
    new_params_vec = []
    
    # zip the two vectors for iteration
    for sigma,param in zip(sigma_vec,old_params_vec):
        param_change = random.gauss(0, sigma)
        param =  param + param_change
        new_params_vec.append(param)
    
    return new_params_vec
#==============================================================================


#==============================================================================
# This function is like the above but reflects the values about minimum and
# maximum values
#==============================================================================
def GenerateNextStepParamsReflective(sigma_vec, old_params_vec,min_params,max_params):
    import random    
    new_params_vec = []
    
    # zip the parameters for iteration
    for sigma,param,min_param,max_param in zip(sigma_vec,old_params_vec,min_params,max_params):
        param_change = random.gauss(0, sigma)
        test_new_param = param+param_change
        if ( test_new_param < min_param):
            reflect = min_param - test_new_param
            param = reflect+min_param 
        if ( test_new_param > max_param):
            reflect = test_new_param-max_param
            param = reflect-max_param
        new_params_vec.append(test_new_param)
                        
    return new_params_vec        
#==============================================================================     
    
    
    
    