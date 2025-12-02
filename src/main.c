#include <allegro.h>

int main() {
    // Inicializar Allegro
    allegro_init();
    install_keyboard();

    // Configurar modo gráfico (640x480, 16 bits)
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT, 640, 480, 0, 0);

    // Mostrar texto en pantalla
    textout_centre_ex(screen, font, "Hello World - Allegro 4.2.3 - from VSCode",
                      SCREEN_W / 4, SCREEN_H / 4,
                      makecol(2, 255, 7), -1);

    // Esperar a que el usuario presione una tecla
    readkey();

    return 0;
}
END_OF_MAIN();
