package com.cloudera.sa.copybook;

/**
 * Created by hadoop on 2/11/15.
 */
public class OccursRepeat {

    public static void main(String[] args) {
        String str = "15 AM04-NUM-PASTDUE-LTD PIC S9(3) COMP-3.";
        for(int i =1; i<=12;i++)
        {
            String[] strings = str.split(" ");
            System.out.println(strings[0] + " " + strings[1].concat(String.valueOf(i)) + " " +strings[2] + " " + strings[3] + " " + strings[4]);
            
        }
    }
    
}
