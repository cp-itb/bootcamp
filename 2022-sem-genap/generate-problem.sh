#!/bin/sh

# Usage: bash generate-problem.sh <id> <problem-slug/folder-name> <problem-name> <time-limit> <memory-limit> <dest-folder>
# bash generate-problem.sh permen seleksi-ieeextreme15-wibo-dan-permen "Wibo dan Permen" 2 128
# fix error '\r': sed 's/\r$//' generate-problem.sh > generate-problem2.sh

# read -p 'Probid: ' PROBID
# read -p 'Problem folder name: ' PROBLEM_SLUG
# read -p 'Problem name: ' PROBLEM_NAME
# read -p 'Time Limit: ' TIME_LIMIT
# read -p 'Memory Limit: ' MEM_LIMIT

PROBID=$1
PROBLEM_SLUG=$2
PROBLEM_NAME=$3
TIME_LIMIT=$4
MEM_LIMIT=$5
DEST_FOLDER=$6

mkdir $DEST_FOLDER

# Generate statement, solution, and testcases
echo "preparing problem"
cd "$PROBLEM_SLUG"
pdflatex "statement.tex"
rm *.aux *.log *.dvi *.out *.toc *.synctex.gz

g++ solution.cpp -O2 -Wall -o solution -std=c++11
$TCFRAME_HOME/scripts/tcframe build
./runner
cd ".."

echo "creating problem"
rm -r "temp"
mkdir "temp"
cd "temp"

# Generate domjudge-problem.ini
echo "probid=$PROBID" > domjudge-problem.ini
echo "timelimit='$TIME_LIMIT'" >> domjudge-problem.ini

# Generate problem.yaml
echo "---" > problem.yaml
echo "name: $PROBLEM_NAME" >> problem.yaml

FILE=../$PROBLEM_SLUG/validator.cpp # whether custom checker is used
if test -f "$FILE"; then
    echo "validation: custom" >> problem.yaml
    # Add validator
    mkdir "output_validators"
    cp "../$PROBLEM_SLUG/validator.cpp" "output_validators/validator.cpp"
fi

echo "limits:" >> problem.yaml
echo "    memory: $MEM_LIMIT" >> problem.yaml

# Add testcase
mkdir "data"
mkdir "data/secret"
for testcases in "../$PROBLEM_SLUG/tc/*"; do
    cp $testcases "data/secret"
done
cd "data/secret"
rename 's/\.out$/.ans/' *
rename 's/^.*_//' *
cd "../.."

# Add statement
cp "../$PROBLEM_SLUG/statement.pdf" "problem.pdf"

# zipping everything
zip -r "problem.zip" "."
cp "problem.zip" "../$DEST_FOLDER/$PROBID.zip"
mv "problem.zip" "../$PROBLEM_SLUG/$PROBID.zip"
cd ..