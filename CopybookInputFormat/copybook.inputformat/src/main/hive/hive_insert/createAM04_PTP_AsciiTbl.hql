CREATE EXTERNAL TABLE IF NOT EXISTS AM04_PTP_AsciiTbl
(
  AM04_SEGMENT_LENGTH DOUBLE,
  AM04_POP_SEGMENT_CODE STRING,
  AM04_SEGMENT_SEQ BIGINT,
  AM04_OPERATOR_ID STRING,
  AM04_AMT_PTP DOUBLE,
  AM04_DATE_PTP_DUE DOUBLE,
  AM04_DATE_PTP_TAKEN DOUBLE,
  FILLER STRING
)
ROW FORMAT DELIMITED FIELDS TERMINATED BY '1'
STORED AS TEXTFILE
LOCATION '/user/admin/copybook/ascii/AM04_PTP/';
