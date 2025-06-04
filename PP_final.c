#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definire constante
#define MAX_GAMES 100
#define MAX_NAME_LENGTH 50
#define CONSOLE_MEMORY 1024

// Coduri de culori ANSI simplificate
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

// Structura pentru un joc
typedef struct {
    char nume[MAX_NAME_LENGTH];
    float dimensiune;
    int instalat;
} Joc;

// Variabile globale
Joc jocuri[MAX_GAMES];
int numar_jocuri = 0;
float memorie_folosita = 0;

// Funcție pentru afișare text rapid (fără delay pentru web)
void print_fast(const char* text, const char* color) {
    printf("%s%s%s", color, text, RESET);
    fflush(stdout);
}

// Funcție pentru afișare titlu
void afiseaza_titlu() {
    system("clear");
    print_fast("======================================================\n", CYAN);
    print_fast("           SISTEM GESTIONARE JOCURI CONSOLA          \n", BOLD);
    print_fast("======================================================\n", CYAN);
    printf("\n");
}

// Inițializare jocuri
void initializeaza_jocuri() {
    strcpy(jocuri[0].nume, "Call of Duty Modern Warfare");
    jocuri[0].dimensiune = 175.5;
    jocuri[0].instalat = 1;
    
    strcpy(jocuri[1].nume, "FIFA 24");
    jocuri[1].dimensiune = 65.2;
    jocuri[1].instalat = 1;
    
    strcpy(jocuri[2].nume, "Grand Theft Auto V");
    jocuri[2].dimensiune = 95.8;
    jocuri[2].instalat = 0;
    
    strcpy(jocuri[3].nume, "Red Dead Redemption 2");
    jocuri[3].dimensiune = 120.3;
    jocuri[3].instalat = 0;
    
    strcpy(jocuri[4].nume, "Cyberpunk 2077");
    jocuri[4].dimensiune = 70.5;
    jocuri[4].instalat = 1;
    
    strcpy(jocuri[5].nume, "The Witcher 3");
    jocuri[5].dimensiune = 35.7;
    jocuri[5].instalat = 0;
    
    strcpy(jocuri[6].nume, "Fortnite");
    jocuri[6].dimensiune = 26.8;
    jocuri[6].instalat = 1;
    
    strcpy(jocuri[7].nume, "Minecraft");
    jocuri[7].dimensiune = 4.2;
    jocuri[7].instalat = 0;
    
    strcpy(jocuri[8].nume, "Assassins Creed Valhalla");
    jocuri[8].dimensiune = 110.4;
    jocuri[8].instalat = 0;
    
    strcpy(jocuri[9].nume, "Spider-Man Remastered");
    jocuri[9].dimensiune = 75.6;
    jocuri[9].instalat = 0;
    
    numar_jocuri = 10;
    
    for (int i = 0; i < numar_jocuri; i++) {
        if (jocuri[i].instalat) {
            memorie_folosita += jocuri[i].dimensiune;
        }
    }
}

// Afișare meniu
void afiseaza_meniu() {
    print_fast("\n+---------------------------------------+\n", BLUE);
    print_fast("|              MENIU PRINCIPAL          |\n", BLUE);
    print_fast("+---------------------------------------+\n", BLUE);
    print_fast("| ", BLUE);
    print_fast("1.", GREEN);
    print_fast(" Vizualizeaza jocuri instalate", WHITE);
    print_fast("      |\n", BLUE);
    print_fast("| ", BLUE);
    print_fast("2.", GREEN);
    print_fast(" Vizualizeaza toate jocurile", WHITE);
    print_fast("        |\n", BLUE);
    print_fast("| ", BLUE);
    print_fast("3.", GREEN);
    print_fast(" Instaleaza joc", WHITE);
    print_fast("                     |\n", BLUE);
    print_fast("| ", BLUE);
    print_fast("4.", GREEN);
    print_fast(" Dezinstaleaza joc", WHITE);
    print_fast("                  |\n", BLUE);
    print_fast("| ", BLUE);
    print_fast("5.", GREEN);
    print_fast(" Sorteaza jocuri instalate", WHITE);
    print_fast("          |\n", BLUE);
    print_fast("| ", BLUE);
    print_fast("6.", GREEN);
    print_fast(" Afiseaza info memorie", WHITE);
    print_fast("              |\n", BLUE);
    print_fast("| ", BLUE);
    print_fast("0.", RED);
    print_fast(" Iesire", WHITE);
    print_fast("                             |\n", BLUE);
    print_fast("+---------------------------------------+\n", BLUE);
    print_fast("\nAlegeti o optiune: ", YELLOW);
}

// Afișare jocuri instalate
void afiseaza_jocuri_instalate() {
    afiseaza_titlu();
    print_fast("JOCURI INSTALATE\n", BOLD);
    print_fast("=======================================================\n", MAGENTA);
    
    int gasit = 0;
    for (int i = 0; i < numar_jocuri; i++) {
        if (jocuri[i].instalat) {
            printf("%s%-3d%s", GREEN, gasit + 1, RESET);
            printf("%s| %s%-35s%s", BLUE, CYAN, jocuri[i].nume, RESET);
            printf("%s| %s%6.1f GB%s\n", BLUE, YELLOW, jocuri[i].dimensiune, RESET);
            gasit++;
        }
    }
    
    if (gasit == 0) {
        print_fast("Nu exista jocuri instalate!\n", RED);
    }
    
    printf("\n");
    print_fast("Apasati Enter pentru a continua...", WHITE);
    getchar();
}

// Afișare toate jocurile
void afiseaza_toate_jocurile() {
    afiseaza_titlu();
    print_fast("TOATE JOCURILE DISPONIBILE\n", BOLD);
    print_fast("=======================================================\n", CYAN);
    
    for (int i = 0; i < numar_jocuri; i++) {
        printf("%s%-3d%s", GREEN, i + 1, RESET);
        printf("%s| %s%-35s%s", BLUE, WHITE, jocuri[i].nume, RESET);
        printf("%s| %s%6.1f GB%s", BLUE, YELLOW, jocuri[i].dimensiune, RESET);
        
        if (jocuri[i].instalat) {
            printf("%s| %sINSTALAT%s\n", BLUE, GREEN, RESET);
        } else {
            printf("%s| %sNU E INSTALAT%s\n", BLUE, RED, RESET);
        }
    }
    
    printf("\n");
    print_fast("Apasati Enter pentru a continua...", WHITE);
    getchar();
}

// Instalare jox
void instaleaza_joc() {
    afiseaza_titlu();
    print_fast("INSTALARE JOC\n", BOLD);
    print_fast("=======================================================\n", GREEN);
    
    print_fast("Jocuri disponibile pentru instalare:\n\n", WHITE);
    
    int jocuri_disponibile[MAX_GAMES];
    int count = 0;
    
    for (int i = 0; i < numar_jocuri; i++) {
        if (!jocuri[i].instalat) {
            jocuri_disponibile[count] = i;
            printf("%s%-3d%s", CYAN, count + 1, RESET);
            printf("%s| %s%-35s%s", BLUE, WHITE, jocuri[i].nume, RESET);
            printf("%s| %s%6.1f GB%s\n", BLUE, YELLOW, jocuri[i].dimensiune, RESET);
            count++;
        }
    }
    
    if (count == 0) {
        print_fast("Toate jocurile sunt deja instalate!\n", RED);
        print_fast("Apasati Enter pentru a continua...", WHITE);
        getchar();
        return;
    }
    
    int alegere;
    print_fast("\nAlegeti jocul de instalat (numarul): ", YELLOW);
    scanf("%d", &alegere);
    getchar();
    
    if (alegere < 1 || alegere > count) {
        print_fast("Alegere invalida!\n", RED);
        print_fast("Apasati Enter pentru a continua...", WHITE);
        getchar();
        return;
    }
    
    int index_joc = jocuri_disponibile[alegere - 1];
    
    if (memorie_folosita + jocuri[index_joc].dimensiune > CONSOLE_MEMORY) {
        print_fast("Nu exista suficienta memorie pentru instalare!\n", RED);
        printf("%sMemorie necesara: %.1f GB%s\n", YELLOW, jocuri[index_joc].dimensiune, RESET);
        printf("%sMemorie disponibila: %.1f GB%s\n", YELLOW, CONSOLE_MEMORY - memorie_folosita, RESET);
    } else {
        jocuri[index_joc].instalat = 1;
        memorie_folosita += jocuri[index_joc].dimensiune;
        
        printf("%sJocul '%s' a fost instalat cu succes!%s\n", GREEN, jocuri[index_joc].nume, RESET);
        printf("%sMemorie folosita: %.1f/%.0f GB%s\n", CYAN, memorie_folosita, (float)CONSOLE_MEMORY, RESET);
    }
    
    print_fast("Apasati Enter pentru a continua...", WHITE);
    getchar();
}

// Dezinstalare joc
void dezinstaleaza_joc() {
    afiseaza_titlu();
    print_fast("DEZINSTALARE JOC\n", BOLD);
    print_fast("=======================================================\n", RED);
    
    print_fast("Jocuri instalate:\n\n", WHITE);
    
    int jocuri_instalate[MAX_GAMES];
    int count = 0;
    
    for (int i = 0; i < numar_jocuri; i++) {
        if (jocuri[i].instalat) {
            jocuri_instalate[count] = i;
            printf("%s%-3d%s", CYAN, count + 1, RESET);
            printf("%s| %s%-35s%s", BLUE, WHITE, jocuri[i].nume, RESET);
            printf("%s| %s%6.1f GB%s\n", BLUE, YELLOW, jocuri[i].dimensiune, RESET);
            count++;
        }
    }
    
    if (count == 0) {
        print_fast("Nu exista jocuri instalate!\n", RED);
        print_fast("Apasati Enter pentru a continua...", WHITE);
        getchar();
        return;
    }
    
    int alegere;
    print_fast("\nAlegeti jocul de dezinstalat (numarul): ", YELLOW);
    scanf("%d", &alegere);
    getchar();
    
    if (alegere < 1 || alegere > count) {
        print_fast("Alegere invalida!\n", RED);
        print_fast("Apasati Enter pentru a continua...", WHITE);
        getchar();
        return;
    }
    
    int index_joc = jocuri_instalate[alegere - 1];
    
    jocuri[index_joc].instalat = 0;
    memorie_folosita -= jocuri[index_joc].dimensiune;
    
    printf("%sJocul '%s' a fost dezinstalat cu succes!%s\n", GREEN, jocuri[index_joc].nume, RESET);
    printf("%sMemorie eliberata: %.1f GB%s\n", CYAN, jocuri[index_joc].dimensiune, RESET);
    printf("%sMemorie folosita: %.1f/%.0f GB%s\n", CYAN, memorie_folosita, (float)CONSOLE_MEMORY, RESET);
    
    print_fast("Apasati Enter pentru a continua...", WHITE);
    getchar();
}

// Funcții de comparare pentru sortare
int compara_nume(const void *a, const void *b) {
    Joc *jocA = (Joc *)a;
    Joc *jocB = (Joc *)b;
    return strcmp(jocA->nume, jocB->nume);
}

int compara_dimensiune(const void *a, const void *b) {
    Joc *jocA = (Joc *)a;
    Joc *jocB = (Joc *)b;
    if (jocA->dimensiune < jocB->dimensiune) return -1;
    if (jocA->dimensiune > jocB->dimensiune) return 1;
    return 0;
}

// Sortare jocuri instalate
void sorteaza_jocuri() {
    afiseaza_titlu();
    print_fast("SORTARE JOCURI INSTALATE\n", BOLD);
    print_fast("=======================================================\n", BLUE);
    
    Joc jocuri_instalate[MAX_GAMES];
    int count = 0;
    
    for (int i = 0; i < numar_jocuri; i++) {
        if (jocuri[i].instalat) {
            jocuri_instalate[count] = jocuri[i];
            count++;
        }
    }
    
    if (count == 0) {
        print_fast("Nu exista jocuri instalate pentru sortare!\n", RED);
        print_fast("Apasati Enter pentru a continua...", WHITE);
        getchar();
        return;
    }
    
    print_fast("Criterii de sortare:\n", WHITE);
    print_fast("1. Sortare dupa nume\n", GREEN);
    print_fast("2. Sortare dupa dimensiune\n", GREEN);
    print_fast("\nAlegeti criteriul (1 sau 2): ", YELLOW);
    
    int criteriu;
    scanf("%d", &criteriu);
    getchar();
    
    if (criteriu == 1) {
        qsort(jocuri_instalate, count, sizeof(Joc), compara_nume);
        print_fast("\nJocuri sortate dupa nume:\n", GREEN);
    } else if (criteriu == 2) {
        qsort(jocuri_instalate, count, sizeof(Joc), compara_dimensiune);
        print_fast("\nJocuri sortate dupa dimensiune:\n", GREEN);
    } else {
        print_fast("Criteriu invalid!\n", RED);
        print_fast("Apasati Enter pentru a continua...", WHITE);
        getchar();
        return;
    }
    
    print_fast("=======================================================\n", BLUE);
    
    for (int i = 0; i < count; i++) {
        printf("%s%-3d%s", CYAN, i + 1, RESET);
        printf("%s| %s%-35s%s", BLUE, WHITE, jocuri_instalate[i].nume, RESET);
        printf("%s| %s%6.1f GB%s\n", BLUE, YELLOW, jocuri_instalate[i].dimensiune, RESET);
    }
    
    printf("\n");
    print_fast("Apasati Enter pentru a continua...", WHITE);
    getchar();
}

// Afișare informații memorie
void afiseaza_info_memorie() {
    afiseaza_titlu();
    print_fast("INFORMATII MEMORIE\n", BOLD);
    print_fast("=======================================================\n", CYAN);
    
    float memorie_libera = CONSOLE_MEMORY - memorie_folosita;
    float procent_folosit = (memorie_folosita / CONSOLE_MEMORY) * 100;
    
    printf("%sMemorie totala consola: %s%.0f GB%s\n", WHITE, BOLD, (float)CONSOLE_MEMORY, RESET);
    printf("%sMemorie folosita: %s%.1f GB%s\n", WHITE, RED, memorie_folosita, RESET);
    printf("%sMemorie libera: %s%.1f GB%s\n", WHITE, GREEN, memorie_libera, RESET);
    printf("%sProcent folosit: %s%.1f%%%s\n", WHITE, BLUE, procent_folosit, RESET);
    
    // Bara de progres simplificata
    print_fast("\nBara de progres memorie:\n", WHITE);
    printf("%s[", BLUE);
    int bara_lungime = 50;
    int pozitie = (int)(procent_folosit * bara_lungime / 100);
    
    for (int i = 0; i < bara_lungime; i++) {
        if (i < pozitie) {
            if (procent_folosit > 80) printf("%s#%s", RED, RESET);
            else if (procent_folosit > 60) printf("%s#%s", YELLOW, RESET);
            else printf("%s#%s", GREEN, RESET);
        } else {
            printf("%s-%s", WHITE, RESET);
        }
    }
    printf("%s]%s\n", BLUE, RESET);
    
    int jocuri_instalate_count = 0;
    for (int i = 0; i < numar_jocuri; i++) {
        if (jocuri[i].instalat) jocuri_instalate_count++;
    }
    
    printf("\n%sJocuri instalate: %s%d din %d%s\n", WHITE, MAGENTA, jocuri_instalate_count, numar_jocuri, RESET);
    
    printf("\n");
    print_fast("Apasati Enter pentru a continua...", WHITE);
    getchar();
}

// Funcția principală
int main() {
    initializeaza_jocuri();
    
    int optiune;
    
    do {
        afiseaza_titlu();
        afiseaza_meniu();
        scanf("%d", &optiune);
        getchar();
        
        switch (optiune) {
            case 1:
                afiseaza_jocuri_instalate();
                break;
            case 2:
                afiseaza_toate_jocurile();
                break;
            case 3:
                instaleaza_joc();
                break;
            case 4:
                dezinstaleaza_joc();
                break;
            case 5:
                sorteaza_jocuri();
                break;
            case 6:
                afiseaza_info_memorie();
                break;
            case 0:
                afiseaza_titlu();
                print_fast("La revedere! Multumim ca ati folosit sistemul nostru!\n", GREEN);
                break;
            default:
                print_fast("Optiune invalida! Incercati din nou.\n", RED);
                print_fast("Apasati Enter pentru a continua...", WHITE);
                getchar();
                break;
        }
    } while (optiune != 0);
    
    return 0;
}
