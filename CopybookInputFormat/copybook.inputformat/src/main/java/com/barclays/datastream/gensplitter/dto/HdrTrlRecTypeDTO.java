package com.barclays.datastream.gensplitter.dto;

/**
 * Created by hadoop on 2/24/15.
 */
public class HdrTrlRecTypeDTO {
    
    public HdrTrlRecTypeDTO(){
        this.recId = "";
        this.recIdPos = 1;
        this.dateIdPos = -1;
        this.recIdLen = "";
        this.recLen = 0;
        this.outFileName = "";
    }
    
    private String recId;
    private int recIdPos;
    private int dateIdPos;
    private int dateIdLen;
    private String recIdLen;
    private int recLen;
    private String outFileName;
    private int peekLen;
    private int fileId;
    private String tableName;
    private String schemaFile;
    private String loadJobName;

    public String getRecId() {
        return recId;
    }

    public void setRecId(String recId) {
        this.recId = recId;
    }

    public int getRecIdPos() {
        return recIdPos;
    }

    public void setRecIdPos(int recIdPos) {
        this.recIdPos = recIdPos;
    }

    public int getDateIdPos() {
        return dateIdPos;
    }

    public void setDateIdPos(int dateIdPos) {
        this.dateIdPos = dateIdPos;
    }

    public int getDateIdLen() {
        return dateIdLen;
    }

    public void setDateIdLen(int dateIdLen) {
        this.dateIdLen = dateIdLen;
    }

    public String getRecIdLen() {
        return recIdLen;
    }

    public void setRecIdLen(String recIdLen) {
        this.recIdLen = recIdLen;
    }

    public int getRecLen() {
        return recLen;
    }

    public void setRecLen(int recLen) {
        this.recLen = recLen;
    }

    public String getOutFileName() {
        return outFileName;
    }

    public void setOutFileName(String outFileName) {
        this.outFileName = outFileName;
    }

    public int getPeekLen() {
        return peekLen;
    }

    public void setPeekLen(int peekLen) {
        this.peekLen = peekLen;
    }

    public int getFileId() {
        return fileId;
    }

    public void setFileId(int fileId) {
        this.fileId = fileId;
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

    public String getLoadJobName() {
        return loadJobName;
    }

    public void setLoadJobName(String loadJobName) {
        this.loadJobName = loadJobName;
    }
}
