#!/bin/bash

while true; do

Battery= $(cat /sys/class/power_supply/BAT1/capacity)%
BatteryStatus= $(cat /sys/class/power_supply/BAT1/status)
if [[$BatteryStatus == D* ]];then
	BatteryStatus='need change'
else
	BatteryStatus='changing...'
fi

Volume=$(amixer get Master | tail -n1 | cut -d'[' -f4 |cut -d']' -f1)
if [[ $Volume == off ]];then
	Volume='mute'
else
	Volume=$(amixer get Master | sed -n '5p' | cut -d'[' -f2 | cut -d% -f1)
fi

DateTime=$(date +"%a $m-%d %T" )
BackLight= $(xbacklight | cut -d. -f1)

xsetroot -name "Bat.$BackLight|Vol.$Volume|$DateTime|[$BatteryStatus:$Batter
sleep 1s
done &
