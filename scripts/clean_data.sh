#!/bin/bash

for file in data/bigdif_dist/seed_*/*.csv
do
    cat /dev/null > $file
done

for file in data/exp_dist/seed_*/*.csv
do
    cat /dev/null > $file
done
