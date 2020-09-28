#include <curses.h>
WINDOW *ventana;
WINDOW *ventanaTorres;
WINDOW *ventanaAguja1;
WINDOW *ventanaAguja2;
WINDOW *ventanaAguja3;
int main(){
    int MaxY, MaxX, TorreX, TorreY;
    initscr();
    getmaxyx(stdscr, MaxY, MaxX);
    if (!has_colors()){
        endwin();
        return 1;
    } // Fin If
    cbreak();
    noecho();
    nonl();
    intrflush(ventana, FALSE);
    keypad(ventana, TRUE);
    int tecla = 0;
    //tecla = getch();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    int numdisc = 7;
    int cont = 3;
    for (int i = 1; i < numdisc; i++){
        cont = cont + 2;
    } // Fin For
    int** mAguja1 = new int*[numdisc];
    for (int i = 0; i < numdisc; i++){
        mAguja1[i] = new int[cont];
    } // Fin For
    int** mAguja2 = new int*[numdisc];
    for (int i = 0; i < numdisc; i++){
        mAguja2[i] = new int[cont];
    } // Fin For
    int** mAguja3 = new int*[numdisc];
    for (int i = 0; i < numdisc; i++){
        mAguja3[i] = new int[cont];
    } // Fin For
    int izquierda, derecha;
    izquierda = 0;
    derecha = cont - 1;
    for (int i = numdisc - 1; i >= 0; i--){
        for (int j = 0; j < cont; j++){
            if (j >= izquierda && j <= derecha){
                mAguja1[i][j] = 0;
            } else {
                mAguja1[i][j] = 1;
            }// Fin If          
        } // Fin For
        izquierda++;
        derecha--;       
    } // Fin For
    ventana = newwin(MaxY, MaxX - 2, 0, 1);
    TorreY = MaxY - 14;
    TorreX = MaxX - 16;
    ventanaTorres = newwin(TorreY, TorreX, 7, 8);
    int y, x1, x2, x3, mitad;
    y = ( 6 + TorreY) - numdisc;
    mitad = cont / 2;
    x1 = 21 - mitad;
    x2 = (8 + (TorreX / 2)) - mitad;
    x3 = (8 + (TorreX - 13)) - mitad;
    ventanaAguja1 = newwin(numdisc, cont, y, x1);
    ventanaAguja2 = newwin(numdisc, cont, y, x2);
    ventanaAguja3 = newwin(numdisc, cont, y, x3);
    wbkgd(ventana, COLOR_PAIR(1));
    wbkgd(ventanaTorres, COLOR_PAIR(1));
    wbkgd(ventanaAguja1, COLOR_PAIR(1));
    wbkgd(ventanaAguja2, COLOR_PAIR(1));
    wbkgd(ventanaAguja3, COLOR_PAIR(1));
    box(ventana, ACS_VLINE, ACS_HLINE);
    double centro1, centro2, centro3, centro4, centro5, centro6;
    centro1 = (MaxX / 2) - 15.5;
    centro2 = (MaxX / 2) - 16.5;
    centro3 = (MaxX / 2) - 23.5;
    centro4 = (MaxX / 2) - 21.5;
    centro5 = (MaxX / 2) - 8;
    centro6 = (MaxX / 2) - 31;
    mvwprintw(ventana, 0, centro1, " T O R R E S   D E   H A N O I ");
    mvwprintw(ventana, MaxY - 1, centro2, " P R O G R A M A C I O N   I I I ");
    mvwprintw(ventana, MaxY - 3, centro4, "Desarrollado por Monica Castillo (11941017)");   
    mvwprintw(ventana, 3, centro5, "MOVIMIENTO # 000"); 
    for (int i = 0; i < TorreX; i++){
        mvwprintw(ventanaTorres, TorreY - 1, i, "%c", 219);
    } // Fin For
    for (int i = 0; i < MaxY; i++){
        mvwprintw(ventanaTorres, i, TorreX / 2, "%c", 219);
        mvwprintw(ventanaTorres, i, 13, "%c", 219);
        mvwprintw(ventanaTorres, i, TorreX - 13, "%c", 219);
    } // Fin For
    for (int i = 0; i < MaxY; i++){
        mvwprintw(ventanaAguja1, i, cont / 2, "%c", 219);
    } // Fin For
    for (int i = 0; i < MaxY; i++){
        mvwprintw(ventanaAguja2, i, cont / 2, "%c", 219);
    } // Fin For
    for (int i = 0; i < MaxY; i++){
        mvwprintw(ventanaAguja3, i, cont / 2, "%c", 219);
    } // Fin For
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    attrset(COLOR_PAIR(2));
    wattron(ventana, COLOR_PAIR(2));
    wattron(ventanaTorres, COLOR_PAIR(2));
    mvwprintw(ventana, 2, centro3, " MUESTRA DE MOVIMIENTOS NECESARIOS PASO A PASO ");
    mvwprintw(ventana, MaxY - 4, centro6, " Presione cualquier tecla para continuar o ESC para finalizar ");
    mvwprintw(ventanaTorres, TorreY - 1, TorreX / 2, "2");
    mvwprintw(ventanaTorres, TorreY - 1, 13, "1");
    mvwprintw(ventanaTorres, TorreY - 1, TorreX - 13, "3");
    wattroff(ventana, COLOR_PAIR(2));
    wattroff(ventanaTorres, COLOR_PAIR(2));
    int colores = 3;
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(8, COLOR_YELLOW, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    for (int i = 0; i < numdisc; i++){
        for (int j = 0; j < cont; j++){
            if (mAguja1[i][j] == 0){
                if (colores != 9){
                attrset(COLOR_PAIR(colores));
                wattron(ventanaAguja1, COLOR_PAIR(colores));
                mvwprintw(ventanaAguja1, i, j, "%c", 219);    
                } else {
                    colores = 3;
                    attrset(COLOR_PAIR(colores));
                    wattron(ventanaAguja1, COLOR_PAIR(colores));
                    mvwprintw(ventanaAguja1, i, j, "%c", 219);
                } // Fin If                      
            } // Fin If        
        } // Fin For
        wattroff(ventanaAguja1, COLOR_PAIR(colores));
        colores++;  
    } // Fin For
    while(tecla != 27){  
    touchwin(ventana);
    wrefresh(ventana);
    touchwin(ventanaTorres);
    wrefresh(ventanaTorres);
    touchwin(ventanaAguja1);
    wrefresh(ventanaAguja1);
    touchwin(ventanaAguja2);
    wrefresh(ventanaAguja2);
    touchwin(ventanaAguja3);
    wrefresh(ventanaAguja3);;
    tecla = getch();
    }
    endwin(); 
    for (int i = 0; i < numdisc; i++){
        delete[] mAguja1[i];
    } // Fin For
    delete[] mAguja1;
    for (int i = 0; i < numdisc; i++){
        delete[] mAguja2[i];
    } // Fin For
    delete[] mAguja2;
    for (int i = 0; i < numdisc; i++){
        delete[] mAguja3[i];
    } // Fin For
    delete[] mAguja3;
    return 0;
} // Fin Main