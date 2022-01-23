#!/bin/bash

myCurrentBright=`brightnessctl g`
myMaxBright=`brightnessctl m`
myMinBright=`expr $myMaxBright / 100`

if [ $myCurrentBright -gt $myMinBright ] ; then

brightnessctl s 1%-

fi
/usr/local/dwmScript/bar-message.sh
