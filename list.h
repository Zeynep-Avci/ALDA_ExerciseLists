//
//  list.h
//  ALDA_ExerciseLists
//
//  Created by Michael Strommer on 26.04.21.
//

#ifndef list_h
#define list_h

#include <stdio.h>

struct element {
    char data;
    struct element *next;
    struct element *prev;
};

typedef struct element node;
void helloWorld(node **list);
#endif /* list_h */
