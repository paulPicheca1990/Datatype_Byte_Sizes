#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_console_width() { return 75; }
int get_column_width( int number_of_columns ) { return get_console_width() / number_of_columns; }

char *get_number_format( int width ) {
  char *pre_number_format = " %%-%ds | %%%dd\n";
  char *number_format = (char *)malloc( strlen(pre_number_format) + 1  );
  sprintf(number_format, pre_number_format, width, width - 5);  

  return number_format;
}

char *get_string_format( int width ) {
  char *pre_string_format = " %%-%ds | %%-%ds\n";
  char *string_format = (char *)malloc( strlen(pre_string_format) + 1  );
  sprintf(string_format, pre_string_format, width, width);  

  return string_format;
}

void print_bar() {
  char *bar = "===============================================================================================================================";
  printf( "%.*s\n", get_console_width(), bar );
}

void print_columns( char *columns[],  int number_of_columns ) {
  int column_width = get_column_width(number_of_columns);
  char *string_format = get_string_format(column_width);

  print_bar();
  int index;
  for( index = 0; index < number_of_columns; index+=2 )
    printf( string_format, columns[index], columns[index+1] );
  print_bar();

  free(string_format);
}

void print_datatypes( int column_width ) {
  char *number_format = get_number_format(column_width);  

  printf(number_format, "char", (char *)sizeof(char));
  printf(number_format, "short", (char *)sizeof(short));
  printf(number_format, "int", (char *)sizeof(int));  
  printf(number_format, "long", (char *)sizeof(long));
  printf(number_format, "long long", (char *)sizeof(long long));
  printf(number_format, "float", (char *)sizeof(float));
  printf(number_format, "double", (char *)sizeof(double));
  printf(number_format, "long double", (char *)sizeof(long double));

  free(number_format);  
}

int main( int argc, char * argv[] ) { 
  char *columns[] = { "Datatype", "# of Bytes" };  
  int number_of_columns = (int)sizeof(columns) / sizeof(columns[0]);  
    
  print_columns(columns, number_of_columns);
  print_datatypes(get_column_width(number_of_columns));
  
  return 0;
}