#!/bin/bash

# Run Python file
for i in {266..500}
do
    python3 ../scripts/pointsgenerator.py $i

    # Run executable file
    ./main $i

# Compare output files
    python3 ../scripts/writecsv.py $i
    
done