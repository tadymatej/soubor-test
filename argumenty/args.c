#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Main je vstupní bod programu
//Pokud například spustíme program jako: ./args argument1 12 argument2 22 33, 
// potom budou parametry v main následující:
// argc = 6
// **argv = {"./args", "argument1", "12", "argument2", "22", "33"}
//Uvažujme, že náš program, očekává jeden z následujících vstupů: 
// ./argc number1
// ./argc --version
// ./argc number1 --name nameValue
// kde number1 je int hodnota, 
// --name a --version jsou přepínače, které se musí vyskytovat přesně a 
// nameValue je char* hodnota
// 
//Současně program dokáže příjmat znaky ze souboru stdin, poté se program spouští jedním z následujících možností:
//./argc number1 < file.txt
// ./argc --version < file.txt
// ./argc number1 --name nameValue < file.txt
//Kde soubor file.txt bude "přesměrován" do souboru stdin našeho programu
int main(int argc, char **argv) {
    
    if(argc > 4 || argc < 2) { //Více než 4 argumenty jsou chybné spuštění
        fprintf(stderr, "Špatný počet argumentů\n");
        return 1;
    }
    if(strcmp(argv[1], "--version") == 0) { //Na vstupu je --version, vypíšeme verzi
        fprintf(stdout, "Verze: 1.0\n");
    }
    else {
        int number1 = atoi(argv[1]);
        fprintf(stdout, "number1=%d\n", number1);
        if(argc > 2) { //Máme hodně argumentů, tudíž obsluhujeme: ./argc number1 --name nameValue
            if(strcmp(argv[2], "--name") == 0) { // --name bylo nalezeno
                char *nameValue = argv[3];
                fprintf(stdout, "nameValue=%s\n", nameValue);
            } else { // --name nebylo nalezeno, což je chyba
                fprintf(stderr, "Očekával se argument --name\n"); 
                return 1; 
            }
        }
    }
    fprintf(stdout, "Program probehl OK\n");
    fprintf(stdout, "Na vstupu stdin je:\n");
    int znak = 0;
    while((znak = fgetc(stdin)) != EOF) { //Klasická práce se soubory
        fprintf(stdout, "%c", znak);
    }

    return 0;
}