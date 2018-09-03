#!/bin/bash

# backup original lsqr.m file
sudo mv /usr/local/MATLAB/R2018a/toolbox/matlab/sparfun/lsqr.m /usr/local/MATLAB/R2018a/toolbox/matlab/sparfun/lsqr.m.bak

# copy the optimised lsqr.m to the location where it supposed to be
sudo cp Optimised/lsqr.m /usr/local/MATLAB/R2018a/toolbox/matlab/sparfun/.

