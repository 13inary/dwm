#!/bin/bash

MYTOUCHPAD=`xinput --list | grep Touchpad | awk -F= '{print $2}' | awk '{print $1}'`
#if [ `xinput list-props 12 | grep "Device '" | awk -F ' ' '{print $4}'` == "Touchpad':" ] ; then
if [ `xinput list-props $MYTOUCHPAD | grep "Device Enabled" | awk -F' ' '{ print $4 }'` == "0" ] ; then
	xinput enable $MYTOUCHPAD
	xdotool mousemove 960 540
#fi

else

#if [ `xinput list-props 12 | grep "Device '" | awk -F ' ' '{print $4}'` == "Touchpad':" ] ; then
	xinput disable $MYTOUCHPAD
	xdotool mousemove 1919 111
fi
#fi
