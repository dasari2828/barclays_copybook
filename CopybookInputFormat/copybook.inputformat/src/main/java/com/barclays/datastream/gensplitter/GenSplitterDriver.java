package com.barclays.datastream.gensplitter;

import com.barclays.datastream.gensplitter.dto.DriverUtilDTO;
import com.barclays.datastream.gensplitter.dto.GenSplitterDTO;
import com.barclays.datastream.gensplitter.util.GenSplitterUtil;
import org.apache.log4j.Level;
import org.apache.log4j.Logger;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;

/**
 * Created by hadoop on 2/24/15.
 */
public class GenSplitterDriver {
    static Logger log = Logger.getLogger(GenSplitterDriver.class);
    public static Logger getLog() {
        return log;
    }

    public static void setLog(Logger log) {
        GenSplitterDriver.log = log;
    }
    public static void main(String[] args) throws Exception{
        DriverUtilDTO driverUtilDTO = new DriverUtilDTO();
        GenSplitterDriver driver = new GenSplitterDriver(); 
        GenSplitterUtil util = new GenSplitterUtil();
      log.setLevel(Level.DEBUG);  
      if(args.length <4){
          System.out.println("Usage:" +
                  "1) Input File Name" +
                  "2) Output Path" +
                  "3) Config File Name" +
                  "4) Prcss Id or Primer");
          System.exit(1);
      }

        BufferedInputStream inputStream = new BufferedInputStream(new FileInputStream(args[0]));
        driverUtilDTO.setPrimerFlag("Primer".equalsIgnoreCase(args[4])? true:false);
        if(!driverUtilDTO.isPrimerFlag())
        {
            driverUtilDTO.setPrcssId(Long.valueOf(args[4]));
        }
        for(int confLoop =3; confLoop<args.length; confLoop++){
            driverUtilDTO.setCfgFileName(args[confLoop]);
            util.resetVars(driverUtilDTO);
            BufferedInputStream cfgFileStream = new BufferedInputStream(new FileInputStream(args[2]));
            Scanner scanner = new Scanner(cfgFileStream);
            while(scanner.hasNextLine()){
              String tmpLine = scanner.nextLine();
                if(tmpLine != null && tmpLine.trim() != "") {
                    if ("BEGIN".equalsIgnoreCase(tmpLine.trim().substring(0,5))) {
                        driverUtilDTO.setCfgVarName("BEGIN");
                    } else if ("END".equalsIgnoreCase(tmpLine.trim().substring(0,3))) {
                        driverUtilDTO.setCfgVarName("END");
                    }else if(tmpLine.startsWith("#")) {
                        driverUtilDTO.setCfgVarName("COMMENT");
                    }else if(tmpLine.length() > 0){
                        int indexOf = tmpLine.indexOf('=');
                        if(indexOf > 0)
                            driverUtilDTO.setCfgVarValue(tmpLine.substring(0,indexOf));
                        else {
                            log.error("ERROR on Config line. No Equals Found");
                            System.exit(1);
                        }
                    }                        
                    
                }else if(tmpLine.trim() == ""){
                    driverUtilDTO.setCfgLine("");
                }
            }
            GenSplitterDTO childDTO = new GenSplitterDTO();
            if("BEGIN".equalsIgnoreCase(driverUtilDTO.getCfgVarName())){
                int depthLevel  = driverUtilDTO.getDepthLevel()+1;
                driverUtilDTO.setDepthLevel(depthLevel);
                if(driverUtilDTO.getStartDtlRecDTO() == null){
                    GenSplitterDTO startDtlRecDTO = new GenSplitterDTO();
                    driverUtilDTO.getLevelNodeDTO().add(startDtlRecDTO);
                    driverUtilDTO.setStartDtlRecDTO(startDtlRecDTO);
                    
                }else{
                    if(driverUtilDTO.getLevelNodeDTO().get(
                            driverUtilDTO.getDepthLevel()) == null){
                        driverUtilDTO.setCurrDTO(driverUtilDTO
                                .getLevelNodeDTO()
                                .get(driverUtilDTO.getDepthLevel() - 1));
                        childDTO = driverUtilDTO.getStartDtlRecDTO();

                    }else{
                        driverUtilDTO.setCurrDTO(driverUtilDTO
                                .getLevelNodeDTO()
                                .get(driverUtilDTO.getDepthLevel()));
                        driverUtilDTO.setNextDTO(new GenSplitterDTO());
                    }
                }
                GenSplitterDTO.initializeGenSplitterDTO(driverUtilDTO.getCurrDTO());
            }else if("END".equalsIgnoreCase(driverUtilDTO.getCfgVarName())){
                //driverUtilDTO.getLevelNodeDTO().get(driverUtilDTO.getDepthLevel()+1)
                //TODO Implement This
            }else{
                if("COMMENT".equalsIgnoreCase(driverUtilDTO.getCfgVarName())){
                    driverUtilDTO.setCurrDTO(GenSplitterUtil.assignCfgValuesDTO(driverUtilDTO.getCurrDTO(), driverUtilDTO.getCfgVarName(), driverUtilDTO.getCfgVarValue()));
                    driverUtilDTO = util.assignCfgValuesUtil(driverUtilDTO.getCfgVarName(), driverUtilDTO.getCfgVarValue(), driverUtilDTO);
                }
            }
            if(driverUtilDTO.getStartDtlRecDTO() == null){
                log.error("There were no detail record definitions. Is there just a header and a trailer?");
            }
            if(driverUtilDTO.getDepthLevel() != 0){
                log.error("The number of BEGIN and END statements are not matching up");
            }
            if(driverUtilDTO.getDsConfigFileName() == null || driverUtilDTO.getDsConfigFileName().trim() == ""){
                GenSplitterUtil.generateDsConfigFile(driverUtilDTO);
            }
        }
        
    }
}
