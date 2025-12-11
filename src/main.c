#include "allegro/text.h"
#include <allegro.h>

void draw_vehicle(float vx, float vy, BITMAP *buffer);


int main() {
	// Inicializar Allegro
	allegro_init();
	// Control de entrada de teclado
	install_keyboard();
	// Crear una pantalla de 640x480
	set_color_depth(16);
	set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 320, 240, 0, 0);

	// Buffer para dibujar
	BITMAP *buffer = create_bitmap(320, 240);

	// iniciarilzar coordenadas de un rectángulo
	//int x1,x2,y1,y2;
	//x1=0; x2=20; y1=0; y2=20;

	float vx, vy;
	vx = 50;
	vy = 50;


	// BUCLE PRINCIPAL
	while (!key[KEY_ESC]) {
		// Limpiar el buffer
		clear_to_color(buffer, makecol(0, 0, 0));


		//Texto en pantalla
		textout_centre_ex(buffer, font, "TTT", 50, 10, makecol(255, 0, 0), 0x0000FF);
		// Dibujar un rectángulo relleno con RGB
		//rectfill(buffer, x1, y1, x2, y2, makecol(255, 0, 0));
		/* Dibujar con hex
        rectfill(buffer, x1, y1, x2+50, y2+50, 0xFF0000);
        */

		// Actualizar las coordenadas cuadrado rojo
		//x1 += 2; x2 += 2;
		//if (x1 > 640) { x1 = 0; x2 = 0; }
		/*if (key[KEY_RIGHT]) { x1 += 2; x2 += 2;}
        if (key[KEY_LEFT])  { x1 -= 2; x2 -= 2;}
        if (x1 < 0) { x1 = 0; x2 = 0; }
        if (x2 > 640) { x2 = 640; x1 = 640 - (x2 - x1); }

        if (key[KEY_DOWN]) { y1 += 2; y2 += 2;}
        if (key[KEY_UP])   { y1 -= 2; y2 -= 2;}
        if (y1 < 0) { y1 = 0; y2 = 0; }
        if (y2 > 480) { y2 = 480; y1 = 480 - (y2 - y1); }
        */

		//
		if (key[KEY_RIGHT]) { vx += 2; }
		if (key[KEY_LEFT]) { vx -= 2; }
		if (vx < 0) { vx = 0; }
		if (vx > 640) { vx = 640; }

		if (key[KEY_DOWN]) { vy += 2; }
		if (key[KEY_UP]) { vy -= 2; }
		if (vy < 0) { vy = 0; }
		if (vy > 480) { vy = 480; }

		// Dibujar el vehículo en las coordenadas vx, vy
		draw_vehicle(vx, vy, buffer);

		// Copiar el buffer a la pantalla
		blit(buffer, screen, 0, 0, 0, 0, 320, 240);
		//bitmap, destino, sx, sy, dx, dy, w, h)

		// Esperar un 20milisegundos
		rest(20);
	}

	return 0;
}
END_OF_MAIN();

void draw_vehicle(float vx, float vy, BITMAP *buffer) {
	line(buffer, vx - 30, vy + 5, vx + 30, vy + 5, makecol(255, 0, 0));  // suelo
	line(buffer, vx - 20, vy - 10, vx + 15, vy - 10, makecol(255, 0, 0));// techo
	line(buffer, vx, vy + 5, vx, vy - 10, makecol(255, 0, 0));           // puerta

	line(buffer, vx - 25, vy + 5, vx - 20, vy + 10, makecol(0, 255, 0)); // rueda trasera 1
	line(buffer, vx - 20, vy + 10, vx - 15, vy + 10, makecol(0, 255, 0));// rueda trasera 2
	line(buffer, vx - 15, vy + 10, vx - 10, vy + 5, makecol(0, 255, 0)); // rueda trasera 3

	line(buffer, vx + 10, vy + 5, vx + 15, vy + 10, makecol(0, 0, 255)); // rueda delanera 1
	line(buffer, vx + 15, vy + 10, vx + 20, vy + 10, makecol(0, 0, 255));// rueda delantera 2
	line(buffer, vx + 20, vy + 10, vx + 25, vy + 5, makecol(0, 0, 255)); // rueda delantera 3

	line(buffer, vx - 30, vy, vx - 15, vy, makecol(255, 255, 0));     // ventanilla trasera 1
	line(buffer, vx - 15, vy, vx - 15, vy - 10, makecol(255, 255, 0));// ventanilla trasera 2
	line(buffer, vx - 30, vy, vx - 20, vy - 10, makecol(255, 255, 0));// ventanilla trasera 3

	line(buffer, vx + 10, vy - 10, vx + 10, vy - 5, makecol(255, 0, 255));// ventanilla delantera 1
	line(buffer, vx + 10, vy - 5, vx + 20, vy - 5, makecol(255, 0, 255)); // ventanilla delantera 2
	line(buffer, vx + 25, vy, vx + 15, vy - 10, makecol(255, 0, 255));    // ventanilla delantera 3

	line(buffer, vx - 30, vy + 5, vx - 30, vy, makecol(0, 255, 255));// parachoques trasero

	line(buffer, vx + 30, vy + 5, vx + 30, vy, makecol(128, 128, 128));// parachoques delantero 1
	line(buffer, vx + 30, vy, vx + 25, vy, makecol(128, 128, 128));    // parachoques delantero 1
}