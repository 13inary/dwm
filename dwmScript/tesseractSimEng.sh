#!/bin/bash

scrot -q 100 -s ~/Pictures/ocr/tmp.png 
tesseract -l chi_sim+eng  ~/Pictures/ocr/tmp.png  ~/Pictures/ocr/data
cat ~/Pictures/ocr/data.txt | xsel -b
rm ~/Pictures/ocr/tmp.png
#rm ~/Pictures/ocr/data.txt
