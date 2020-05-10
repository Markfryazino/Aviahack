#!/bin/bash
python3 utils/csv_to_txt.py
cd algos
cmake -Bbuild -H.
cmake --build build --target all
./build/algos
cd ..
python3 Tkinter.py
