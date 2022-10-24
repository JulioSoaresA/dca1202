#include "sculpter.h"
#include <cmath>
#include <fstream>
#include <iostream>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    /**
     * Construtor com argumentos
     */

    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];

    for(int i = 1; i < nz; i++){
        v[i] = v[i-1] + ny;
    }

    for(int i = 1;i < nz*ny; i++){
        v[0][i] = v[0][i - 1] + nx;
    }

    std::cout << "Area da estrutura criada" << std::endl;
}

Sculptor::~Sculptor(){
    /**
     * Destrutor
     */

    delete v[0][0];
    delete v[0];
    delete v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    /**
     * Define a cor
     */

    if(r >= 0 && r <= 1){
        this -> r = r;
    }
    if(g >= 0 && g <= 1){
        this -> g = g;
    }
    if(b >= 0 && b <= 1){
        this -> b = b;
    }
    if(alpha >= 0 && alpha <= 1){
        a = alpha;
    }
}

void Sculptor::putVoxel(int x, int y, int z){
    /**
     * Cria o voxel
     */

    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    /**
     * Desativa um voxel
     */

    v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    /** \brief Cria uma caixa
     *
     * Cria uma caixa nas dimensões de x0 até x1,
     * de y0 até y1 e de z0 até z1
     * e atribui a mesma cor atual de desenho.
     */

    int i, j, k;
    for(k = z0; k < z1; k++){
       for(i = x0; i < x1; i++){
           for(j = y0; j < y1; j++){
               putVoxel(i, j, k);
           }
       }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    /**
     * \brief Desativa voxels dentro de uma caixa
     *
     * Desativa todos os voxels que estão dentro de uma caixa
     * nas dimensões de x0 até x1,
     * de y0 até y1 e de z0 até z1
     */

    int i, j, k;
    for(j = y0; j <= y1; j++){
        for(k = z0; k <= z1; k++){
            for(i = x0; i <= x1; i++){
                cutVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    /**
     * \brief Cria uma esfera
     *
     * Cria uma esfera com centro em xcenter,
     * ycenter, zcenter e de raio radius
     */

    int i, j, k;
    double esfera;
    for(k = 0; k < nz; k++){
        for(j = 0; j < ny; j++){
            for(i = 0; i < nx; i++){
                esfera = ((i - xcenter)*(i - xcenter)) + ((j - ycenter)*(j - ycenter)) + ((k - zcenter)*(k - zcenter));
                if(esfera <= (radius)*(radius)){
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    /**
     * \brief Desativa voxels dentro de uma esfera
     *
     * Desativa todos os voxels que estão dentro de
     * uma esfera de centro xcenter,
     * ycenter, zcenter
     * e raio radius
     */

    int i, j, k;
    double esfera;
    for(k = 0; k < nz; k++){
        for(j = 0; j < ny; j++){
            for(i = 0; i < nx; i++){
                esfera = ((i - xcenter)*(i - xcenter)) + ((j - ycenter)*(j - ycenter)) + ((k - zcenter)*(k - zcenter));
                if(esfera <= (radius)*(radius)){
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    /**
     * \brief Cria um epipsoide
     *
     * Cria um elipsoid com centro em xcenter,
     * ycenter, zcenter e de raios rx,
     * ry e rz
     */

    double elipse;
    if(rx == 0)
    {
        for (int pz = 0; pz <= nz; pz++)
        {
            for (int py = 0; py <= ny; py++)
            {
                elipse = ( pow(py - ycenter,2) / pow(ry,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                if (elipse <= 1)
                {
                    putVoxel(xcenter,py,pz);
                }
            }
        }
    }
    else if(ry == 0)
    {
        for (int pz = 0; pz <= nz; pz++)
        {
            for (int px = 0; px <= nx; px++)
            {
                elipse = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                if (elipse <= 1)
                {
                    putVoxel(px,ycenter,pz);
                }
            }
        }
    }
    else if(rz == 0)
    {
        for (int py = 0; py <= ny; py++)
        {
            for (int px = 0; px <= nx; px++)
            {
                elipse = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(py - ycenter,2) / pow(ry,2) );
                if (elipse <= 1)
                {
                    putVoxel(px,py,zcenter);
                }
            }
        }
    }
    else
    {
        for (int pz = 0; pz <= nz; pz++)
        {
            for (int py = 0; py <= ny; py++)
            {
                for (int px = 0; px <= nx; px++)
                {
                    elipse = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(py - ycenter,2) / pow(ry,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                    if (elipse <= 1)
                    {
                        putVoxel(px,py,pz);
                    }
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    /**
     * \brief Cria um epipsoide
     *
     * Desativa todos os voxels que estão dentro de um elipsoid
     * com centro em xcenter,
     * ycenter, zcenter e de raios rx,
     * ry e rz
     */

    double elipse;
    if(rx == 0)
    {
        for (int pz = 0; pz <= nz; pz++)
        {
            for (int py = 0; py <= ny; py++)
            {
                elipse = ( pow(py - ycenter,2) / pow(ry,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                if (elipse <= 1)
                {
                    cutVoxel(xcenter,py,pz);
                }
            }
        }
    }
    else if(ry == 0)
    {
        for (int pz = 0; pz <= nz; pz++)
        {
            for (int px = 0; px <= nx; px++)
            {
                elipse = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                if (elipse <= 1)
                {
                    cutVoxel(px,ycenter,pz);
                }
            }
        }
    }
    else if(rz == 0)
    {
        for (int py = 0; py <= ny; py++)
        {
            for (int px = 0; px <= nx; px++)
            {
                elipse = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(py - ycenter,2) / pow(ry,2) );
                if (elipse <= 1)
                {
                    cutVoxel(px,py,zcenter);
                }
            }
        }
    }
    else
    {
        for (int pz = 0; pz <= nz; pz++)
        {
            for (int py = 0; py <= ny; py++)
            {
                for (int px = 0; px <= nx; px++)
                {
                    elipse = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(py - ycenter,2) / pow(ry,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                    if (elipse <= 1)
                    {
                        cutVoxel(px,py,pz);
                    }
                }
            }
        }
    }
}


void Sculptor::writeOFF(const char *filename){
    /**
     * Cria o arquivo em formato OFF
     */

    std::ofstream fileOutput;

    fixed(fileOutput);

    int vertices = 0;
    int faces = 0;
    int position = 0;

    // Abre o arquivo com o nome passado
    fileOutput.open(filename);

    // Verifica se foi possivel abrir o arquivo
    if(fileOutput.is_open()){
        std::cout << "Arquivo aberto com sucesso...\nAguarde enquanto o arquivo esta sendo escrito..." << std::endl;
    }
    else{
        std::cout << "Nao foi possível abrir o arquivo." << std::endl;
        exit(EXIT_FAILURE);
    }

    fileOutput << "OFF" << std::endl;//escrevendo o formato do arquivo

    // Quantidade de vertices e faces dos voxels
    for (int px = 0; px < nx; px++){
        for (int py = 0; py < ny; py++){
            for (int pz = 0; pz < nz; pz++){
                if (v[px][py][pz].isOn){
                    vertices += 8;
                    faces += 6;
                }
            }
        }
    }

    // Quantidade de vértices e faces
    fileOutput << vertices << ' ' << faces << ' ' << 0 << std::endl;

    // Posições dos vértices
    for (int px = 0; px < nx; px++){
        for (int py = 0; py < ny; py++){
            for (int pz = 0; pz < nz; pz++){
                if (v[px][py][pz].isOn){
                    fileOutput << (px - 0.5) << ' ' << (py + 0.5) << ' ' << (pz - 0.5) << std::endl;
                    fileOutput << (px - 0.5) << ' ' << (py - 0.5) << ' ' << (pz - 0.5) << std::endl;
                    fileOutput << (px + 0.5) << ' ' << (py - 0.5) << ' ' << (pz - 0.5) << std::endl;
                    fileOutput << (px + 0.5) << ' ' << (py + 0.5) << ' ' << (pz - 0.5) << std::endl;
                    fileOutput << (px - 0.5) << ' ' << (py + 0.5) << ' ' << (pz + 0.5) << std::endl;
                    fileOutput << (px - 0.5) << ' ' << (py - 0.5) << ' ' << (pz + 0.5) << std::endl;
                    fileOutput << (px + 0.5) << ' ' << (py - 0.5) << ' ' << (pz + 0.5) << std::endl;
                    fileOutput << (px + 0.5) << ' ' << (py + 0.5) << ' ' << (pz + 0.5) << std::endl;
                }
            }
        }
    }

    // Conexão dos vertices para formar as faces e cores
    for (int px = 0; px < nx; px++){
        for (int py = 0; py < ny; py++){
            for (int pz = 0; pz < nz; pz++){
                if (v[px][py][pz].isOn){
                    fileOutput << 4 << ' ' << position + 0 << ' ' << position + 3 << ' ' << position + 2 << ' ' << position + 1 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;
                    fileOutput << 4 << ' ' << position + 4 << ' ' << position + 5 << ' ' << position + 6 << ' ' << position + 7 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;
                    fileOutput << 4 << ' ' << position + 0 << ' ' << position + 1 << ' ' << position + 5 << ' ' << position + 4 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;
                    fileOutput << 4 << ' ' << position + 0 << ' ' << position + 4 << ' ' << position + 7 << ' ' << position + 3 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;
                    fileOutput << 4 << ' ' << position + 3 << ' ' << position + 7 << ' ' << position + 6 << ' ' << position + 2 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;
                    fileOutput << 4 << ' ' << position + 1 << ' ' << position + 2 << ' ' << position + 6 << ' ' << position + 5 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;
                    position += 8;
                }
            }
        }
    }

    // Fecha o arquivo
    fileOutput.close();
    std::cout << filename << " foi criado com sucesso!" << std::endl;
}
