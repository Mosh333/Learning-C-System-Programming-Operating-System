#!/bin/bash
# Script to run the Student Database System

currDir=$(pwd)

if  [[ $currDir == *studentDatabaseSystem ]] ;
then
    echo "Yes"
    rm ./runStudentDatabaseSystem; clear; gcc "$currDir/src/main.c" -o runStudentDatabaseSystem; ./runStudentDatabaseSystem;
else
    echo "Make sure you are running from top level directory (./studentDatabaseSystem)"
fi

