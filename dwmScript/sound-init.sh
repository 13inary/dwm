#!/bin/bash

amixer -qM sset Master unmute
MYIFHEADPHONE=`amixer contents | grep ",iface=CARD,name='Headphone" | awk -F'=' '{ print $2 }' | awk -F',' '{ print $1 }'`
if [ "`amixer cget numid=$MYIFHEADPHONE | grep ": values=" | awk -F'=' 'END{ print $2 }'`" == "on" ] ; then
	amixer -qM sset Speaker 20% mute
	amixer -qM sset Headphone 5% unmute
else
	amixer -qM sset Speaker 20% unmute
	amixer -qM sset Headphone 5% mute
fi
