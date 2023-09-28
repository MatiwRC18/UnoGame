#include <iostream>
#include <random>
#include "CImg.h"
using namespace cimg_library;
using namespace std;




int main() {

    
    CImg<unsigned char> fondo("fondo.jpg");
    CImg<unsigned char> fondo2("fondo2.jpg");
    CImg<unsigned char> fondo3("fondo3.jpg");
    CImg<unsigned char> boton_comer("uno_cart.png");

    
    const int ancho_display = 960;
    const int alto_display = 540;

    
    fondo.resize(ancho_display, alto_display);
    fondo2.resize(ancho_display, alto_display);
    fondo3.resize(ancho_display, alto_display);
    boton_comer.resize(121.5, 189);

   
    fondo.blur(3); 
    fondo2.blur(3);

    
    unsigned char yellow[] = { 255, 204, 0 };
    unsigned char orange[] = { 255, 102, 0 };
    unsigned char green[] = { 153, 204, 0 };
    unsigned char black[] = { 0, 0, 0 };
    unsigned char red[] = { 255, 0, 0 };

    
    fondo.draw_rectangle(240, 50, 240 + 480, 50 + 80, orange);

    fondo.draw_rectangle(240, 175, 240 + 480, 175 + 80, yellow);

    fondo.draw_rectangle(230, 303, 250 + 480, 303 + 80, yellow);

    fondo.draw_rectangle(280, 425, 280 + 400, 425 + 52, green);

    fondo.draw_text(287, 72, "ESCOJE EL MODO DE JUEGO", black, 0, 1, 36, "arial"); 

    fondo.draw_text(290, 197, "DOS JUGADORES (PRESS 1)", black, 0, 1, 36, "arial");

    fondo.draw_text(240, 325, "JUGAR VS LA CONSOLA (PRESS 2)", black, 0, 1, 36, "arial");

    fondo.draw_text(358, 435, "Matiw Rivera Cascante", black, 0, 1, 30, "arial");

    
    fondo2.draw_rectangle(277, 223, 300 + 380, 223 + 80, orange);
    fondo2.draw_text(288, 247, "JUGAR UNO (PRESS ENTER)", black, 0, 1, 36, "arial");

    
    fondo3.draw_circle(700, 400, 60, red);
    fondo3.draw_circle(700, 400, 45, yellow);
    fondo3.draw_text(671, 375, "UNO", black, 0, 1, 36, "arial");
    fondo3.draw_text(672, 410, "PRESS 1", black, 0, 1, 15, "arial");
    fondo3.draw_image(200, 150, boton_comer);
    fondo3.draw_text(240, 200, "PRESS C", black, 0, 1, 15, "arial");

    CImg<unsigned char> fullImage("card.png"); 

    int numRows = 8;
    int numCols = 14;
    int cardWidth = 143;
    int cardHeight = 214;
    int newCardWidth = 50; 
    int newCardHeight = 75; 

    int cardCoordinates[8][14][2]; 

    
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            int x = col * cardWidth;
            int y = row * cardHeight;
            cardCoordinates[row][col][0] = x;
            cardCoordinates[row][col][1] = y;
        }
    }

    
    CImg<unsigned char> jugadorUno[7];

    
    CImg<unsigned char> jugadorDos[7];

    
    for (int i = 0; i < 7; i++) {
        mt19937 rng(random_device{}());
        uniform_int_distribution<int> rowRand(0, 7);
        uniform_int_distribution<int> colRand(0, 13);

        int row = rowRand(rng); 
        int col = colRand(rng); 

        int x = cardCoordinates[row][col][0];
        int y = cardCoordinates[row][col][1];

        CImg<unsigned char> croppedImage = fullImage.get_crop(x, y, x + cardWidth - 1, y + cardHeight - 1);

        
        jugadorUno[i] = croppedImage.resize(newCardWidth, newCardHeight);
    }

    
    for (int i = 0; i < 7; i++) {
        mt19937 rng(random_device{}());
        uniform_int_distribution<int> rowRand(0, 7);
        uniform_int_distribution<int> colRand(0, 13);

        int row = rowRand(rng); 
        int col = colRand(rng); 

        int x = cardCoordinates[row][col][0];
        int y = cardCoordinates[row][col][1];

        CImg<unsigned char> croppedImage = fullImage.get_crop(x, y, x + cardWidth - 1, y + cardHeight - 1);

        
        jugadorDos[i] = croppedImage.resize(newCardWidth, newCardHeight);
    }

    
    int displayWidth = 960;
    int displayHeight = 540;

    
    fondo3(displayWidth, displayHeight, 1, 3, 0);

   
    for (int i = 0; i < 7; i++) {
        fondo3.draw_image(0, i * newCardHeight, jugadorUno[i]);
    }

    
    for (int i = 0; i < 7; i++) {
        fondo3.draw_image(displayWidth - newCardWidth, i * newCardHeight, jugadorDos[i]);
    }

    
    CImgDisplay ventana(fondo, "JUEGO UNO");
    ventana.set_key();
    int fondoActual = 1;
    ventana.move(280, 100);

    while (!ventana.is_closed()) {
        ventana.wait();

        if (ventana.key()) {
            char tecla = ventana.key();

            if ((tecla == '1') || (tecla == '2')) {
                ventana.render(fondo2);
                fondoActual = 2;
                ventana.paint();
            }
            if ((tecla == '\r' || tecla == '\n')) {
                ventana.render(fondo3);
                fondoActual = 3;
                ventana.paint();


            }
        }

    }

    return 0;
}