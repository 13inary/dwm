#!/bin/bash

rm -f ./config.h
sudo make clean install
rm -f ./*.o
rm -f ./*.rej
rm -f ./*.orig
rm -f ./config.h
rm -f ./dwm
