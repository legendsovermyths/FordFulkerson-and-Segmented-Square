#!/bin/bash

# Run Python file
for i in {6..10}
do
    python3 ../scripts/GenerateFlow.py $i > output1.txt

    # Run executable file
    ./main $i > output2.txt

# Compare output files
    python3 ../scripts/WriteCSV.py $i
    
done