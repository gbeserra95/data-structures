#include <stdio.h>

#include "../helpers.h"

int main(void) {
    hash *h = create_hash();
    if (h == NULL) {
        printf("Couldn't allocate memory for hash\n");
        return 1;
    }

    insert(h, "Brazil", "+55");
    insert(h, "Brazil", "+55");
    insert(h, "Argentina", "+54");
    insert(h, "Chile", "+55");
    insert(h, "USA", "+00");

    char *country_code = search(h, "Brazil");
    if (country_code != NULL)
        printf("Brazil's country code: %s\n", country_code);

    country_code = search(h, "Argentina");
    if (country_code != NULL)
        printf("Argentina's country code: %s\n", country_code);

    country_code = search(h, "China");
    if (country_code != NULL)
        printf("China's country code: %s\n", country_code);

    country_code = search(h, "Chile");
    if (country_code != NULL)
        printf("Chile's country code: %s\n", country_code);

    update(h, "Chile", "+56");

    country_code = search(h, "Chile");
    if (country_code != NULL)
        printf("Chile's country code: %s\n", country_code);

    update(h, "Canada", "+01");
    delete(h, "Argentina");

    country_code = search(h, "Argentina");
    if (country_code != NULL)
        printf("Argentina's country code: %s\n", country_code);

    destroy_hash(h);
    return 0;
}