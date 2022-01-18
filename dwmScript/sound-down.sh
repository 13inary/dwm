#!/bin/bash

if [ `amixer get Master | awk -F'[][]' 'END{ print $6 }'` == "on" ] ; then

	if [ `amixer get Headphone | awk -F'[][]' 'END{ print $6 }'` == "on" ] ; then
		amixer -qM sset Headphone 1%- unmute
	fi

	if [ `amixer get Speaker | awk -F'[][]' 'END{ print $6 }'` == "on" ] ; then
		amixer -qM sset Speaker 1%- unmute
	fi
fi
~/.dwm/bar-message.sh
