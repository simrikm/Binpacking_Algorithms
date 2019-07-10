#!/bin/bash


#making the make file 
make

#cleaning generated object files 
make clean

echo -e "\nbin_packing algorithms are being runned...."

#running the executable file
bin_packing

echo -e "RUNNING COMPLETE....\n"
