// "Copyright [2022] <tblitzcr>"
#include "./test_fun.h"

void identity(S21Matrix* o) {
    int count = 1;
    for (int i = 0; i < o->get_row(); ++i) {
        for (int j = 0; j < o->get_col(); ++j) {
            o->operator()(i, j) = count;
            ++count;
        }
    }
}
