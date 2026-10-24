
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#define W 120
#define H 40

char screen[H][W];
float zbuf[H][W];

const char *shades = " .:-=+*#%@";

void clear_buffers(void) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            screen[y][x] = ' ';
            zbuf[y][x] = -1000.0f;
        }
    }

    /* Random background stars */
    for (int i = 0; i < 100; i++) {
        int x = rand() % W;
        int y = rand() % H;

        if (rand() % 3 == 0) {
            screen[y][x] = '.';
        }
    }
}

void put_pixel(int x, int y, float z, float brightness) {
    if (x < 0 || x >= W || y < 0 || y >= H)
        return;

    if (z > zbuf[y][x]) {
        zbuf[y][x] = z;

        int idx = (int)(brightness * 9);

        if (idx < 0) idx = 0;
        if (idx > 9) idx = 9;

        screen[y][x] = shades[idx];
    }
}

void draw_sphere(float cx, float cy, float cz,
                 float r, float rot) {
    float lx = 0.3f;
    float ly = -0.6f;
    float lz = -0.7f;

    float len = sqrtf(lx * lx + ly * ly + lz * lz);

    lx /= len;
    ly /= len;
    lz /= len;

    for (float lat = -1.57f; lat < 1.57f; lat += 0.12f) {
        for (float lon = 0; lon < 6.28f; lon += 0.12f) {
            float nx = cosf(lat) * cosf(lon);
            float ny = sinf(lat);
            float nz = cosf(lat) * sinf(lon);

            /* Rotate the sphere */
            float nx2 = nx * cosf(rot) - nz * sinf(rot);
            float nz2 = nx * sinf(rot) + nz * cosf(rot);

            /* Diffuse lighting */
            float dot = nx2 * lx + ny * ly + nz2 * lz;

            if (dot < 0)
                dot = 0;

            float px = cx + nx2 * r;
            float py = cy + ny * r * 0.5f;
            float pz = cz + nz2 * r;

            /* Perspective projection */
            float ooz = 1.0f / (4.0f + pz);

            int sx = W / 2 + (int)(px * 35 * ooz);
            int sy = H / 2 - (int)(py * 18 * ooz);

            put_pixel(sx, sy, pz, dot);
        }
    }
}

void draw_orbit(float rad_x, float rad_y, float cz) {
    for (float a = 0; a < 6.28f; a += 0.02f) {
        float px = cosf(a) * rad_x;
        float py = sinf(a) * rad_y * 0.5f;
        float pz = cz + sinf(a) * rad_x * 0.2f;

        float ooz = 1.0f / (4.0f + pz);

        int sx = W / 2 + (int)(px * 35 * ooz);
        int sy = H / 2 - (int)(py * 18 * ooz);

        if (sx >= 0 && sx < W && sy >= 0 && sy < H) {
            if (screen[sy][sx] == ' ') {
                screen[sy][sx] = '.';
            }
        }
    }
}

void render(void) {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }

    fflush(stdout);
}

int main(void) {
    srand((unsigned int)time(NULL));

    float angle = 0.0f;

    /* Hide the cursor and clear the terminal */
    printf("\033[?25l\033[2J");

    while (1) {
        printf("\033[H");

        clear_buffers();

        /* Sun */
        draw_sphere(0.0f, 0.0f, -2.0f,
                    1.5f, angle * 0.5f);

        /* Planet 1 */
        draw_sphere(3.5f, 0.5f, -5.0f,
                    0.8f, angle);
        draw_orbit(4.5f, 4.5f, -5.0f);

        /* Planet 2 */
        draw_sphere(-5.5f, -1.0f, -8.0f,
                    1.2f, angle * 1.2f);
        draw_orbit(7.0f, 7.0f, -8.0f);

        /* Planet 3 */
        draw_sphere(8.5f, 2.0f, -12.0f,
                    0.6f, angle * 1.5f);
        draw_orbit(10.0f, 10.0f, -12.0f);

        render();

        usleep(80000);
        angle += 0.05f;
    }

    /* Unreachable in this animation loop */
    printf("\033[?25h");
    return 0;
}
