#!/bin/bash
cd ~/Downloads/
rm -rf LSQR-cpp-master
cp -r LSQR-cpp-backup LSQR-cpp-master
rm -rf LSQR-cpp-master/Testing/lsmrTest2.cxx
cp lsmrTest2.cxx LSQR-cpp-master/Testing/.
cd LSQR-cpp-master
cmake .
cd Testing
make
./lsqrCxxTests