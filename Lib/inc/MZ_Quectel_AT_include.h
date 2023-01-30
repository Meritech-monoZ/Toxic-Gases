/*
 * MZ_Quectel_AT_include.h
 *
 *  Created on: June 22, 2022
 *      Author: Mahendra & Kafeel
 */
#ifndef MZ_QUECTEL_AT_INCLUDE_H_
#define MZ_QUECTEL_AT_INCLUDE_H_
#ifdef __cplusplus
extern "C" {
#endif

#if(MZ_MODEM_QUECTEL == MZ_ENABLE)
#include "MZ_error_handler.h"

// Quectel specific AT CMD's

/**
 * @defgroup STANDARD_AT_COMMAND STANDARD AT COMMAND
 * AT commands of STANDARD
 * @{
 * @fn mz_error_t mz_raw_at_exe_at(void)
 * @brief This API issues AT command. Expected output is OK/Error
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_at(void);

/**
 * @fn mz_error_t mz_raw_at_test_cgmi(void)
 * @brief Issues AT+CGMI=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cgmi(void);

/**
 * @fn mz_error_t mz_raw_at_exe_cgmi(void)
 * @brief Issues AT+CGMI? command to request the manufacturer identification
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_cgmi(void);

/**
 * @fn mz_error_t mz_raw_at_test_gmi(void)
 * @brief Issues AT+GMI=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_gmi(void);

/**
 * @fn mz_error_t mz_raw_at_exe_gmi(void)
 * @brief Issues AT+GMI? command to request the TA manufacturer identification
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_gmi(void);

/**
 * @fn mz_error_t mz_raw_at_test_cgmm(void)
 * @brief Issues AT+CGMM=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cgmm(void);

/**
 * @fn mz_error_t mz_raw_at_exe_cgmm(void)
 * @brief Monoz Standard  AT Command for Requests Model Identification
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_cgmm(void);

/**
 * @fn mz_error_t mz_raw_at_test_gmm(void)
 * @brief Issues AT+GMM=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_gmm(void);

/**
 * @fn mz_error_t mz_raw_at_exe_gmm(void)
 * @brief Monoz Standard  AT Command for Requests TA Model Identification
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_gmm(void);

/**
 * @fn mz_error_t mz_raw_at_test_cgmr(void)
 * @brief Issues AT+CGMR=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cgmr(void);

/**
 * @fn mz_error_t mz_raw_at_exe_cgmr(void)
 * @brief Monoz Standard  AT Command for Requests revision Identification
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_cgmr(void);

/**
 * @fn mz_error_t mz_raw_at_test_gmr(void)
 * @brief Issues AT+GMR=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_gmr(void);

/**
 * @fn mz_error_t mz_raw_at_exe_gmr(void)
 * @brief Monoz Standard  AT Command for Requests TA revision Identification
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_gmr(void);

/**
 * @fn mz_error_t mz_raw_at_test_cgsn(void)
 * @brief Issues AT+CGSN=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cgsn(void);

/**
 * @fn mz_error_t mz_raw_at_exe_cgsn(void)
 * @brief Monoz Standard  AT Command for Requests serial number Identification
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_cgsn(void);

/**
 * @fn mz_error_t mz_raw_at_test_gsn(void)
 * @brief Issues AT+GSN=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_gsn(void);

/**
 * @fn mz_error_t mz_raw_at_exe_gsn(void)
 * @brief Monoz Standard  AT Command for Requests TA serial number Identification
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_gsn(void);

/**
 * @fn mz_error_t mz_raw_at_test_cimi(void)
 * @brief Issues AT+CIMI=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cimi(void);

/**
 * @fn mz_error_t mz_raw_at_exe_cimi(void)
 * @brief Monoz Standard  AT Command for Requests  international mobile subscriber
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_cimi(void);

/**
 * @fn mz_error_t mz_raw_at_exe_z(void)
 * @brief AT sets all parameters to their defaults as specified by a user memory profile or by the manufacturer,and resets AT
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_z(void);

/**
 * @fn mz_error_t mz_raw_at_write_cfun(mzUint8 setval,mzUint8 rst)
 * @brief This command is used to change the mode of phone functionality
 * @param setval mzUint8,mzUint8 rst
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cfun(mzUint8 setval,mzUint8 rst);

/**
 * @fn mz_error_t mz_raw_at_test_cfun(void)
 * @brief Issues AT+CFUN=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cfun(void);

/**
 * @fn mz_error_t mz_raw_at_read_cfun(void)
 * @brief Read  phone functionality
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cfun(void);

/**
 * @fn mz_error_t mz_raw_at_test_cereg(void)
 * @brief Issues AT+CEREG=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cereg(void);

/**
 * @fn mz_error_t mz_raw_at_read_cereg(void)
 * @brief EPS network registration status
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cereg(void);

/**
 * @fn mz_error_t mz_raw_at_write_cereg(mzUint8 setval)
 * @brief This command is used to subscribe or unsubscibe unsolicited network status notification
 * @param setval mzUint8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cereg(mzUint8 setval);

/**
* @brief This is IPR test command is used to query and set the baud rate of the UART.
* @param : None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_at_test_ipr(void);

/**
* @brief This is IPR READ command is used to query and set the baud rate of the UART.
* @param : Baud Rate
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_at_read_ipr(void);

/**
 * @fn mz_error_t mz_raw_at_write_ipr(mzUint32 band)
 * @brief This command is used to set the baud rate of the serial interface of the devive
 * @param band mzUint32
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_ipr(mzUint32 band);

/**
 * @fn mz_error_t mz_raw_at_test_cpsms(void)
 * @brief Issues AT+CPSMS=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cpsms(void);

/**
 * @fn mz_error_t mz_raw_at_write_cpsms(mzUint8 mode, char * RPRAU,char * RGRT,char * RPTAU,char * RAT)
 * @brief This command is used to set the power saving mode
 * @param mode mzUint8
 * @param RPRAU char
 * @param RGRT char
 * @param RPTAU char
 * @param RAT char
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cpsms(mzUint8 mode, char * RPRAU,char * RGRT,char * RPTAU,char * RAT);

/**
 * @fn mz_error_t mz_raw_at_read_cpsms(void)
 * @brief Power Saving Mode Setting
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cpsms(void);

/**
 * @fn mz_error_t mz_raw_at_test_cedrxs(void)
 * @brief Issues AT+CEDRXS=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cedrxs(void);

/**
 * @fn mz_error_t mz_raw_at_write_cedrxs(mzUint8 mode, mzUint8 actiontype,char * ReDRXv)
 * @brief This command is used to controls  the setting of eDRX parameter
 * @param mode mzUint8
 * @param actiontype mzUint8
 * @param ReDRXv char
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cedrxs(mzUint8 mode, mzUint8 actiontype,char * ReDRXv);

/**
 * @fn mz_error_t mz_raw_at_read_cedrxs(void)
 * @brief Controls the setting of  eDRX parameters
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cedrxs(void);

/**
 * @fn mz_error_t mz_raw_at_test_cedrxrdp(void)
 * @brief Issues AT+CEDRXRDP=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cedrxrdp(void);

/**
 * @fn mz_error_t mz_raw_at_exe_cedrxrdp(void)
 * @brief Retrieves eDRX parameters
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_cedrxrdp(void);

/**
 * @fn mz_error_t mz_raw_at_write_cmgd(mzInt8 range , mzInt8 delflag)
 * @brief Monoz Standard  AT Command for Delete Messages
 * @param range mzInt8
 * @param delflag mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cmgd(mzInt8 range , mzInt8 delflag);

/**
 * @fn mz_error_t mz_raw_at_test_cmgd(void)
 * @brief Issues AT+CMGD=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cmgd(void);

/**
 * @fn mz_error_t mz_raw_at_write_cmgf(mzInt8 stat)
 * @brief This command is used to select between protocol data unit and message format
 * @param stat mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cmgf(mzInt8 stat);

/**
 * @fn mz_error_t mz_raw_at_test_cmgf(void)
 * @brief Issues AT+CMGF=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cmgf(void);

/**
 * @fn mz_error_t mz_raw_at_read_cmgf(void)
 * @brief Monoz Standard  AT Command for Message Format
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cmgf(void);

/**
 * @fn mz_error_t mz_raw_at_write_cmgl(mzInt8 setvalue)
 * @brief This command is used to list messages from prefered storage
 * @param setvalue mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cmgl(mzInt8 setvalue);

/**
 * @fn mz_error_t mz_raw_at_test_cmgl(void)
 * @brief Issues AT+CMGL=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cmgl(void);

/**
 * @fn mz_error_t mz_raw_at_exe_cmgl(void)
 * @brief Monoz Standard  AT Command for List Messages
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_cmgl(void);

/**
 * @fn mz_error_t mz_raw_at_write_cmgr(mzInt8 setvalue)
 * @brief This command is used to read messages from prefered storage
 * @param setvalue mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cmgr(mzInt8 setvalue);

/**
 * @fn mz_error_t mz_raw_at_test_cmgr(void)
 * @brief Issues AT+CMGR=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cmgr(void);

/**
 * @fn mz_error_t mz_raw_at_write_cmgs(mzInt8 setvalue)
 * @brief This command is used to send the message from host
 * @param setvalue mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cmgs(mzInt8 setvalue);

/**
 * @fn mz_error_t mz_raw_at_test_cmgs(void)
 * @brief Issues AT+CMGS=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cmgs(void);

/**
 * @fn mz_error_t mz_raw_at_write_cmgw(mzInt8 setvalue)
 * @brief This command is used to write the message to the memory
 * @param setvalue mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cmgw(mzInt8 setvalue);

/**
 * @fn mz_error_t mz_raw_at_test_cmgw(void)
 * @brief Issues AT+CMGW=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cmgw(void);

/**
 * @fn mz_error_t mz_raw_at_write_cmss(mzInt8 setvalue, char * da , mzInt8 toda)
 * @brief This command is used to Send SMS from storage
 * @param setvalue mzInt8
 * @param da char
 * @param toda  mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cmss(mzInt8 setvalue, char * da , mzInt8 toda);

/**
 * @fn mz_error_t mz_raw_at_test_cmss(void)
 * @brief Issues AT+CMSS=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cmss(void);

/**
 * @fn mz_error_t mz_raw_at_write_cnma(mzInt8 setvalue)
 * @brief This command is used to send a new message or delivery status acknowledgement
 * @param setvalue mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cnma(mzInt8 setvalue);

/**
 * @fn mz_error_t mz_raw_at_test_cnma(void)
 * @brief Issues AT+CNMA=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cnma(void);

/**
 * @fn mz_error_t mz_raw_at_exe_cnma(void)
 * @brief New Message Acknowledgement to ME/TA
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_cnma(void);

/**
 * @fn mz_error_t mz_raw_at_write_cnmi(mzInt8 setvalue, mzInt8 mt, mzInt8 bm, mzInt8 ds, mzInt8 bfr)
 * @brief This command is used to registers and unregisters and SMS clients
 * @param setvalue mzInt8 -(1,2)
 * @param mt mzInt8 -(0-2)
 * @param bm mzInt8 -(0,2)
 * @param ds mzInt8 -(0-2)
 * @param bfr mzInt8 -(0-1)
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cnmi(mzInt8 setvalue, mzInt8 mt, mzInt8 bm, mzInt8 ds, mzInt8 bfr);

/**
 * @fn mz_error_t mz_raw_at_test_cnmi(void)
 * @brief Issues AT+CNMI=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cnmi(void);

/**
 * @fn mz_error_t mz_raw_at_read_cnmi(void)
 * @brief It request to read New Message Indications
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cnmi(void);

/**
 * @fn mz_error_t mz_raw_at_write_cpms(char *mem1, char *mem2, char * mem3)
 * @brief The +CPMS command selects the memory storage "ME/SM"
 * @param mem1 Char
 * @param mem2 char
 * @param mem3 char
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cpms(char *mem1, char *mem2, char * mem3);

/**
 * @fn mz_error_t mz_raw_at_test_cpms(void)
 * @brief Issues AT+CPMS=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cpms(void);

/**
 * @fn mz_error_t mz_raw_at_read_cpms(void)
 * @brief It request to read Preferred Message Storage
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cpms(void);

/**
 * @fn mz_error_t mz_raw_at_write_csca(char *sca, mzInt8 tosca)
 * @brief Set the SMS service center address
 * @param sca Char -<phone_number>
 * @param tosca mzInt8 -<address_type(129/145)>
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_csca(char *sca, mzInt8 tosca);

/**
 * @fn mz_error_t mz_raw_at_test_csca(void)
 * @brief Issues AT+CSCA=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_csca(void);

/**
 * @fn mz_error_t mz_raw_at_read_csca(void)
 * @brief It request to read Service Centre Address
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_csca(void);

/**
 * @fn mz_error_t mz_raw_at_write_cscs(char *setvalue)
 * @brief This command is used to select the character set
 * @param setvalue Char
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cscs(char *setvalue);

/**
 * @fn mz_error_t mz_raw_at_test_cscs(void)
 * @brief Issues AT+CSCS=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cscs(void);

/**
 * @fn mz_error_t mz_raw_at_read_cscs(void)
 * @brief It request to read Select TE (Terminal) character set
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cscs(void);

/**
 * @fn mz_error_t mz_raw_at_write_csmp(mzInt8 fo, mzInt8 vp, mzInt8 pid, mzInt8 dcs)
 * @brief Used to set text mode parameters
 * @param fo mzInt8 -(1,17,33,49,65,81,97,113)
 * @param vp mzInt8 -(0-255)
 * @param pid mzInt8 -(0)
 * @param dcs mzInt8 -(0,4,8)
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_csmp(mzInt8 fo, mzInt8 vp, mzInt8 pid, mzInt8 dcs);

/**
 * @fn mz_error_t mz_raw_at_test_csmp(void)
 * @brief Issues AT+CSMP=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_csmp(void);

/**
 * @fn mz_error_t mz_raw_at_read_csmp(void)
 * @brief It request to read Set Text Mode Parameters
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_csmp(void);

/**
 * @fn mz_error_t mz_raw_at_write_csms(mzInt8 setvalue)
 * @brief This command is used to select the message service
 * @param setvalue mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_csms(mzInt8 setvalue);

/**
 * @fn mz_error_t mz_raw_at_test_csms(void)
 * @brief Issue AT+CSMS=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_csms(void);

/**
 * @fn mz_error_t mz_raw_at_read_csms(void)
 * @brief It request to read Select Message Service
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_csms(void);

/**
 * @fn mz_error_t mz_raw_at_write_cmee(mzInt8 setvalue)
 * @brief This command is used to enable or disable the use of result code
 * @param setvalue mzInt8
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_write_cmee(mzInt8 setvalue);

/**
 * @fn mz_error_t mz_raw_at_test_cmee(void)
 * @brief Issue AT+CMEE=? command to test this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_cmee(void);

/**
 * @fn mz_error_t mz_raw_at_read_cmee(void)
 * @brief It request to read Report mobile termination error
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_read_cmee(void);

/**
 * @fn mz_error_t mz_raw_at_test_csq(void)
 * @brief Issue AT+CSQ=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_test_csq(void);

/**
 * @fn mz_error_t mz_raw_at_exe_csq(void)
 * @brief Issue AT+CSQ=? command to request the signal quality
 * @return MZ_OK/MZ_FAIL
 */
mz_error_t mz_raw_at_exe_csq(void);

/**
 * @fn mz_error_t mz_raw_at_read_cops(void)
 * @brief The command returns the current operators and
 * their status, and allows setting automatic or manual network selection.
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t mz_raw_at_read_cops(void);

/**
 * @fn mz_error_t mz_raw_at_write_cops(mzInt8 mode, mzInt8 format, char *operator,mzInt8 act)
 * @brief The command returns the current operators and
 * their status, and allows setting automatic or manual network selection.
 * @param setvalue mzInt8
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t mz_raw_at_write_cops(mzInt8 mode, mzInt8 format, char *operator);

/**
 * @fn mz_error_t mz_raw_at_test_cops(void)
 * @brief Issue AT+COPS=? command to test the this command is supported or not
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t mz_raw_at_test_cops(void);

/**
* @brief This is CCLK read command.
* @param : None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_at_read_cclk(void);

/**
* @brief This is CCLK set command.
* @param : time
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_at_write_cclk(char *time);

/**
 * @fn mz_error_t mz_raw_at_read_cclk(void)
 * @brief This is CCLK read command.
 * @return MZ_OK/MZ_FAIL
 */

mz_error_t mz_raw_at_read_cclk(void);

/**
* @brief This is exe command for display product information
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATI(void);

/**
* @brief This is exe command Set To Factory-Defined Configuration.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATF(void);

/**
* @brief The command determines the contents of header and trailer
* transmitted with AT command result codes and information responses.
* @param In: value (0 for Error code 1 for Error response)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATV(char code);

/**
* @brief The command repeats previous AT command line, and “/”
* 			acts as the line terminating character.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_A(void);

/**
* @brief The command stores the current AT command settings to a
* user defined profile in non-volatile memory.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATW(void);

/**
* @brief The command restores the current AT command settings to the
* user defined profile in non-volatile memory, if they were stored with AT&W before
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATZ(char value);

/**
* @brief The command controls whether the result code is transmitted  to the TE.
* Other information text transmitted as response is not affected.
* @param In: 0 Transmit Error code 1 Suppress Error code
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATQ(char code);

/**
* @brief The command controls whether or not the module echoes
* characters received from TE during AT command mode.
* @param In: 0 Echo mode off  1: Echo mode ON
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATV_VAL(char value);

/**
* @brief The command controls whether or not the module echoes
* characters received from TE during AT command mode.
* @param In: 0 Echo mode off  1: Echo mode ON
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATE(char code);

/**
* @brief The command determines the character recognized
* by the module to terminate an incoming command line.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ATS3(void);

/**
* @brief The command determines the character recognized
* by the module to terminate an incoming commandline.
* @param In: val(Command line termination character)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ATS3(char val);

/**
* @brief The command determines the character generated by
* the module for result code and information text.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ATS4(void);

/**
* @brief The command determines the character generated by
* the module for result code and information text.
* @param In: val(Command line termination character)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ATS4(char val);

/**
* @brief The command determines the character value used by the
*  module to delete the immediately preceding character .
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ATS5(void);

/**
* @brief The command determines the character value used by the
* module to delete the immediately preceding character .
* @param In: val(Command line termination character)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ATS5(char val);

/**
* @brief The command determines whether or not the module
* transmits particular result codes to the TE.
* @param In: value
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATX(char value);

/**
* @brief The command controls the behavior of the UE‟s DCD line.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATC(void);

/**
* @brief The command can be used to set up outgoing voice and data calls.
* @param In: *value(String of dialing digits and optionally),*mgsm(String of GSM modifiers)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATD(char *value,char *mgsm);

/**
* @brief The command disconnects circuit switched data calls or voice calls.
* @param In: value
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATH(char value);

/**
* @brief The test command disconnects circuit switched data calls or voice calls.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CVHU(void);

/**
* @brief The command disconnects circuit switched data calls or voice calls.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CVHU(void);

/**
* @brief The command disconnects circuit switched data calls or voice calls.
* @param In: value(0 or 1)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CVHU(char mode);

/**
* @brief The command cancels all voice calls in the state of
* Active, Waiting and Held.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/


mz_error_t mz_raw_quectel_at_test_CHUP(void);

/**
* @brief The command cancels all voice calls in the state
* of Active, Waiting and Held.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_CHUP(void);

/**
* @brief The command resumes the connection and
* switches back to data mode from command mode.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_ATO(char mode);

/**
* @brief The command disconnects circuit switched data calls or voice calls.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ATS0(void);

/**
* @brief The command disconnects circuit switched data calls or voice calls.
* @param In: value(Enable or disable anwering)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ATS0(char mode);

/**
* @brief The command is implemented for compatibility
* reasons only, and has no effect.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ATS6(void);

/**
* @brief The command is implemented for compatibility
*  reasons only, and has no effect.
* @param In: value(Number of seconds to wait before blind dialing)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ATS6(char seconds);

/**
* @brief The command is implemented for compatibility
* reasons only, and has no effect.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ATS7(void);

/**
* @brief The command is implemented for compatibility
*  reasons only, and has no effect.
* @param In: value(Number of seconds to wait before blind dialing)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ATS7(char seconds);

/**
* @brief The command is implemented for compatibility
* reasons only, and has no effect.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ATS8(void);

/**
* @brief The command is implemented for compatibility
*  reasons only, and has no effect.
* @param In: value(Number of seconds to wait before blind dialing)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ATS8(char seconds);

/**
* @brief The command is implemented for compatibility
* reasons only, and has no effect.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ATS10(void);

/**
* @brief The command is implemented for compatibility
*  reasons only, and has no effect.
* @param In: value(Number of seconds to wait before blind dialing)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ATS10(char seconds);

/**
* @brief The Write Command selects the type of number for
* further dialing commands ATD according to 3GPP Specifications.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CSTA(void);

/**
* @brief The Write Command selects the type of number for
* further dialing commands ATD according to 3GPP Specifications.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CSTA(void);

/**
* @brief The Write Command selects the type of number for
* further dialing commands ATD according to 3GPP Specifications.
* @param In: value(0 or 1)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CSTA(char type);

/**
* @brief The Execution Command returns the list of all current calls.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_CLCC(void);

/**
* @brief The Execution Command returns the list of all current calls.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CLCC(void);

/**
* @brief The command controls the module whether or not to
*  transmit an intermediate result code +CR: <serv> to
* the TE when a call is being set up.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CR(void);

/**
* @brief The command controls the module whether or not to
*  transmit an intermediate result code +CR: <serv> to
* the TE when a call is being set up.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CR(void);

/**
* @brief The command controls the module whether or not to
*  transmit an intermediate result code +CR: <serv> to
* the TE when a call is being set up.
* @param In: value(0 or 1)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CR(char mode);
/*
mz_error_t mz_raw_quectel_at_test_CRC(void); 				//Pending due to error
mz_error_t mz_raw_quectel_at_read_CRC(void);
mz_error_t mz_raw_quectel_at_write_CRC(char mode);
*/

/**
* @brief The Write Command sets radio link protocol (RLP)
*  parameters used when non-transparent data calls are originated.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CRLP(void);

/**
* @brief The Write Command sets radio link protocol (RLP)
*  parameters used when non-transparent data calls are originated.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CRLP(void);

/**
* @brief The Write Command sets radio link protocol (RLP)
*  parameters used when non-transparent data calls are originated.
* @param In: iws(Interworking window size),mws(Mobile window size),T1(Acknowledgment timer)
* N2(Retransmission attempts) ,ver(RLP version number in integer format)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CRLP(char iws,char mws,char T1,char N2,char ver);

/**
* @brief The command can be used to query, add or delete
*  ECC numbers (emergency call numbers).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QECCNUM(void);

/**
* @brief The command can be used to query, add or delete
*  ECC numbers (emergency call numbers).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QECCNUM(void);

/**
* @brief The command can be used to query, add or delete
* ECC numbers (emergency call numbers).
* @param In:mode(ECC number operation mode),type(ECC number type),eccnum(ECC numbers)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QECCNUM(char mode,char type,char *eccnum);

/**
* @brief The command can be used to query, add or delete
* ECC numbers (emergency call numbers).
* @param In:ECC number operation mode,ECC number type,. ECC numbers
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QHUP(void);

/**
* @brief The command can be used to query, add or delete
* ECC numbers (emergency call numbers).
* @param In:ECC number operation mode,ECC number type,. ECC numbers
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QHUP(char cause,char idx);

/**
* @brief The command controls the continuity of the
* SMS relay protocol link.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CMMS(void);

/**
* @brief The command controls the continuity of the
* SMS relay protocol link.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CMMS(void);

/**
* @brief The command controls the continuity of the
* SMS relay protocol link.
* @param In:mode(Feature enable or disabled )
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CMMS(char mode);

/**
* @brief The command is used to send concatenated massages.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QCMGS(void);

/**
* @brief The command is used to send concatenated massages.
* @param In:dest_add,type_rec_add,uid,msg_seg,msg_total
* buffer_res_code.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QCMGS(char* dest_add,char type_rec_add,char uid,char msg_seg,char msg_total);

/**
* @brief The Read Command returns SMS messages with
* location value <index> from message storage <mem1>
* to the TE.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QCMGR(void);

/**
* @brief The Read Command returns SMS messages with
* location value <index> from message storage <mem1>
* to the TE.
* @param In:index
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QCMGR(char index);

/**
* @brief The command specifies PDP context parameters
* for a specific context <cid>.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGDCONT(void);

/**
* @brief The command specifies PDP context parameters
* for a specific context <cid>.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CGDCONT(void);

/**
* @brief The command specifies PDP context parameters
* for a specific context <cid>.
* @param In:cid(PDP context identifier),PDP_type(Packet data protocol type.),
* APN(Access point name),PDP_addr(A string parameter identifies the MT),
* data_comp(A numeric parameter that controls PDP),head_comp(A numeric parameter).
* buffer_res_code.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGDCONT(char cid,char *PDP_type,char *APN,char *PDP_addr,char data_comp,char head_comp);

/**
* @brief The Test Command is used to activate or
* deactivate the specified PDP context(s).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGACT(void);

/**
* @brief The Test Command is used to activate or
* deactivate the specified PDP context(s).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CGACT(void);

/**
* @brief The Test Command is used to activate or
* deactivate the specified PDP context(s).
* @param In:state(Indicates the state of PDP context activation.),
* cid(A numeric parameter which specifies a particular PDP context.).
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGACT(char state,char cid);

/**
* @brief The command allows the TE to specify a minimum
* acceptable profile which is checked by the MT against
* the negotiated profile when a PDP context is activated.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGQMIN(void);

/**
* @brief The command allows the TE to specify a minimum
* acceptable profile which is checked by the MT against
* the negotiated profile when a PDP context is activated.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CGQMIN(void);

/**
* @brief The command allows the TE to specify a minimum
* acceptable profile which is checked by the MT against
* the negotiated profile when a PDP context is activated.
* @param In:cid,precedence,delay,reliability,peak,mean.
* data_comp(A numeric parameter that controls PDP),head_comp(A numeric parameter).
* buffer_res_code.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGQMIN(char cid,char precedence,char delay,char reliability,char peak,char mean);

/**
* @brief The Test Command is used to activate or
* deactivate the specified PDP context(s).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGDATA(void);

/**
* @brief The Test Command is used to activate or
* deactivate the specified PDP context(s).
* @param In:L2P,cid
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGDATA(char *L2P,char cid);

/**
* @brief The Test Command is used to activate or
* deactivate the specified PDP context(s).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGPADDR(void);

/**
* @brief The Test Command is used to activate or
* deactivate the specified PDP context(s).
* @param In:cid
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGPADDR(char cid);

/**
* @brief The command allows the TE to specify the quality
*  of service profile that is used when the MT activates a
*  PDP context.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGQREQ(void);

/**
* @brief The command allows the TE to specify the quality
*  of service profile that is used when the MT activates a
*  PDP context.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CGQREQ(void);

/**
* @brief The command allows the TE to specify the quality
*  of service profile that is used when the MT activates a
*  PDP context.
* @param In:cid,precedence,delay,reliability,peak,mean.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGQREQ(char cid,char precedence,char delay,char reliability,char peak,char mean);

/**
* @brief The command queries the network registration
* status and controls the presentation of an unsolicited
* result code.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGREG(void);

/**
* @brief The command queries the network registration
* status and controls the presentation of an unsolicited
* result code.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CGREG(void);

/**
* @brief The command queries the network registration
* status and controls the presentation of an unsolicited
* result code.
* @param In:mode
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGREG(char mode);

/**
* @brief The command allows control of the call
* forwarding supplementary service according to 3GPP TS 22.082.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CCFC(void);

/**
* @brief The command allows control of the call
* forwarding supplementary service according to 3GPP TS 22.082.
* @param In:read,mode,number,type,class,subaddr,satype,time.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CCFC(char read,char mode,char *number,char type,char class,char *subaddr,char satype,char time);

/**
* @brief The test Command enables or disables sending
* of unsolicited result codes.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGEREP(void);

/**
* @brief The read Command enables or disables sending
* of unsolicited result codes.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CGEREP(void);

/**
* @brief The Write Command enables or disables sending
*  of unsolicited result codes
* @param In:mode ,bfr
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGEREP(char mode,char bfr);

/**
* @brief The Execute Command enables or disables sending
*  of unsolicited result codes.
* @param In:None.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_CGEREP(void);

/**
* @brief The command specifies the service or service
*  preference that the MT will use to send MO (mobile
*  originated) SMS messages.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGSMS(void);

/**
* @briefThe command specifies the service or service
*  preference that the MT will use to send MO (mobile
*  originated) SMS messages.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CGSMS(void);

/**
* @brief The command specifies the service or service
*  preference that the MT will use to send MO (mobile
*  originated) SMS messages.
* @param In:service
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGSMS(char service);

/**
* @brief The command allows control of the call waiting
* Activation, deactivation and status query are supported.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CCWA(void);

/**
* @brief The command allows control of the call waiting
* Activation, deactivation and status query are supported.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CCWA(void);

/**
* @brief The command allows control of the call waiting
* Activation, deactivation and status query are supported.
* @param In:n,mode,class
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CCWA(char n,char mode,char class);

/**
* @brief The command allows the control of the
* following call related services.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CHLD(void);

/**
* @brief The command allows the control of the
* following call related services.
* @param In:n,mode,class
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CHLD(char action_oncall);

/**
* @brief The command refers to the GSM/UMTS supplementary service
* CLIP ) that enables a called subscriber to get the calling line identity.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CLIP(void);

/**
* @brief The command refers to the GSM/UMTS supplementary service
* CLIP ) that enables a called subscriber to get the calling line identity.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CLIP(void);

/**
* @brief The command refers to the GSM/UMTS supplementary service
* CLIP ) that enables a called subscriber to get the calling line identity.
* @param In:mode
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CLIP(char mode);

/**
* @brief The command allows a calling subscriber to enable
* or disable the presentation of the calling line identity.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CLIR(void);

/**
* @brief The command allows a calling subscriber to enable
* or disable the presentation of the calling line identity.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CLIR(void);

/**
* @brief The command allows a calling subscriber to enable
* or disable the presentation of the calling line identity.
* @param In:mode
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CLIR(char mode);

/**
* @brief The command enables a calling subscriber to get the
*  connected line identity (COL) of the called party
*  after setting up a mobile originated call.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_COLP(void);

/**
* @brief The command enables a calling subscriber to get the
*  connected line identity (COL) of the called party
*  after setting up a mobile originated call.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_COLP(void);

/**
* @brief The command enables a calling subscriber to get the
*  connected line identity (COL) of the called party
*  after setting up a mobile originated call.
* @param In:mode
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_COLP(char mode);

/**
* @brief The command refers to supplementary service
*  related network initiated notifications.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CSSN(void);

/**
* @brief The command refers to supplementary service
*  related network initiated notifications.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CSSN(void);

/**
* @brief The command refers to supplementary service
*  related network initiated notifications.
* @param In:mode,reqstr
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CSSN(char mode,char reqstr);

/**
* @brief The command allows control of the
* Unstructured Supplementary Service Data.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CUSD(void);

/**
* @brief The command allows control of the
* Unstructured Supplementary Service Data.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CUSD(void);

/**
* @brief The command allows control of the
* Unstructured Supplementary Service Data.
* @param In:mode,reqstr,rspstr
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CUSD(char mode,char reqstr,char dcs);

/**
* @brief The command returns the status of MT indicators.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CIND(void);

/**
* @brief The command returns the status of MT indicators.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CIND(void);

/**
* @brief The command edits and queries the list of preferred operators.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/
mz_error_t mz_raw_quectel_at_test_CPOL(void);

/**
* @brief The command edits and queries the list of preferred operators.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CPOL(void);

/**
* @brief The command edits and queries the list of preferred operators.
* @param In:index,format,oper,GSM,GSM_compact,Utran,EUtran.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CPOL(char index,char *format,char oper,char GSM,char GSM_compact,char Utran,char EUtran);

/**
* @brief The command returns the list of operator names from the ME.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_COPN(void);

/**
* @brief The command returns the list of operator names from the ME.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_COPN(void);

/**
* @brief The test Command enables and disables automatic time zone update via NITZ
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CTZU(void);

/**
* @brief The read Command enables and disables automatic time zone update via NITZ
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CTZU(void);

/**
* @brief The Write Command enables and disables automatic time zone
*  update via NITZ
* @param In:onoff.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CTZU(char onoff);

/**
* @brief  The test Command controls the setting of BG96‟s
power saving mode (PSM) parameters.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QPSMS(void);

/**
* @brief  The read Command controls the setting of BG96‟s
power saving mode (PSM) parameters.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QPSMS(void);

/**
* @brief  The Write Command controls the setting of BG96‟s
power saving mode (PSM) parameters.
* @param In:mode,RPRAU,RGRT,RPTAU,RAT.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QPSMS(char  mode,char * RPRAU,char * RGRT,char *RPTAU,char *RAT);

/**
* @brief This command is used to set NV#73769 (PSM configuration) parameters.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QPSMCFG(void);

/**
* @brief This command is used to set NV#73769 (PSM configuration) parameters.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QPSMCFG(void);

/**
* @brief This command is used to set NV#73769 (PSM configuration) parameters.
* @param In:threshold,psm_ver.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QPSMCFG(char threshold,char psm_ver);

/**
* @brief The command is also used for PSM setting, and
* it is mainly used to set extended parameters for modem
* optimizations.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QPSMEXTCFG(void);

/**
* @brief The command is also used for PSM setting, and
* it is mainly used to set extended parameters for modem
* optimizations.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QPSMEXTCFG(void);

/**
* @brief The command is also used for PSM setting, and
* it is mainly used to set extended parameters for modem
* optimizations.
* @param In:pom,mofs,pddto,prw,mot,ewut.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QPSMEXTCFG(char pom,char mofs,char pddto,char prw,char mot,char ewut);

/**
* @brief The command determines the flow control behavior of the serial port
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_IFC(void);

/**
* @brief The command determines the flow control behavior of the serial port
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_IFC(void);

/**
* @brief The command determines the flow control behavior of the serial port
* @param In:dce_by_dte,dte_by_dce.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_IFC(char dce_by_dte,char dte_by_dce);

/**
* @brief The command determines the serial interface
* character framing format and parity received by TA from TE.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_ICF(void);

/**
* @brief The command determines the serial interface
* character framing format and parity received by TA from TE.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_ICF(void);

/**
* @brief The command determines the serial interface
* character framing format and parity received by TA from TE.
* @param In:dce_by_dte,dte_by_dce.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_ICF( char format,char parity);

/**
* @brief This command is used to restored to inactive RI (ring indicator).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QRIR(void);

/**
* @brief This command is used to restored to inactive RI (ring indicator).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QRIR(void);

/**
* @brief The command requests the International Mobile Subscriber Identity (IMSI).
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CLCK(void);

/**
* @brief The command is used to lock, unlock or interrogate a
* MT or a network facility.
* @param In: facility , mode , password (Password necessary only
* when need to set lock mode else can be NULL)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CLCK(char *fac, char *mode, char *passwd);

/**
* @brief The command is used to test SIM pin functionality
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CPIN(void);

/**
* @brief The command is used to read SIM pin status
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CPIN(void);

/**
* @brief The command is used to set SIM pin
* @param In: Pin
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CPIN(char *pin);

/**
* @brief The test command is used for change password
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CPWD(void);

/**
* @brief The command sets a new password for the facility lock
* function defined by command facility lock
* @param In: facility , old password , new password
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CPWD(char *fac, char *old_passwd, char *new_passwd);

/**
* @brief The command offers easy and limited access to the
* (U)SIM database. It transmits the (U)SIM command
* number (<command>) and its required parameters to the MT.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CRSM(void);


/**
* @brief The command offers easy and limited access to the
* (U)SIM database. It transmits the (U)SIM command
* number (<command>) and its required parameters to the MT.
* @param In: *command,fileld,P1,P2,P3,*data,PathId
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CRSM(char *command, char fileld, char P1,char P2,char P3,char *data,char PathId);

/**
* @brief The command is used to test clock
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CCLCK(void);

/**
* @brief The command is used to set clock time
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CCLCK(void);

/**
* @brief The command is used to set clock time
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CCLCK(char *time);

/**
* @brief The command is used to test AT cmd power down
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QPOWD(void);

/**
* @brief The command is used to power down the modem
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QPOWD(void);

/**
* @brief The command is used to test AT cmd check battery voltage
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CBC(void);

/**
* @brief The command is used to check battery status
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_CBC(void);

/**
* @brief The command is used to test the voltage value of ADC channel.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QADC(void);

/**
* @brief The command is used to read the voltage value of ADC channel.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QADC(char port);

/**
* @brief The command is used to test AT cmd check temp
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QTEMP(void);

/**
* @brief The command is used to check battery temperature
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QTEMP(void);

/**
* @brief The command is used to test AT cmd of modem sleep state
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QSCLK(void);

/**
* @brief The command is used to check modem sleep status enabled/disabled
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QSCLK(void);

/**
* @brief The command is used to write modem sleep status enabled/disabled
* @param In: 0: Disable slow clock 1: Enable slow clock
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QSCLK(char val);

/**
* @brief The command is used to test the AT cmd for configure URC port
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QURCCFG(void);

/**
* @brief The command is used to chose the port for URC notification
* @param In: "usbat" , "usbmodem","uart1"
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QURCCFG(char *value);

/**
* @brief The command is used to test the AT cmd QGMR
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QGMR(void);

/**
* @brief The command is used to execute the command to get firmware
* and application version
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QGMR(void);

/**
* @brief The command is used to test the AT cmd QAPPVER
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QAPPVER(void);

/**
* @brief The command is used to execute the command to get application version
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QAPPVER(void);

/**
* @brief The command is used to test the AT cmd CPAS
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CPAS(void);

/**
* @brief The command is used to execute the mobile equipment activity status
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_CPAS(void);

/**
* @brief The command is used to test the AT cmd QCCID
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QCCID(void);

/**
* @brief The command is used to query the ICCID of USIM card
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QCCID(void);

/**
* @brief The command is used to test the AT cmd QINISTAT
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QINISTAT(void);

/**
* @brief The command is used to query the initialization status of USIM card
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QINISTAT(void);

/**
* @brief The command is used to test the AT cmd QSIMDET
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QSIMDET(void);

/**
* @brief The command is used to enable the hot swap detection
* @param In: "0" or "1" Disable / Enable SIM detection ,
*            "0" or "1" level of USIM detection pin on insertion
* (to be consistent with HW design)
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QSIMDET(char value, char ins_level);

/**
* @brief The command is used read the status of hot swap SIM function
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QSIMDET(void);

/**
* @brief The command is used to test the AT cmd QSIMSTAT
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QSIMSTAT(void);

/**
* @brief This command configures to enable/disable (U)SIM card insertion status
* @param In: "0" or "1" Disable / Enable
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QSIMSTAT(char value);

/**
* @brief The command queries (U)SIM card insertion status
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QSIMSTAT(void);



//Some more remaining Quectel AT cmds

/**
* @brief The command can query the number of attempts left to
* enter the password of (U)SIM PIN/PUK
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QPINC(void);

/**
* @brief The command tests the Display PIN remainder counter
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QPINC(void);

/**
* @brief The command can query the number of attempts left to
* enter the password specifc to SIM facility
* @param In: SIM facility
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QPINC(char *value);

/**
* @brief The command controls the time zone reporting of changed
* event. If reporting is enabled, the MT returns
* the unsolicited result code
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CTZR(void);

/**
* @brief The command controls the time zone reporting of changed
* event. If reporting is enabled, the MT returns
* the unsolicited result code
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CTZR(void);

/**
* @brief The command controls the time zone reporting of changed
* event. If reporting is enabled, the MT returns
* the unsolicited result code
* @param In: reporting
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CTZR( char reporting);

/**
* @brief The command gives details of the terminal’s perceived
* radio connection status. It returns an indication of the current state.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QCSCON(void);

/**
* @brief This is test command for signalling connection status.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QCSCON(void);

/**
* @brief This command is to enable/disable Unsolicited result code.
* @param In: Value for enable/disable
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QCSCON(char value);

/**
* @brief The Execution Command returns the latest time that has been
* synchronized through network
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QLTS(void);

/**
* @brief This is test command for query latest time through network
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QLTS(void);

/**
* @brief This is test command for query latest time through network
* @param In: value
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLTS(char value);

/**
* @brief This returns for the query network time mode to return the
* latest time that has been synchronized through network
* @param In: None.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CREG(void);

/**
* @brief This returns for the query network time mode to return the
* latest time that has been synchronized through network
* @param In: None.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CREG(void);

/**
* @brief This returns for the query network time mode to return the
* latest time that has been synchronized through network
* @param In: Mode 0: Query latest time through network  ,
*                 1: Query latest GMT time
*                 2:  Query local time
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CREG(mzInt8 n);


/**
* @brief The Write Command is used to attach the MT to,
* or detach the MT from the Packet Domain service. After
* the command has been completed,
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_CGATT(void);

/**
* @brief The Write Command is used to attach the MT to,
* or detach the MT from the Packet Domain service. After
* the command has been completed,
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_CGATT(void);

/**
* @brief The Write Command is used to attach the MT to,
* or detach the MT from the Packet Domain service. After
* the command has been completed,
* @param In: state.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_CGATT(mzInt8 state);

/**
* @brief This command is used to Extended Configuration Settings.
* @param In: For AT+QCFG=nwscanseq - Configure RAT Searching Sequence.
* 			 (AT+QCFG="nwscanseq","0","0",param1,param2,"0",0).
*
* 			 For AT+QCFG=nwscanmode - Configure RAT(s) to be Searched.
* 			 (AT+QCFG="nwscanmode","0","0",param1,param2,"0",0).
*
* 			 For AT+QCFG=iotopmode - Configure Network Category to be Searched under LTE RAT.
* 			 (AT+QCFG="iotopmode","0","0",param1,param2,"0",0).
*
* 			 For AT+QCFG=roamservice - Roam Service Configuration.
* 			 (AT+QCFG="roamservice","0","0",param1,param2,"0",0).
*
* 			 For AT+QCFG=band - Band Configuration.
* 			 (AT+QCFG="band",paramptr1,paramptr2,0,0,"paramptr1",param3).
*
* 			 For AT+QCFG=celevel - Get LTE Cat NB1 Coverage Enhancement Level.
* 			 (AT+QCFG="celevel","0","0",0,0,"0",0).
*
* 			 For AT+QCFG=servicedomain - Service Domain Configuration.
* 			 (AT+QCFG="servicedomain","0","0",param1,param2,"0",0).
*
* 			 For AT+QCFG=nb1/bandprior - Configure Band Scan Priority under LTE Cat NB1.
* 			 (AT+QCFG="nb1/bandprior","paramptr1","0",0,0,"0",0).
*
* 			 For AT+QCFG=psm/urc - Enable/Disable PSM Entering Indication.
* 			 (AT+QCFG="psm/urc","paramptr1","0",0,0,"0",0).
*
* 			 For AT+QCFG=sgsn - UE SGSN Release Version Configuration.
* 			 (AT+QCFG="sgsn","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=msc - UE MSC Release Version Configuration.
* 			 (AT+QCFG="msc","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=pdp/duplicatechk - Establish Multi PDNs with the Same APN.
* 			 (AT+QCFG="pdp/duplicatechk","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=ledmode - Configure NETLIGHT Output Mode.
* 			 (AT+QCFG="ledmode","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=ims -IMS Function Control.
* 			 (AT+QCFG="ims","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=urc/ri/ring -RI Behavior When RING URC is Presented.
* 			 (AT+QCFG="urc/ri/ring","paramptr1","0",param1,param2,"paramptr3",param3).
*
* 			 For AT+QCFG=urc/ri/smsincoming -RI Behavior When Incoming SMS URCs are Presented.
* 			 (AT+QCFG="urc/ri/smsincoming","paramptr1","0",param1,0,"0",param3).
*
* 			 For AT+QCFG=urc/ri/other -RI Behavior When Other URCs are Presented.
* 			 (AT+QCFG="urc/ri/other","paramptr1","0",param1,0,"0",param3).
*
* 			 For AT+QCFG=risignaltype -RI Signal Output Carrier.
* 			 (AT+QCFG="risignaltype","paramptr1","0",0,0,"0",0).
*
* 			 For AT+QCFG=urc/delay -Delay URC Indication.
* 			 (AT+QCFG="urc/delay","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=cmux/urcport -Configure URC Output Port for CMUX.
* 			 (AT+QCFG="cmux/urcport","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=apready -Configure AP_READY Pin.
* 			 (AT+QCFG="apready","0","0",param1,param2,"0",param3).
*
* 			 For AT+QCFG=psm/enter -Trigger Module into PSM Immediately.
* 			 (AT+QCFG="psm/enter","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=rrcabort -Abort RRC Connection.
* 			 (AT+QCFG="rrcabort","0","0",param1,0,"0",0).
*
* 			 For AT+QCFG=nccconf -Configure Features of NB-IoT.
* 			 (AT+QCFG="nccconf","0","0",param1,0,"0",0).
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QCFG(char *select ,char *paramptr1,char *paramptr2, char *paramptr3,char *paramptr4 ,char *paramptr5, mzInt8 effect);

/**
* @brief This is Execution command for Query Network Information
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QNWINFO(void);

/**
* @brief This is Test command for Query Network Information
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QNWINFO(void);

/**
* @brief The command is used to query and report the signal strength
* of the current service network
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QCSQ(void);

/**
* @brief The command is used to Display the Name of Registered Network
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_exe_QSPN(void);

/**
* @brief This is test command for Display the Name of Registered Network
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QSPN(void);

/**
* @brief The command allows the application to check how much bytes
* are sent to or received by the module.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QGDCNT(void);

/**
* @brief The is test command for packet data counter.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QGDCNT(void);

/**
* @brief This command performs operation mode for packet data counter.
* @param In: 0: Reset counter 1: Save counter to NV
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QGDCNT(char value);

/**
* @brief The command reads timer in second for AT+QGDCNT to save
* results to NV automatically
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QAUGDCNT(void);

/**
* @brief The is test command for auto save of AT+QAUGDCNT
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QAUGDCNT(void);

/**
* @brief The command writes timer value in second for AT+QGDCNT to save
* results to NV automatically
* @param In: time in seconds
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QAUGDCNT(char value);

/**
* @brief This is ATE execution command controls whether or not the module echoes characters received from TE during AT command echoes mode disable
* @param : None
* @return Error code
* MZ_OK
* MZ_FAIL
*/
mz_error_t mz_raw_at_exe_e0(void);
/**
* @brief This is ATE execution command controls whether or not the module echoes characters received from TE during AT command echoes mode enable
* @param : None
* @return Error code
* MZ_OK
* MZ_FAIL
*/
mz_error_t mz_raw_at_exe_e1(void);

/**
* @brief This is test command for control URC indication.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/


mz_error_t mz_raw_quectel_at_test_QINDCFG(void);

/**
* @brief This command is for control URC indication.
* @param In: urc: "all": Main switch of all URCs. Default is ON.
*                  "csq" : Indication of signal strength and channel bit error rate
*                          change (similar to AT+CSQ). Default is OFF.
*                  "smsfull": SMS storage full indication. Default is OFF. If this
*                             configuration is ON, present:+QIND: "smsfull",<storage>
*                  "ring": RING indication. Default is ON.
*                  "smsincoming":  Incoming message indication. Default is ON.
*            mode:   0 : OFF 1 : ON
*            savetonv: 0: Not save 1: Save
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QINDCFG(char *urc, char mode , char savetonv);

/**
* @brief This command is for setting  configure optional parameters of MQTT.
* @param In: version:
             tcpid:    	MQTT socket identifier.
             vsn:		MQTT protocol version.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTCFG(char *select, char tcpid,char param1, char param2,char param3,char *willtop_pkey,char *wmsg_devname,char *devicesecret);

/**
* @brief This command configures optional parameters of MQTT.
* @param In: None.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTCFG(void);

/**
* @brief The command is used to open a network for MQTT client.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTOPEN(void);

/**
* @brief The command is used to read a network for MQTT client.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QMTOPEN(void);

/**
* @brief This command is for setting open a network for MQTT client.
* @param In:tcpid:    	MQTT socket identifier. The range is 0-5
            host_name:	The address of the server.IP address or domain name
            port:		The port of the server. The range is 1-65535.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTOPEN(char tcpid,char *host_name,mzInt16 port);

/**
* @brief The command is used to close a network for MQTT client.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTCLOSE(void);

/**
* @brief This command is for setting close a network for MQTT client.
* @param In:tcpid:    	MQTT socket identifier. The range is 0-5.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTCLOSE(char tcpid);

/**
* @brief The command is used when a client requests a connection to MQTT server.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTCONN(void);

/**
* @brief The command is used when a client requests a connection to MQTT server.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_read_QMTCONN(void);

/**
* @brief The command is used when a client requests a connection to MQTT server.
* @param In:client_idx:    	MQTT client identifier. Range: 0–5.
            clientID:		The client identifier string.
            username:		User name of the client. It can be used for authentication.
            password:		Password corresponding to the user name of the client. It can be used for authentication.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTCONN(char client_idx,char *clientID,char *username,char *password);

/**
* @brief The command is used when a client requests a disconnection from MQTT server.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTDISC(void);

/**
* @brief The command is used when a client requests a disconnection from MQTT server.
* @param In:tcpid:    	MQTT socket identifier. The range is 0-5.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTDISC(char tcpid);

/**
* @brief The command is used to subscribe to one or more topics.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTSUB(void);

/**
* @brief The command is used to subscribe to one or more topics.
* @param In:tcpid:    	MQTT socket identifier. The range is 0-5.
* 			msgID:		Message identifier of packet. The range is 1-65535.
* 			topic:		Topic that the client wants to subscribe to or unsubscribe from.
* 			qos:		The QoS level at which the client wants to publish the messages.value 1,2,3.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTSUB(char tcpid ,char msgID, char *topic, char qos);

/**
* @brief The command is used to unsubscribe from one or more topics.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTUNS(void);

/**
* @brief The command is used to unsubscribe from one or more topics.
* @param In:tcpid:    	MQTT socket identifier. The range is 0-5.
* 			msgID:		Message identifier of packet. The range is 1-65535.
* 			topic:		Topic that the client wants to subscribe to or unsubscribe from.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTUNS(char tcpid ,char msgID, char *topic);

/**
* @brief The command is used to publish messages by a client to a server for distribution to interested subscribers.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTPUB(void);

/**
* @brief The command is used to publish messages by a client to a server for distribution to interested subscribers.
* @param In:tcpid:    	MQTT socket identifier. The range is 0-5.
* 			msgID:		Message identifier of packet. The range is 1-65535.
* 			qos:		The QoS level at which the client wants to publish the messages.value 1,2,3.
* 			retain:		Whether or not the server will retain the message after it has been delivered to the current subscribers.
* 			topic:		Topic that the client wants to subscribe to or unsubscribe from.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTPUB(char tcpid ,char msgID,char qos,char retain, char *topic,mzInt16 msglen);

/**
* @brief This command publishes messages. Unlike AT+QMTPUB, customers can enter the specified payload
		directly by executing this command.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTPUBEX(void);

/**
* @brief This command publishes messages. Unlike AT+QMTPUB, customers can enter the specified payload
		directly by executing this command.
* @param In:tcpid:    	MQTT socket identifier. The range is 0-5.
* 			msgID:		Message identifier of packet. The range is 1-65535.
* 			qos:		The QoS level at which the client wants to publish the messages.value 1,2,3.
* 			retain:		Whether or not the server will retain the message after it has been delivered to the current subscribers.
* 			topic:		Topic that the client wants to subscribe to or unsubscribe from.
* 			mesg:		Message to be published. Maximum message length: 560 bytes.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTPUBEX(char tcpid ,char msgID,char qos,char retain, char *topic, char *mesg);

/**
* @brief This command reads messages from the storage buffer where the messages are stored when they are
		reported by the server.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_test_QMTRECV(void);

/**
* @brief This command reads messages from the storage buffer where the messages are stored when they are
		reported by the server.
* @param In:client_idx:  MQTT socket identifier. The range is 0-5.
* 			recvID:		 Serial number of every single message received. Range: 0–4.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QMTRECV(char client_idx ,char recvID);

//LWM2M cmds

/**
* @brief This command is for register to LWM2M server.
* @param In: regmode: 0 Register to the server only once.
*                     1 Register to the server automatically.
* @return Error code
* MZ_OK
* MZ_FAIL
*/


mz_error_t mz_raw_quectel_at_write_QLWM2M_REGISTER(char *regmode);

/**
* @brief This command is for de-register to LWM2M server.
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_DEREGISTER(void *empty);

/**
* @brief This command is for selection of category of LWM2M server.
* @param In: mode: 0 Leshan server
*                  1 T-Mobile server
*                  2 LGU+ server
*                  3 Verizon motive server
*                  4 Ericsson server
*                  5 AT&T server 0 Register to the server only once.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_SELECT(char *mode);

/**
* @brief This command is for selection of CDP URL and portnum.
* @param In: coap_url: URL for coap connection for LWM2M server
*            port_num: Port number
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_CDP(char *coap_url, char *port_num);

/**
* @brief This command is for selection of BOOTSTRAP URL.
* @param In: bs_url: URL for coap connection for BOOTSTRAP server
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_BOOTSTRAP_URL(char *bs_url);

/**
* @brief This command is for configuring lifetime of LWM2M connection.
* @param In: lifetime_s: lifetime in seconds
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_BOOTSTRAP_LIFETIME(char *lifetime);

/**
* @brief This command is for configuring connection to Bootstrap or LWM2M server.
* @param In: access_mode: "false":registration server , "true": Bootstrap server
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_BOOTSTRAP_MODE(char *access_mode);

/**
* @brief This command is for configuring security mode of bootstrap.
* @param In: access_mode: 0: PSK mode , 3: Non secure mode
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_BOOTSTRAP_SECMODE(char *sec_mode);

/**
* @brief This command is for configuring Endpoint name
* @param In: mode:  "0" --> Generate EP name automatically
*                   "1" --> Configure EP name as ep_name
*            ep_name: End point name
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_EPNS(char *mode, char *ep_name);

/**
* @brief This command is for configuring bootstrap mode
* @param In: mode:  "0" --> Factory bootstrap
*                   "1" --> Client bootstrap
*            ep_name: End point name
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_BSMODE(char *mode);

/**
* @brief This command is for configuring LWM2M connection apn name
* @param In: mode:  apn --> APN name
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_APN(char *apn);

/**
* @brief This command is for configuring endpoint type for LWM2M
* @param In: reg_epmode : 4 :IMEI URN ,7 :IMEI MSISDN URN
*            bs_epmode  : 4 :IMEI URN ,7 :IMEI MSISDN URN
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_ENDPOINT(char *reg_epmode, char *bs_epmode);

/**
* @brief This command is for configuring LWM2M client
* @param In: value: 0 : Disable , 1 : Enable
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_ENABLE(char *value);

/**
* @brief This command is for uploading data to LWM2M server in hex
* @param In:  objID: Object ID
*             size : Size of data in hex format bytes
*             hexdata: Data in hex format
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_ULHEX(char *objID, char *size,
                                                 char *hexdata);

/**
* @brief This command is for uploading data to LWM2M server in text
* @param In:  objID: Object ID
*             size : Size of data in text format bytes
*             textdata: Data in text format
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_ULDATA(char *objID, char *size,
                                                 char *textdata);

/**
* @brief This command is for resetting LWM2M client, delete all persistent
*        files of LWM2M client connection
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_RESET(void *empty);

/**
* @brief This command is for cleaning all LWM2M client configuration
* @param In: None
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_CLEAN(void *empty);

/**
* @brief This command is for setting preferred download type from LWM2M server
* @param In: "0" : Prefer in text format , "1": Prefer in hex format
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_DLTYPE(char *value);

/**
* @brief This command is for setting update mode of LWM2M client connection
* @param In: ssid: Short server id
*            lifetime_s: Lifetime of connection in seconds
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_LIFETIME(char *ssid , char *lifetime_s);

/**
* @brief This command is for setting preference type for IP data call
* @param In: ip_type: 0 Prefer to start IPv4 data call.
                      1 Prefer to start IPv6 data call.
* @return Error code
* MZ_OK
* MZ_FAIL
*/

mz_error_t mz_raw_quectel_at_write_QLWM2M_IPPREF(char *pref);

/**
 * @fn void mz_create_cmd_timeout(mzInt32 _to)
 * @brief creates the command timeout
 * @param _to mzInt32
 */
void mz_create_cmd_timeout(mzInt32 _to);

/**
 * @fn void mz_create_cmd_time_wait_before_next(mzInt32 _twn)
 * @brief creates the command time wait before next command
 * @param _twn mzInt32
 */
void mz_create_cmd_time_wait_before_next(mzInt32 _twn);

/** @} */
#endif /* MZ_QUECTEL_AT_INCLUDE_H_ */
#ifdef __cplusplus
}
#endif
#endif /* (MZ_MODEM_BG96 == 1) */
