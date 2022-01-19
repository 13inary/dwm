#!/bin/bash

#MYSOUNDSWITCH=`amixer get Master | awk -F'[][]' 'END{ print $6 }'`
#if [ $MYSOUNDSWITCH == "on" ] ; then
#	#echo "pre is on"
#
#	MYHEADPHONESTATUS=`amixer get Headphone | awk -F'[][]' 'END{ print $6 }'`
#	MYSPEAKERSTATUS=`amixer get Speaker | awk -F'[][]' 'END{ print $6 }'`
#	if [ "`amixer cget numid=18 | grep ": values=" | awk -F'=' 'END{ print $2 }'`" == "on" ] ; then
#		# speaker file
#		echo $MYSPEAKERSTATUS > /.dwm/.h-speaker-status
#		#echo "h-s to file"
#		#echo "speaker file : `cat /.dwm/.h-speaker-status`"
#		# headphone file
#		echo $MYHEADPHONESTATUS > /.dwm/.h-headphone-status
#		#echo "h-h to file"
#		#echo "head file : `cat /.dwm/.h-headphone-status`"
#
#	else
#		# speaker file
#		echo $MYSPEAKERSTATUS > /.dwm/.s-speaker-status
#		#echo "s-s to file"
#		#echo "speaker file : `cat /.dwm/.s-speaker-status`"
#		# headphone file
#		echo $MYHEADPHONESTATUS > /.dwm/.s-headphone-status
#		#echo "s-h to file"
#		#echo "head file : `cat /.dwm/.s-headphone-status`"
#	fi
#fi

amixer -qM sset Master toggle

MYSOUNDSWITCH=`amixer get Master | awk -F'[][]' 'END{ print $6 }'`
if [ $MYSOUNDSWITCH == "on" ] ; then
	#echo "after is on"
	#echo "head file : `cat /.dwm/.headphone-status`"
	#echo "speaker file : `cat /.dwm/.speaker-status`"
	MYIFHEADPHONE=`amixer contents | grep ",iface=CARD,name='Headphone" | awk -F'=' '{ print $2 }' | awk -F',' '{ print $1 }'`

	if [ "`amixer cget numid=$MYIFHEADPHONE | grep ": values=" | awk -F'=' 'END{ print $2 }'`" == "on" ] ; then
		#if [ `cat /.dwm/.h-headphone-status` == "on" ] ; then
			amixer -qM sset Headphone unmute
			#echo "set h-headphone on"

			amixer -qM sset Speaker mute
			#echo "set h-speaker on"
	else
			amixer -qM sset Headphone mute
			#echo "set s-headphone on"

			amixer -qM sset Speaker unmute
			#echo "set s-speaker on"
	fi
fi
#echo "=========END======="
#echo "current head : `amixer get Headphone | awk -F'[][]' 'END{ print $6 }'`"
#echo "current speaker  : `amixer get Speaker | awk -F'[][]' 'END{ print $6 }'`"
/usr/local/dwmScript/bar-message.sh
#amixer -qM sset Master unmute
#amixer -qM sset Headphone toggle
