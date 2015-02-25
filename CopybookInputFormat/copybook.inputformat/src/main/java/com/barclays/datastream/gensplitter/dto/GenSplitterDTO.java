package com.barclays.datastream.gensplitter.dto;

/**
 * Created by hadoop on 2/24/15.
 */
public class GenSplitterDTO {
    private String recId;
    private int dtlPeekLen;
    private int inRecLen;
    private int outRecLen;
    private String outFileName;
    private int dtlIdPos;
    private int dtlIdLen;
    private int dtlLenLen;
    private String dtlLenDataType;
    private String dtlOccursDataType;
    private int dtlOccursPos;
    private int dtlLenPos;
    private int dtlOccursSegLen;
    private int outFileId;
    private String recType;
    private int recsRead;
    private int recsWritten;
    private int dtlRecLenAdj;
    private int childPeekLen;
    private int userExitRtn;
    private String recordType;
    private String tableName;
    private String schemaFile;
    private String sumColumn;
    private String grpColumn;
    private String loadJobName;
    private String dtlSumColumn;
    private String trailerSumColumn;
    private String trailerCountColumn;
    private String errorToleranceCount;
    private String pipeFileFlag;
    private String dupFileFlag;

    public String getFormat() {
        return format;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    private String format;
    
    

    public int getDtlLenLen() {
        return dtlLenLen;
    }

    public void setDtlLenLen(int dtlLenLen) {
        this.dtlLenLen = dtlLenLen;
    }

    public String getRecId() {
        return recId;
    }

    public void setRecId(String recId) {
        this.recId = recId;
    }

    public int getDtlPeekLen() {
        return dtlPeekLen;
    }

    public void setDtlPeekLen(int dtlPeekLen) {
        this.dtlPeekLen = dtlPeekLen;
    }

    public int getInRecLen() {
        return inRecLen;
    }

    public void setInRecLen(int inRecLen) {
        this.inRecLen = inRecLen;
    }

    public int getOutRecLen() {
        return outRecLen;
    }

    public void setOutRecLen(int outRecLen) {
        this.outRecLen = outRecLen;
    }

    public String getOutFileName() {
        return outFileName;
    }

    public void setOutFileName(String outFileName) {
        this.outFileName = outFileName;
    }

    public int getDtlIdPos() {
        return dtlIdPos;
    }

    public void setDtlIdPos(int dtlIdPos) {
        this.dtlIdPos = dtlIdPos;
    }

    public int getDtlIdLen() {
        return dtlIdLen;
    }

    public void setDtlIdLen(int dtlIdLen) {
        this.dtlIdLen = dtlIdLen;
    }

    public String getDtlLenDataType() {
        return dtlLenDataType;
    }

    public void setDtlLenDataType(String dtlLenDataType) {
        this.dtlLenDataType = dtlLenDataType;
    }

    public String getDtlOccursDataType() {
        return dtlOccursDataType;
    }

    public void setDtlOccursDataType(String dtlOccursDataType) {
        this.dtlOccursDataType = dtlOccursDataType;
    }

    public int getDtlOccursPos() {
        return dtlOccursPos;
    }

    public void setDtlOccursPos(int dtlOccursPos) {
        this.dtlOccursPos = dtlOccursPos;
    }

    public int getDtlLenPos() {
        return dtlLenPos;
    }

    public void setDtlLenPos(int dtlLenPos) {
        this.dtlLenPos = dtlLenPos;
    }

    public int getDtlOccursSegLen() {
        return dtlOccursSegLen;
    }

    public void setDtlOccursSegLen(int dtlOccursSegLen) {
        this.dtlOccursSegLen = dtlOccursSegLen;
    }

    public int getOutFileId() {
        return outFileId;
    }

    public void setOutFileId(int outFileId) {
        this.outFileId = outFileId;
    }

    public String getRecType() {
        return recType;
    }

    public void setRecType(String recType) {
        this.recType = recType;
    }

    public int getRecsRead() {
        return recsRead;
    }

    public void setRecsRead(int recsRead) {
        this.recsRead = recsRead;
    }

    public int getRecsWritten() {
        return recsWritten;
    }

    public void setRecsWritten(int recsWritten) {
        this.recsWritten = recsWritten;
    }

    public int getDtlRecLenAdj() {
        return dtlRecLenAdj;
    }

    public void setDtlRecLenAdj(int dtlRecLenAdj) {
        this.dtlRecLenAdj = dtlRecLenAdj;
    }

    public int getChildPeekLen() {
        return childPeekLen;
    }

    public void setChildPeekLen(int childPeekLen) {
        this.childPeekLen = childPeekLen;
    }

    public int getUserExitRtn() {
        return userExitRtn;
    }

    public void setUserExitRtn(int userExitRtn) {
        this.userExitRtn = userExitRtn;
    }

    public String getRecordType() {
        return recordType;
    }

    public void setRecordType(String recordType) {
        this.recordType = recordType;
    }

    public String getTableName() {
        return tableName;
    }

    public void setTableName(String tableName) {
        this.tableName = tableName;
    }

    public String getSchemaFile() {
        return schemaFile;
    }

    public void setSchemaFile(String schemaFile) {
        this.schemaFile = schemaFile;
    }

    public String getSumColumn() {
        return sumColumn;
    }

    public void setSumColumn(String sumColumn) {
        this.sumColumn = sumColumn;
    }

    public String getGrpColumn() {
        return grpColumn;
    }

    public void setGrpColumn(String grpColumn) {
        this.grpColumn = grpColumn;
    }

    public String getLoadJobName() {
        return loadJobName;
    }

    public void setLoadJobName(String loadJobName) {
        this.loadJobName = loadJobName;
    }

    public String getDtlSumColumn() {
        return dtlSumColumn;
    }

    public void setDtlSumColumn(String dtlSumColumn) {
        this.dtlSumColumn = dtlSumColumn;
    }

    public String getTrailerSumColumn() {
        return trailerSumColumn;
    }

    public void setTrailerSumColumn(String trailerSumColumn) {
        this.trailerSumColumn = trailerSumColumn;
    }

    public String getTrailerCountColumn() {
        return trailerCountColumn;
    }

    public void setTrailerCountColumn(String trailerCountColumn) {
        this.trailerCountColumn = trailerCountColumn;
    }

    public String getErrorToleranceCount() {
        return errorToleranceCount;
    }

    public void setErrorToleranceCount(String errorToleranceCount) {
        this.errorToleranceCount = errorToleranceCount;
    }

    public String getPipeFileFlag() {
        return pipeFileFlag;
    }

    public void setPipeFileFlag(String pipeFileFlag) {
        this.pipeFileFlag = pipeFileFlag;
    }

    public String getDupFileFlag() {
        return dupFileFlag;
    }

    public void setDupFileFlag(String dupFileFlag) {
        this.dupFileFlag = dupFileFlag;
    }

    public static void initializeGenSplitterDTO(GenSplitterDTO genSplitterDTO){
        genSplitterDTO.setRecId("");
        genSplitterDTO.setInRecLen(0);
        genSplitterDTO.setOutRecLen(0);
        genSplitterDTO.setDtlPeekLen(0);
        genSplitterDTO.setDtlRecLenAdj(0);
        genSplitterDTO.setDtlLenPos(-1);
        genSplitterDTO.setDtlIdPos(-1);
        genSplitterDTO.setDtlOccursSegLen(1);
        genSplitterDTO.setDtlLenLen(2);
        genSplitterDTO.setDtlLenDataType("Binary");
        genSplitterDTO.setDtlIdLen(0);
        genSplitterDTO.setRecsRead(0);
        genSplitterDTO.setRecsWritten(0);
        genSplitterDTO.setErrorToleranceCount("0");
        genSplitterDTO.setOutFileId(0);
        genSplitterDTO.setOutFileName("");
        genSplitterDTO.setRecType("FIXED");
        genSplitterDTO.setPipeFileFlag("1");
        genSplitterDTO.setDupFileFlag("0");

    }
}
