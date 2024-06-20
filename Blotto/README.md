
# Blotto

## CPSC 223 Fall 2023

### Instructors: Alan Weide & Ozan Erat


## Introduction

Blotto is a simultaneous game for two players in which the players distribute military units over a number of battlefields each worth some number of points that represent the battlefields' strategic value. Each player has a set number of units to distribute, each unit is equivalent to each other unit, and a unit must be allocated entirely to a single battlefield. For each battlefield, the player who allocates more units to that battlefield wins the points for it (with the points split evenly in case of a tie, including a 0-0 tie), and the winner is the player with the most total points.

## Overview

Write a program called `Blotto` that reads players' distributions from standard input, along with a list of head-to-head matchups between pairs of those players. Output gives the result of each matchup, where, for each matchup, points are awarded to each player based on who placed more units in each battlefield, and the value of the battlefields given on the command line.

## Implementing the `gmap` ADT

You must implement the `gmap` ADT according to the specification in `gmap.h`, which can then be used to store the players' distributions as you read them from standard input for retrieval later when you read the matchups. **You may not modify `gmap.h` at all.**

## Details

### Command-line Arguments

- There will be at least one command-line argument
- Each command-line argument will be a positive integer in a format readable by `atoi`
- The number of battlefields is determined by the number of command-line arguments

### Input

- Standard input will consist of two parts separated by a blank line
- The first part lists the players' distributions as follows
    - There will be one line per player
    - There may be no players, in which case standard input will begin with a blank line
    - Each line starts with a unique non-empty entry id for the player
    - The id will contain at most 31 characters and no commas or whitespace
    - The rest of the line will contain the number of units the player distributes to each battlefield, with each number being a non-negative integer in a format readable by `scanf` with the `%d` format specifier
    - Each player's distribution will have a value for each battlefield
    - All parts of the data for each player are separated by commas
    - There is no whitespace on each line except for a newline at the end of each line
    - The total number of units for each player will be non-zero and equal to the number of units for all other players
- The second part lists the matchups as follows
    - There is one matchup per line
    - There may be no matchups, in which case standard input ends with the blank line that follows the players' distributions
    - Each matchup is specified by giving the id of two different players that were given in the first part of the input, separated by a single space
    - There is no other whitespace on each line aside from the space that delimits the ids and the newline at the end of the line

### Output

- There is exactly one line of output per matchup, written to standard output in the order the matchups appeared in standard input
- If there are duplicate matchups in standard input, then the corresponding output will appear repeated in the corresponding locations in the output
- Each line contains the id of the winner of the matchup (or the id of the first player given in the matchup, in the case of a draw), a single space, the score for that player given with one digit after the decimal point, a hyphen (`'-'`) with a single space on either side as a separator, and then the id and score of the other player in the same format
- Each line ends with a newline character
- There is no other output to either standard output or standard error

If any of the input to the `Blotto` program (standard input or the command-line arguments) is invalid for any reason, then the output can be anything but your program must not crash or hang.

## Submissions

Submit your project to Gradescope by uploading your `LOG.md` file as well as all files needed to compile and run both executables required by this assignment (`Blotto` and `GmapUnit`). Do not submit any files in the `Tests` directory. It is due **11:59 PM NHT on Friday, November 3, 2023**.
```


