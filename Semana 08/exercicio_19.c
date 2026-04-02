#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int valores19[] = {12, 45, 12, 67, 89, 45, 23};
    int i19, j19, k19, count19, jaImprimiu19;
    printf("Valores duplicados:\n");
    for (i19 = 0; i19 < 7; i19++) {
        count19 = 0;
        for (j19 = 0; j19 < 7; j19++) {
            if (valores19[j19] == valores19[i19]) count19++;
        }
        if (count19 > 1) {
            jaImprimiu19 = 0;
            for (k19 = 0; k19 < i19; k19++) {
                if (valores19[k19] == valores19[i19]) jaImprimiu19 = 1;
            }
            if (jaImprimiu19 == 0)
                printf("Valor %d aparece %d vezes\n", valores19[i19], count19);
        }
    }
return 0;
}