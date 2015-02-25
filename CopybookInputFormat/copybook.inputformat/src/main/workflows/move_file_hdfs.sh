#!/bin/sh

function showHelp(){
echo '';
echo "Usage : SourceDir, DestinationDir, FileName"
}

#NUM_ARGS = ${#} ;

#if [ "${NUM_ARGS}" -ne 3 ] ; then
# showHelp ;
# exit 1
#fi;
  
  SOURCE_DIR=$0
  DEST_DIR=$1
  FILE_NAME=$2
  
  hadoop fs -test -d $DEST_DIR
  
  if [ $? -ne 0 ] ; then
   hadoop fs -mkdir -p $DEST_DIR
   echo "${DEST_DIR} Created"
 fi  
 
  hadoop fs -test -e ${DEST_DIR}/${FILE_NAME}
  
  if [ $? -ne 0 ] ; then
    hadoop fs -rm -r ${DEST_DIR}/${FILE_NAME}
    echo "Deleted Stale File From HDFS"
  fi
    
  if [ -f "${SOURCE_DIR}${FILE_NAME}" ] ; then
    echo "Starting HDFS File Transfer"
    echo "Input File: " ${SOURCE_DIR}${FILE_NAME}
    echo "Output Dir: " ${DEST_DIR}

    hadoop fs -put ${SOURCE_DIR}${FILE_NAME}" "${DEST_DIR}"
    
    if [ "$?" = "0" ] ; then
      echo "Source File Copied to HDFS"
      exit 0;
    else
      echo "Unable to Copy File to HDFS"
      exit 1;
      fi;
  else
      echo "File Failed to Copied from Linux to HDFS"
      exit 1;
  fi ;    