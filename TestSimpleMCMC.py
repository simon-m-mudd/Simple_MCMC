# -*- coding: utf-8 -*-
"""
Created on Fri May 08 14:44:04 2015

@author: smudd
"""

#import numpy as np
import SimpleMCMC as SMCMC

def TestSimpleMCMC():
    params = 10,0.2,0.3,0.4    
    
    BlackBoxName = "BlackBox"
    like = SMCMC.RunBlackBox(params,BlackBoxName)
    print "Likelihood is: " + str(like)
     
     
if __name__ == "__main__":
    #fit_weibull_from_file(sys.argv[1]) 
    TestSimpleMCMC()      