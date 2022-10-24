#ifndef SCULPTER_H
#define SCULPTER_H
#include "voxel.h"

class Sculptor {
private:
    Voxel ***v; // 3D matrix
    int nx, ny, nz;
    float r, g, b, a; // Current drawning color

public:
    Sculptor(int _nx, int _ny, int _nz); // Construtor
    ~Sculptor(); // Destrutor

    // Declaração das funções
    void setColor(float r, float g, float b, float a);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeOFF(const char* filename);
};

#endif // SCULPTER_H
