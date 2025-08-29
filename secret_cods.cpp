#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "secret_cods.h"
#include "constats.h"

void comand_str_arguments(int amount_arguments, char* mass_with_arguments[],
                            struct secret_code_for_terminal* code_data) {

    assert(code_data);

    for (int i = 1; i < amount_arguments; i++) {

        if (!strcmp(mass_with_arguments[i], is_test)) {
            code_data->is_without_tests = true;
            printf("||Activate mod without tests||\n");
        }

        else if (!strcmp(mass_with_arguments[i], SKN)) {
            code_data->is_master_input = true;
            printf("||Activate God Mod||\n");
        }

        else if (!strcmp(mass_with_arguments[i], Cats)) {
            code_data->poltorashka = true;
        }

        else if (!strcmp(mass_with_arguments[i], test)) {
            code_data->is_standard_work = false;
            printf("||Active only test mod||\n");
        }

        else {
            printf("Sorry, we do not know this code\n");
        }
    }
}
