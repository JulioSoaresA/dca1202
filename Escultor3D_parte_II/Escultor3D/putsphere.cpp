#include "putsphere.h"
#include <cmath>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius = radius;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutSphere::~PutSphere(){
}

void PutSphere::draw(Sculptor &s){
    s.setColor(r,g,b,a);

    int px, py, pz;
    double esfera;

    for (pz = zcenter-radius; pz < zcenter+radius; pz++){
        for (py = ycenter-radius; py < ycenter+radius; py++){
            for (px = xcenter-radius; px < xcenter+radius; px++){
                esfera = ((px - xcenter)*(px - xcenter)) + ((py - ycenter)*(py - ycenter)) + ((pz - zcenter)*(pz - zcenter));
                if(esfera <= (radius)*(radius)){
                    s.putVoxel(px,py,pz);
                }
            }
        }
    }
}


//int i, j, k;
//double esfera;
//for(k = 0; k < nz; k++){
//    for(j = 0; j < ny; j++){
//        for(i = 0; i < nx; i++){
//            esfera = ((px - xcenter)*(px - xcenter)) + ((py - ycenter)*(py - ycenter)) + ((pz - zcenter)*(pz - zcenter));
//            if(esfera <= (radius)*(radius)){
//                putVoxel(i, j, k);
//            }
//        }
//    }
//}
