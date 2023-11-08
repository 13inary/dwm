#!/bin/bash

filename=`now`.png

scrot -q 100 -s /tmp/screenshot_tmp/${filename}

feh /tmp/screenshot_tmp/${filename}
