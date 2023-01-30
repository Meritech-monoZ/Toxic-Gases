/*
 * MZ_modem_config.c
 *
 *  Created on: Jun 29, 2021
 *      Author: MZ_click
 */

#include "MZ_timer.h"
#include "MZ_Modem_public.h"
#include "MZ_Simcom_AT_include.h"
#include "MZ_Quectel_AT_include.h"
#include "main.h"

#if(MZ_SDK_ADVANCE_AT_INJECT == 1)

// Please refer the Advance documentation.

#else
void bg96_setup(void)
{
	mz_create_cmd_timeout(AT_TIME_1SEC);
	mz_create_cmd_time_wait_before_next(AT_TIME_1SEC);
	mz_raw_quectel_at_write_IFC(0,0);mz_create_cmd_time_wait_before_next(300);
	mz_raw_at_exe_at();mz_create_cmd_time_wait_before_next(300);
	mz_raw_at_exe_e1();
	mz_raw_at_write_cmee(0);//NO handling so disable
	mz_raw_quectel_at_exe_ATV(1);
	mz_raw_quectel_at_exe_ATD(0,0);
	mz_raw_at_exe_cgmr();
	mz_raw_at_write_cfun(1,0);
	mz_raw_at_write_cpsms(0,0,0,0,0);
	mz_raw_quectel_at_write_QCFG("roamservice","","","","","",0);
	mz_raw_quectel_at_write_QCFG("band","","","","","",0);
	mz_raw_quectel_at_write_QCFG("nwscanseq","","","","","",0);
	mz_raw_quectel_at_write_QCFG("nwscanmode","","","","","",0);
	mz_raw_quectel_at_write_QCFG("iotopmode","","","","","",0);
	mz_raw_at_write_cops(0,0,0);//operator not get latch after switching the NW
	mz_raw_quectel_at_exe_QCCID();
	mz_raw_quectel_at_read_CPIN();
	mz_raw_quectel_at_read_CGDCONT();
	mz_raw_at_exe_cimi();
	mz_raw_quectel_at_write_CGDCONT(1,"IP","iot.1nce.net",0,0,0);
	mz_raw_quectel_at_write_CGACT(1,1);
	mz_raw_quectel_at_write_CREG(2);
	mz_raw_quectel_at_write_CGREG(2);
	mz_raw_at_write_cereg(2);
	mz_raw_at_exe_gsn();
	mz_raw_at_exe_cgmi();
	mz_raw_at_exe_cgmm();
	mz_raw_quectel_at_exe_QGMR();
	mz_raw_at_exe_cgsn();
	mz_raw_at_read_cops();
	mz_raw_at_exe_csq();
	mz_raw_at_read_cclk();
	init_complete = 1;
}

void mz_reset_sequence(void * arg)
{
	(void)arg;
	bg96_setup();
}

void mz_reboot_sequence(void * arg)
{
	(void)arg;
	bg96_setup();
}

#endif //(MZ_SDK_ADVANCE_AT_INJECT == 1)
