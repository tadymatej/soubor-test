#include <stdio.h>

//Definujeme maximální velikost řádku
#define LINE_MAX_LENGTH 100

//Funkce vrací číslo (int) a na vstupu bere dva parametry: 
//                                                  Odkaz na soubor a pole, do kterého se bude ukládat řádek
//Voláme to z main(). Podle tohoto kodu v main() zde f == inputFile a 
//                              resultLine == line1 || line2
int readLine(FILE *f, char resultLine[LINE_MAX_LENGTH]) {
    int znak; //Musí být typu int, protože EOF má hodnotu -1 a char se vleze pouze na intervalu <0, 255>
    resultLine[0] = '\0'; //Inicializujeme řádek na prázdný řetězec
    int len = 0;

    //znak = fgetc(f) Načte znak ze souboru f
    while((znak = fgetc(f)) != EOF) { //Iterujeme dokud nenarazíme na konec souboru
        if(len + 2 >= LINE_MAX_LENGTH) { //Abychom nezapsali na pozici line[100]
            resultLine[len + 1] = '\0'; //Každý řetězec musí být zakončen '\0'
            break;
        }
        resultLine[len] = znak; //Postupně si ukládáme řádek do proměnné line
        if(znak == '\n') {
            resultLine[len + 1] = '\0'; //Každý řetězec musí být zakončen '\0'
            break; //Pokud jsme došli na konec řádku, ukončujeme cyklus
        }
        len++; //Zvýšíme pozici v řádku
    }

    //Volitelně:
    //Zbavíme se zbytku řádku, pokud řádek obsahoval více než 100 znaků
    while((znak != '\n') && (znak = fgetc(f)) != EOF);
    

    return len; //Vrátíme počet přečtených znaků
}

int main(int argc, char **argv) {
    //Otevření souboru pro čtení a uložení do proměnné inputFile
    FILE * inputFile = fopen("inputFile.txt", "r"); 
    if(inputFile == NULL) return 1; //Pokud se soubor nepodařilo otevřít, ukončujeme program

    char line1[LINE_MAX_LENGTH];
    //Voláme funkci, která do len1 uloží délku prvního řádku
    // jako parametry jí předáváme odkaz na soubor inputFile a pole line1
    int len1 = readLine(inputFile, line1);
    printf("radek1=%s", line1);


    char line2[LINE_MAX_LENGTH];
    //Voláme funkci, která do len2 uloží délku druhého řádku
    // jako parametry jí předáváme odkaz na soubor inputFile a pole line2
    int len2 = readLine(inputFile, line2);
    printf("radek1=%s", line2);


    readLine(inputFile, &line2); //inputFile.txt nic neobsahuje, ale program nesmí spadnout
    readLine(inputFile, &line2); //inputFile.txt nic neobsahuje, ale program nesmí spadnout
    

    fclose(inputFile); //Uzavření souboru
}