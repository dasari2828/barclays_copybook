CREATE EXTERNAL TABLE IF NOT EXISTS AM0B_AsciiTbl
(
  AM0B_SEGMENT_LENGTH DOUBLE,
  AM0B_ACCT_MISC_DATA_TYPE BIGINT,
  AM0B_SEGMENT_SEQ BIGINT,
  AM0B_ACCT_MISC_DATA STRING
)
ROW FORMAT DELIMITED FIELDS TERMINATED BY '1'
STORED AS TEXTFILE
LOCATION '/user/admin/copybook/ascii/AM0B/'