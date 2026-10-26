#!/bin/bash

# Create directory and subdirectory
mkdir -p MyDirectory/SubDirectory

# Move into directory
cd MyDirectory

# Create text file using cat
cat > file.txt << EOF
This is a sample text file.
This file is created using cat command.
EOF

# Make a copy
cp file.txt copy.txt

# Rename the copy
mv copy.txt renamed.txt

# Set permissions
# Owner  : read, write, execute
# Group  : read only
# Others : read only
chmod 744 file.txt
chmod 744 renamed.txt

# List files with permissions, owner and group
ls -l
