#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct drink {
    char name[32];
    int price;
    struct drink* next;
} drink;

typedef struct pub {
    char name[32];
    drink* price_list;
    struct pub* next;
} pub;

pub* read_pubs(char* name) {
    pub head = {"", NULL, NULL};
    pub** current_pub = &(head.next);
    char buffer[32];
    int price;
    FILE* f = fopen(name, "rt");
    while (fscanf(f, "%31[^\n]\n", buffer) == 1) {
        pub* new_pub = (pub*)malloc(sizeof(pub));
        drink** current_drink;
        strcpy(new_pub->name, buffer);
        new_pub->next = NULL;
        *current_pub = new_pub;
        current_pub = &(new_pub->next);
        new_pub->price_list = NULL;
        current_drink = &(new_pub->price_list);
        while (fscanf(f, "%31[^*.]...%d\n", buffer, &price) == 2) {
            drink* new_drink = (drink*)malloc(sizeof(drink));
            new_drink->price = price;
            strcpy(new_drink->name, buffer);
            new_drink->next = NULL;
            *current_drink = new_drink;
            current_drink = &(new_drink->next);
        }
        fscanf(f, "%*[^\n]\n");
    }
    fclose(f);
    return head.next;
}

pub* find_cheapest(pub *list, char *alc_drink) {
    pub* currentPub = list;
    int minimumPrice = 0;
    pub* bestPub = NULL;
    while(currentPub != NULL) {
        drink* currentDrink = currentPub->price_list;
        while(currentDrink != NULL) {
            if(!strcmp(currentDrink->name, alc_drink) && (currentDrink->price < minimumPrice || minimumPrice == 0)) {
                minimumPrice  = currentDrink->price;
                bestPub = currentPub;
            }
            currentDrink = currentDrink->next;
        }
        currentPub = currentPub->next;
    }
    return bestPub;
}

int main() {
    pub* pubs = read_pubs("pubs.txt");
    pub* bestPub = find_cheapest(pubs, "Gosser Radler");
    printf("%s", bestPub->name);
    return 0;
}