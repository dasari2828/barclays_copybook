#ifndef GenSplitter__INCLUDED
#define GenSplitter__INCLUDED

#include <stdio.h>

struct dtl_rec_type {
  char rec_id[51];
  int dtl_peek_len;
  int in_rec_len;
  int out_rec_len;
  char out_file_name[151];
  int dtl_id_pos;
  int dtl_id_len;
  char dtl_len_datatype[10];
  char dtl_occurs_datatype[10];
  int dtl_occurs_pos;
  int dtl_len_len;
  int dtl_len_pos;  /* These two fields are position and length of the bytes containing the record length */
  int dtl_occurs_seg_len;
  int out_file_id;
  char rec_type[21];
  int recs_read;
  int recs_writ;
  int dtl_rec_len_adj;
  int child_peek_len;
  int user_exit_rtn;
  char record_type[51];
  char table_name[31];
  char schema_file[101];
  char sum_column[31];
  char group_column[31];
  char load_job_name[151];
  char detail_sum_column[31];
  char trailer_sum_column[31];
  char trailer_count_column[31];
  char error_tolerance_count[10];
  char pipe_file_flag;
  char dup_file_flag;

  struct dtl_rec_type *child_struct;
  struct dtl_rec_type *next_struct;
};

struct hdr_trl_rec_type {
  char rec_id[11];
  int rec_id_pos;
  int date_id_pos;
  int date_id_len;
  char rec_id_len;
  int rec_len;
  char out_file_name[151];
  int peek_len;
  int file_id;
  char table_name[31];
  char schema_file[101];
  char load_job_name[151];
};


/* These variables are in this header file because they are
   accessed in custom_map */

unsigned char padded_buf[32767];
int bytes_to_write;
unsigned char suffix[2];
unsigned char rec_nbr_str[10];
FILE *in_file_strm;
unsigned char in_rec_buf_save[32767];
int debug;
unsigned char account_identifier[6];
unsigned char acct_nbr[19];

#endif