/*
 * train-conductor.cpp
 * CPSC 223 Pset 5
 *
 * TO STUDENT: Do not modify this file!
 *
 * Author: Alan Weide
 */

#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constants
const int FAIL = -1;

/**
 * Opens file stations_file, reads all stations found in that file, then adds
 *  them into the given LinkedList. Then it prints the list to outfile_name.
 *  Once finished it returns the number of stations inserted.
 *
 * @param stations_file name of the file from which to read in stations
 * @param outfile_name name of the file to which the stations should be printed
 * @param stations the LinkedList in which to store the stations read from
 *  input
 * @return the number of stations inserted.
 */
int readAllStations(string stations_filename, string outfile_name, LinkedList &stations);

/**
 * Procedure that removes up to num_remove stations in an arbitrary pattern
 *  from the given LinkedList and prints the remaining stations of the list
 *  to outfile_name.
 *
 * @param outfile_name name of the file to which the list should be printed
 * @param stations the LinkedList from which to remove stations
 * @param num_remove the maximum number of removals to perform
 * @param pattern the pattern of "skips" to follow when removing
 * @return the number of stations removed
 */
int removeSome(string outfile_name, LinkedList &stations, int num_remove, vector<int> pattern);

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        cerr << "Usage: " << argv[0] << " stations-file output-one output-two num-remove" << endl;
        cerr << "Exiting." << endl;
        return 1;
    }

    const string stations_filename = argv[1];
    const string output_one_filename = argv[2];
    const string output_two_filename = argv[3];
    const int num_remove = stoi(argv[4]);

    LinkedList stations;

    // Read in all the stations and print
    int numStations = readAllStations(stations_filename, output_one_filename, stations);
    if (numStations == FAIL)
    {
        cerr << "Failed to read and print all stations, exiting" << endl;
        return 1;
    }
    cout << "I just read and inserted " << numStations << " stations" << endl;

    // Get rid of some of the stations
    vector<int> pattern;
    for (int i = 5; i < argc; i++)
    {
        pattern.push_back(stoi(argv[i]));
    }

    int removed = removeSome(output_two_filename, stations, num_remove, pattern);
    if (removed == FAIL)
    {
        cerr << "Failed to remove stations from list and write file,"
             << "exiting" << endl;
        return 1;
    }
    cout << "Removed " << removed << " stations and printed to file" << endl;

    cout << "Done!" << endl;

    return 0;
}

int readAllStations(string stations_filename, string outfile_name, LinkedList &stations)
{
    int counter = 0;

    // Read in original list from file
    ifstream infile;
    infile.open(stations_filename.c_str());
    if (!infile.is_open())
    {
        cerr << "Could not add station from file" << endl;
        return FAIL;
    }

    string stationInfo = "";
    while (getline(infile, stationInfo))
    {
        char accesschar = stationInfo[stationInfo.length() - 1];
        string station_name = stationInfo.substr(0, stationInfo.length() - 2);
        bool access = false;
        if (accesschar == 'Y')
        {
            access = true;
        }
        else
        {
            access = false;
        }
        Station s(station_name, access);
        stations.insertStation(s);
        counter++;
    }

    infile.close();

    // Print the untouched list; it will be in reverse order than we inserted
    ofstream outfile;
    outfile.open(outfile_name.c_str());
    if (!outfile.is_open())
    {
        cerr << "Failed to open file for writing" << endl;
        return FAIL;
    }
    stations.print(outfile);
    outfile.close();
    return counter;
}

int removeSome(string outfile_name, LinkedList &stations, int num_remove, vector<int> pattern)
{
    int actual_removes = 0;
    for (int i = 0; i < num_remove; i++)
    {
        Station s = stations.getNextStation();
        bool reached_end = false;
        for (int j = 1; j < pattern[i % (int)pattern.size()] && !reached_end; j++)
        {
            if (stations.isCurrPosNull())
            {
                reached_end = true;
                break;
            }
            s = stations.getNextStation();
        }
        if (reached_end)
        {
            break;
        }

        stations.removeStation(s);
        actual_removes++;

        if (stations.isCurrPosNull())
        {
            break;
        }
    }

    // Print the truncated list
    ofstream outfile;
    outfile.open(outfile_name.c_str());
    if (!outfile.is_open())
    {
        cerr << "Failed to open file for writing\n";
        return FAIL;
    }
    stations.print(outfile);
    outfile.close();
    return actual_removes;
}
