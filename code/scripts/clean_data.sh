#!/bin/bash

for file in data/*.csv
do
    cat /dev/null > $file
done
