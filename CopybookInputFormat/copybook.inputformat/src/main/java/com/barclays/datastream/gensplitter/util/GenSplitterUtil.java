package com.barclays.datastream.gensplitter.util;

import com.barclays.datastream.gensplitter.dto.DriverUtilDTO;
import com.barclays.datastream.gensplitter.dto.GenSplitterDTO;
import com.barclays.datastream.gensplitter.dto.HdrTrlRecTypeDTO;
import org.apache.log4j.Logger;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by hadoop on 2/25/15.
 */
public class GenSplitterUtil {

    static Logger log = Logger.getLogger(GenSplitterUtil.class);
    public static Logger getLog() {
        return log;
    }

    public static void setLog(Logger log) {
        GenSplitterUtil.log = log;
    }
    
    public DriverUtilDTO assignCfgValuesUtil(String cfgVarName, String cfgVarValue, DriverUtilDTO util) {
        if ("END".equalsIgnoreCase(cfgVarName)) {
            log.error("Found END");
        } else if ("FORMAT".equalsIgnoreCase(cfgVarName)) {
            util.setFormat(cfgVarValue);
        } else if ("MULTIPLE_OCCURANCES".equalsIgnoreCase(cfgVarName)) {
            util.setMultiOccurs("TRUE".equalsIgnoreCase(cfgVarValue) ? 0 : 1);
        } else if ("IGNORE_TRAILING_DATA".equalsIgnoreCase(cfgVarName)) {
            util.setIgnoreTrailingData("TRUE".equalsIgnoreCase(cfgVarValue) ? "0" : "1");
        } else if ("DS_CONFIG_FILE_NAME".equalsIgnoreCase(cfgVarName)) {
            util.setDsConfigFileName(cfgVarValue);
        } else if ("HEADER_LENGTH".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setRecLen(Integer.valueOf(cfgVarValue));
        } else if ("HEADER_ID_POSITION".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setRecIdPos(Integer.valueOf(cfgVarValue) - 1);
        } else if ("HEADER_DATE_START_POSITION".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setDateIdPos(Integer.valueOf(cfgVarValue) - 1);
        } else if ("HEADER_DATE_LENGTH".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setDateIdLen(Integer.valueOf(cfgVarValue));
        } else if ("HEADER_IDENTIFIER".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setRecId(cfgVarValue);
        } else if ("HEADER_FILE_NAME".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setOutFileName(cfgVarValue);
        } else if ("HEADER_ID_LENGTH".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setRecIdLen(cfgVarValue);
        } else if ("HEADER_SCHEMA_FILE".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setSchemaFile(cfgVarValue);
        } else if ("HEADER_TABLE_NAME".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setTableName(cfgVarValue);
        } else if ("HEADER_LOAD_JOB_NAME".equalsIgnoreCase(cfgVarName)) {
            util.getHdrRecDTO().setLoadJobName(cfgVarValue);
        } else if ("TRAILER_ID_POSITION".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setRecIdPos(Integer.valueOf(cfgVarValue) - 1);
        } else if ("TRAILER_ID_LENGTH".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setRecIdLen(cfgVarValue);
        } else if ("TRAILER_IDENTIFIER".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setRecId(cfgVarValue);
        } else if ("TRAILER_LENGTH".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setRecLen(Integer.valueOf(cfgVarValue));
        } else if ("TRAILER_FILE_NAME".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setOutFileName(cfgVarValue);
        } else if ("TRAILER_PEEK_LENGTH".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setPeekLen(Integer.valueOf(cfgVarValue));
        } else if ("TRAILER_SCHEMA_FILE".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setSchemaFile(cfgVarValue);
        } else if ("TRAILER_TABLE_NAME".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setTableName(cfgVarValue);
        } else if ("TRAILER_LOAD_JOB_NAME".equalsIgnoreCase(cfgVarName)) {
            util.getTrlRecDTO().setLoadJobName(cfgVarValue);
        } else if ("CUSTOM_MAP_OVERRIDE".equalsIgnoreCase(cfgVarName)) {
            util.setCustomMapOverride("TRUE".equals(cfgVarValue) ? 0 : 1);
        } else if ("CUSTOM_MAP_HDR_TRL_OVERRIDE".equalsIgnoreCase(cfgVarName)) {
            util.setCustomMapHdrTrlOverride("TRUE".equals(cfgVarValue) ? 0 : 1);
        } else if ("LOAD_METHOD".equalsIgnoreCase(cfgVarName)) {
            util.setLoadMethod(cfgVarValue);
        } else if ("ETC_DIR".equalsIgnoreCase(cfgVarName) ||
                "BIN_DIR".equalsIgnoreCase(cfgVarName) ||
                "PRCS_ID".equalsIgnoreCase(cfgVarName) ||
                "SCHEMA_NAME".equalsIgnoreCase(cfgVarName) ||
                "PROCESS_NAME".equalsIgnoreCase(cfgVarName) ||
                "HEADER_DATE_FORMAT".equalsIgnoreCase(cfgVarName) ||
                "ORIGINAL_FILE_NAME".equalsIgnoreCase(cfgVarName) ||
                "DEV_ORIGINAL_FILE_NAME".equalsIgnoreCase(cfgVarName) ||
                "QA_ORIGINAL_FILE_NAME".equalsIgnoreCase(cfgVarName) ||
                "PROD_ORIGINAL_FILE_NAME".equalsIgnoreCase(cfgVarName) ||
                "FILE_ID_START_POSITION".equalsIgnoreCase(cfgVarName) ||
                "FILE_ID_LENGTH".equalsIgnoreCase(cfgVarName) ||
                "GENSPLITTER_SPLIT_PROGRAM".equalsIgnoreCase(cfgVarName)) {
            util.setI(1);
        }
        return util;
    }

    public static GenSplitterDTO assignCfgValuesDTO(GenSplitterDTO genSplitterDTO, String cfgVarName, String cfgVarValue){
        if("IDENTIFIER".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setRecId(cfgVarValue);
        }else if("DETAIL_LENGTH".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setInRecLen(Integer.valueOf(cfgVarValue));
        }else if("OUT_LENGTH".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setOutRecLen(Integer.valueOf(cfgVarValue));
        }else if("RECORD_TYPE".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setRecordType(cfgVarValue);
        }else if("DETAIL_PEEK_LENGTH".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlPeekLen(Integer.valueOf(cfgVarValue));
        }else if("FILE_NAME".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setOutFileName(cfgVarValue);
        }else if("DETAIL_LENGTH_POSITION".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlLenPos(Integer.valueOf(cfgVarValue));
        }else if("DETAIL_ID_POSITION".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlIdPos(Integer.valueOf(cfgVarValue));
        }else if("DETAIL_LENGTH_LENGTH".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlLenLen(Integer.valueOf(cfgVarValue));
        }else if("DETAIL_OCCURS_POSITION".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlOccursPos(Integer.valueOf(cfgVarValue));
        }else if("DETAIL_OCCURS_LENGTH".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlOccursSegLen(Integer.valueOf(cfgVarValue));
        }else if("DETAIL_OCCURS_DATATYPE".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlOccursDataType(cfgVarValue);
        }else if("DETAIL_LENGTH_DATATYPE".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlLenDataType(cfgVarValue);
        }else if("DETAIL_ID_LENGTH".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlIdLen(Integer.valueOf(cfgVarValue));
        }else if("DETAIL_PEEK_LENGTH".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlPeekLen(Integer.valueOf(cfgVarValue));
        }else if("CHILD_PEEK_LENGTH".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setChildPeekLen(Integer.valueOf(cfgVarValue));
        }else if("DETAIL_RECORD_LENGTH_ADJ".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlRecLenAdj(Integer.valueOf(cfgVarValue));
        }else if("DETAIL_SCHEMA_FILE".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setSchemaFile(cfgVarValue);
        }else if("DETAIL_TABLE_NAME".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setTableName(cfgVarValue);
        }else if("DETAIL_SUM_COLUMN".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlSumColumn(cfgVarValue);
        }else if("DETAIL_GROUP_COLUMN".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setGrpColumn(cfgVarValue);
        }else if("DETAIL_RECORD_TYPE".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setRecordType(cfgVarValue);
        }else if("DETAIL_LOAD_JOB_NAME".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setLoadJobName(cfgVarValue);
        }else if("DETAIL_FILE_SUM_COLUMN".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDtlSumColumn(cfgVarValue);
        }else if("DETAIL_TRAILER_SUM_COLUMN".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setTrailerSumColumn(cfgVarValue);
        }else if("DUPLICATE_FILE_FLAG".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setDupFileFlag("TRUE".equals(cfgVarValue) ? "0" : "1");
        }else if("DETAIL_ERROR_TOLERANCE_COUNT".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setErrorToleranceCount(cfgVarValue);
        }else if("DETAIL_TRAILER_COUNT_COLUMN".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setTrailerCountColumn(cfgVarValue);
        }else if("PIPE_FILE".equalsIgnoreCase(cfgVarName)){
            genSplitterDTO.setPipeFileFlag("TRUE".equals(cfgVarValue)? "0" : "1");
        }else{
            log.error("UNknown Variable found in the config file :" + cfgVarName);
            System.exit(1);
        }
        return genSplitterDTO;
    }

    public DriverUtilDTO resetVars(DriverUtilDTO util){
        util.setDepthLevel(0);
        util.setMultiOccurs(0);
        util.setIgnoreTrailingData("");
        util.setTotBytesRead(0.0);
        util.setEndOfFile("");
        util.setFoundTrailer("");
        util.setUnknownRecsRead(0);
        util.setHdrRecDTO(new HdrTrlRecTypeDTO());
        util.getHdrRecDTO().setRecId("H");
        util.setTrlRecDTO(new HdrTrlRecTypeDTO());
        util.getTrlRecDTO().setRecId("T");
        util.setStartDtlRecDTO(null);
        return util;
    }

    public static void generateDsConfigFile(DriverUtilDTO driverUtilDTO) {
        File outfile = new File(driverUtilDTO.getDsConfigFileName() + "/" + driverUtilDTO.getOutFilePath());
        StringBuffer sb = new StringBuffer();
        if(driverUtilDTO.getHdrRecDTO().getRecLen() > 0)
        {
            if(driverUtilDTO.getHdrRecDTO().getLoadJobName().length() == 0){
                sb.append("utilLoadSeqFileOra.").append(driverUtilDTO.getHdrRecDTO().getTableName());
                sb.append("\n");
            }
        }
        if(driverUtilDTO.getTrlRecDTO().getRecLen() > 0){
            if(driverUtilDTO.getTrlRecDTO().getLoadJobName().length() == 0) {
                sb.append("utilLoadSeqFileOra.").append(driverUtilDTO.getTrlRecDTO().getTableName());
            }
        }
        //TODO Add Current Struct, Child Struct, Next Struct Code In Here.

    }
}
