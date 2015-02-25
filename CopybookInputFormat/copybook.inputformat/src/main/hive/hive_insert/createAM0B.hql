ADD JAR ${mainFrameJar};
use default;

CREATE EXTERNAL TABLE IF NOT EXISTS AM0Btbl
(
  AM0B_SEGMENT_LENGTH DOUBLE,
  AM0B_ACCT_MISC_DATA_TYPE BIGINT,
  AM0B_SEGMENT_SEQ BIGINT,
  AM0B_ACCT_MISC_DATA STRING
)
ROW FORMAT DELIMITED FIELDS TERMINATED BY '1'
STORED AS INPUTFORMAT 'com.cloudera.sa.copybook.mapred.CopybookInputFormat' OUTPUTFORMAT 'org.apache.hadoop.hive.ql.io.HiveIgnoreKeyTextOutputFormat'
LOCATION '${destDir}'
TBLPROPERTIES ('copybook.inputformat.cbl.hdfs.path' = '${cblPath}');
