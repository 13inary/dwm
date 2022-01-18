#!/bin/bash

myCurrentBright=`brightnessctl g`

if [ $myCurrentBright -gt 960 ] ; then

brightnessctl s 1%-

fi
~/.dwm/bar-message.sh
