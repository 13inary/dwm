#!/bin/bash

rm /tmp/dwm_tesseract_ocr/tmp.png
rm /tmp/dwm_tesseract_ocr/data.txt

scrot -q 100 -s /tmp/dwm_tesseract_ocr/tmp.png

tesseract -l chi_sim+eng  /tmp/dwm_tesseract_ocr/tmp.png  /tmp/dwm_tesseract_ocr/data

cat /tmp/dwm_tesseract_ocr/data.txt | xsel -b
