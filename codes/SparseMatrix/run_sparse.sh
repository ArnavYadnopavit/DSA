#!/bin/bash

# Compile the program
gcc libsparse.c sparse.c -g -o sparse

# Run the program with input using a here document
./sparse << EOF
0 0 5
1 2 8
2 1 6
3 3 7
4 0 9
0 0 3
1 2 2
1 3 4
2 1 1
3 3 5
4 0 6
4 4 7
EOF

