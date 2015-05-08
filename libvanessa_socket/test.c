#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include </usr/include/mysql/mysql.h>
int main(void) {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   int lengths;
  /* Change me */
   char *server = "localhost";
   char *user = "perdition";
   char *password = "123456";
   char *database = "perdition";
   
   conn = mysql_init(NULL);
   
   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
 
   /* send SQL query */
   if (mysql_query(conn, "select keyword from replace_keyword") == 0) {
      res = mysql_store_result( conn );
      if ( res != NULL ){
         //Lay ra so ket qua tra ve
         lengths = mysql_num_rows( res );
         printf( "Retrieved %u rows\n", lengths );
         
         char **arrayString = (char**)malloc(lengths * sizeof(char*));
         int i = 0;

         for (i = 0; i < lengths; i++) {
            arrayString[i] = (char*)malloc(lengths * sizeof(char));
         }

         int index = 0;
         /*In ket qua ra */
         printf("MySQL Tables in mysql database:\n");
         while ((row = mysql_fetch_row(res)) != NULL){
            printf("%s \n", row[0]);
            printf("%d \n", index);
            strcpy(arrayString[index],row[0]);
            index++;
            printf("%d \n", index);
         }
         printf("Printf data from array string:\n");
         for (i = 0; i < index; i++) {
            printf("%s \n", arrayString[i]);
         }   
            
      }
      else
         printf( "Query failed\n" );
   } 
  
 
   
   /* close connection */
   mysql_free_result(res);
   mysql_close(conn);
 
  return 0;
}