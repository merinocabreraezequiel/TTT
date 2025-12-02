#include <allegro.h>

int main() {
    // Inicializar Allegro
    allegro_init();
    // Control de entrada de teclado
    install_keyboard();
    // Crear una pantalla de 640x480
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

    // Buffer para dibujar
    BITMAP *buffer = create_bitmap(640, 480);

    // iniciarilzar coordenadas de un rectángulo
    int x1,x2,y1,y2;
    x1=0; x2=0; y1=20; y2=20;

    // BUCLE PRINCIPAL
    while (!key[KEY_ESC]) {
        // Limpiar el buffer
        clear_to_color(buffer, makecol(0, 0, 0));

        // Dibujar un rectángulo relleno con RGB
        rectfill(buffer, x1, y1, x2, y2, makecol(255, 0, 0));
        /* Dibujar con hex
        rectfill(buffer, x1, y1, x2+50, y2+50, 0xFF0000);
        */

        // Actualizar las coordenadas
        //x1 += 2; x2 += 2;
        //if (x1 > 640) { x1 = 0; x2 = 0; }
        if (key[KEY_RIGHT]) { x1 += 2; x2 += 2; }
        if (key[KEY_LEFT])  { x1 -= 2; x2 -= 2; }
        if (x1 < 0) { x1 = 0; x2 = 0; }
        if (x2 > 640) { x2 = 640; x1 = 640 - (x2 - x1); }

        if (key[KEY_DOWN]) { y1 += 2; y2 += 2; }
        if (key[KEY_UP])   { y1 -= 2; y2 -= 2; }
        if (y1 < 0) { y1 = 0; y2 = 0; }
        if (y2 > 480) { y2 = 480; y1 = 480 - (y2 - y1); }
        

        // Copiar el buffer a la pantalla
        blit(buffer, screen, 0, 0, 0, 0, 640, 480);
        //bitmap, destino, sx, sy, dx, dy, w, h)

        // Esperar un poco
        rest(20);
    }
    rectfill(buffer, 100, 100, 200, 200, makecol

    return 0;
}
END_OF_MAIN();
