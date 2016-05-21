#include <stdlib.h>
#include <string.h>

typedef struct programmer_s programmer_t;

programmer_t * programmer_new();
void programmer_free(programmer_t * self);
void programmer_set(programmer_t * self,char * name, char * surname, char * company, char * language, double rating);
char * programmer_getName(programmer_t * self);
char * programmer_getSurname(programmer_t * self);
char * programmer_getCompany(programmer_t * self);
char * programmer_getLanguage(programmer_t * self);
double  programmer_getRating(programmer_t * self);
char * programmer_toJSON(programmer_t * self);
