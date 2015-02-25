/*
********************************************************************************
 $Author: hjaggavarapu $
 $Date: 2013/07/11 21:16:43 $
 $Id: GenSplitter.c,v 1.42 2013/07/11 21:16:43 hjaggavarapu Exp $
 $Name:  $
*********************************************************************************

****************************************************
*                                                  *
* Author: Michael Connolly                         *
* Date: 03/21/07                                   *
* Id: splitter.c, v1.0                             *
*                                                  *
****************************************************
Decription:


Usage:
   GenSplitter Input_File_Name Output_Path Config_File_Name [Config_File_Name]

   0 - success
   1 - failure

   Env variables supported -
     DEBUG - to turn on more outputs from program do export DEBUG=1. DEBUG=2 will
             give you hexidecimal record dumps.
     PRINT_UNKNOWNS - will print out undefined record identifiers. Any value will
                      cause values to be printed.



Notes:

--The Maximum Record Size is 32767.

--You cannot have more than 50 nested levels of BEGIN/END statements.

--The input, header, trailer, and output file names cannot contain more then 150 characters.

--The record indentifer cannot be more than 50 characters long.

--The output file path cannot be more than 150 characters long.

--The output file path and output file name together cannot be
  more then 150 characters long.

--The maximum size of a line in the config file is 1000 characters.

--The maximum size of a value given to a config file variable is 200 characters.


****  Config File Notes  ****

Record Types -

PARENT - If the input file contains records that have more then one format then these
         records should mostly likely need to be written to separate output files.
         A PARENT record type is where you would identify how to identify the different
         record types so that they can be written to different output sets.

VARIABLE - Some records include their length within the record data itself. This information
           can then be used to determine how much data should be read in and written. If the
           record size should change sometime in the future then no programming or config file
           changes would be neccessary.

FIXED - If the record does not contain information about how long it is then this value will
        have to be contained somewhere within the Config file.

Each line that contains a variable definition must start with the variable name, in uppercase
in the first position. An "=" sign should follow the variable name with no space in between
and the value being assigned should follow the "=", also with no space. Characters or
character strings should not be enclosed in any type of quotation marks.
All other lines in the config file should either be comments, which will start with an # sign
in the first position or blank lines.


****  Definition of Terms ****


PEEK SEGMENT - When reading a PARENT or VARIABLE type record you first need to read in just enough
               data so that one can determine what type of record it is or the record length. Once
               the record type and/or record length has been determined the remaining bytes of that
               record will be read and/or written.

ADJUSTMENT - Sometimes the length of a record must be adjusted because sometimes the record length
             that we read from the record itself includes those bytes the contain the length and
             sometimes they do not. Traditionally the length should include the bytes that contain
             the length however TSYS often adds two extra dummy bytes to the end of each record type
             so that the length will equal the number of bytes of the record not including the bytes
             that contain the record size. TSYS is not consistent in the practice so you may have to
             examine the data before making this determination. Another reason this field may be used
             is if the record length is just plain wrong but wrong by the same amount each time.


*********************************************************************************


********************  Configuration File Documentation  *************************



# All positions are based from a Starting position of 1  ( as opposed to 0 ).

# FORMAT - Must be EBCDIC or ASCII. *Required*

FORMAT=<EBCDIC/ASCII>

# MULTIPLE_OCCURANCES - This should be set to true if there are multiple
# header/trailer records for the same file type. The same config file will
# be used for every file. ( Default = False )

MULTIPLE_OCCURANCES=<FALSE/TRUE>

# CUSTOM_MAP_OVERRIDE - This should be set to true if
# a call to an external custom function needs to take place due to
# very special proecssing needs for a particular data segment.
# ( Default = False )

CUSTOM_MAP_OVERRIDE=<FALSE/TRUE>

# CUSTOM_MAP_HDR_TRL_OVERRIDE - This should be set to true if
# a call to an external custom function needs to take place due to
# very special proecssing needs for a particular data segment.
# ( Default = False )

CUSTOM_MAP_HDR_TRL_OVERRIDE=<FALSE/TRUE>

# HEADER_LENGTH - This is the total length of the header record.
# Length of 0 means there is no header ( Default = 0 ).

HEADER_LENGTH=<#>

# HEADER_ID_POSITION - This is the starting position within the
#  header record of where the identifier that tells us that
# "This is a header record" is. ( Default = 1 )

HEADER_ID_POSITION=<#>

# This is the length of the Header record indentifier. ( Default = 0 ).

HEADER_ID_LENGTH=<#>

# HEADER_FILE_NANE - This is the name of the file the header
# record should be written to. If no name is given then the
# record is not written. ( Default = "" )

HEADER_FILE_NAME=<string>

# HEADER_IDENTIFIER - This is the value means that the record
# is a header record. ( Default = "H" )

HEADER_IDENTIFIER=<string>

# TRAILER_ID_POSITION - This is the starting position within the
# header record of where the identifier that tells us that
# "This is a header record" is.
# ( Default = 1 )

TRAILER_ID_POSITION=<#>

# TRAILER_IDENTIFIER - This is the value means that the record is
# a trailer record ( Default = "T" )

TRAILER_IDENTIFIER=<string>

# TRAILER_LENGTH - This is the total length of the trailer record.
# Length of 0 means there is no trailer ( Default = 0 ).

TRAILER_LENGTH=<#>

# TRAILER_ID_LENGTH - This is the length of the Trailer record indentifier.
# ( Default = 0 ).

TRAILER_ID_LENGTH=<#>

# TRAILER_FILE_NAME - This is the name of the file the header record
# should be written to.
# If no name is given then the record is not written.
# ( Default = "" )

TRAILER_PEEK_LENGTH=<#>

TRAILER_FILE_NAME=<string>

BEGIN

# DETAIL_ID_POSITION - This is the starting position within the Peek segment that holds the
# detail type record identifier. ( Default = 0 )

DETAIL_ID_POSITION=<#>

# DETAIL_ID_LENGTH - This is the length of the detail record identifier.
# ( Default = 0 )

DETAIL_ID_LENGTH=<#>

# DETAIL_LENGTH_POSITION - This is the starting position within the
# peek segment that hold the length of the detail record.
# Only variable length segments will have this defined.
# ( Default = -1 )

DETAIL_LENGTH_POSITION=<#>

# DETAIL_LENGTH - This is the default length of the detail records.
# If this is a parent record this value will propogate down to the
# child records if none is explicity assigned for the child record.
# ( Default = 0 )

# DETAIL_LENGTH=<#>

# RECORD_TYPE - This is the type of record it is -
# FIXED, PARENT or VARIABLE. ( Default = FIXED )

RECORD_TYPE=<PARENT/FIXED/VARIABLE>

# DETAIL_PEEK_LEN - If this is a parent record then this would be the
# peek length of any child records. ( Default = 0 ).

DETAIL_PEEK_LENGTH=<#>

# CHILD_PEEK_LENGTH - If all the child records are variable or parent record type then
# this value will be propogated down to all the child records.
#
# ( Default = 0 )

CHILD_PEEK_LENGTH=<#>

# DETAIL_RECORD_LENGTH_ADJ - This is the number of bytes the record length
# must be adjusted due to more than one peek or an incorrect length
# specified within the detail record. ( Default= 0 )

DETAIL_RECORD_LENGTH_ADJ=<#>

# There should be an END specified for every BEGIN.

END


*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "GenSplitter.h"

char in_file_name[150];
FILE *cfg_file_strm;


int print_unknowns;
char format[15];
char load_method[31];
long double tot_bytes_read;
int bytes_read;
char end_of_file;
char found_trailer;
unsigned char in_rec_buf[32767];
int unknown_recs_read;
char multi_occurs;
char ignore_trailing_data;
int tot_recs_read=0;
int tot_recs_writ=0;
int hdr_rec_cnt=0;
int trl_rec_cnt=0;
int custom_map_override=0;
int custom_map_hdr_trl_override=0;
long prcs_id;
char prcs_dt[11];
char ds_config_file_name[151];
unsigned char sqlldr_hdr[20];

struct hdr_trl_rec_type hdr_rec_map,trl_rec_map;

struct dtl_rec_type *start_dtl_rec_map;

void parse_cfg_name_value(char *,char *,char *);
void assign_cfg_values(struct dtl_rec_type *, char *, char *);
void print_cfg_values(struct dtl_rec_type *);
void print_stats();
void process_header(char *);
void process_trailer(char *);
int check_trailer();
void error_msg(char *);
void open_detail_files(struct dtl_rec_type *,char *,char *,int);
struct dtl_rec_type * identify_detail(struct dtl_rec_type *,int,int,int);
void close_files(struct dtl_rec_type *);
void print_cfg_node(struct dtl_rec_type *);
void print_stats_node(struct dtl_rec_type *);
char check_more_bytes();
void initialize_struct(struct dtl_rec_type *);
void process_unknown_rec(struct dtl_rec_type *,int);
void process_parent_rec(struct dtl_rec_type *,int);
void process_fixed_rec(struct dtl_rec_type *,int,int,int);
void process_delimited_rec(struct dtl_rec_type *,int,int,int);
void process_subrecord_rec(struct dtl_rec_type *);
void process_variable_rec(struct dtl_rec_type *,int,int,int,int,int);
void generate_ds_config_file(char *);
void write_dtl_config_file(struct dtl_rec_type *,FILE * );
void print_data(unsigned char *,int);
int str_buf_atoi(unsigned char *,int);
int pd_to_int(unsigned char *,int);
void strncpy_unsigned(unsigned char *,unsigned char *,int);

static char ascii_equiv[256] = {
/* values 0-9 */     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 10-19 */   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 20-29 */   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 30-39 */   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 40-49 */   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 50-59 */   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 60-69 */   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 70-79 */   ' ', ' ', ' ', ' ', ' ', ' ', '<', '(', '+', '|',
/* values 80-89 */   '&', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 90-99 */   '!', '$', '*', ')', ';', ' ', '~', '/', ' ', ' ',
/* values 100-109 */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ',', '%', '_',
/* values 110-119 */ '>', '?', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 120-129 */ ' ', ' ', ':', '#', '@', '\'', '=', '"', ' ', 'a',
/* values 130-139 */ 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', ' ', ' ',
/* values 140-149 */ ' ', ' ', ' ', ' ', ' ', 'j', 'k', 'l', 'm', 'n',
/* values 150-159 */ 'o', 'p', 'q', 'r', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 160-169 */ ' ', ' ', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
/* values 170-179 */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 180-189 */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 190-199 */ ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
/* values 200-209 */ 'H', 'I', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'J',
/* values 210-219 */ 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', ' ', ' ',
/* values 220-229 */ ' ', ' ', ' ', ' ', ' ', ' ', 'S', 'T', 'U', 'V',
/* values 230-239 */ 'W', 'X', 'Y', 'Z', ' ', ' ', ' ', ' ', ' ', ' ',
/* values 240-249 */ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
/* values 250-255 */ ' ', ' ', ' ', ' ', ' ', ' '};

void (*ptr_custom_map)(unsigned char *,struct dtl_rec_type *);

void (*ptr_custom_map_hdr_trl)(unsigned char *,struct hdr_trl_rec_type *,char * );

extern void custom_map(unsigned char *,struct dtl_rec_type *);

extern void custom_map_hdr_trl(unsigned char *,struct hdr_trl_rec_type *,char * );


int main(int argc, char *argv[] ) {

char cfg_file_name[151];
char cfg_line[1001];
char cfg_var_name[51];
char cfg_var_value[201];
int i,j;
struct dtl_rec_type *new_struct_addr;
struct dtl_rec_type *curr_struct;
int depth_level;
int cfg_loop;
char more_bytes=0;
char out_file_path[151];
char debug_level[21];
char num_params;
char prcs_id_str[13];
char primer_flag=0;

struct dtl_rec_type *level_node_addr[50];

if (getenv("DEBUG") == NULL ) {
  debug=0;
}
else {
  strcpy(debug_level,getenv("DEBUG"));
  if (strcmp(debug_level,"1") == 0 )
    debug=1;
  else if (strcmp(debug_level,"2") == 0 )
    debug=2;
  else if (strcmp(debug_level,"3") == 0 )
    debug=3;
  else {
    fprintf(stderr,"Invalid DEBUG value = %s\n",debug_level);
    exit(1);
  }
}
if (getenv("PRINT_UNKNOWNS") == NULL ) {
  print_unknowns=0;
}
else {
  print_unknowns=1;
}

if (argc < 4) {
  fprintf(stderr,"Program Usage: %s Input_File_Name Output_Path Config_File_Name [Config_File_Name] \n\n", argv[0]);
  fprintf(stderr,"Or if you are using SQL Loader with pipes\n\n");
  fprintf(stderr,"Program Usage: %s Input_File_Name Output_Path Config_File_Name <Prcs_Id or PRIMER> \n\n", argv[0]);
  exit (1);
}

fprintf(stderr,"\nExecuting Program: %s\n",argv[0]);

strcpy(in_file_name,argv[1]);
strcpy(out_file_path,argv[2]);

fprintf(stderr,"Input File Name = %s\n",in_file_name);

in_file_strm=fopen64(in_file_name,"rb");
if ( in_file_strm == NULL ) {
  fprintf(stderr,"Error opening Input File %s\n",in_file_name);
  exit(1);
}

num_params=argc;

fprintf(stderr,"num_params = %d\n",argc);

if ( (num_params == 5 ) && ( !strchr(argv[4],46) ) ) {  /* if the 5th param does not have a period then it's the PRCS ID  or Primer*/
  num_params=4;
  if ( strcmp(argv[4],"PRIMER") == 0 ) {
    fprintf(stderr,"Primer Run - Will only create config file\n");
    primer_flag=1;
  }
  else {
    prcs_id=atoi(argv[4]);
    if ( prcs_id == 0 ) {
      fprintf(stderr,"Error converting prcs id to a number. PRCS_ID = %s\n",argv[4]);
      exit(1);
    }
    sprintf(prcs_id_str,"%12d",prcs_id);
    fprintf(stderr,"prcs id = %s\n",prcs_id_str);
  }
}

strcpy(load_method,"DATASTAGE");

for (cfg_loop=3;cfg_loop<num_params;cfg_loop++) {   /* loop through the config file name parameters */

  strcpy(cfg_file_name,argv[cfg_loop]);

  depth_level=0;
  multi_occurs=0;
  ignore_trailing_data=0;
  tot_bytes_read=0;
  end_of_file=0;
  found_trailer=0;
  unknown_recs_read=0;
  strcpy(hdr_rec_map.rec_id,"H");
  hdr_rec_map.rec_id_pos=1;
  hdr_rec_map.date_id_pos=-1;
  hdr_rec_map.rec_id_len=1;
  hdr_rec_map.rec_len=0;
  strcpy(hdr_rec_map.out_file_name,"");
  strcpy(trl_rec_map.rec_id,"T");
  trl_rec_map.rec_id_pos=1;
  trl_rec_map.rec_id_len=1;
  trl_rec_map.rec_len=0;
  trl_rec_map.peek_len=1;
  strcpy(trl_rec_map.out_file_name,"");
  start_dtl_rec_map=NULL;

  for (i=0;i<50;i++) {
    level_node_addr[i]=NULL;
  }

  fprintf(stderr,"Config File Name = %s\n",cfg_file_name);

  cfg_file_strm=fopen(cfg_file_name,"rb");

  if (cfg_file_strm == NULL ) {
  fprintf(stderr,"Error opening Config File\n");
  exit(1);
  }

  while (fscanf(cfg_file_strm,"%[^\n]\n",cfg_line) == 1) {  /* Loop to read config file */

    parse_cfg_name_value(cfg_line,cfg_var_name,cfg_var_value);

    if ( strcmp("BEGIN",cfg_var_name) == 0 ) {
      fprintf(stderr,"Generating New Structure\n");
      depth_level++;
      if ( ( new_struct_addr=(struct dtl_rec_type *) malloc(sizeof(struct dtl_rec_type ))) == NULL ) {
        fprintf(stderr,"Error with Malloc\n");
        exit(1);
      }
      if ( start_dtl_rec_map == NULL ) {
        start_dtl_rec_map=new_struct_addr;
        level_node_addr[1]=new_struct_addr;
      }
      else {
        fprintf(stderr,"Assigning new node\n");
        if ( level_node_addr[depth_level] == NULL ) {
          curr_struct=level_node_addr[depth_level-1];
          curr_struct->child_struct=new_struct_addr;
        }
        else {
          curr_struct=level_node_addr[depth_level];
          curr_struct->next_struct=new_struct_addr;
        }
      level_node_addr[depth_level]=new_struct_addr;
      }

      curr_struct=new_struct_addr;

      initialize_struct(curr_struct);
    }
    else if ( strcmp("END",cfg_var_name) == 0 ) {
      level_node_addr[(--depth_level)+2]=NULL;
    }
    else {
      if (strcmp(cfg_var_name,"COMMENT") != 0 ) {
        assign_cfg_values(curr_struct,cfg_var_name,cfg_var_value);
      }
    }
  }   /* End While Loop - Read Config file */


  if ( start_dtl_rec_map == NULL ) {
    error_msg("There were no detail record definitions. Is there just a header and a trailer?\n");
  }

  if ( depth_level != 0 ) {
    error_msg("The number of BEGIN and END statements are not matching up\n");
  }

  print_cfg_values(start_dtl_rec_map);

  if ( strcmp(ds_config_file_name,"") ) {
    generate_ds_config_file(out_file_path);
  }

  if ( primer_flag ) {
    fprintf(stderr,"Primer Run Complete\n");
    exit(0);
  }

/*  if ( argc > 4 && multi_occurs ) {
    fprintf(stderr,"You can't have multiple occurs turned on and more than one config file passed\n");
    exit(1);
  }*/

  if ( argc == 4 && (strcmp(load_method,"SQLLDR") == 0 ) )  {
    fprintf(stderr,"You need to pass as Process Id if using SQLLDR load method\n");
    exit(1);
  }

  hdr_rec_cnt=0;
  trl_rec_cnt=0;


  if ( hdr_rec_map.rec_len > 0 ) {
    hdr_rec_cnt++;
    if ( debug ) fprintf(stderr,"Processing Header Record\n");
    process_header(out_file_path);
  }


  found_trailer=0;

  open_detail_files(start_dtl_rec_map,out_file_path,"",0);

  while (!end_of_file) {

    if ( debug ) fprintf(stderr,"Reading peek segment\n");
    if ( trl_rec_map.rec_len > 0 ) {
      bytes_read=fread(in_rec_buf,trl_rec_map.peek_len,1,in_file_strm)*trl_rec_map.peek_len;
    }
    else {
      bytes_read=0;
    }

    if ( ( bytes_read > 0 ) || ( trl_rec_map.rec_len == 0 ) ) {
      tot_recs_read++;
      if ( trl_rec_map.rec_len > 0 && check_trailer() ) {
        tot_bytes_read+=trl_rec_map.peek_len;
        trl_rec_cnt++;
        process_trailer(out_file_path);
        found_trailer=1;
        more_bytes=check_more_bytes();
      }
      else {
        if ( debug ) fprintf(stderr,"processing detail\n");
        if ( strcmp(start_dtl_rec_map->rec_type,"FIXED") == 0 ) {
           process_fixed_rec(start_dtl_rec_map,0,0,0);
        }
        else if ( strcmp(start_dtl_rec_map->rec_type,"PARENT") == 0 ) {
        process_parent_rec(start_dtl_rec_map,0);
        }
        else if ( strcmp(start_dtl_rec_map->rec_type,"VARIABLE") == 0 ) {
        process_variable_rec(start_dtl_rec_map,0,0,-1,0,0);
        }
        else if ( strcmp(start_dtl_rec_map->rec_type,"DELIMITED") == 0 ) {
        process_delimited_rec(start_dtl_rec_map,0,0,0);
        }
        else {
          fprintf(stderr,"Start - Unknown Record Type = %s\n",start_dtl_rec_map->rec_type);
          error_msg("\n");
        }
      }
    }
    else {
      if ( bytes_read == 0 && trl_rec_map.rec_len != 0 && hdr_rec_map.rec_len > 0 ) {
        error_msg("Was expecting a trailer but EOF was found first\n");
      }
      else {
        end_of_file=1;
      }
    }

    if ( found_trailer ) {
      if ( more_bytes && multi_occurs ) {
        fprintf(stderr,"There is another file occurance in the file\n");
        if ( hdr_rec_map.rec_len > 0 ) {
          hdr_rec_cnt++;
          process_header(out_file_path);
        }
        found_trailer=0;
      }
      else {
      end_of_file=1;
      }
    }

  } /* end while not eof loop */

  close_files(start_dtl_rec_map);

  if ( hdr_rec_map.rec_len > 0 ) {
    close(hdr_rec_map.file_id);
  }

  if ( trl_rec_map.rec_len > 0 ) {
    close(trl_rec_map.file_id);
  }

  print_stats();

} /* end for loop for config files */

if ( more_bytes ) {
  if ( !ignore_trailing_data ) {
    error_msg("There are still unprocessed bytes in the file");
  }
  else {
    fprintf(stderr,"There are still unprocessed bytes in the file\n");
    fprintf(stderr,"IGNORE TRAILING DATA flag is set so not error is thrown\n");
  }
}

fclose(in_file_strm);

if ( strcmp(ds_config_file_name,"") ) {
  generate_ds_config_file(out_file_path);
}

exit(0);

}  /* End Main */

/*************************************************************************************************************/

void assign_cfg_values(
struct dtl_rec_type *dtl_rec_map,
char *cfg_var_name,
char *cfg_var_value )
{

char i;

if ( strcmp("END",cfg_var_name) == 0 ) {
  fprintf(stderr,"Found End\n");
}
else if ( strcmp("FORMAT",cfg_var_name) == 0 ) {
  strcpy(format,cfg_var_value);
}
else if ( strcmp("MULTIPLE_OCCURANCES",cfg_var_name) == 0 ) {
  multi_occurs=(!strcmp("TRUE",cfg_var_value));
}
else if ( strcmp("IGNORE_TRAILING_DATA",cfg_var_name) == 0 ) {
  ignore_trailing_data=(!strcmp("TRUE",cfg_var_value));
}
else if ( strcmp("DS_CONFIG_FILE_NAME",cfg_var_name) == 0 ) {
  strcpy(ds_config_file_name,cfg_var_value);
}
else if ( strcmp("HEADER_LENGTH",cfg_var_name) == 0 ) {
  hdr_rec_map.rec_len=atoi(cfg_var_value);
}
else if ( strcmp("HEADER_ID_POSITION",cfg_var_name) == 0 ) {
  hdr_rec_map.rec_id_pos=atoi(cfg_var_value)-1;
}
else if ( strcmp("HEADER_DATE_START_POSITION",cfg_var_name) == 0 ) {
  hdr_rec_map.date_id_pos=atoi(cfg_var_value)-1;
}
else if ( strcmp("HEADER_DATE_LENGTH",cfg_var_name) == 0 ) {
  hdr_rec_map.date_id_len=atoi(cfg_var_value);
}
else if ( strcmp("HEADER_IDENTIFIER",cfg_var_name) == 0 ) {
  strcpy(hdr_rec_map.rec_id,cfg_var_value);
}
else if ( strcmp("HEADER_FILE_NAME",cfg_var_name) == 0 ) {
  strcpy(hdr_rec_map.out_file_name,cfg_var_value);
}
else if ( strcmp("HEADER_ID_LENGTH",cfg_var_name) == 0 ) {
  hdr_rec_map.rec_id_len=atoi(cfg_var_value);
}
else if ( strcmp("HEADER_SCHEMA_FILE",cfg_var_name) == 0 ) {
  strcpy(hdr_rec_map.schema_file,cfg_var_value);
}
else if ( strcmp("HEADER_TABLE_NAME",cfg_var_name) == 0 ) {
  strcpy(hdr_rec_map.table_name,cfg_var_value);
}
else if ( strcmp("HEADER_LOAD_JOB_NAME",cfg_var_name) == 0 ) {
  strcpy(hdr_rec_map.load_job_name,cfg_var_value);
}
else if ( strcmp("TRAILER_ID_POSITION",cfg_var_name) == 0 ) {
  trl_rec_map.rec_id_pos=atoi(cfg_var_value)-1;
}
else if ( strcmp("TRAILER_ID_LENGTH",cfg_var_name) == 0 ) {
  trl_rec_map.rec_id_len=atoi(cfg_var_value);
}
else if ( strcmp("TRAILER_IDENTIFIER",cfg_var_name) == 0 ) {
  strcpy(trl_rec_map.rec_id,cfg_var_value);
}
else if ( strcmp("TRAILER_LENGTH",cfg_var_name) == 0 ) {
  trl_rec_map.rec_len=atoi(cfg_var_value);
}
else if ( strcmp("TRAILER_FILE_NAME",cfg_var_name) == 0 ) {
  strcpy(trl_rec_map.out_file_name,cfg_var_value);
}
else if ( strcmp("TRAILER_PEEK_LENGTH",cfg_var_name) == 0 ) {
  trl_rec_map.peek_len=atoi(cfg_var_value);
}
else if ( strcmp("TRAILER_SCHEMA_FILE",cfg_var_name) == 0 ) {
  strcpy(trl_rec_map.schema_file,cfg_var_value);
}
else if ( strcmp("TRAILER_TABLE_NAME",cfg_var_name) == 0 ) {
  strcpy(trl_rec_map.table_name,cfg_var_value);
}
else if ( strcmp("TRAILER_LOAD_JOB_NAME",cfg_var_name) == 0 ) {
  strcpy(trl_rec_map.load_job_name,cfg_var_value);
}
else if ( strcmp("IDENTIFIER",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->rec_id,cfg_var_value);
}
else if ( strcmp("DETAIL_LENGTH",cfg_var_name) == 0 ) {
  dtl_rec_map->in_rec_len=atoi(cfg_var_value);
}
else if ( strcmp("OUT_LENGTH",cfg_var_name) == 0 ) {
  dtl_rec_map->out_rec_len=atoi(cfg_var_value);
}
else if ( strcmp("RECORD_TYPE",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->rec_type,cfg_var_value);
}
else if ( strcmp("DETAIL_PEEK_LENGTH",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_peek_len=atoi(cfg_var_value);
}
else if ( strcmp("FILE_NAME",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->out_file_name,cfg_var_value);
}
else if ( strcmp("DETAIL_LENGTH_POSITION",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_len_pos=atoi(cfg_var_value)-1;
}
else if ( strcmp("DETAIL_ID_POSITION",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_id_pos=atoi(cfg_var_value)-1;
}
else if ( strcmp("DETAIL_LENGTH_LENGTH",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_len_len=atoi(cfg_var_value);
}
else if ( strcmp("DETAIL_OCCURS_POSITION",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_occurs_pos=atoi(cfg_var_value)-1;
}
else if ( strcmp("DETAIL_OCCURS_LENGTH",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_occurs_seg_len=atoi(cfg_var_value);
}
else if ( strcmp("DETAIL_OCCURS_DATATYPE",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->dtl_occurs_datatype,cfg_var_value);
}
else if ( strcmp("DETAIL_LENGTH_DATATYPE",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->dtl_len_datatype,cfg_var_value);
}
else if ( strcmp("DETAIL_ID_LENGTH",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_id_len=atoi(cfg_var_value);
}
else if ( strcmp("DETAIL_PEEK_LENGTH",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_peek_len=atoi(cfg_var_value);
}
else if ( strcmp("CHILD_PEEK_LENGTH",cfg_var_name) == 0 ) {
  dtl_rec_map->child_peek_len=atoi(cfg_var_value);
}
else if ( strcmp("DETAIL_RECORD_LENGTH_ADJ",cfg_var_name) == 0 ) {
  dtl_rec_map->dtl_rec_len_adj=atoi(cfg_var_value);
}
else if ( strcmp("DETAIL_SCHEMA_FILE",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->schema_file,cfg_var_value);
}
else if ( strcmp("DETAIL_TABLE_NAME",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->table_name,cfg_var_value);
}
else if ( strcmp("DETAIL_SUM_COLUMN",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->sum_column,cfg_var_value);
}
else if ( strcmp("DETAIL_GROUP_COLUMN",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->group_column,cfg_var_value);
}
else if ( strcmp("DETAIL_RECORD_TYPE",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->record_type,cfg_var_value);
}
else if ( strcmp("DETAIL_LOAD_JOB_NAME",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->load_job_name,cfg_var_value);
}
else if ( strcmp("DETAIL_FILE_SUM_COLUMN",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->detail_sum_column,cfg_var_value);
}
else if ( strcmp("DETAIL_TRAILER_SUM_COLUMN",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->trailer_sum_column,cfg_var_value);
}
else if ( strcmp("DETAIL_ERROR_TOLERANCE_COUNT",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->error_tolerance_count,cfg_var_value);
}
else if ( strcmp("DETAIL_TRAILER_COUNT_COLUMN",cfg_var_name) == 0 ) {
  strcpy(dtl_rec_map->trailer_count_column,cfg_var_value);
}
else if ( strcmp("CUSTOM_MAP_OVERRIDE",cfg_var_name) == 0 ) {
  custom_map_override=(!strcmp("TRUE",cfg_var_value));
}
else if ( strcmp("CUSTOM_MAP_HDR_TRL_OVERRIDE",cfg_var_name) == 0 ) {
  custom_map_hdr_trl_override=(!strcmp("TRUE",cfg_var_value));
}
else if ( strcmp("DUPLICATE_FILE_FLAG",cfg_var_name) == 0 ) {
  dtl_rec_map->dup_file_flag=(!strcmp("TRUE",cfg_var_value));
}
else if ( strcmp("LOAD_METHOD",cfg_var_name) == 0 ) {
  strcpy(load_method,cfg_var_value);
}
else if ( strcmp("ETC_DIR",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("BIN_DIR",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("PRCS_ID",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("SCHEMA_NAME",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("PROCESS_NAME",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("HEADER_DATE_FORMAT",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("ORIGINAL_FILE_NAME",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("DEV_ORIGINAL_FILE_NAME",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("QA_ORIGINAL_FILE_NAME",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("PROD_ORIGINAL_FILE_NAME",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("FILE_ID_START_POSITION",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("FILE_ID_LENGTH",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("GENSPLITTER_SPLIT_PROGRAM",cfg_var_name) == 0 ) {
  i=1;
}
else if ( strcmp("PIPE_FILE",cfg_var_name) == 0 ) {
  dtl_rec_map->pipe_file_flag=(!strcmp("TRUE",cfg_var_value));
}
else {
  fprintf(stderr,"Unknown Variable %s found in Config File\n",cfg_var_name);
  exit(1);
}

}

char check_more_bytes() {

char test_byte;

if ( fread(&test_byte,1,1,in_file_strm)) {
  if ( fseeko64(in_file_strm,(long long) -1,SEEK_CUR) != NULL ) {
    error_msg("Problem moving back one byte\n");
  }
  return(1);
}
else {
  return(0);
}

}
/*************************************************************************************************************/


int check_trailer() {

char rec_id[11];
char i;

if ( trl_rec_map.rec_len == 0 ) {
  return(0);
}

if ( strcmp(format,"EBCDIC") == 0 ) {
  for (i=0;i<trl_rec_map.rec_id_len;i++)
    rec_id[i]=ascii_equiv[*(in_rec_buf+trl_rec_map.rec_id_pos+i)];
}
else {
  for (i=0;i<trl_rec_map.rec_id_len;i++)
    rec_id[i]=*(in_rec_buf+trl_rec_map.rec_id_pos+i);
}
rec_id[trl_rec_map.rec_id_len]='\0';

if (strcmp(rec_id,trl_rec_map.rec_id) == 0 ) {
  fprintf(stderr,"Trailer found\n");
  return(1);
}
else {
  fseeko64(in_file_strm,(long long) (trl_rec_map.peek_len*-1),SEEK_CUR);
  return(0);
}

}
/*************************************************************************************************************/


void close_files(struct dtl_rec_type *curr_struct)
{

if ( strcmp(curr_struct->out_file_name,"" ) != 0 ) {
  close(curr_struct->out_file_id);
}

if ( curr_struct->child_struct != NULL ) {
  close_files(curr_struct->child_struct);
}
if ( curr_struct->next_struct != NULL ) {
  close_files(curr_struct->next_struct);
}

}

void error_msg(char *msg_text)
{

fprintf(stderr,"Error Message:\n\n");

fprintf(stderr,"%s\n\n",msg_text);

fprintf(stderr,"Total bytes read = %15.0Lf\n",tot_bytes_read);
fprintf(stderr,"Aborting processing....");

exit(1);

}
/*************************************************************************************************************/

struct dtl_rec_type * identify_detail(
  struct dtl_rec_type *start_addr,
  int dtl_id_len,
  int dtl_id_pos,
  int curr_peek_start_pos
)
{

struct dtl_rec_type *next_addr;
struct dtl_rec_type *curr_struct;
int i;
char rec_id[100];

next_addr=start_addr;

if ( debug ) fprintf(stderr,"Started identify\n");

while ( next_addr != NULL ) {
  curr_struct=next_addr;

  if ( strcmp(format,"EBCDIC") == 0 ) {
    for (i=0;i<dtl_id_len;i++)
      rec_id[i]=ascii_equiv[*(in_rec_buf+dtl_id_pos+curr_peek_start_pos+i)];
  }
  else {
    for (i=0;i<dtl_id_len;i++) {
      if ( *(in_rec_buf+dtl_id_pos+curr_peek_start_pos+i) != 32 || ( i == 0) )  /* If its a one character blank we don't want to strip */
        rec_id[i]=*(in_rec_buf+dtl_id_pos+curr_peek_start_pos+i);
      else
        rec_id[i]='\0';
    }
  }
  rec_id[dtl_id_len]='\0';

  if ( debug ) fprintf(stderr,"Comparing %s with %s\n",rec_id,curr_struct->rec_id);

  if ( strcmp(rec_id,curr_struct->rec_id) == 0 ) {
    return(curr_struct);
  }

  next_addr=curr_struct->next_struct;
}

/* If the record identifier didn't match any record types then check to see if there is a
   catch all identifer ( UNDEFINED ) so the records will be written to that output */

if ( debug ) fprintf(stderr,"Looking for a catch all output ( UNDEFINED )\n");

next_addr=start_addr;

while ( next_addr != NULL ) {

  curr_struct=next_addr;

  if ( debug ) fprintf(stderr,"Comparing UNDEFINED with %s\n",curr_struct->rec_id);

  if ( strcmp(curr_struct->rec_id,"UNDEFINED") == 0 ) {
    return(curr_struct);
  }

next_addr=curr_struct->next_struct;

}


if ( debug ) fprintf(stderr,"Returning Null\n");
if ( print_unknowns ) fprintf(stderr,"Unknown identifier = %s\n",rec_id);

return(NULL);

}
/*************************************************************************************************************/


void initialize_struct(struct dtl_rec_type *new_struct)
{

new_struct->next_struct=NULL;
new_struct->child_struct=NULL;
strcpy(new_struct->rec_id,"");
new_struct->in_rec_len=0;
new_struct->out_rec_len=0;
new_struct->dtl_peek_len=0;
new_struct->dtl_rec_len_adj=0;
new_struct->dtl_len_pos=-1;
new_struct->dtl_id_pos=-1;
new_struct->dtl_occurs_seg_len=1;
new_struct->dtl_len_len=2;
strcpy(new_struct->dtl_len_datatype,"BINARY");
new_struct->dtl_id_len=0;
new_struct->recs_read=0;
new_struct->recs_writ=0;
strcpy(new_struct->error_tolerance_count,"0");
new_struct->out_file_id=NULL;
strcpy(new_struct->out_file_name,"");
strcpy(new_struct->rec_type,"FIXED");
new_struct->pipe_file_flag=1;
new_struct->dup_file_flag=0;


return;
}
/*************************************************************************************************************/

void open_detail_files( struct dtl_rec_type *curr_struct,char *file_path,char *prev_file_name,int prev_file_id)
{

char full_file_name[151];

if ( strlen(curr_struct->out_file_name) > 0 ) {
  if (strcmp(curr_struct->out_file_name,prev_file_name) == 0 ) {
    curr_struct->out_file_id=prev_file_id;
  }
  else {
    strcpy(full_file_name,file_path);
    strcat(full_file_name,"/");
    strcat(full_file_name,curr_struct->out_file_name);
    if ( debug ) fprintf(stderr,"opening file = %s\n",full_file_name);
    if ( ( strcmp(load_method,"SQLLDR") == 0 ) && curr_struct->pipe_file_flag ) {
      if ( ( curr_struct->out_file_id=open(full_file_name,O_WRONLY,00744)) <= 0 ) {
        fprintf(stderr,"Error opening detail output file %s\n",full_file_name);
        exit(1);
      }
    }
    else {
      if ( ( curr_struct->out_file_id=open64(full_file_name,O_WRONLY|O_CREAT|O_TRUNC,00744)) <= 0 ) {
        fprintf(stderr,"Error opening detail output file %s\n",full_file_name);
        exit(1);
      }
    }
    if ( debug ) fprintf(stderr,"opened file = %s with file id = %d\n",full_file_name,curr_struct->out_file_id);
  }
}

if ( curr_struct->child_struct != NULL ) {
  open_detail_files(curr_struct->child_struct,file_path,"",0);
}
if ( curr_struct->next_struct != NULL ) {
  open_detail_files(curr_struct->next_struct,file_path,curr_struct->out_file_name,curr_struct->out_file_id);
}

return;

}
/*************************************************************************************************************/

void parse_cfg_name_value(
char *cfg_line,
char *cfg_var_name,
char *cfg_var_value)
{
char cfg_line_len;
int i;

fprintf(stderr,"Line = %s\n",cfg_line);

if (strncmp("BEGIN",cfg_line,5) == 0 ) {
 strcpy(cfg_var_name,"BEGIN");
 return;
}

if (strncmp("END",cfg_line,3) == 0 ) {
 strcpy(cfg_var_name,"END");
 return;
}

if (( strncmp("#",cfg_line,1) == 0 ) || (strncmp("\0",cfg_line,1) == 0 )) {
 strcpy(cfg_var_name,"COMMENT");
 return;
}

i=-1;

while ( (*(cfg_line+(++i)) != ' ') && (*(cfg_line+i) != '\0') );

/* fprintf(stderr,"i = %d %d %d\n",i,*(cfg_line+i),*(cfg_line+i)); */

*(cfg_line+i)='\0';

cfg_line_len=strlen(cfg_line);

i=-1;

while ( (*(cfg_line+(++i)) != '=') && (*(cfg_line+i) != '\0') );

if (i == cfg_line_len) {
  fprintf(stderr,"Equal sign not found on Config file line\n");
  fprintf(stderr,"Config File line = %s\n",cfg_line);
  exit(1);
}

strncpy(cfg_var_name,cfg_line,i);
*(cfg_var_name+i)='\0';

strcpy(cfg_var_value,cfg_line+i+1);

if (strcmp(cfg_var_value,"BLANK")==0) {
  strcpy(cfg_var_value," ");
}

}
/*************************************************************************************************************/

void print_cfg_node(struct dtl_rec_type *curr_struct)
{

fprintf(stderr,"\nrec id  = %s\n",curr_struct->rec_id);
fprintf(stderr,"dtl peek len = %d\n",curr_struct->dtl_peek_len);
fprintf(stderr,"child peek len = %d\n",curr_struct->child_peek_len);
fprintf(stderr,"in rec len = %d\n",curr_struct->in_rec_len);
fprintf(stderr,"out rec len = %d\n",curr_struct->out_rec_len);
fprintf(stderr,"out file name = %s\n",curr_struct->out_file_name);
fprintf(stderr,"out file id = %d\n",curr_struct->out_file_id);
fprintf(stderr,"rec type = %s\n",curr_struct->rec_type);
fprintf(stderr,"adj len = %d\n",curr_struct->dtl_rec_len_adj);
fprintf(stderr,"dtl id pos = %d\n",curr_struct->dtl_id_pos);
fprintf(stderr,"dtl occurs seg len = %d\n",curr_struct->dtl_occurs_seg_len);
fprintf(stderr,"dtl len len = %d\n",curr_struct->dtl_len_len);
fprintf(stderr,"dtl len datatype = %s\n",curr_struct->dtl_len_datatype);
fprintf(stderr,"dtl occurs datatype = %s\n",curr_struct->dtl_occurs_datatype);
fprintf(stderr,"dtl id len = %d\n",curr_struct->dtl_id_len);
fprintf(stderr,"dtl occurs pos = %d\n",curr_struct->dtl_occurs_pos);
fprintf(stderr,"dtl len pos = %d\n",curr_struct->dtl_len_pos);
fprintf(stderr,"record type = %s\n",curr_struct->record_type);
fprintf(stderr,"table name = %s\n",curr_struct->table_name);
fprintf(stderr,"schema file = %s\n",curr_struct->schema_file);
fprintf(stderr,"sum column = %s\n",curr_struct->sum_column);
fprintf(stderr,"group column = %s\n",curr_struct->group_column);



if ( curr_struct->child_struct != NULL ) {
  print_cfg_node(curr_struct->child_struct);
}
if ( curr_struct->next_struct != NULL ) {
  print_cfg_node(curr_struct->next_struct);
}

return;

}
/*************************************************************************************************************/

void print_cfg_values(struct dtl_rec_type *start_struct)

{

fprintf(stderr,"format = %s\n", format);
fprintf(stderr,"load method = %s\n", load_method);
fprintf(stderr,"multi occurs = %d\n",multi_occurs);
fprintf(stderr,"ds config file = %s\n",ds_config_file_name);
fprintf(stderr,"custom map override = %d\n",custom_map_override);
fprintf(stderr,"custom map hdr trl override = %d\n",custom_map_hdr_trl_override);

fprintf(stderr,"\nheader rec_len = %d\n", hdr_rec_map.rec_len);
fprintf(stderr,"header id pos = %d\n",hdr_rec_map.rec_id_pos);
fprintf(stderr,"header dt pos = %d\n",hdr_rec_map.date_id_pos);
fprintf(stderr,"header dt len = %d\n",hdr_rec_map.date_id_len);
fprintf(stderr,"header rec id = %s\n",hdr_rec_map.rec_id);
fprintf(stderr,"header id len = %d\n", hdr_rec_map.rec_id_len);
fprintf(stderr,"header file nm = %s\n",hdr_rec_map.out_file_name);
fprintf(stderr,"header table name = %s\n",hdr_rec_map.table_name);
fprintf(stderr,"header schema file = %s\n\n",hdr_rec_map.schema_file);

fprintf(stderr,"\ntrailer rec_len = %d\n", trl_rec_map.rec_len);
fprintf(stderr,"trailer id pos = %d\n",trl_rec_map.rec_id_pos);
fprintf(stderr,"trailer rec id = %s\n",trl_rec_map.rec_id);
fprintf(stderr,"trailer id len = %d\n", trl_rec_map.rec_id_len);
fprintf(stderr,"trailer file nm = %s\n",trl_rec_map.out_file_name);
fprintf(stderr,"trailer table name = %s\n",trl_rec_map.table_name);
fprintf(stderr,"trailer schema file = %s\n",trl_rec_map.schema_file);

if ( start_struct != NULL ) {
  print_cfg_node(start_struct);
}

}

/*************************************************************************************************************/


void print_stats() {

if ( start_dtl_rec_map != NULL ) {
  print_stats_node(start_dtl_rec_map);
}

fprintf(stderr,"\ntotal bytes read = %15.0Lf\n",tot_bytes_read);
fprintf(stderr,"total unknown records read = %d\n",unknown_recs_read);
fprintf(stderr,"total records read = %d\n",tot_recs_read);
fprintf(stderr,"total records written = %d\n",tot_recs_writ);

}
/*************************************************************************************************************/

void print_stats_node(struct dtl_rec_type *curr_struct)
{

fprintf(stderr,"record id - %s table_name - %s  records read = %d   records written = %d\n",curr_struct->rec_id,curr_struct->table_name,curr_struct->recs_read,curr_struct->recs_writ);

if ( curr_struct->child_struct != NULL ) {
  print_stats_node(curr_struct->child_struct);
}
if ( curr_struct->next_struct != NULL ) {
  print_stats_node(curr_struct->next_struct);
}

return;

}
/*************************************************************************************************************/

/* Note: The variables dtl_id_pos, dtl_id_len, peek_len and dtl_len_pos come from the parent node
         and cannot be overriden by the values in the current node. The other variables
         which are prefixed with def_ - "default" may be overriden with the values in the current node.  */

void process_fixed_rec(
  struct dtl_rec_type *dtl_map_addr,
  int def_dtl_len,
  int accum_peek_len,
  int def_rec_len_adj
)

{

struct dtl_rec_type *child_map_addr;
int in_rec_len;
int local_rec_len_adj=0;
int remaining_dtl_bytes;
int additional_bytes;
/* int bytes_to_write;  change to global variable because it can get changed in custom_map function */
struct dtl_rec_type *child_struct;

if ( debug ) fprintf(stderr,"Processing fixed record\n");

if ( debug ) {
  if ( dtl_map_addr != NULL ) {
    fprintf(stderr,"\n segtype      = %s\n",dtl_map_addr->rec_id);
    fprintf(stderr,"dtl_len         = %d\n",def_dtl_len);
    fprintf(stderr,"def_rec_len_adj = %d\n",def_rec_len_adj);
    fprintf(stderr,"accum peek_len   = %d\n",accum_peek_len);
    fprintf(stderr,"bytes read      = %15.0Lf\n",tot_bytes_read);
    fprintf(stderr,"out file id     =%d\n",dtl_map_addr->out_file_id);
  }
  else fprintf(stderr,"Unknown segment type\n");
}

/* if ( debug ) fprintf(stderr,"bytes read      = %15.0Lf\n",tot_bytes_read);
 if ( tot_bytes_read > 10000 && debug)  exit(1); */

if ( dtl_map_addr != NULL ) {
  dtl_map_addr->recs_read++;
}


if ( def_rec_len_adj != 0 ) {   /* If there is a default adjustment assign it to the local variable */
  local_rec_len_adj=def_rec_len_adj;
}
if ( dtl_map_addr->dtl_rec_len_adj != 0 ) {  /* If this record type has an adjustment override the default */
  local_rec_len_adj=dtl_map_addr->dtl_rec_len_adj;
}

if ( debug ) fprintf(stderr,"Fixed record type\n");

if ( dtl_map_addr->in_rec_len != 0 ) {  /* If the record type has a record length then use it */
  in_rec_len=dtl_map_addr->in_rec_len;
}
else if ( def_dtl_len > 0 ) { /* If the two above checks do not produce a record type then use the default from the parent */
  in_rec_len=def_dtl_len;
}
else if ( def_dtl_len == -1 ) { /* This means that there were no occurances of the variable segment */
  in_rec_len=0;
}
else {
  fprintf(stderr,"Record length was not set at the record level, file level and no peek position has been set\n");
  exit(1);
}

if ( in_rec_len < 0 || in_rec_len > 32767 ) {
  fprintf(stderr,"Invalid record length = %d\n",in_rec_len);
  fprintf(stderr,"Record Identifier = %s\n",dtl_map_addr->rec_id);
  error_msg("\n");
}

if ( debug ) fprintf(stderr,"in rec len = %d\n",in_rec_len);

remaining_dtl_bytes=in_rec_len+local_rec_len_adj;

if ( debug ) fprintf(stderr,"bytes to read = %d\n",remaining_dtl_bytes);

if ( in_rec_len > 0 ) {

  bytes_read=fread(in_rec_buf+accum_peek_len,remaining_dtl_bytes,1,in_file_strm)*(remaining_dtl_bytes);

  if ( ( bytes_read == 0 ) && ( trl_rec_map.rec_len == 0 ) ) {
    end_of_file=1;
    dtl_map_addr->recs_read--;
    tot_recs_read--;
    return;
  }

  if ( debug ) fprintf(stderr,"Read record\n");

  tot_bytes_read+=bytes_read;

  if ( bytes_read == 0 ) {
    error_msg("Error reading detail record\n");
  }

}

if ( dtl_map_addr->out_file_id != NULL ) { /* If there is a file name specified then write out the output */

  if ( debug ) fprintf(stderr,"Writing data record\n");

  bytes_to_write=remaining_dtl_bytes+accum_peek_len;

  if ( debug ) fprintf(stderr,"Pre Adjustment bytes to write out = %d\n",bytes_to_write);

  if ( dtl_map_addr->out_rec_len > 0 && dtl_map_addr->out_rec_len < bytes_to_write ) {
    bytes_to_write=dtl_map_addr->out_rec_len;
  }

  if ( custom_map_override == 1 ) {
    if ( ptr_custom_map == 0 ) {
      fprintf(stderr,"Custom header function not defined\n");
      fprintf(stderr,"Make sure you are using the correct GenSplitter\n");
      fprintf(stderr,"Regular GenSplitter does not work with custom functions\n");
      exit(1);
    }
    (*ptr_custom_map) (in_rec_buf,dtl_map_addr);
    if ( debug ) fprintf(stderr,"Returned from custom function\n");
  }

/*  if ( debug ) fprintf(stderr,"Post Adjustment bytes to write out = %d\n",bytes_to_write);*/

  if ( debug == 2 ) {
    fprintf(stderr,"Writing from buffer starting addr %d\n",in_rec_buf);
    fprintf(stderr,"Output file id = %d\n",dtl_map_addr->out_file_id);
  }


  if ( write(dtl_map_addr->out_file_id,in_rec_buf,bytes_to_write) == 0 ) {  /* Write the data */
    fprintf(stderr,"Error writing detail segment to file %s\n",dtl_map_addr->out_file_name);
    error_msg("\n");
  }
  if ( debug ) fprintf(stderr,"Record Written\n");

  if ( dtl_map_addr->out_rec_len > bytes_to_write) {  /* Write out additional padding if needed */
    additional_bytes=dtl_map_addr->out_rec_len-bytes_to_write;
    if ( debug ) fprintf(stderr,"Writing %d additional bytes\n",additional_bytes);
    if ( write(dtl_map_addr->out_file_id,padded_buf,additional_bytes) != additional_bytes ) {
      fprintf(stderr,"Error writing padded buffer detail segment to file %s\n",dtl_map_addr->out_file_name);
      error_msg("\n");
    }
  }

  tot_recs_writ++;
  dtl_map_addr->recs_writ++;

}

child_struct=dtl_map_addr->child_struct;

if ( child_struct != NULL ) {
  if ( strcmp(child_struct->rec_type,"FIXED") == 0 ) {
    process_fixed_rec(child_struct,in_rec_len,accum_peek_len,local_rec_len_adj);
  }
  else if ( strcmp(child_struct->rec_type,"PARENT") == 0 ) {
    process_parent_rec(child_struct,accum_peek_len);
  }
  else if ( strcmp(child_struct->rec_type,"VARIABLE") == 0 ) { /* If a fixed record is calling a variable then no pass through values */
    process_variable_rec(child_struct,accum_peek_len,0,-1,0,0);
  }
  else if ( strcmp(child_struct->rec_type,"DELIMITED") == 0 ) {
    process_delimited_rec(child_struct,in_rec_len,accum_peek_len,local_rec_len_adj);
  }
  else if ( strcmp(child_struct->rec_type,"SUBRECORD") == 0 ) {
    strncpy_unsigned(in_rec_buf_save,in_rec_buf,bytes_to_write);
    process_subrecord_rec(child_struct);
  }
  else {
 /*   print_cfg_values(dtl_map_addr);*/
    fprintf(stderr,"Fixed Rec Processing - Unknown Record Type = %s\n",child_struct->rec_type);
    error_msg("\n");
  }


if ( debug ) fprintf(stderr,"Exiting process fixed\n");

}

return;
}


void process_subrecord_rec(
  struct dtl_rec_type *dtl_map_addr
)

{

struct dtl_rec_type *child_map_addr;
int in_rec_len;
int i;
int local_rec_len_adj=0;
int remaining_dtl_bytes;
unsigned char num_occurs_str[10];
int num_occurs;
int dtl_occurs_len;
int additional_bytes;
/* int bytes_to_write;  change to global variable because it can get changed in custom_map function */
struct dtl_rec_type *child_struct;

if ( debug ) fprintf(stderr,"Processing subrecord record\n");

if ( debug ) {
  if ( dtl_map_addr != NULL ) {
    fprintf(stderr,"\n segtype      = %s\n",dtl_map_addr->rec_id);
    fprintf(stderr,"bytes read      = %15.0Lf\n",tot_bytes_read);
    fprintf(stderr,"out file id     =%d\n",dtl_map_addr->out_file_id);
  }
  else fprintf(stderr,"Unknown segment type\n");
}

dtl_occurs_len=dtl_map_addr->dtl_occurs_seg_len;

in_rec_len=dtl_map_addr->in_rec_len;

strncpy_unsigned(num_occurs_str,in_rec_buf_save+dtl_map_addr->dtl_occurs_pos,dtl_occurs_len);

num_occurs=str_buf_atoi(num_occurs_str,dtl_occurs_len);

if ( debug ) fprintf(stderr,"Number of occurances = %d\n",num_occurs);

for (i=0;i<num_occurs;i++) {

  bytes_read=fread(in_rec_buf,dtl_map_addr->in_rec_len,1,in_file_strm)*dtl_map_addr->in_rec_len;

  if ( ( bytes_read == 0 ) && ( trl_rec_map.rec_len == 0 ) ) {
    end_of_file=1;
    dtl_map_addr->recs_read--;
    tot_recs_read--;
    return;
  }

  dtl_map_addr->recs_read++;

  if ( debug ) {
    fprintf(stderr,"Read subrecord\n");
    fprintf(stderr,"Total Bytes Read = %15.0Lf\n",tot_bytes_read);
  }


  tot_bytes_read+=bytes_read;

  if ( bytes_read == 0 ) {
    error_msg("Error reading detail subrecord\n");
  }


  if ( dtl_map_addr->out_file_id != NULL ) { /* If there is a file name specified then write out the output */

    if ( debug == 2 ) fprintf(stderr,"Writing data record\n");

    bytes_to_write=bytes_read;

    if ( dtl_map_addr->out_rec_len > 0 && dtl_map_addr->out_rec_len < bytes_to_write ) {
      bytes_to_write=dtl_map_addr->out_rec_len;
    }

    if ( custom_map_override == 1 ) {
      if ( ptr_custom_map == 0 ) {
        fprintf(stderr,"Custom header function not defined\n");
        fprintf(stderr,"Make sure you are using the correct GenSplitter\n");
        fprintf(stderr,"Regular GenSplitter does not work with custom functions\n");
        exit(1);
      }
      (*ptr_custom_map) (in_rec_buf,dtl_map_addr);
      if ( debug ) fprintf(stderr,"Returned from custom function\n");
    }

    if ( debug == 2 ) {
      fprintf(stderr,"Writing from buffer starting addr %d\n",in_rec_buf);
      fprintf(stderr,"Output file id = %d\n",dtl_map_addr->out_file_id);
    }

    if ( write(dtl_map_addr->out_file_id,in_rec_buf,bytes_to_write) == 0 ) {  /* Write the data */
      fprintf(stderr,"Error writing detail segment to file %s\n",dtl_map_addr->out_file_name);
      error_msg("\n");
    }
    if ( debug ) fprintf(stderr,"SubRecord Written\n");

    if ( dtl_map_addr->out_rec_len > bytes_to_write) {  /* Write out additional padding if needed */
      additional_bytes=dtl_map_addr->out_rec_len-bytes_to_write;
      if ( debug ) fprintf(stderr,"Writing %d additional bytes\n",additional_bytes);
      if ( write(dtl_map_addr->out_file_id,padded_buf,additional_bytes) != additional_bytes ) {
        fprintf(stderr,"Error writing padded buffer detail segment to file %s\n",dtl_map_addr->out_file_name);
        error_msg("\n");
      }
    }

    tot_recs_writ++;
    dtl_map_addr->recs_writ++;

  }
}

child_struct=dtl_map_addr->child_struct;

if ( child_struct != NULL ) {
  if ( strcmp(child_struct->rec_type,"SUBRECORD") == 0 ) {
    process_subrecord_rec(child_struct);
  }
  else {
    fprintf(stderr,"Fixed Rec Processing - Unknown Record Type = %s\n",child_struct->rec_type);
    error_msg("\n");
  }

}

if ( debug ) fprintf(stderr,"Exiting process subrecord\n");

return;
}

/*************************************************************************************************************/
void process_delimited_rec(
  struct dtl_rec_type *dtl_map_addr,
  int def_dtl_len,
  int accum_peek_len,
  int def_rec_len_adj
)

{

struct dtl_rec_type *child_map_addr;
int in_rec_len;
int local_rec_len_adj=0;
int remaining_dtl_bytes;
int additional_bytes;
int dlmtd_str_len;
struct dtl_rec_type *child_struct;

if ( debug ) fprintf(stderr,"Processing delimited record\n");

if ( debug ) {
  if ( dtl_map_addr != NULL ) {
    fprintf(stderr,"\n segtype      = %s\n",dtl_map_addr->rec_id);
    fprintf(stderr,"dtl_len         = %d\n",def_dtl_len);
    fprintf(stderr,"def_rec_len_adj = %d\n",def_rec_len_adj);
    fprintf(stderr,"accum peek_len   = %d\n",accum_peek_len);
    fprintf(stderr,"bytes read      = %15.0Lf\n",tot_bytes_read);
    fprintf(stderr,"out file id     =%d\n",dtl_map_addr->out_file_id);
  }
  else fprintf(stderr,"Unknown segment type\n");
}

if ( def_rec_len_adj != 0 ) {   /* If there is a default adjustment assign it to the local variable */
  local_rec_len_adj=def_rec_len_adj;
}
if ( dtl_map_addr->dtl_rec_len_adj != 0 ) {  /* If this record type has an adjustment override the default */
  local_rec_len_adj=dtl_map_addr->dtl_rec_len_adj;
}

if ( debug ) fprintf(stderr,"Delimited record type\n");

if ( fgets( (char * ) in_rec_buf+accum_peek_len,32767,in_file_strm) == NULL ) {
  if ( trl_rec_map.rec_len == 0 ) {
    end_of_file=1;
    tot_recs_read--;
    return;
  }
  else {
    fprintf(stderr,"problem reading delimited record\n");
    exit(1);
  }
}

if ( dtl_map_addr != NULL ) {
  dtl_map_addr->recs_read++;
}

if ( debug ) fprintf(stderr,"Read ( Red ) record\n");

dlmtd_str_len=strlen( (char *) in_rec_buf);

tot_bytes_read+=dlmtd_str_len-accum_peek_len;


if ( dtl_map_addr->out_file_id != NULL ) { /* If there is a file name specified then write out the output */

  if ( debug ) fprintf(stderr,"Writing data record\n");

  bytes_to_write=dlmtd_str_len;

  if ( debug ) fprintf(stderr,"Bytes to Write - %d\n",bytes_to_write);

  if ( custom_map_override == 1 ) {
    if ( ptr_custom_map == 0 ) {
      fprintf(stderr,"Custom header function not defined\n");
      fprintf(stderr,"Make sure you are using the correct GenSplitter\n");
      fprintf(stderr,"Regular GenSplitter does not work with custom functions\n");
      exit(1);
    }
    (*ptr_custom_map) (in_rec_buf,dtl_map_addr);
    if ( debug ) fprintf(stderr,"Returned from custom function\n");
    dlmtd_str_len=strlen( (char *) in_rec_buf);
    tot_bytes_read+=dlmtd_str_len-bytes_to_write;
    bytes_to_write=dlmtd_str_len;
  }

  if ( debug == 2 ) {
    fprintf(stderr,"Writing from buffer starting addr %d\n",in_rec_buf);
    fprintf(stderr,"Output file id = %d\n",dtl_map_addr->out_file_id);
  }


  if ( write(dtl_map_addr->out_file_id,in_rec_buf,bytes_to_write) == 0 ) {  /* Write the data */
    fprintf(stderr,"Error writing detail segment to file %s\n",dtl_map_addr->out_file_name);
    error_msg("\n");
  }
  if ( debug ) fprintf(stderr,"Record Written\n");

  tot_recs_writ++;
  dtl_map_addr->recs_writ++;

}

if ( debug ) fprintf(stderr,"Exiting process delimited\n");

return;
}
/*************************************************************************************************************/


void process_header(char * file_path)

{

char rec_id[11];
int i;
char full_file_name[151];
unsigned char header_date[9];
unsigned char sqlldr_hdr_ascii[21];
int dlmtd_str_len;

if ( strcmp(format,"EBCDIC") == 0 ) {
  for (i=0;i<8;i++)
    header_date[i]=64;
}
else {
  for (i=0;i<8;i++)
    header_date[i]=32;
}


fprintf(stderr,"In process header function\n");

fprintf(stderr,"Reading Header Record\n");
if ( strcmp(format,"DELIMITED") == 0 ) {
  if (fgets( (char * ) in_rec_buf,32767,in_file_strm) == NULL ) {
    fprintf(stderr,"Error reading header record from input file\n");
    exit(1);
  }
}
else {
  if (fread(in_rec_buf, hdr_rec_map.rec_len,1,in_file_strm) == 0 ) {
    fprintf(stderr,"Error reading header record from input file\n");
    exit(1);
  }
}
tot_bytes_read+=hdr_rec_map.rec_len;
tot_recs_read++;


if ( strcmp(format,"EBCDIC") == 0 ) {
  for (i=0;i<hdr_rec_map.rec_id_len;i++)
    rec_id[i]=ascii_equiv[*(in_rec_buf+hdr_rec_map.rec_id_pos+i)];
}
else {
  for (i=0;i<hdr_rec_map.rec_id_len;i++)
    rec_id[i]=*(in_rec_buf+hdr_rec_map.rec_id_pos+i);
}
rec_id[hdr_rec_map.rec_id_len]='\0';

fprintf(stderr,"Checking header identifier\n");

if (strcmp(rec_id,hdr_rec_map.rec_id) != 0 ) {
  fprintf(stderr,"Record Header Id not found in First Record\n");
  fprintf(stderr,"Config Header id = %s\n",hdr_rec_map.rec_id);
  fprintf(stderr,"File Header id = %s\n",rec_id);
  fprintf(stderr,"File Header number value  = %d\n",rec_id);
  exit(1);
}

if ( hdr_rec_cnt == 1 ) {
  strcpy(full_file_name,file_path);
  strcat(full_file_name,"/");
  strcat(full_file_name,hdr_rec_map.out_file_name);

if ( debug ) fprintf(stderr,"Opening Header File\n");

  if ( ( hdr_rec_map.file_id=open(full_file_name,O_WRONLY|O_CREAT|O_TRUNC,00744 )) == NULL ) {
    fprintf(stderr,"Error opening Header outout file %s\n",hdr_rec_map.out_file_name);
    exit(1);
  }
}

if ( custom_map_hdr_trl_override == 1 ) {
  if ( debug ) fprintf(stderr,"Calling custom header function\n");
  if ( ptr_custom_map_hdr_trl == 0 ) {
    fprintf(stderr,"Custom header function not defined\n");
    fprintf(stderr,"Make sure you are using the correct GenSplitter\n");
    fprintf(stderr,"Regular GenSplitter does not work with custom functions\n");
    exit(1);
  }
  (*ptr_custom_map_hdr_trl) (in_rec_buf,&hdr_rec_map,"HEADER");
}


if ( strcmp(format,"EBCDIC") == 0 ) {
  if ( debug ) printf("Converting header to ascii\n");
  for (i=0;i<hdr_rec_map.rec_len;i++) {
    in_rec_buf[i]=ascii_equiv[*(in_rec_buf+i)];
  }
}

if ( strcmp(format,"DELIMITED") == 0 ) {
  dlmtd_str_len=strlen( (char *) in_rec_buf);
  if (write(hdr_rec_map.file_id,in_rec_buf, dlmtd_str_len) != dlmtd_str_len) {
    fprintf(stderr,"Error writing Header record\n");
    exit(1);
  }
}
else {
  if (write(hdr_rec_map.file_id,in_rec_buf, hdr_rec_map.rec_len) != hdr_rec_map.rec_len) {
    fprintf(stderr,"Error writing Header record\n");
    exit(1);
  }
}
tot_recs_writ++;

}
/*************************************************************************************************************/
void process_parent_rec( struct dtl_rec_type *dtl_map_addr, int accum_peek_len)
{

struct dtl_rec_type *child_map_addr;
int curr_peek_start_pos;
int i;

if ( debug ) fprintf(stderr,"Processing Parent Record\n");

if ( debug ) {
  if ( dtl_map_addr != NULL ) {
    fprintf(stderr,"accum peek_len   = %d\n",accum_peek_len);
    fprintf(stderr,"bytes read      = %15.0Lf\n",tot_bytes_read);
  }
  else fprintf(stderr,"Unknown segment type\n");
}

bytes_read=fread(in_rec_buf+accum_peek_len,dtl_map_addr->dtl_peek_len,1,in_file_strm)*dtl_map_addr->dtl_peek_len;

if ( debug == 2 ) print_data(in_rec_buf,bytes_read+accum_peek_len);

if ( ( bytes_read == 0 ) && ( trl_rec_map.rec_len == 0 ) && ( dtl_map_addr->dtl_peek_len > 0 ) ) {
  end_of_file=1;
  return;
}

if ( bytes_read < dtl_map_addr->dtl_peek_len ) {
  error_msg("Not enough bytes were read in for a child peek segment\n");
}
tot_bytes_read+=bytes_read;

curr_peek_start_pos=accum_peek_len;

accum_peek_len+=dtl_map_addr->dtl_peek_len;

if ( debug ) fprintf(stderr,"Indentifying record type\n");

child_map_addr=identify_detail(dtl_map_addr->child_struct,dtl_map_addr->dtl_id_len,dtl_map_addr->dtl_id_pos,curr_peek_start_pos);

if ( child_map_addr == NULL ) {
  process_unknown_rec(dtl_map_addr,accum_peek_len);
}
else if ( strcmp(child_map_addr->rec_type,"FIXED") == 0 ) {
  process_fixed_rec(child_map_addr,dtl_map_addr->in_rec_len,accum_peek_len,dtl_map_addr->dtl_rec_len_adj);
}
else if ( strcmp(child_map_addr->rec_type,"PARENT") == 0 ) {
  process_parent_rec(child_map_addr,accum_peek_len);
}
else if ( strcmp(child_map_addr->rec_type,"VARIABLE") == 0 ) {
  process_variable_rec(child_map_addr,accum_peek_len,dtl_map_addr->dtl_rec_len_adj,dtl_map_addr->dtl_len_pos,dtl_map_addr->child_peek_len,dtl_map_addr->dtl_len_len);
}
else if ( strcmp(child_map_addr->rec_type,"DELIMITED") == 0 ) {
  process_delimited_rec(child_map_addr,dtl_map_addr->in_rec_len,accum_peek_len,dtl_map_addr->dtl_rec_len_adj);
}
else {
/*  print_cfg_values(child_map_addr);*/
  fprintf(stderr,"Parent Rec Processing - Unknown Record Type = %s\n",child_map_addr->rec_type);
  error_msg("\n");
}

}
/*************************************************************************************************************/

void process_trailer(char * file_path)

{

unsigned char *trl_rec_buf;
char rec_id[11];
char i;
int remaining_bytes;
char full_file_name[151];
int dlmtd_str_len;

if ( strcmp(format,"DELIMITED") == 0 ) {

  if ( fgets( (char *) in_rec_buf+trl_rec_map.peek_len,32767,in_file_strm) == NULL ) {
    error_msg("Error reading trailer record from input file\n");
  }
  dlmtd_str_len=strlen( (char *) in_rec_buf);
  fprintf(stderr,"Trailer record length = %d\n",dlmtd_str_len);
  tot_bytes_read+=dlmtd_str_len-trl_rec_map.peek_len;
}
else {

  remaining_bytes=trl_rec_map.rec_len-trl_rec_map.peek_len;

  if ( ( trl_rec_buf=(unsigned char *) calloc( remaining_bytes,1 )) == NULL ) {
    error_msg("Error allocating trailer buffer memory\n");
  }
  bytes_read=fread(in_rec_buf+trl_rec_map.peek_len,remaining_bytes,1,in_file_strm)*remaining_bytes;

  if ( bytes_read < remaining_bytes ) {
    error_msg("Error reading trailer record from input file\n");
  }
  tot_bytes_read+=bytes_read;
}

if ( custom_map_hdr_trl_override == 1 ) {
  (*ptr_custom_map_hdr_trl) (in_rec_buf,&trl_rec_map,"TRAILER");
}

if ( trl_rec_cnt == 1 ) {

  strcpy(full_file_name,file_path);
  strcat(full_file_name,"/");
  strcat(full_file_name,trl_rec_map.out_file_name);

  if ( ( trl_rec_map.file_id=open(full_file_name,O_WRONLY|O_CREAT|O_TRUNC,00744 )) == NULL ) {
    fprintf(stderr,"Error opening Trailer outout file %s\n",trl_rec_map.out_file_name);
    exit(1);
  }
}


if ( strcmp(format,"DELIMITED") == 0 ) {

  dlmtd_str_len=strlen( (char *) in_rec_buf);
  if (write(trl_rec_map.file_id,in_rec_buf,dlmtd_str_len) != dlmtd_str_len) {
    fprintf(stderr,"Error writing Trailer record\n");
    exit(1);
  }
}
else {
  if (write(trl_rec_map.file_id,in_rec_buf, trl_rec_map.rec_len) != trl_rec_map.rec_len) {
    fprintf(stderr,"Error writing Trailer record\n");
    exit(1);
  }
}

tot_recs_writ++;

}

/*************************************************************************************************************/



/* Since record type was not identified the parent record information will be used */

void process_unknown_rec(struct dtl_rec_type *dtl_map_addr, int accum_peek_len)
{

int total_peek_len;
int local_dtl_len_pos;
int in_rec_len;
int remaining_dtl_bytes;

if ( debug ) {
  fprintf(stderr,"Processing unknown record\n");
  fprintf(stderr,"\n segtype      = %s\n",dtl_map_addr->rec_id);
  fprintf(stderr,"accum peek_len  = %d\n",accum_peek_len);
  fprintf(stderr,"dtl_len_pos     = %d\n",dtl_map_addr->dtl_len_pos);
  fprintf(stderr,"in rec len      = %d\n",dtl_map_addr->in_rec_len);
  fprintf(stderr,"bytes read      = %15.0Lf\n",tot_bytes_read);
}


total_peek_len=accum_peek_len+dtl_map_addr->dtl_peek_len;

if ( dtl_map_addr->dtl_len_pos != -1 ) {   /* record length is defined in data */
  local_dtl_len_pos=accum_peek_len+dtl_map_addr->dtl_len_pos;
}
else {                    /* record length is not in data */
  local_dtl_len_pos=-1;
}

unknown_recs_read++;

if ( debug ) fprintf(stderr,"Unknown record type\n");

if ( strcmp("DELIMITED",format) == 0 ) {
  if ( fgets( (char * ) in_rec_buf+accum_peek_len,32767,in_file_strm) == NULL ) {
    if ( trl_rec_map.rec_len == 0 ) {
      end_of_file=1;
      return;
    }
    else {
      fprintf(stderr,"problem reading delimited record\n");
      exit(1);
    }
  }
 fprintf(stderr,"In Rec = %s\n",in_rec_buf);
return;
}


if ( debug ) fprintf(stderr,"local detail len position = %d\n",local_dtl_len_pos);

if ( local_dtl_len_pos != -1 ) {   /* If the record length is in the peek segment then use it otherwise use the default */
  if ( strcmp(dtl_map_addr->dtl_len_datatype,"BINARY")) {
    in_rec_len=(*(in_rec_buf+local_dtl_len_pos)*256)+(*(in_rec_buf+local_dtl_len_pos+1));
    if ( debug ) fprintf(stderr,"first len byte = %x second byte = %x\n",*(in_rec_buf+local_dtl_len_pos),*(in_rec_buf+local_dtl_len_pos+1));
  }
  else if ( strcmp(dtl_map_addr->dtl_len_datatype,"TEXT")) {
    in_rec_len=str_buf_atoi((in_rec_buf+local_dtl_len_pos),dtl_map_addr->dtl_len_len);
    if ( debug ) fprintf(stderr,"Record Length from TEXT field = %d",in_rec_len);
  }
  else if ( strcmp(dtl_map_addr->dtl_len_datatype,"PACKED")) {
    in_rec_len=pd_to_int((in_rec_buf+local_dtl_len_pos),dtl_map_addr->dtl_len_len);
    if ( debug ) fprintf(stderr,"Record Length from PACKED field = %d",in_rec_len);
  }
/* If the in_rec_len represents the numbers of occurs then we need to multiply it */
/* by the actual length of the segment */
  in_rec_len=dtl_map_addr->dtl_occurs_seg_len*in_rec_len;
}
else if ( dtl_map_addr->in_rec_len > 0 ) {
  in_rec_len=dtl_map_addr->in_rec_len;
}
else {
  fprintf(stderr,"Record length was not set at the file level and no peek position has been set\n");
  exit(1);
}

if ( in_rec_len < 0 || in_rec_len > 32767 ) {
  fprintf(stderr,"Invalid record length = %d\n",in_rec_len);
  error_msg("\n");
}

if ( debug ) fprintf(stderr,"in rec len = %d\n",in_rec_len);

remaining_dtl_bytes=in_rec_len+dtl_map_addr->dtl_rec_len_adj;

if ( debug ) fprintf(stderr,"bytes to read = %d\n",remaining_dtl_bytes);

bytes_read=fread(in_rec_buf+total_peek_len,remaining_dtl_bytes,1,in_file_strm)*(remaining_dtl_bytes);

if ( debug ) fprintf(stderr,"bytes read = %d\n",bytes_read);

tot_bytes_read+=bytes_read;

if ( bytes_read == 0 ) {
  error_msg("Error reading detail record\n");
}

return;
}
/*************************************************************************************************************/


void process_variable_rec
(
  struct dtl_rec_type *dtl_map_addr,
  int accum_peek_len,
  int def_rec_len_adj,
  int def_dtl_len_pos,
  int def_peek_len,
  int def_dtl_len_len
)
{

int local_rec_len_adj=0;
int local_dtl_len_pos=0;
int local_peek_len=0;
int local_dtl_len_len=0;
int in_rec_len;
int i;


/* The position of local_dtl_len_pos is based on what new peek data will be read into the in_rec_buf
   so you may already have data in the buffer but position 0 is where that data ends. If the position
   of the record length is within the previous peek segment then a negative value will
   have to be used to look back at the previous peek data and no new peek data should be read */

if ( debug ) {
  fprintf(stderr,"Processing Variable record\n");
  if ( dtl_map_addr != NULL ) {
    fprintf(stderr,"\n segtype      = %s\n",dtl_map_addr->rec_id);
    fprintf(stderr,"def_rec_len_adj = %d\n",def_rec_len_adj);
    fprintf(stderr,"def_dtl_len_len = %d\n",def_dtl_len_len);
    fprintf(stderr,"def_dtl_len_pos = %d\n",def_dtl_len_pos);
    fprintf(stderr,"accum peek_len   = %d\n",accum_peek_len);
    fprintf(stderr,"bytes read      = %15.0Lf\n",tot_bytes_read);
  }
  else fprintf(stderr,"Unknown segment type\n");
}


if ( def_rec_len_adj != 0 ) {   /* If there is a default adjustment assign it to the local variable */
  local_rec_len_adj=def_rec_len_adj;
}

if ( dtl_map_addr->dtl_rec_len_adj != 0 ) {  /* If this record type has an adjustment override the default */
  local_rec_len_adj=dtl_map_addr->dtl_rec_len_adj;
}

if ( def_dtl_len_pos != -1 ) {  /* If there is a default adjustment assign it to the local variable */
  local_dtl_len_pos=def_dtl_len_pos+accum_peek_len;
}

if ( dtl_map_addr->dtl_len_pos != -1 ) {  /* If this record type has a value then override the default */
  local_dtl_len_pos=dtl_map_addr->dtl_len_pos+accum_peek_len;
}

if ( def_dtl_len_len > 0 ) {  /* If there is a default adjustment assign it to the local variable */
  local_dtl_len_len=def_dtl_len_len;
}

if ( dtl_map_addr->dtl_len_len > 0 ) {  /* If this record type has a value then override the default */
  local_dtl_len_len=dtl_map_addr->dtl_len_len;
}

if ( def_peek_len > 0 ) {  /* If there is a default then assign it to the local variable */
  local_peek_len=def_peek_len;
}
if ( dtl_map_addr->dtl_peek_len > 0 ) {  /* If this record type has a value then override the default */
  local_peek_len=dtl_map_addr->dtl_peek_len;
}

if ( local_peek_len > 0 ) {  /* If the length of record isn't already in peek that has been read then read more */

  bytes_read=fread(in_rec_buf+accum_peek_len,local_peek_len,1,in_file_strm)*local_peek_len;

  if ( bytes_read < local_peek_len ) {
    error_msg("Not enough bytes were read in for variable length peek segment\n");
  }
  tot_bytes_read+=bytes_read;

  accum_peek_len+=local_peek_len;

}

if ( debug ) {
  fprintf(stderr,"accum_peek_len = %d\n",accum_peek_len);
  fprintf(stderr,"local_dtl_len_pos = %d\n",local_dtl_len_pos);
  fprintf(stderr,"local_dtl_len_len = %d\n",local_dtl_len_len);
  fprintf(stderr,"dtl_datatype = %s\n",dtl_map_addr->dtl_len_datatype);
}

/* dtl_len_pos may be negative as it may have been read in as part of the child peek segment */

if ( strcmp(dtl_map_addr->dtl_len_datatype,"BINARY") == 0 ) {
  in_rec_len=(*(in_rec_buf+local_dtl_len_pos)*256)+(*(in_rec_buf+local_dtl_len_pos+1));
  if ( debug ) fprintf(stderr,"first len byte = %x second byte = %x\n",*(in_rec_buf+local_dtl_len_pos),*(in_rec_buf+local_dtl_len_pos+1));
}
else if ( strcmp(dtl_map_addr->dtl_len_datatype,"TEXT") == 0 ) {
  in_rec_len=str_buf_atoi((in_rec_buf+local_dtl_len_pos),dtl_map_addr->dtl_len_len);
  if ( debug ) {
    fprintf(stderr,"Record Length from TEXT field = %d",in_rec_len);
    for (i=0;i<dtl_map_addr->dtl_len_len;i++)
      fprintf(stderr,"Text length string position %d has value %c\n",i,*(in_rec_buf+local_dtl_len_pos+i));
  }
}
else if ( strcmp(dtl_map_addr->dtl_len_datatype,"PACKED") == 0 ) {
  in_rec_len=pd_to_int((in_rec_buf+local_dtl_len_pos),dtl_map_addr->dtl_len_len);
  if ( debug ) fprintf(stderr,"Record Length from PACKED field = %d\n",in_rec_len);
}

/* If the in_rec_len represents the numbers of occurs then we need to multiply it by the actual length of the segment */
if ( dtl_map_addr->dtl_occurs_seg_len > 0 ) {
  in_rec_len=dtl_map_addr->dtl_occurs_seg_len*in_rec_len;
  if ( in_rec_len == 0 ) {  /* We don't want to confuse the process_fix_rec segment as this is not a error */
    in_rec_len = -1;
  }
}

process_fixed_rec(dtl_map_addr,in_rec_len,accum_peek_len,local_rec_len_adj);

return;

}


void generate_ds_config_file(char *out_file_path)
{

char ds_config_file_full_name[251];
FILE *ds_cfg_file_id;

strcpy(ds_config_file_full_name,out_file_path);
strcat(ds_config_file_full_name,"/");
strcat(ds_config_file_full_name,ds_config_file_name);

if ((ds_cfg_file_id=fopen(ds_config_file_full_name,"wb")) == NULL ) {
  fprintf(stderr,"Error opening config file. File name = %s\n",ds_config_file_full_name);
  exit(1);
}

if ( hdr_rec_map.rec_len > 0 ) {

  if ( strlen(hdr_rec_map.load_job_name) == 0 ) {
    strcpy(hdr_rec_map.load_job_name,"utilLoadSeqFileOra.");
    strcat(hdr_rec_map.load_job_name,hdr_rec_map.table_name);
  }

  fprintf(ds_cfg_file_id,"HEADER_FILE|%s|%s|%s|||%s^%s||||0\n",hdr_rec_map.out_file_name,hdr_rec_map.table_name,hdr_rec_map.schema_file,hdr_rec_map.load_job_name,hdr_rec_map.table_name);
}

if ( trl_rec_map.rec_len > 0 ) {

  if ( strlen(trl_rec_map.load_job_name) == 0 ) {
    strcpy(trl_rec_map.load_job_name,"utilLoadSeqFileOra.");
    strcat(trl_rec_map.load_job_name,trl_rec_map.table_name);
  }

  fprintf(ds_cfg_file_id,"TRAILER_FILE|%s|%s|%s|||%s^%s||||0\n",trl_rec_map.out_file_name,trl_rec_map.table_name,trl_rec_map.schema_file,trl_rec_map.load_job_name,trl_rec_map.table_name);
}

write_dtl_config_file(start_dtl_rec_map,ds_cfg_file_id);

fclose(ds_cfg_file_id);

}


void write_dtl_config_file(struct dtl_rec_type *curr_struct,FILE *cfg_file_id)
{

if (strlen(curr_struct->table_name) > 0 && curr_struct->dup_file_flag == 0) {

  if ( strlen(curr_struct->load_job_name) == 0 ) {
    strcpy(curr_struct->load_job_name,"utilLoadSeqFileOra.");
    strcat(curr_struct->load_job_name,curr_struct->table_name);
  }

  fprintf(cfg_file_id,"%s|%s|%s|%s|%s|%s|%s^%s|%s|%s|%s|%s\n",curr_struct->record_type,curr_struct->out_file_name,curr_struct->table_name,curr_struct->schema_file,curr_struct->sum_column,curr_struct->group_column,curr_struct->load_job_name,curr_struct->table_name,curr_struct->detail_sum_column,curr_struct->trailer_sum_column,curr_struct->trailer_count_column,curr_struct->error_tolerance_count);

}

if ( curr_struct->child_struct != NULL ) {
  write_dtl_config_file(curr_struct->child_struct,cfg_file_id);
}

if ( curr_struct->next_struct != NULL ) {
  write_dtl_config_file(curr_struct->next_struct,cfg_file_id);
}

}


void print_data(unsigned char *in_buf,int buf_len)
{

int i;

fprintf(stderr,"\nPrinting record dump\n");

for (i=0;i<buf_len;i++) {
  if ( ( i % 16 ) == 0 ) {
    fprintf(stderr,"\n%4o  ",i);
  }
  if ( *(in_buf+i) < 16 )
    fprintf(stderr,"0%1x ",*(in_buf+i));
  else
    fprintf(stderr,"%2x ",*(in_buf+i));
}

fprintf(stderr,"\n\n");

}


int str_buf_atoi( unsigned char *in_buf, int length ) {

char in_str[10];
char i;

for (i=0;i<length;i++) {
  if (strcmp(format,"EBCDIC") == 0 ) {
    if (*(in_buf+i) == 64 )
      in_str[i] = 48; /* if this is an ebcdic space make it an ascii zero */
    else
      in_str[i] = *(in_buf+i)-192; /* transform ebcdic number to ascii number */
    }
  else
    in_str[i] = *(in_buf+i);
}

in_str[i] = '\0';

return(atoi(in_str));
}


int pd_to_int(unsigned char *inp_str, int length)
{
int ret_value = 0;
unsigned long nibble;
char i;
for (i=0;i<length-1;i++)
{
  nibble = *(inp_str+i) >> 4;
  ret_value = ret_value * 10 + nibble;
  nibble = *(inp_str+i) & 0xF;
  ret_value = ret_value * 10 + nibble;
}

nibble = *(inp_str+i) >> 4;
ret_value = ret_value * 10 + nibble;
nibble = *(inp_str+i) & 0xF;
if ( nibble != 0xC && nibble != 0xF )
  ret_value = -ret_value;

return(ret_value);
}

void strncpy_unsigned(unsigned char *inp_str1,unsigned char *inp_str2,int length)
{
int i;

for (i=0;i<length;i++) {
  *(inp_str1+i) = *(inp_str2+i);
}

}
