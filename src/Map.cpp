#include <iostream>
#include <fstream>
#include "Map.h"

using namespace std;

Map::Map(int numTilesX, int numTilesY)
{
    this->numTilesX = numTilesX;
    this->numTilesY = numTilesY;

    mapMatrix = new char* [numTilesX];
    for(int i=0; i<numTilesX; i++) {
        mapMatrix[i] = new char [numTilesY];
    }

    for(int i=0; i<numTilesX; i++) {
        for(int j=0; j<numTilesY; j++) {
            mapMatrix[i][j] = 'b';
        }
    }
}

Map::~Map()
{
    for(int i=0; i<numTilesX; i++) {
        delete [] mapMatrix[i];
    }
    delete [] mapMatrix;
}

Map::Map(char *filename) {

    ifstream fin;
    fin.open(filename, ios::in);

    if(fin.is_open()) {
        fin >> numTilesX >> numTilesY;

        mapMatrix = new char* [numTilesX];
        for(int i=0; i<numTilesX; i++) {
            mapMatrix[i] = new char [numTilesY];
        }

        while(!fin.eof()) {
            for(int i=0; i<numTilesX; i++) {
                for(int j=0; j<numTilesY; j++) {
                    fin >> mapMatrix[i][j];
                }
            }
        }
        fin.close();
    }

    else cout << "Error opening file: " << filename << endl;
}

void Map::printMatrix() {
    cout << numTilesX << " " << numTilesY << endl;
    for(int i=0; i<numTilesX; i++) {
        for(int j=0; j<numTilesY; j++) {
            cout << mapMatrix[i][j] <<  ' ';

        }
        cout << endl;
    }
}
