package com.barclays.datastream.gensplitter.dto;

import org.apache.log4j.Logger;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by hadoop on 2/25/15.
 */
public class DriverUtilDTO {
    String cfgFileName;
    String cfgLine;
    String cfgVarName;
    String cfgVarValue;
    int i,j;
    GenSplitterDTO currDTO;
    GenSplitterDTO nextDTO;
    List<GenSplitterDTO> levelNodeDTO = new ArrayList<GenSplitterDTO>();
    GenSplitterDTO startDtlRecDTO = new GenSplitterDTO();
    HdrTrlRecTypeDTO hdrRecDTO = new HdrTrlRecTypeDTO();
    HdrTrlRecTypeDTO trlRecDTO = new HdrTrlRecTypeDTO();
    int depthLevel = 0;
    int cfgLoop;
    String moreBytes;
    String outFilePath;
    String numParams;
    boolean primerFlag;
    long prcssId;
    int multiOccurs = 0;
    int printUnknowns;
    String format;
    String loadMethod;
    Double totBytesRead = 0.0;
    int bytesRead;
    String endOfFile = new String();
    String foundTrailer = new String();
    char[] inRecBuff = new char[32767];
    int unknownRecsRead = 0;
    String ignoreTrailingData = new String();
    int totRecsRead = 0;
    int totRecsWrite = 0;
    int hdrRecCnt = 0;
    int trlRecCnt = 0;
    int customMapHdrTrlOverride = 0;
    int customMapOverride;
    String prcssDate;
    String dsConfigFileName;
    char[] sqlLdrHdr = new char[20];

    public int getCustomMapOverride() {
        return customMapOverride;
    }

    public void setCustomMapOverride(int customMapOverride) {
        this.customMapOverride = customMapOverride;
    }

    public String getCfgFileName() {
        return cfgFileName;
    }

    public void setCfgFileName(String cfgFileName) {
        this.cfgFileName = cfgFileName;
    }

    public String getCfgLine() {
        return cfgLine;
    }

    public void setCfgLine(String cfgLine) {
        this.cfgLine = cfgLine;
    }

    public String getCfgVarName() {
        return cfgVarName;
    }

    public void setCfgVarName(String cfgVarName) {
        this.cfgVarName = cfgVarName;
    }

    public String getCfgVarValue() {
        return cfgVarValue;
    }

    public void setCfgVarValue(String cfgVarValue) {
        this.cfgVarValue = cfgVarValue;
    }

    public int getI() {
        return i;
    }

    public void setI(int i) {
        this.i = i;
    }

    public int getJ() {
        return j;
    }

    public void setJ(int j) {
        this.j = j;
    }

    public GenSplitterDTO getCurrDTO() {
        return currDTO;
    }

    public void setCurrDTO(GenSplitterDTO currDTO) {
        this.currDTO = currDTO;
    }

    public GenSplitterDTO getNextDTO() {
        return nextDTO;
    }

    public void setNextDTO(GenSplitterDTO nextDTO) {
        this.nextDTO = nextDTO;
    }

    public List<GenSplitterDTO> getLevelNodeDTO() {
        return levelNodeDTO;
    }

    public void setLevelNodeDTO(ArrayList<GenSplitterDTO> levelNodeDTO) {
        this.levelNodeDTO = levelNodeDTO;
    }

    public GenSplitterDTO getStartDtlRecDTO() {
        return startDtlRecDTO;
    }

    public void setStartDtlRecDTO(GenSplitterDTO startDtlRecDTO) {
        this.startDtlRecDTO = startDtlRecDTO;
    }

    public HdrTrlRecTypeDTO getHdrRecDTO() {
        return hdrRecDTO;
    }

    public void setHdrRecDTO(HdrTrlRecTypeDTO hdrRecDTO) {
        this.hdrRecDTO = hdrRecDTO;
    }

    public HdrTrlRecTypeDTO getTrlRecDTO() {
        return trlRecDTO;
    }

    public void setTrlRecDTO(HdrTrlRecTypeDTO trlRecDTO) {
        this.trlRecDTO = trlRecDTO;
    }

    public int getDepthLevel() {
        return depthLevel;
    }

    public void setDepthLevel(int depthLevel) {
        this.depthLevel = depthLevel;
    }

    public int getCfgLoop() {
        return cfgLoop;
    }

    public void setCfgLoop(int cfgLoop) {
        this.cfgLoop = cfgLoop;
    }

    public String getMoreBytes() {
        return moreBytes;
    }

    public void setMoreBytes(String moreBytes) {
        this.moreBytes = moreBytes;
    }

    public String getOutFilePath() {
        return outFilePath;
    }

    public void setOutFilePath(String outFilePath) {
        this.outFilePath = outFilePath;
    }

    public String getNumParams() {
        return numParams;
    }

    public void setNumParams(String numParams) {
        this.numParams = numParams;
    }

    public boolean isPrimerFlag() {
        return primerFlag;
    }

    public void setPrimerFlag(boolean primerFlag) {
        this.primerFlag = primerFlag;
    }

    public long getPrcssId() {
        return prcssId;
    }

    public void setPrcssId(long prcssId) {
        this.prcssId = prcssId;
    }

    public int getMultiOccurs() {
        return multiOccurs;
    }

    public void setMultiOccurs(int multiOccurs) {
        this.multiOccurs = multiOccurs;
    }

    public int getPrintUnknowns() {
        return printUnknowns;
    }

    public void setPrintUnknowns(int printUnknowns) {
        this.printUnknowns = printUnknowns;
    }

    public String getFormat() {
        return format;
    }

    public void setFormat(String format) {
        this.format = format;
    }

    public String getLoadMethod() {
        return loadMethod;
    }

    public void setLoadMethod(String loadMethod) {
        this.loadMethod = loadMethod;
    }

    public Double getTotBytesRead() {
        return totBytesRead;
    }

    public void setTotBytesRead(Double totBytesRead) {
        this.totBytesRead = totBytesRead;
    }

    public int getBytesRead() {
        return bytesRead;
    }

    public void setBytesRead(int bytesRead) {
        this.bytesRead = bytesRead;
    }

    public String getEndOfFile() {
        return endOfFile;
    }

    public void setEndOfFile(String endOfFile) {
        this.endOfFile = endOfFile;
    }

    public String getFoundTrailer() {
        return foundTrailer;
    }

    public void setFoundTrailer(String foundTrailer) {
        this.foundTrailer = foundTrailer;
    }

    public char[] getInRecBuff() {
        return inRecBuff;
    }

    public void setInRecBuff(char[] inRecBuff) {
        this.inRecBuff = inRecBuff;
    }

    public int getUnknownRecsRead() {
        return unknownRecsRead;
    }

    public void setUnknownRecsRead(int unknownRecsRead) {
        this.unknownRecsRead = unknownRecsRead;
    }

    public String getIgnoreTrailingData() {
        return ignoreTrailingData;
    }

    public void setIgnoreTrailingData(String ignoreTrailingData) {
        this.ignoreTrailingData = ignoreTrailingData;
    }

    public int getTotRecsRead() {
        return totRecsRead;
    }

    public void setTotRecsRead(int totRecsRead) {
        this.totRecsRead = totRecsRead;
    }

    public int getTotRecsWrite() {
        return totRecsWrite;
    }

    public void setTotRecsWrite(int totRecsWrite) {
        this.totRecsWrite = totRecsWrite;
    }

    public int getHdrRecCnt() {
        return hdrRecCnt;
    }

    public void setHdrRecCnt(int hdrRecCnt) {
        this.hdrRecCnt = hdrRecCnt;
    }

    public int getTrlRecCnt() {
        return trlRecCnt;
    }

    public void setTrlRecCnt(int trlRecCnt) {
        this.trlRecCnt = trlRecCnt;
    }

    public int getCustomMapHdrTrlOverride() {
        return customMapHdrTrlOverride;
    }

    public void setCustomMapHdrTrlOverride(int customMapHdrTrlOverride) {
        this.customMapHdrTrlOverride = customMapHdrTrlOverride;
    }

    public String getPrcssDate() {
        return prcssDate;
    }

    public void setPrcssDate(String prcssDate) {
        this.prcssDate = prcssDate;
    }

    public String getDsConfigFileName() {
        return dsConfigFileName;
    }

    public void setDsConfigFileName(String dsConfigFileName) {
        this.dsConfigFileName = dsConfigFileName;
    }

    public char[] getSqlLdrHdr() {
        return sqlLdrHdr;
    }

    public void setSqlLdrHdr(char[] sqlLdrHdr) {
        this.sqlLdrHdr = sqlLdrHdr;
    }
}
