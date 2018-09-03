#!/bin/bash

# restore original file from backup
sudo rm -rf /usr/local/MATLAB/R2018a/toolbox/matlab/sparfun/lsqr.m
sudo mv /usr/local/MATLAB/R2018a/toolbox/matlab/sparfun/lsqr.m.bak /usr/local/MATLAB/R2018a/toolbox/matlab/sparfun/lsqr.m
