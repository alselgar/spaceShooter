#ifndef MAP_H
#define MAP_H


class Map
{
    public:
        Map(int numTilesX, int numTilesY);
        Map(char *filename);
        virtual ~Map();
        int getnumTilesX();
        int getnumTilesY();
        void printMatrix();
    protected:
    private:
        int numTilesX;
        int numTilesY;
        char **mapMatrix;
};

#endif // MAP_H
