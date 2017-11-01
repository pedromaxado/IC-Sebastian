#!/bin/bash

for file in data/all/1000_rep/seed_*/*.csv
do
    cat /dev/null > $file
done

for file in data/triv_vs_atriv/seed_*/*.csv
do
    cat /dev/null > $file
done
