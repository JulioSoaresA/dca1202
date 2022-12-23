#ifndef SCULPTOR_H
#define SCULPTOR_H

#include<iostream>
#include<cstring>

struct Voxel{
    float r,g,b;
    float a;
    bool isOn;
};

class Sculptor{
protected:
    Voxel ***v;
    int nx;
    int ny;
    int nz;
    float r;
    float g;
    float b;
    float a;

public:
    /** \brief Classe contrutora onde as dimensões são inicializadas e a
     *  matriz será alocada dinamicamente
     */
    Sculptor(int _nx, int _ny, int _nz);

    /** \brief Classe destrutora onde a memoria é liberada
     */
    ~Sculptor();

    /** \brief Classe onde é configurado a cor que será usada
     *  @param r Representa a cor vermelha
     *  @param g Representa a cor verde
     *  @param b Representa a cor Azul
     *  @param a Representa o Alpha ou opacidade
     */
    void setColor(float r, float g, float b, float alpha);

    /** \brief Classe onde é criado o Voxel
     *  @param x Representa a coordenada x
     *  @param y Representa a coordenada y
     *  @param z Representa a coordenada z
     */
    void putVoxel(int x, int y, int z);

    /** \brief Classe onde é apagado o Voxel
     *  @param x Representa a coordenada x
     *  @param y Representa a coordenada y
     *  @param z Representa a coordenada z
     */
    void cutVoxel(int x, int y, int z);

    /** \brief Classe cria uma caixa de dimensões x0, x1, y0, y1, z0, z1 herdando diretamenta de FiguraGeometrica
     *  @param x0 Represenca a coordenada de x inicial
     *  @param x1 Representa a coordenada de x final
     *  @param y0 Represenca a coordenada de y inicial
     *  @param y1 Representa a coordenada de y final
     *  @param z0 Represenca a coordenada de z inicial
     *  @param z1 Representa a coordenada de z final
     */
    void putBox(int x0, int x1,int y0, int y1,int z0, int z1);

    /** \brief Classe apaga uma caixa de dimensões x0, x1, y0, y1, z0, z1 herdando diretamenta de FiguraGeometrica
     *  @param x0 Represenca a coordenada de x inicial
     *  @param x1 Representa a coordenada de x final
     *  @param y0 Represenca a coordenada de y inicial
     *  @param y1 Representa a coordenada de y final
     *  @param z0 Represenca a coordenada de z inicial
     *  @param z1 Representa a coordenada de z final
     */
    void cutBox(int x0, int x1,int y0, int y1,int z0, int z1);

    /** \brief Classe apaga uma esfera de centro x, y, z e de raio radius
     *  @param xcenter Representa o centro x da esfera
     *  @param ycenter Representa o centro y da esfera
     *  @param zcenter Representa o centro z da esfera
     *  @param radius Representa o raio da esfera
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    /** \brief Classe apaga uma esfera de centro x, y, z e de raio radius
     *  @param xcenter Representa o centro x da esfera
     *  @param ycenter Representa o centro y da esfera
     *  @param zcenter Representa o centro z da esfera
     *  @param radius Representa o raio da esfera
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /** \brief Classe cria um ellipsoid com dimensões de raios rx, ry e rz com centros x, y e z
     *  @param xcenter Representa o centro x da figura
     *  @param ycenter Representa o centro y da figura
     *  @param zcenter Representa o centro z da figura
     *  @param rx Representa o raio x da figura
     *  @param ry Representa o raio y da figura
     *  @param rz Representa o raio z da figura
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /** \brief Classe apaga um ellipsoid com dimensões de raios rx, ry e rz com centros x, y e z
     *  @param xcenter Representa o centro x da figura
     *  @param ycenter Representa o centro y da figura
     *  @param zcenter Representa o centro z da figura
     *  @param rx Representa o raio x da figura
     *  @param ry Representa o raio y da figura
     *  @param rz Representa o raio z da figura
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void writeVECT(std::string filename);

    /** \brief Classe usada para converter a estrutura criada para um arquivo OFF
     *  para conseguir ser lida por um programa de visualizacão
     */
    void writeOFF(std::string filename);

    /** \brief Verifica se está dentro dos limites
     */
    bool dentroDosLimites(int x, int y, int z);

    /** \brief Inicializa a matriz 3D
     */
    void inicializaMatriz3D();

    /** \brief Printa o Sculptor
     */
    void print_sculptor();
    void otimizar();
};

#endif // SCULPTOR_H
