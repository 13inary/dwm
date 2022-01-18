#!/bin/bash

scrot -q 100 -s ~/pictures/ocr/tmp.png 
tesseract -l chi_sim+eng  ~/pictures/ocr/tmp.png  ~/pictures/ocr/data
cat ~/pictures/ocr/data.txt | xsel -b
rm ~/pictures/ocr/tmp.png
#rm ~/pictures/ocr/data.txt
