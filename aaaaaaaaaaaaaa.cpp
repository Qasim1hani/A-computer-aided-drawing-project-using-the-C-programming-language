#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

char talk[5][50] = {
    "Hi",
    "Hello",
    "Who is your uncle?",
    "Leo Messi",
    "Indeed it is the best"
};

// ====== «·„‘Âœ «·√”«”Ì »œÊ‰ «·»ÌÊ  (Â–« «··Ì ‰Õ›ŸÂ ﬂŒ·›Ì…) ======
void drawBaseScene() {
    // Sky
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    bar(0, 0, 640, 300);

    // Sun
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(590, 80, 40);
    floodfill(590, 80, YELLOW);

    // Grass („À· ﬂÊœﬂ ﬂ«‰ √»Ì÷)
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 300, 640, 360);
    floodfill(10, 310, WHITE);

    // Road
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, 380, 640, 480);

    // Lane marks
    setfillstyle(SOLID_FILL, WHITE);
    for (int i = 0; i < 640; i += 50) {
        bar(i, 425, i + 40, 435);
    }

    // Side tiles
    int tileSize = 40;
    for (int i = 0; i < 640; i += tileSize) {
        if ((i / tileSize) % 2 == 0) setfillstyle(SOLID_FILL, YELLOW);
        else setfillstyle(SOLID_FILL, BLACK);
        bar(i, 360, i + tileSize, 380);
    }
}

// ====== «·»ÌÊ  ·ÊÕœÂ« (‰—”„Â« ¬Œ— ‘Ì¡ ⁄‘«‰  ﬂÊ‰ ›Êﬁ «·ÿ«∆—…) ======
void drawHouses() {
    setcolor(WHITE);

    // House 1
    setfillstyle(SOLID_FILL, LIGHTRED);
    rectangle(10, 200, 110, 300);
    floodfill(100, 240, WHITE);

    // House 2
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    rectangle(120, 220, 220, 300);
    floodfill(130, 230, WHITE);

    // House 3
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    rectangle(230, 180, 330, 300);
    floodfill(240, 190, WHITE);

    // House 4
    setfillstyle(SOLID_FILL, LIGHTCYAN);
    rectangle(340, 200, 440, 300);
    floodfill(350, 210, WHITE);

    // windows and doors
    setfillstyle(SOLID_FILL, YELLOW);

    // House 1
    bar(30, 220, 50, 240);
    bar(70, 220, 90, 240);
    bar(50, 270, 70, 290);

    // House 2
    bar(140, 240, 160, 260);
    bar(180, 240, 200, 260);
    bar(160, 280, 180, 290);

    // House 3
    bar(250, 200, 270, 220);
    bar(290, 200, 310, 220);
    bar(270, 270, 290, 290);

    // House 4
    bar(360, 220, 380, 240);
    bar(400, 220, 420, 240);
    bar(380, 270, 400, 290);
}

// ====== «·ÿ«∆—… (‰›” ﬂÊœﬂ) ======
void drawPlane(int shift) {
    setcolor(WHITE);

    //Front area
    line(400-shift,100,450-shift,100);
    line(400-shift,100,390-shift,105);
    line(400-shift,110,450-shift,110);
    line(400-shift,110,390-shift,105);

    //TOP FRONT WING
    line(450-shift,100,470-shift,30);
    line(470-shift,30,470-shift,100);

    //BOTTOM FRONT WING
    line(450-shift,110,470-shift,180);
    line(470-shift,180,470-shift,110);

    //REAR AREA
    line(470-shift,100,520-shift,100);
    line(470-shift,110,520-shift,110);

    //TOP REAR WING
    line(520-shift,100,530-shift,70);
    line(530-shift,70,530-shift,100);

    //BOTTOM REAR WING
    line(520-shift,110,530-shift,140);
    line(530-shift,140,530-shift,110);

    //LAST AREA
    line(530-shift,100,535-shift,100);
    line(530-shift,110,535-shift,110);
    line(535-shift,110,535-shift,100);

    // Cyan pass (‰›” ›ﬂ— ﬂ)
    setcolor(CYAN);

    //Front area
    line(400-shift,100,450-shift,100);
    line(400-shift,100,390-shift,105);
    line(400-shift,110,450-shift,110);
    line(400-shift,110,390-shift,105);

    //TOP FRONT WING
    line(450-shift,100,470-shift,30);
    line(470-shift,30,470-shift,100);

    //BOTTOM FRONT WING
    line(450-shift,110,470-shift,180);
    line(470-shift,180,470-shift,110);

    //REAR AREA
    line(470-shift,100,520-shift,100);
    line(470-shift,110,520-shift,110);

    //TOP REAR WING
    line(520-shift,100,530-shift,70);
    line(530-shift,70,530-shift,100);

    //BOTTOM REAR WING
    line(520-shift,110,530-shift,140);
    line(530-shift,140,530-shift,110);

    //LAST AREA
    line(530-shift,100,535-shift,100);
    line(530-shift,110,535-shift,110);
    line(535-shift,110,535-shift,100);
}

// ====== «·—Ã· (‰›” ﬂÊœﬂ) ======
void drawMan(int xOffset) {
    setcolor(BLACK);

    circle(475 + xOffset, 220, 20);
    rectangle(465 + xOffset, 240, 485 + xOffset, 280);

    circle(467 + xOffset, 220, 3);
    circle(483 + xOffset, 220, 3);

    arc(475 + xOffset, 225, 220, 325, 7);

    line(465 + xOffset, 240, 440 + xOffset, 255);
    line(485 + xOffset, 240, 510 + xOffset, 255);
    line(510 + xOffset, 255, 485 + xOffset, 270);
    line(440 + xOffset, 255, 465 + xOffset, 270);

    line(465 + xOffset, 280, 450 + xOffset, 340);
    line(485 + xOffset, 280, 500 + xOffset, 340);
}

// ====== «·ﬂ·«„ (‰›” „‰ÿﬁﬂ) ======
void drawTalk(int idx) {
    settextstyle(3, 0, 2);

    if (idx % 2 == 0) {
        setcolor(WHITE);
        outtextxy(455, 160, talk[idx]);

        setcolor(BLACK);
        line(440 + 100, 255, 420 + 95, 235);
        setcolor(CYAN);
        line(440 + 100, 255, 410 + 95, 245);
    } else {
        setcolor(WHITE);
        outtextxy(250, 50, talk[idx]);

        setcolor(CYAN);
        line(440 + 100, 255, 420 + 95, 235);
        setcolor(BLACK);
        line(440 + 100, 255, 410 + 95, 245);
    }
}

// ====== «·”Ì«—… (‰›” ﬂÊœﬂ) ======
void drawCar(int x, int midy) {
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, RED);

    line(x, midy + 23, x, midy);
    line(x, midy, 40 + x, midy - 20);
    line(40 + x, midy - 20, 80 + x, midy - 20);
    line(80 + x, midy - 20, 100 + x, midy);
    line(100 + x, midy, 120 + x, midy);
    line(120 + x, midy, 120 + x, midy + 23);
    line(0 + x, midy + 23, 18 + x, midy + 23);

    arc(30 + x, midy + 23, 0, 180, 12);
    line(42 + x, midy + 23, 78 + x, midy + 23);
    arc(90 + x, midy + 23, 0, 180, 12);
    line(102 + x, midy + 23, 120 + x, midy + 23);

    line(28 + x, midy, 43 + x, midy - 15);
    line(43 + x, midy - 15, 57 + x, midy - 15);
    line(57 + x, midy - 15, 57 + x, midy);
    line(57 + x, midy, 28 + x, midy);

    line(62 + x, midy - 15, 77 + x, midy - 15);
    line(77 + x, midy - 15, 92 + x, midy);
    line(92 + x, midy, 62 + x, midy);
    line(62 + x, midy, 62 + x, midy - 15);

    floodfill(5 + x, midy + 22, YELLOW);

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, DARKGRAY);
    circle(30 + x, midy + 25, 9);
    circle(90 + x, midy + 25, 9);
    floodfill(30 + x, midy + 25, BLUE);
    floodfill(90 + x, midy + 25, BLUE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int maxx = getmaxx();
    int maxy = getmaxy();

    // 1) «—”„ «·„‘Âœ «·√”«”Ì »œÊ‰ «·»ÌÊ 
    drawBaseScene();

    // 2) «Õ›ŸÂ ﬂŒ·›Ì…
    unsigned int bgSize = imagesize(0, 0, maxx, maxy);
    void *bg = malloc(bgSize);
    if (bg == NULL) {
        closegraph();
        printf("Memory allocation failed!\n");
        return 1;
    }
    getimage(0, 0, maxx, maxy, bg);

    // ===================== «·ÿ«∆—… =====================
    for (int s = 1; s < maxx; s++) {
        putimage(0, 0, bg, COPY_PUT);  // —Ã¯⁄ «·Œ·›Ì…
        drawPlane(s);                 // «—”„ «·ÿ«∆—…
        drawHouses();                 // «—”„ «·»ÌÊ  ›Êﬁ «·ÿ«∆—… (Õ· ≈Œ›«¡ «·—√”)
        delay(10);
    }

    // ===================== «·ÕÊ«— + «·—Ã·Ì‰ =====================
    for (int t = 0; t < 5; t++) {
        putimage(0, 0, bg, COPY_PUT); // —Ã¯⁄ «·Œ·›Ì…
        drawHouses();                 // «·»ÌÊ  À«» … Ê ŸÂ— „‰ «·»œ«Ì…
        drawTalk(t);
        drawMan(0);
        drawMan(100);
        delay(500);
    }

    // ===================== «·”Ì«—… =====================
    int midy = 400;
    while (!kbhit()) {
        for (int x = 0; x < maxx - 130 && !kbhit(); x += 5) {
            putimage(0, 0, bg, COPY_PUT); // Œ·›Ì…
            drawHouses();                 // «·»ÌÊ 
            drawCar(x, midy);             // «·”Ì«—… ›Êﬁ «·ÿ—Ìﬁ
            delay(50);
        }
    }

    getch();
    free(bg);
    closegraph();
    return 0;
}

