#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "struct.h"

void parse(char * text, programmer ** p)
{
	cJSON * jList = cJSON_Parse(text);
	if (!jList) {
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return 1;
	}

    int count = cJSON_GetArraySize(jList);
   for (int i = 0; i < count; i++) {
        cJSON * jItem = cJSON_GetArrayItem(jList, i);
        char * name = cJSON_GetObjectItem(jItem, "name")->valuestring;
        char * surname = cJSON_GetObjectItem(jItem, "surname")->valuestring;
        char * birthdate = cJSON_GetObjectItem(jItem, "birthdate")->valuestring;
        cJSON * jGroup = cJSON_GetObjectItem(jItem, "working");
        char * companyName = cJSON_GetObjectItem(jGroup, "company")->valuestring;
        char * position = cJSON_GetObjectItem(jGroup, "position")->valuestring;
        int  hired = cJSON_GetObjectItem(jItem, "hired")->valueint;
        double rating = cJSON_GetObjectItem(jItem, "rating")->valuedouble;
        char * language = cJSON_GetObjectItem(jItem, "language")->valuestring;
        set_progr(p[i],name,surname,birthdate,companyName,position,language,hired,rating);
        cJSON * jProjects = cJSON_GetObjectItem(jItem, "projects");
        int cnt = cJSON_GetArraySize(jProjects);
        for (int j = 0; j < cnt; j++){
           cJSON * pItem = cJSON_GetArrayItem(jProjects, j);
           char * pname = cJSON_GetObjectItem(pItem, "name")->valuestring;
           char * start = cJSON_GetObjectItem(pItem, "started")->valuestring;
           char * release = cJSON_GetObjectItem(pItem, "release")->valuestring;
           int hours = cJSON_GetObjectItem(pItem, "spendHours")->valueint;
           int percent = cJSON_GetObjectItem(pItem, "percent")->valueint;
           set_proj(p[i],pname,start,release,hours,percent,j);

        }
    }
    cJSON_Delete(jList);

}

// gcc main.c cJSON.c -lm
int main() {
	FILE * fr = fopen("Programmers.json", "r");
    char text[10000];
    char line[100];
    int size = 3;
    programmer * p[size];            // create array of struture pointers

    for (int i = 0; i < size; i++){ // fill it
    p[i] = progr_create();
    }
    while(fgets(line, 100, fr) != NULL) {  // read file
        strcat(text, line);
    }
	parse(text,p);                         // to parse json file
	for (int i = 0; i < size; i++){       // to print array of structure
    printf("Programmer %d:\n",i+1);
	prog_print(p[i]);
	}
	for (int i = 0; i < size; i++){
    progr_free(p[i]);
    }
	return 0;
}
