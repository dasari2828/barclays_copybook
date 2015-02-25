ADD JAR hdfs://ddas1029a.juniper.com:8020/user/admin/jar_files/copybookInputFormat.jar;
CREATE EXTERNAL TABLE IF NOT EXISTS AM02Tbl
(
  AM02_SEGMENT_LENGTH DOUBLE,
  AM02_PAYMENT_STATUS_CTD STRING,
  AM02_PAYMENT_TIMING_CTD STRING,
  AM02_COLLECTION_AGENCY STRING,
  AM02_BILL_STMT_AT_CYCLE1 STRING,
  AM02_BILL_STMT_AT_CYCLE2 STRING,
  AM02_BILL_STMT_AT_CYCLE3 STRING,
  AM02_BILL_STMT_AT_CYCLE4 STRING,
  AM02_BILL_STMT_AT_CYCLE5 STRING,
  AM02_BILL_STMT_AT_CYCLE6 STRING,
  AM02_BILL_STMT_AT_CYCLE7 STRING,
  AM02_BILL_STMT_AT_CYCLE8 STRING,
  AM02_BILL_STMT_AT_CYCLE9 STRING,
  AM02_BILL_STMT_AT_CYCLE10 STRING,
  AM02_BILL_STMT_AT_CYCLE11 STRING,
  AM02_BILL_STMT_AT_CYCLE12 STRING,
  AM02_BILL_STMT_AT_CYCLE13 STRING,
  AM02_BILL_STMT_AT_CYCLE14 STRING,
  AM02_BILL_STMT_AT_CYCLE15 STRING,
  AM02_BILL_STMT_AT_CYCLE16 STRING,
  AM02_BILL_STMT_AT_CYCLE17 STRING,
  AM02_BILL_STMT_AT_CYCLE18 STRING,
  AM02_BILL_STMT_AT_CYCLE19 STRING,
  AM02_BILL_STMT_AT_CYCLE20 STRING,
  AM02_BILL_STMT_AT_CYCLE21 STRING,
  AM02_BILL_STMT_AT_CYCLE22 STRING,
  AM02_BILL_STMT_AT_CYCLE23 STRING,
  AM02_BILL_STMT_AT_CYCLE24 STRING,
  AM02_BILL_STMT_AT_CYCLE25 STRING,
  AM02_BILL_STMT_AT_CYCLE26 STRING,
  AM02_BILL_STMT_AT_CYCLE27 STRING,
  AM02_BILL_STMT_AT_CYCLE28 STRING,
  AM02_BILL_STMT_AT_CYCLE29 STRING,
  AM02_BILL_STMT_AT_CYCLE30 STRING,
  AM02_BILL_STMT_AT_CYCLE31 STRING,
  AM02_BILL_STMT_AT_CYCLE32 STRING,
  AM02_BILL_STMT_AT_CYCLE33 STRING,
  AM02_BILL_STMT_AT_CYCLE34 STRING,
  AM02_BILL_STMT_AT_CYCLE35 STRING,
  AM02_BILL_STMT_AT_CYCLE36 STRING,
  AM02_BILL_STMT_AT_CYCLE37 STRING,
  AM02_BILL_STMT_AT_CYCLE38 STRING,
  AM02_BILL_STMT_AT_CYCLE39 STRING,
  AM02_BILL_STMT_AT_CYCLE40 STRING,
  AM02_BILL_STMT_AT_CYCLE41 STRING,
  AM02_BILL_STMT_AT_CYCLE42 STRING,
  AM02_BILL_STMT_AT_CYCLE43 STRING,
  AM02_BILL_STMT_AT_CYCLE44 STRING,
  AM02_BILL_STMT_AT_CYCLE45 STRING,
  AM02_BILL_STMT_AT_CYCLE46 STRING,
  AM02_BILL_STMT_AT_CYCLE47 STRING,
  AM02_BILL_STMT_AT_CYCLE48 STRING,
  AM02_BILL_STMT_AT_CYCLE49 STRING,
  AM02_BILL_STMT_AT_CYCLE50 STRING,
  AM02_BILL_STMT_AT_CYCLE51 STRING,
  AM02_BILL_STMT_AT_CYCLE52 STRING,
  AM02_BILL_STMT_AT_CYCLE53 STRING,
  AM02_BILL_STMT_AT_CYCLE54 STRING,
  AM02_BILL_STMT_AT_CYCLE55 STRING,
  AM02_BILL_STMT_AT_CYCLE56 STRING,
  AM02_BILL_STMT_AT_CYCLE57 STRING,
  AM02_BILL_STMT_AT_CYCLE58 STRING,
  AM02_BILL_STMT_AT_CYCLE59 STRING,
  AM02_BILL_STMT_AT_CYCLE60 STRING,
  AM02_BILL_STMT_AT_CYCLE61 STRING,
  AM02_BILL_STMT_AT_CYCLE62 STRING,
  AM02_BILL_STMT_AT_CYCLE63 STRING,
  AM02_BILL_STMT_AT_CYCLE64 STRING,
  AM02_BILL_STMT_AT_CYCLE65 STRING,
  AM02_BILL_STMT_AT_CYCLE66 STRING,
  AM02_BILL_STMT_AT_CYCLE67 STRING,
  AM02_BILL_STMT_AT_CYCLE68 STRING,
  AM02_BILL_STMT_AT_CYCLE69 STRING,
  AM02_BILL_STMT_AT_CYCLE70 STRING,
  AM02_BILL_STMT_AT_CYCLE71 STRING,
  AM02_BILL_STMT_AT_CYCLE72 STRING,
  AM02_BILL_STMT_AT_CYCLE73 STRING,
  AM02_BILL_STMT_AT_CYCLE74 STRING,
  AM02_BILL_STMT_AT_CYCLE75 STRING,
  AM02_BILL_STMT_AT_CYCLE76 STRING,
  AM02_BILL_STMT_AT_CYCLE77 STRING,
  AM02_BILL_STMT_AT_CYCLE78 STRING,
  AM02_BILL_STMT_AT_CYCLE79 STRING,
  AM02_BILL_STMT_AT_CYCLE80 STRING,
  AM02_BILL_STMT_AT_CYCLE81 STRING,
  AM02_BILL_STMT_AT_CYCLE82 STRING,
  AM02_BILL_STMT_AT_CYCLE83 STRING,
  AM02_BILL_STMT_AT_CYCLE84 STRING,
  AM02_PASTDUE_AT_CYCLE1 STRING,
  AM02_PASTDUE_AT_CYCLE2 STRING,
  AM02_PASTDUE_AT_CYCLE3 STRING,
  AM02_PASTDUE_AT_CYCLE4 STRING,
  AM02_PASTDUE_AT_CYCLE5 STRING,
  AM02_PASTDUE_AT_CYCLE6 STRING,
  AM02_PASTDUE_AT_CYCLE7 STRING,
  AM02_PASTDUE_AT_CYCLE8 STRING,
  AM02_PASTDUE_AT_CYCLE9 STRING,
  AM02_PASTDUE_AT_CYCLE10 STRING,
  AM02_PASTDUE_AT_CYCLE11 STRING,
  AM02_PASTDUE_AT_CYCLE12 STRING,
  AM02_PASTDUE_AT_CYCLE13 STRING,
  AM02_PASTDUE_AT_CYCLE14 STRING,
  AM02_PASTDUE_AT_CYCLE15 STRING,
  AM02_PASTDUE_AT_CYCLE16 STRING,
  AM02_PASTDUE_AT_CYCLE17 STRING,
  AM02_PASTDUE_AT_CYCLE18 STRING,
  AM02_PASTDUE_AT_CYCLE19 STRING,
  AM02_PASTDUE_AT_CYCLE20 STRING,
  AM02_PASTDUE_AT_CYCLE21 STRING,
  AM02_PASTDUE_AT_CYCLE22 STRING,
  AM02_PASTDUE_AT_CYCLE23 STRING,
  AM02_PASTDUE_AT_CYCLE24 STRING,
  AM02_PASTDUE_AT_CYCLE25 STRING,
  AM02_PASTDUE_AT_CYCLE26 STRING,
  AM02_PASTDUE_AT_CYCLE27 STRING,
  AM02_PASTDUE_AT_CYCLE28 STRING,
  AM02_PASTDUE_AT_CYCLE29 STRING,
  AM02_PASTDUE_AT_CYCLE30 STRING,
  AM02_PASTDUE_AT_CYCLE31 STRING,
  AM02_PASTDUE_AT_CYCLE32 STRING,
  AM02_PASTDUE_AT_CYCLE33 STRING,
  AM02_PASTDUE_AT_CYCLE34 STRING,
  AM02_PASTDUE_AT_CYCLE35 STRING,
  AM02_PASTDUE_AT_CYCLE36 STRING,
  AM02_PASTDUE_AT_CYCLE37 STRING,
  AM02_PASTDUE_AT_CYCLE38 STRING,
  AM02_PASTDUE_AT_CYCLE39 STRING,
  AM02_PASTDUE_AT_CYCLE40 STRING,
  AM02_PASTDUE_AT_CYCLE41 STRING,
  AM02_PASTDUE_AT_CYCLE42 STRING,
  AM02_PASTDUE_AT_CYCLE43 STRING,
  AM02_PASTDUE_AT_CYCLE44 STRING,
  AM02_PASTDUE_AT_CYCLE45 STRING,
  AM02_PASTDUE_AT_CYCLE46 STRING,
  AM02_PASTDUE_AT_CYCLE47 STRING,
  AM02_PASTDUE_AT_CYCLE48 STRING,
  AM02_PASTDUE_AT_CYCLE49 STRING,
  AM02_PASTDUE_AT_CYCLE50 STRING,
  AM02_PASTDUE_AT_CYCLE51 STRING,
  AM02_PASTDUE_AT_CYCLE52 STRING,
  AM02_PASTDUE_AT_CYCLE53 STRING,
  AM02_PASTDUE_AT_CYCLE54 STRING,
  AM02_PASTDUE_AT_CYCLE55 STRING,
  AM02_PASTDUE_AT_CYCLE56 STRING,
  AM02_PASTDUE_AT_CYCLE57 STRING,
  AM02_PASTDUE_AT_CYCLE58 STRING,
  AM02_PASTDUE_AT_CYCLE59 STRING,
  AM02_PASTDUE_AT_CYCLE60 STRING,
  AM02_PASTDUE_AT_CYCLE61 STRING,
  AM02_PASTDUE_AT_CYCLE62 STRING,
  AM02_PASTDUE_AT_CYCLE63 STRING,
  AM02_PASTDUE_AT_CYCLE64 STRING,
  AM02_PASTDUE_AT_CYCLE65 STRING,
  AM02_PASTDUE_AT_CYCLE66 STRING,
  AM02_PASTDUE_AT_CYCLE67 STRING,
  AM02_PASTDUE_AT_CYCLE68 STRING,
  AM02_PASTDUE_AT_CYCLE69 STRING,
  AM02_PASTDUE_AT_CYCLE70 STRING,
  AM02_PASTDUE_AT_CYCLE71 STRING,
  AM02_PASTDUE_AT_CYCLE72 STRING,
  AM02_PASTDUE_AT_CYCLE73 STRING,
  AM02_PASTDUE_AT_CYCLE74 STRING,
  AM02_PASTDUE_AT_CYCLE75 STRING,
  AM02_PASTDUE_AT_CYCLE76 STRING,
  AM02_PASTDUE_AT_CYCLE77 STRING,
  AM02_PASTDUE_AT_CYCLE78 STRING,
  AM02_PASTDUE_AT_CYCLE79 STRING,
  AM02_PASTDUE_AT_CYCLE80 STRING,
  AM02_PASTDUE_AT_CYCLE81 STRING,
  AM02_PASTDUE_AT_CYCLE82 STRING,
  AM02_PASTDUE_AT_CYCLE83 STRING,
  AM02_PASTDUE_AT_CYCLE84 STRING,
  AM02_OVERLIMIT_AT_CYCLE1 STRING,
  AM02_OVERLIMIT_AT_CYCLE2 STRING,
  AM02_OVERLIMIT_AT_CYCLE3 STRING,
  AM02_OVERLIMIT_AT_CYCLE4 STRING,
  AM02_OVERLIMIT_AT_CYCLE5 STRING,
  AM02_OVERLIMIT_AT_CYCLE6 STRING,
  AM02_OVERLIMIT_AT_CYCLE7 STRING,
  AM02_OVERLIMIT_AT_CYCLE8 STRING,
  AM02_OVERLIMIT_AT_CYCLE9 STRING,
  AM02_OVERLIMIT_AT_CYCLE10 STRING,
  AM02_OVERLIMIT_AT_CYCLE11 STRING,
  AM02_OVERLIMIT_AT_CYCLE12 STRING,
  AM02_OVERLIMIT_AT_CYCLE13 STRING,
  AM02_OVERLIMIT_AT_CYCLE14 STRING,
  AM02_OVERLIMIT_AT_CYCLE15 STRING,
  AM02_OVERLIMIT_AT_CYCLE16 STRING,
  AM02_OVERLIMIT_AT_CYCLE17 STRING,
  AM02_OVERLIMIT_AT_CYCLE18 STRING,
  AM02_OVERLIMIT_AT_CYCLE19 STRING,
  AM02_OVERLIMIT_AT_CYCLE20 STRING,
  AM02_OVERLIMIT_AT_CYCLE21 STRING,
  AM02_OVERLIMIT_AT_CYCLE22 STRING,
  AM02_OVERLIMIT_AT_CYCLE23 STRING,
  AM02_OVERLIMIT_AT_CYCLE24 STRING,
  AM02_OVERLIMIT_AT_CYCLE25 STRING,
  AM02_OVERLIMIT_AT_CYCLE26 STRING,
  AM02_OVERLIMIT_AT_CYCLE27 STRING,
  AM02_OVERLIMIT_AT_CYCLE28 STRING,
  AM02_OVERLIMIT_AT_CYCLE29 STRING,
  AM02_OVERLIMIT_AT_CYCLE30 STRING,
  AM02_OVERLIMIT_AT_CYCLE31 STRING,
  AM02_OVERLIMIT_AT_CYCLE32 STRING,
  AM02_OVERLIMIT_AT_CYCLE33 STRING,
  AM02_OVERLIMIT_AT_CYCLE34 STRING,
  AM02_OVERLIMIT_AT_CYCLE35 STRING,
  AM02_OVERLIMIT_AT_CYCLE36 STRING,
  AM02_OVERLIMIT_AT_CYCLE37 STRING,
  AM02_OVERLIMIT_AT_CYCLE38 STRING,
  AM02_OVERLIMIT_AT_CYCLE39 STRING,
  AM02_OVERLIMIT_AT_CYCLE40 STRING,
  AM02_OVERLIMIT_AT_CYCLE41 STRING,
  AM02_OVERLIMIT_AT_CYCLE42 STRING,
  AM02_OVERLIMIT_AT_CYCLE43 STRING,
  AM02_OVERLIMIT_AT_CYCLE44 STRING,
  AM02_OVERLIMIT_AT_CYCLE45 STRING,
  AM02_OVERLIMIT_AT_CYCLE46 STRING,
  AM02_OVERLIMIT_AT_CYCLE47 STRING,
  AM02_OVERLIMIT_AT_CYCLE48 STRING,
  AM02_OVERLIMIT_AT_CYCLE49 STRING,
  AM02_OVERLIMIT_AT_CYCLE50 STRING,
  AM02_OVERLIMIT_AT_CYCLE51 STRING,
  AM02_OVERLIMIT_AT_CYCLE52 STRING,
  AM02_OVERLIMIT_AT_CYCLE53 STRING,
  AM02_OVERLIMIT_AT_CYCLE54 STRING,
  AM02_OVERLIMIT_AT_CYCLE55 STRING,
  AM02_OVERLIMIT_AT_CYCLE56 STRING,
  AM02_OVERLIMIT_AT_CYCLE57 STRING,
  AM02_OVERLIMIT_AT_CYCLE58 STRING,
  AM02_OVERLIMIT_AT_CYCLE59 STRING,
  AM02_OVERLIMIT_AT_CYCLE60 STRING,
  AM02_OVERLIMIT_AT_CYCLE61 STRING,
  AM02_OVERLIMIT_AT_CYCLE62 STRING,
  AM02_OVERLIMIT_AT_CYCLE63 STRING,
  AM02_OVERLIMIT_AT_CYCLE64 STRING,
  AM02_OVERLIMIT_AT_CYCLE65 STRING,
  AM02_OVERLIMIT_AT_CYCLE66 STRING,
  AM02_OVERLIMIT_AT_CYCLE67 STRING,
  AM02_OVERLIMIT_AT_CYCLE68 STRING,
  AM02_OVERLIMIT_AT_CYCLE69 STRING,
  AM02_OVERLIMIT_AT_CYCLE70 STRING,
  AM02_OVERLIMIT_AT_CYCLE71 STRING,
  AM02_OVERLIMIT_AT_CYCLE72 STRING,
  AM02_OVERLIMIT_AT_CYCLE73 STRING,
  AM02_OVERLIMIT_AT_CYCLE74 STRING,
  AM02_OVERLIMIT_AT_CYCLE75 STRING,
  AM02_OVERLIMIT_AT_CYCLE76 STRING,
  AM02_OVERLIMIT_AT_CYCLE77 STRING,
  AM02_OVERLIMIT_AT_CYCLE78 STRING,
  AM02_OVERLIMIT_AT_CYCLE79 STRING,
  AM02_OVERLIMIT_AT_CYCLE80 STRING,
  AM02_OVERLIMIT_AT_CYCLE81 STRING,
  AM02_OVERLIMIT_AT_CYCLE82 STRING,
  AM02_OVERLIMIT_AT_CYCLE83 STRING,
  AM02_OVERLIMIT_AT_CYCLE84 STRING,
  AM02_FIX_PAYMENT_OPERATOR_ID STRING,
  AM02_PAY_WITHIN_FORCED_GRAC_PD STRING,
  AM02_CB_HISTORY_CHANGE_CTD_IND STRING,
  AM02_COFF_REINSTAT_OPERATOR_ID STRING,
  AM02_COFF_HOLD_OPERATOR_ID STRING,
  AM02_OVERLIMIT_CURR_CYCLE_IND STRING,
  AM02_REAGE_PAYMENT_COUNTER_IND STRING,
  AM02_ANN_STMT_LAST_DATE DOUBLE,
  AM02_REAGE_CONS_PAY_COUNTER DOUBLE,
  AM02_NUM_COLL_FEES_BILLED_YTD DOUBLE,
  AM02_AMT_COLL_FEE_BILLED_YTD DOUBLE,
  AM02_NUM_STOP_FEES_BILLED_YTD DOUBLE,
  AM02_AMT_STOP_FEE_BILLED_YTD DOUBLE,
  AM02_AMT_LAST_FINANCE_CHARGE DOUBLE,
  AM02_DATE_CHARGEOFF_REINSTATED DOUBLE,
  AM02_AMT_LAST_FEE DOUBLE,
  AM02_DATE_LAST_FEE DOUBLE,
  AM02_DATE_POTENTIAL_CHARGEOFF DOUBLE,
  AM02_DATE_COFF_DELAYED_THRU DOUBLE,
  AM02_AMT_CREDIT_BAL_REFUND DOUBLE,
  AM02_DATE_CREDIT_BAL_REFUND DOUBLE,
  AM02_AMT_LAST_ATM DOUBLE,
  AM02_DATE_LAST_ATM DOUBLE,
  AM02_SKIP_MIN_PAY DOUBLE,
  AM02_BALANCE_CURRENT DOUBLE,
  AM02_BALANCE_PREV_STATEMENT DOUBLE,
  AM02_DATE_HIGH_BALANCE DOUBLE,
  AM02_BALANCE_HIGH_LTD DOUBLE,
  AM02_OUT_MIN_PAYMENT_DUE DOUBLE,
  AM02_DATE_FIRST_USE DOUBLE,
  AM02_DATE_PAYMENT_DUE DOUBLE,
  AM02_DATE_BEG_FIX_PAYMENT DOUBLE,
  AM02_DATE_END_FIX_PAYMENT DOUBLE,
  AM02_DATE_FIX_PAYMENT_TAKEN DOUBLE,
  AM02_AMT_FIX_PAYMENT DOUBLE,
  AM02_NUM_DEBIT_TRAN_MEMO DOUBLE,
  AM02_AMT_DEBIT_TRAN_MEMO DOUBLE,
  AM02_NUM_CREDIT_TRAN_MEMO DOUBLE,
  AM02_AMT_CREDIT_TRAN_MEMO DOUBLE,
  AM02_NUM_PAYMENT_TRAN_MEMO DOUBLE,
  AM02_AMT_PAYMENT_TRAN_MEMO DOUBLE,
  AM02_NUM_ACTIVE_DISPUTES_OUT DOUBLE,
  AM02_AMT_ACTIVE_DISPUTES_OUT DOUBLE,
  AM02_DATE_ASSIGNED_COLL_AGENCY DOUBLE,
  AM02_CONS_BILL_CR_BALANCE DOUBLE,
  AM02_PREPAYMENT_COUNTER DOUBLE,
  AM02_DATE_NEXT_COMPUTE_MIN_PAY DOUBLE,
  AM02_NUM_LTE_FEE_SINCE_LST_CUR DOUBLE,
  AM02_NUM_OL_FEE_LST_W_IN_LIMIT DOUBLE,
  AM02_DATE_NEXT_ANN_FEE DOUBLE,
  AM02_NEXT_PAYMENT_DATE DOUBLE,
  AM02_DATE_LAST_DISPUTE_ENTERED DOUBLE,
  AM02_AMT_LAST_DISPUTE DOUBLE,
  AM02_DATE_LAST_PAYMENT DOUBLE,
  AM02_AMT_LAST_PAYMENT DOUBLE,
  AM02_DATE_LAST_PURCHASE DOUBLE,
  AM02_AMT_LAST_PURCHASE DOUBLE,
  AM02_DATE_LAST_CASH DOUBLE,
  AM02_AMT_LAST_CASH DOUBLE,
  AM02_DATE_LAST_CREDIT DOUBLE,
  AM02_AMT_LAST_CREDIT DOUBLE,
  AM02_DATE_LAST_ANN_FEE DOUBLE,
  AM02_AMT_LAST_ANN_FEE DOUBLE,
  AM02_DATE_LAST_OD_PROT_XFR DOUBLE,
  AM02_AMT_LAST_OD_PROT_XFR DOUBLE,
  AM02_DATE_LAST_CONV_CHECK DOUBLE,
  AM02_AMT_LAST_CONV_CHECK DOUBLE,
  AM02_DATE_LAST_NSF_PAYMENT DOUBLE,
  AM02_AMT_LAST_NSF_PAYMENT DOUBLE,
  AM02_DATE_LAST_SYS_GEN_TRANS DOUBLE,
  AM02_AMT_LAST_SYS_GEN_TRANS DOUBLE,
  AM02_DATE_LAST_DEBIT_ADJ DOUBLE,
  AM02_AMT_LAST_DEBIT_ADJ DOUBLE,
  AM02_DATE_LAST_CREDIT_ADJ DOUBLE,
  AM02_AMT_LAST_CREDIT_ADJ DOUBLE,
  AM02_AMT_LAST_AUTO_PAYMENT DOUBLE,
  AM02_DATE_LAST_AUTO_PAYMENT DOUBLE,
  AM02_DATE_LAST_FCHG DOUBLE,
  AM02_DATE_LAST_PAID_BALANCE DOUBLE,
  AM02_DATE_LAST_SKIP_A_PAY DOUBLE,
  AM02_NUM_PTP_BROKEN_YTD DOUBLE,
  AM02_AMT_PTP_BROKEN_YTD DOUBLE,
  AM02_NUM_PTP_BROKEN_PYE DOUBLE,
  AM02_AMT_PTP_BROKEN_PYE DOUBLE,
  AM02_NUM_PTP_BROKEN_LTD DOUBLE,
  AM02_AMT_PTP_BROKEN_LTD DOUBLE,
  AM02_NUM_PTP_KEPT_YTD DOUBLE,
  AM02_AMT_PTP_KEPT_YTD DOUBLE,
  AM02_NUM_PTP_KEPT_PYE DOUBLE,
  AM02_AMT_PTP_KEPT_PYE DOUBLE,
  AM02_NUM_PTP_KEPT_LTD DOUBLE,
  AM02_AMT_PTP_KEPT_LTD DOUBLE,
  AM02_NUM_PTP_PARTIAL_YTD DOUBLE,
  AM02_AMT_PTP_PARTIAL_YTD DOUBLE,
  AM02_NUM_PTP_PARTIAL_PYE DOUBLE,
  AM02_AMT_PTP_PARTIAL_PYE DOUBLE,
  AM02_NUM_PTP_PARTIAL_LTD DOUBLE,
  AM02_AMT_PTP_PARTIAL_LTD DOUBLE,
  AM02_NUM_PTP_DELETE_YTD DOUBLE,
  AM02_AMT_PTP_DELETE_YTD DOUBLE,
  AM02_NUM_PTP_DELETE_PYE DOUBLE,
  AM02_AMT_PTP_DELETE_PYE DOUBLE,
  AM02_NUM_PTP_DELETE_LTD DOUBLE,
  AM02_AMT_PTP_DELETE_LTD DOUBLE,
  AM02_NUM_DISPUTE_YTD DOUBLE,
  AM02_AMT_DISPUTE_YTD DOUBLE,
  AM02_NUM_DISPUTE_PYE DOUBLE,
  AM02_AMT_DISPUTE_PYE DOUBLE,
  AM02_NUM_DISPUTE_LTD DOUBLE,
  AM02_AMT_DISPUTE_LTD DOUBLE,
  AM02_NUM_DISPUTE_CUST_YTD DOUBLE,
  AM02_AMT_DISPUTE_CUST_YTD DOUBLE,
  AM02_NUM_DISPUTE_CUST_PYE DOUBLE,
  AM02_AMT_DISPUTE_CUST_PYE DOUBLE,
  AM02_NUM_DISPUTE_CUST_LTD DOUBLE,
  AM02_AMT_DISPUTE_CUST_LTD DOUBLE,
  AM02_NUM_DISPUTE_CLIENT_YTD DOUBLE,
  AM02_AMT_DISPUTE_CLIENT_YTD DOUBLE,
  AM02_NUM_DISPUTE_CLIENT_PYE DOUBLE,
  AM02_AMT_DISPUTE_CLIENT_PYE DOUBLE,
  AM02_NUM_DISPUTE_CLIENT_LTD DOUBLE,
  AM02_AMT_DISPUTE_CLIENT_LTD DOUBLE,
  AM02_NUM_PAYMENTS_YTD DOUBLE,
  AM02_AMT_PAYMENTS_YTD DOUBLE,
  AM02_NUM_PAYMENTS_PYE DOUBLE,
  AM02_AMT_PAYMENTS_PYE DOUBLE,
  AM02_NUM_PAYMENTS_LTD DOUBLE,
  AM02_AMT_PAYMENTS_LTD DOUBLE,
  AM02_NUM_PAYMENTS_CTD DOUBLE,
  AM02_AMT_PAYMENTS_CTD DOUBLE,
  AM02_AMT_FCHG_BILLED_YTD DOUBLE,
  AM02_AMT_FCHG_BILLED_PYE DOUBLE,
  AM02_AMT_FCHG_BILLED_LTD DOUBLE,
  AM02_AMT_FCHG_PAID_YTD DOUBLE,
  AM02_AMT_FCHG_PAID_PYE DOUBLE,
  AM02_AMT_FCHG_PAID_LTD DOUBLE,
  AM02_NUM_NSF_PAYMENTS_YTD DOUBLE,
  AM02_AMT_NSF_PAYMENTS_YTD DOUBLE,
  AM02_NUM_NSF_PAYMENTS_PYE DOUBLE,
  AM02_AMT_NSF_PAYMENTS_PYE DOUBLE,
  AM02_NUM_NSF_PAYMENTS_LTD DOUBLE,
  AM02_AMT_NSF_PAYMENTS_LTD DOUBLE,
  AM02_NUM_LIMIT_INCREASE_YTD DOUBLE,
  AM02_AMT_LIMIT_INCREASE_YTD DOUBLE,
  AM02_NUM_LIMIT_INCREASE_PYE DOUBLE,
  AM02_AMT_LIMIT_INCREASE_PYE DOUBLE,
  AM02_NUM_LIMIT_INCREASE_LTD DOUBLE,
  AM02_AMT_LIMIT_INCREASE_LTD DOUBLE,
  AM02_NUM_LIMIT_DECREASE_YTD DOUBLE,
  AM02_AMT_LIMIT_DECREASE_YTD DOUBLE,
  AM02_NUM_LIMIT_DECREASE_PYE DOUBLE,
  AM02_AMT_LIMIT_DECREASE_PYE DOUBLE,
  AM02_NUM_LIMIT_DECREASE_LTD DOUBLE,
  AM02_AMT_LIMIT_DECREASE_LTD DOUBLE,
  AM02_NUM_PURCHASES_YTD DOUBLE,
  AM02_AMT_PURCHASES_YTD DOUBLE,
  AM02_NUM_PURCHASES_LTD DOUBLE,
  AM02_AMT_PURCHASES_LTD DOUBLE,
  AM02_NUM_CASH_YTD DOUBLE,
  AM02_AMT_CASH_YTD DOUBLE,
  AM02_NUM_CASH_LTD DOUBLE,
  AM02_AMT_CASH_LTD DOUBLE,
  AM02_NUM_CONV_CHECKS_YTD DOUBLE,
  AM02_AMT_CONV_CHECKS_YTD DOUBLE,
  AM02_NUM_CONV_CHECKS_LTD DOUBLE,
  AM02_AMT_CONV_CHECKS_LTD DOUBLE,
  AM02_NUM_CREDITS_YTD DOUBLE,
  AM02_AMT_CREDITS_YTD DOUBLE,
  AM02_NUM_CREDITS_LTD DOUBLE,
  AM02_AMT_CREDITS_LTD DOUBLE,
  AM02_FUTURE_PAYMENT_COUNTER DOUBLE,
  AM02_ACCT_IN_BAL_IND STRING,
  AM02_NUM_LATE_FEES_BILLED_YTD DOUBLE,
  AM02_NUM_OL_FEES_BILLED_YTD DOUBLE,
  AM02_AMT_OL_FEES_BILLED_YTD DOUBLE,
  AM02_AMT_LATEFEE_BILLED_YTD DOUBLE,
  AM02_AMT_LATEFEE_PAID_YTD DOUBLE,
  AM02_NUM_MISC_DEBITS_CTD DOUBLE,
  AM02_AMT_MISC_DEBITS_CTD DOUBLE,
  AM02_NUM_MISC_CREDITS_CTD DOUBLE,
  AM02_AMT_MISC_CREDITS_CTD DOUBLE,
  AM02_AMT_NSF_PAYMENTS_CTD DOUBLE,
  AM02_NUM_NSF_PAYMENTS_CTD DOUBLE,
  AM02_CHGS_CONS_IN_MIN_FCHG_CTD DOUBLE,
  AM02_CHGS_CONSIDERED_FCHG_CTD DOUBLE,
  AM02_AMT_CSHADV_SBJ_FR_FEE_CTD DOUBLE,
  AM02_GEN_ANN_STMT_IND STRING,
  AM02_AMT_BKDT_CTD DOUBLE,
  AM02_DATE_POST_FIRST_USE DOUBLE,
  AM02_PRENOTE_ACCT_WAIVE STRING,
  AM02_DATE_LAST_FLOAT_PAY DOUBLE,
  AM02_AMF_OVR_REAS_DSPLY STRING,
  AM02_HIGH_BAL_SINCE_PIF DOUBLE,
  AM02_DATE_HIGH_BAL_PIF DOUBLE,
  AM02_NEXT_TLP_EXPIRATION_DATE DOUBLE,
  AM02_TLP_LAST_NUM DOUBLE,
  AM02_BALANCE_AT_BANKRUPTCY DOUBLE,
  AM02_AMT_NON_NSF_PMT_REV_CTD DOUBLE,
  AM02_SYS_GEN_LATE_FEE_FLAG STRING,
  FILLER STRING
)
ROW FORMAT DELIMITED FIELDS TERMINATED BY '1'
STORED AS INPUTFORMAT 'com.cloudera.sa.copybook.mapred.CopybookInputFormat' OUTPUTFORMAT 'org.apache.hadoop.hive.ql.io.HiveIgnoreKeyTextOutputFormat'
LOCATION '/user/admin/copybook/dat/AM02/'
TBLPROPERTIES ('copybook.inputformat.cbl.hdfs.path' = '/user/admin/copybook/schema/AM02.TXT')
