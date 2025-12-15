#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "common.h"
#include "file.h"
#include "parse.h"



void print_usage(char *argv[]) {
  printf("USAGE: %s -n -f <database file>\n", argv[0]);
  printf("\t -n \t- create a new database file\n");
  printf("\t -f \t- (required) path to database file\n");
  printf("\t -l \t- lists all employees\n");
  printf("\t -a \"name,address,hours\" \t- adds a employee\n");
  printf("\t -r \t- enables remove mode\n");
  printf("\t -e \t- enables edit mode\n");
  printf("\t -N \"name\" \t- search by full name\n");
  printf("\t -i \"idex\" \t- search by index\n");
  return;
}

int main(int argc, char *argv[]) {
  int dbfd = -1;
  unsigned int index_to_modify = 0;
  int c;
  char *filepath = NULL;
  char *addstring = NULL;
  char *editstring = NULL;
  char *namestring = NULL;
  char *indexstring = NULL;
  bool newfile = false;
  bool list = false;
  bool removeMode = false;
  struct dbheader_t *dbhdr = NULL;
  struct employee_t *employees = NULL;
  

  while((c = getopt(argc, argv, "nf:a:le:rN:i:")) != -1) {
    switch(c) {
      case 'n':
        newfile = true;
        break;
      case 'f':
        filepath = optarg;
        break;
      case 'a':
        addstring = optarg;
        break;
      case 'e':
        editstring = optarg;
        break;
      case 'r':
        removeMode = true;
        break;
      case 'N':
        namestring = optarg;
        break;
      case 'i':
        indexstring = optarg;
        break;
      case 'l':
        list = true;
        break;
      case '?':
        printf("Unknown option -%c\n", c);
        print_usage(argv);
        break;
      default:
        return -1;
    }
  }

  if (filepath == NULL) {
    printf("Filepath is a required argument\n");
    print_usage(argv);
    return 0;
  }

  if(newfile) {
    dbfd = create_db_file(filepath);
    if(dbfd == STATUS_ERROR) {
      printf("Unable to create database file\n");
      return -1;
    }
    if(create_db_header(&dbhdr) == STATUS_ERROR) {
      printf("Failed to create database header\n");
      return -1;
    }
  } else {
    dbfd = open_db_file(filepath);
    if(dbfd == STATUS_ERROR) {
      printf("Unable to open database file\n");
      return -1;
    }
    if(validate_db_header(dbfd, &dbhdr) == STATUS_ERROR) {
      printf("Failed to validate database header\n");
      return -1;
    }
  }
  if(read_employees(dbfd, dbhdr, &employees) != STATUS_SUCCESS) {
    printf("Failed read employees\n");
    return -1;
  }
  if (addstring) {
    add_employee(dbhdr, &employees, addstring);
  }

  if (list) {
    list_employee(dbhdr, employees);
  }
  if (indexstring) {
    index_to_modify = (unsigned int) atoi(indexstring);
    printf("the index %i \n", index_to_modify);
  } else if (namestring) {
    int status = search_index_by_name(dbhdr, employees, namestring, &index_to_modify);
    if (status == STATUS_NOT_FIND_ERROR) {
      printf("no employee finded\n");  
    }
    if (status <= STATUS_ERROR) {
      return 0;
    }
    printf("the index for \" %s \" is %i\n", namestring, index_to_modify);
  }

  if (index_to_modify > dbhdr->count -1) {
    printf("there are %i employees\n make sure to select a valid index\n from 0 to %i\n", dbhdr->count, dbhdr->count -1);
    return 0;
  }

  if (removeMode) {
    remove_employee(dbhdr, &employees, index_to_modify);
  }
  
  output_file(dbfd, dbhdr, employees);

  return 0;
}