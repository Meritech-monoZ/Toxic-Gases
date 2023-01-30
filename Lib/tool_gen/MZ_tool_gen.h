/**
 * @file MZ_tool_gen.h
 * @date Mar 3  2021
 * @author MZ_click
 * @brief  This is a tool generated file. Do not edit manually
 */ 


#ifndef INC_MZ_TOOL_GEN_H_
#define INC_MZ_TOOL_GEN_H_                              						///< Defines Inc Monoz Tool Generator
#include"MZ_BoardCfg.h"

#if(MZ_ADC1 == MZ_ENABLE)
#define MZI_ADC1		(MZ_DISABLE)
#endif
#if(MZ_ADC2 == MZ_ENABLE)
#define MZI_ADC2		(MZ_DISABLE)
#endif
#if(MZ_ADC3 == MZ_ENABLE)
#define MZI_ADC3		(MZ_ENABLE)
#endif

#endif /* INC_MZ_TOOL_GEN_H_ */
