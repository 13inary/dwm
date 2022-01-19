#!/bin/bash

MYCURRENTSOUND=""
if [ `amixer get Master | awk -F'[][]' 'END{ print $6 }'` == "on" ] ; then
	MYIFHEADPHONE=`amixer contents | grep ",iface=CARD,name='Headphone" | awk -F'=' '{ print $2 }' | awk -F',' '{ print $1 }'`
	if [ "`amixer cget numid=$MYIFHEADPHONE | grep ": values=" | awk -F'=' 'END{ print $2 }'`" == "on" ] ; then
		MYCURRENTSOUND="H`amixer get Headphone | awk -F'[][]' 'END{ print $2 }'`"
	else
		MYCURRENTSOUND="S`amixer get Speaker | awk -F'[][]' 'END{ print $2 }'`"
	fi
else
	MYCURRENTSOUND="mute"
fi

MYBATTERY=""
if [ `acpi -b | grep "Battery 0" | awk -F'[ ,]' '{ print $3 }'` == "Discharging" ] ; then
	MYBATTERY="B`acpi -b | grep "Battery 0" | awk -F'[ ,]' '{ print $5 }'`"
else
	MYBATTERY="C`acpi -b | grep "Battery 0" | awk -F'[ ,]' '{ print $5 }'`"
fi

MYWIFI="`iwconfig | grep ESSID | awk -F'"' '{ print $2 }'`"
if [ "$MYWIFI" == "" ] ; then
	MYWIFI="NO-CONNECT"
fi

MYWIFI="_$MYWIFI"
MYDISK="_`df -h | grep home | awk -F' ' '{ print $4 }'`"
MYLIGHT="_L`brightnessctl | grep % | awk -F'[()]' '{ print $2 }'`"
MYCURRENTSOUND="_$MYCURRENTSOUND"
MYTIME="`now`"
MYBATTERY="_[$MYBATTERY]"
xsetroot -name "$MYWIFI$MYLIGHT$MYCURRENTSOUND$MYBATTERY$MYDISK$MYTIME"
