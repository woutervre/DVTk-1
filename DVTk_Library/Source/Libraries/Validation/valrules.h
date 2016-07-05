// ------------------------------------------------------
// DVTk - The Healthcare Validation Toolkit (www.dvtk.org)
// Copyright � 2009 DVTk
// ------------------------------------------------------
// This file is part of DVTk.
//
// DVTk is free software; you can redistribute it and/or modify it under the terms of the GNU
// Lesser General Public License as published by the Free Software Foundation; either version 3.0
// of the License, or (at your option) any later version. 
// 
// DVTk is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
// the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. 
// 
// You should have received a copy of the GNU Lesser General Public License along with this
// library; if not, see <http://www.gnu.org/licenses/>

//*****************************************************************************
//  DESCRIPTION     :	Contains code definitions for the implemented validation 
//						rules.
//*****************************************************************************
#ifndef VALRULES_H
#define VALRULES_H

//*****************************************************************************
//  EXTERNAL DECLARATIONS
//*****************************************************************************
#include "Iglobal.h"

//*****************************************************************************
//  CONSTANTS AND TYPE DEFINITIONS
//*****************************************************************************
struct T_VAL_RULE_CODE_STRING_STRUCT
{
	UINT32 code;
	char *codeString_ptr;
};

const char* mapValRule(UINT32);

// Base definitions
const UINT32 VAL_RULE_GENERAL_BASE    = 0x0000;

const UINT32 VAL_RULE_D_VR_BASE           = 0x1000;
const UINT32 VAL_RULE_D_VM_BASE           = 0x2000;
const UINT32 VAL_RULE_D_ENCODING_BASE     = 0x3000;
const UINT32 VAL_RULE_D_RANGE_BASE        = 0x4000;
const UINT32 VAL_RULE_D_PRESENCE_BASE     = 0x5000;
const UINT32 VAL_RULE_DEF_COMMAND_BASE    = 0x5500;
const UINT32 VAL_RULE_DEF_DEFINITION_BASE = 0x5600;
const UINT32 VAL_RULE_PIXEL_DATA_BASE	  = 0x5700;
const UINT32 VAL_RULE_PRIVATE_BASE		  = 0x5800;

const UINT32 VAL_RULE_R_REF_BASE      = 0x6000;

const UINT32 VAL_RULE_A_MEDIA_BASE    = 0x8000;      
const UINT32 VAL_RULE_A_QR_BASE       = 0x9000;      
const UINT32 VAL_RULE_A_WLM_BASE      = 0xA000;      
const UINT32 VAL_RULE_A_SR_BASE       = 0xB000;

const UINT32 VAL_RULE_ACSE_BASE		  = 0xC000;      

const UINT32 VAL_RULE_INTERNAL_ERROR_BASE  = 0xF000;


// General rules
const UINT32 VAL_RULE_GENERAL_1       = VAL_RULE_GENERAL_BASE + 0x0001;

// Rules regarding checks against the definition
//
// Codes have prefix D_
//

// Rules regarding value representation
const UINT32 VAL_RULE_D_VR_1          = VAL_RULE_D_VR_BASE + 0x0001; 
const UINT32 VAL_RULE_D_VR_2          = VAL_RULE_D_VR_BASE + 0x0002; 
const UINT32 VAL_RULE_D_VR_3          = VAL_RULE_D_VR_BASE + 0x0003; 

// Rules regarding value multiplicity
const UINT32 VAL_RULE_D_VM_1          = VAL_RULE_D_VM_BASE + 0x0001;
const UINT32 VAL_RULE_D_VM_2          = VAL_RULE_D_VM_BASE + 0x0002;
const UINT32 VAL_RULE_D_VM_3          = VAL_RULE_D_VM_BASE + 0x0003;
const UINT32 VAL_RULE_D_VM_4          = VAL_RULE_D_VM_BASE + 0x0004;
const UINT32 VAL_RULE_D_VM_5          = VAL_RULE_D_VM_BASE + 0x0005;

// Rules regarding value encoding

// VR AE
const UINT32 VAL_RULE_D_AE_1          = VAL_RULE_D_ENCODING_BASE + 0x0001;
const UINT32 VAL_RULE_D_AE_2          = VAL_RULE_D_ENCODING_BASE + 0x0002;
const UINT32 VAL_RULE_D_AE_3          = VAL_RULE_D_ENCODING_BASE + 0x0003;

// VR AS
const UINT32 VAL_RULE_D_AS_1          = VAL_RULE_D_ENCODING_BASE + 0x0011;
const UINT32 VAL_RULE_D_AS_2          = VAL_RULE_D_ENCODING_BASE + 0x0012;
const UINT32 VAL_RULE_D_AS_3          = VAL_RULE_D_ENCODING_BASE + 0x0013;

// VR AT
const UINT32 VAL_RULE_D_AT_1          = VAL_RULE_D_ENCODING_BASE + 0x0021;
const UINT32 VAL_RULE_D_AT_2          = VAL_RULE_D_ENCODING_BASE + 0x0022;
const UINT32 VAL_RULE_D_AT_3          = VAL_RULE_D_ENCODING_BASE + 0x0023;

// VR CS
const UINT32 VAL_RULE_D_CS_1          = VAL_RULE_D_ENCODING_BASE + 0x0031;
const UINT32 VAL_RULE_D_CS_2          = VAL_RULE_D_ENCODING_BASE + 0x0032;
const UINT32 VAL_RULE_D_CS_3          = VAL_RULE_D_ENCODING_BASE + 0x0033;

// VR DA
const UINT32 VAL_RULE_D_DA_1          = VAL_RULE_D_ENCODING_BASE + 0x0041;
const UINT32 VAL_RULE_D_DA_2          = VAL_RULE_D_ENCODING_BASE + 0x0042;
const UINT32 VAL_RULE_D_DA_3          = VAL_RULE_D_ENCODING_BASE + 0x0043;
const UINT32 VAL_RULE_D_DA_4          = VAL_RULE_D_ENCODING_BASE + 0x0044;
const UINT32 VAL_RULE_D_DA_5          = VAL_RULE_D_ENCODING_BASE + 0x0045;
const UINT32 VAL_RULE_D_DA_6          = VAL_RULE_D_ENCODING_BASE + 0x0046;
const UINT32 VAL_RULE_D_DA_7          = VAL_RULE_D_ENCODING_BASE + 0x0047;
const UINT32 VAL_RULE_D_DA_8          = VAL_RULE_D_ENCODING_BASE + 0x0048;

// VR DS
const UINT32 VAL_RULE_D_DS_1          = VAL_RULE_D_ENCODING_BASE + 0x0051;
const UINT32 VAL_RULE_D_DS_2          = VAL_RULE_D_ENCODING_BASE + 0x0052;
const UINT32 VAL_RULE_D_DS_3          = VAL_RULE_D_ENCODING_BASE + 0x0053;
const UINT32 VAL_RULE_D_DS_4          = VAL_RULE_D_ENCODING_BASE + 0x0054;

// VR DT
const UINT32 VAL_RULE_D_DT_1          = VAL_RULE_D_ENCODING_BASE + 0x0061;
const UINT32 VAL_RULE_D_DT_2          = VAL_RULE_D_ENCODING_BASE + 0x0062;
const UINT32 VAL_RULE_D_DT_3          = VAL_RULE_D_ENCODING_BASE + 0x0063;
const UINT32 VAL_RULE_D_DT_4          = VAL_RULE_D_ENCODING_BASE + 0x0064;
const UINT32 VAL_RULE_D_DT_5          = VAL_RULE_D_ENCODING_BASE + 0x0065;
const UINT32 VAL_RULE_D_DT_6          = VAL_RULE_D_ENCODING_BASE + 0x0066;

// VR FL
const UINT32 VAL_RULE_D_FL_1          = VAL_RULE_D_ENCODING_BASE + 0x0071;
const UINT32 VAL_RULE_D_FL_2          = VAL_RULE_D_ENCODING_BASE + 0x0072;
const UINT32 VAL_RULE_D_FL_3          = VAL_RULE_D_ENCODING_BASE + 0x0073;

// VR FD
const UINT32 VAL_RULE_D_FD_1          = VAL_RULE_D_ENCODING_BASE + 0x0081;
const UINT32 VAL_RULE_D_FD_2          = VAL_RULE_D_ENCODING_BASE + 0x0082;
const UINT32 VAL_RULE_D_FD_3          = VAL_RULE_D_ENCODING_BASE + 0x0083;

// VR IS
const UINT32 VAL_RULE_D_IS_1          = VAL_RULE_D_ENCODING_BASE + 0x0091;
const UINT32 VAL_RULE_D_IS_2          = VAL_RULE_D_ENCODING_BASE + 0x0092;
const UINT32 VAL_RULE_D_IS_3          = VAL_RULE_D_ENCODING_BASE + 0x0093;

// VR LO
const UINT32 VAL_RULE_D_LO_1          = VAL_RULE_D_ENCODING_BASE + 0x00A1;
const UINT32 VAL_RULE_D_LO_2          = VAL_RULE_D_ENCODING_BASE + 0x00A2;
const UINT32 VAL_RULE_D_LO_3          = VAL_RULE_D_ENCODING_BASE + 0x00A3;

// VR LT
const UINT32 VAL_RULE_D_LT_1          = VAL_RULE_D_ENCODING_BASE + 0x00B1;
const UINT32 VAL_RULE_D_LT_2          = VAL_RULE_D_ENCODING_BASE + 0x00B2;
const UINT32 VAL_RULE_D_LT_3          = VAL_RULE_D_ENCODING_BASE + 0x00B3;

// VR OB/OF/OW
const UINT32 VAL_RULE_D_OTHER_1        = VAL_RULE_D_ENCODING_BASE + 0x00C1;
const UINT32 VAL_RULE_D_OTHER_2        = VAL_RULE_D_ENCODING_BASE + 0x00C2;
const UINT32 VAL_RULE_D_OTHER_3        = VAL_RULE_D_ENCODING_BASE + 0x00C3;
const UINT32 VAL_RULE_D_OTHER_4        = VAL_RULE_D_ENCODING_BASE + 0x00C4;
const UINT32 VAL_RULE_D_OTHER_5        = VAL_RULE_D_ENCODING_BASE + 0x00C5;
const UINT32 VAL_RULE_D_OTHER_6        = VAL_RULE_D_ENCODING_BASE + 0x00C6;
const UINT32 VAL_RULE_D_OTHER_7        = VAL_RULE_D_ENCODING_BASE + 0x00C7;
const UINT32 VAL_RULE_D_OTHER_8        = VAL_RULE_D_ENCODING_BASE + 0x00C8;
const UINT32 VAL_RULE_D_OTHER_9        = VAL_RULE_D_ENCODING_BASE + 0x00C9;
const UINT32 VAL_RULE_D_OTHER_10       = VAL_RULE_D_ENCODING_BASE + 0x00CA;
const UINT32 VAL_RULE_D_OTHER_11       = VAL_RULE_D_ENCODING_BASE + 0x00CB;
const UINT32 VAL_RULE_D_OTHER_12       = VAL_RULE_D_ENCODING_BASE + 0x00CC;
const UINT32 VAL_RULE_D_OTHER_13       = VAL_RULE_D_ENCODING_BASE + 0x00CD;
const UINT32 VAL_RULE_D_OTHER_14       = VAL_RULE_D_ENCODING_BASE + 0x00CE;
const UINT32 VAL_RULE_D_OTHER_15       = VAL_RULE_D_ENCODING_BASE + 0x00CF;
const UINT32 VAL_RULE_D_OTHER_16       = VAL_RULE_D_ENCODING_BASE + 0x00D0;
const UINT32 VAL_RULE_D_OTHER_17       = VAL_RULE_D_ENCODING_BASE + 0x00D1;
const UINT32 VAL_RULE_D_OTHER_18       = VAL_RULE_D_ENCODING_BASE + 0x00D2;
const UINT32 VAL_RULE_D_OTHER_19       = VAL_RULE_D_ENCODING_BASE + 0x00D3;
const UINT32 VAL_RULE_D_OTHER_20       = VAL_RULE_D_ENCODING_BASE + 0x00D4;

// VR PN
const UINT32 VAL_RULE_D_PN_1          = VAL_RULE_D_ENCODING_BASE + 0x00E1;
const UINT32 VAL_RULE_D_PN_2          = VAL_RULE_D_ENCODING_BASE + 0x00E2;
const UINT32 VAL_RULE_D_PN_3          = VAL_RULE_D_ENCODING_BASE + 0x00E3;

// VR SH
const UINT32 VAL_RULE_D_SH_1          = VAL_RULE_D_ENCODING_BASE + 0x0101;
const UINT32 VAL_RULE_D_SH_2          = VAL_RULE_D_ENCODING_BASE + 0x0102;
const UINT32 VAL_RULE_D_SH_3          = VAL_RULE_D_ENCODING_BASE + 0x0103;

// VR SL
const UINT32 VAL_RULE_D_SL_1          = VAL_RULE_D_ENCODING_BASE + 0x0111;
const UINT32 VAL_RULE_D_SL_2          = VAL_RULE_D_ENCODING_BASE + 0x0112;
const UINT32 VAL_RULE_D_SL_3          = VAL_RULE_D_ENCODING_BASE + 0x0113;

// VR SS
const UINT32 VAL_RULE_D_SS_1          = VAL_RULE_D_ENCODING_BASE + 0x0121;
const UINT32 VAL_RULE_D_SS_2          = VAL_RULE_D_ENCODING_BASE + 0x0122;
const UINT32 VAL_RULE_D_SS_3          = VAL_RULE_D_ENCODING_BASE + 0x0123;

// VR ST
const UINT32 VAL_RULE_D_ST_1          = VAL_RULE_D_ENCODING_BASE + 0x0131;
const UINT32 VAL_RULE_D_ST_2          = VAL_RULE_D_ENCODING_BASE + 0x0132;
const UINT32 VAL_RULE_D_ST_3          = VAL_RULE_D_ENCODING_BASE + 0x0133;

// VR TM
const UINT32 VAL_RULE_D_TM_1          = VAL_RULE_D_ENCODING_BASE + 0x0141;
const UINT32 VAL_RULE_D_TM_2          = VAL_RULE_D_ENCODING_BASE + 0x0142;
const UINT32 VAL_RULE_D_TM_3          = VAL_RULE_D_ENCODING_BASE + 0x0143;
const UINT32 VAL_RULE_D_TM_4          = VAL_RULE_D_ENCODING_BASE + 0x0144;
const UINT32 VAL_RULE_D_TM_5          = VAL_RULE_D_ENCODING_BASE + 0x0145;
const UINT32 VAL_RULE_D_TM_6          = VAL_RULE_D_ENCODING_BASE + 0x0146;
const UINT32 VAL_RULE_D_TM_7          = VAL_RULE_D_ENCODING_BASE + 0x0147;
const UINT32 VAL_RULE_D_TM_8          = VAL_RULE_D_ENCODING_BASE + 0x0148;
const UINT32 VAL_RULE_D_TM_9          = VAL_RULE_D_ENCODING_BASE + 0x0149;
const UINT32 VAL_RULE_D_TM_A          = VAL_RULE_D_ENCODING_BASE + 0x014a;

// VR UI
const UINT32 VAL_RULE_D_UI_1          = VAL_RULE_D_ENCODING_BASE + 0x0151;
const UINT32 VAL_RULE_D_UI_2          = VAL_RULE_D_ENCODING_BASE + 0x0152;
const UINT32 VAL_RULE_D_UI_3          = VAL_RULE_D_ENCODING_BASE + 0x0153;
const UINT32 VAL_RULE_D_UI_4          = VAL_RULE_D_ENCODING_BASE + 0x0154;
const UINT32 VAL_RULE_D_UI_5          = VAL_RULE_D_ENCODING_BASE + 0x0155;
const UINT32 VAL_RULE_D_UI_6          = VAL_RULE_D_ENCODING_BASE + 0x0156;

// VR UL
const UINT32 VAL_RULE_D_UL_1          = VAL_RULE_D_ENCODING_BASE + 0x0161;
const UINT32 VAL_RULE_D_UL_2          = VAL_RULE_D_ENCODING_BASE + 0x0162;
const UINT32 VAL_RULE_D_UL_3          = VAL_RULE_D_ENCODING_BASE + 0x0163;

// VR UN
const UINT32 VAL_RULE_D_UN_1          = VAL_RULE_D_ENCODING_BASE + 0x0171;
const UINT32 VAL_RULE_D_UN_2          = VAL_RULE_D_ENCODING_BASE + 0x0172;
const UINT32 VAL_RULE_D_UN_3          = VAL_RULE_D_ENCODING_BASE + 0x0173;

// VR US
const UINT32 VAL_RULE_D_US_1          = VAL_RULE_D_ENCODING_BASE + 0x0181;
const UINT32 VAL_RULE_D_US_2          = VAL_RULE_D_ENCODING_BASE + 0x0182;
const UINT32 VAL_RULE_D_US_3          = VAL_RULE_D_ENCODING_BASE + 0x0183;

// VR UT
const UINT32 VAL_RULE_D_UT_1          = VAL_RULE_D_ENCODING_BASE + 0x0191;
const UINT32 VAL_RULE_D_UT_2          = VAL_RULE_D_ENCODING_BASE + 0x0192;
const UINT32 VAL_RULE_D_UT_3          = VAL_RULE_D_ENCODING_BASE + 0x0193;

// VR Extended character set rules
const UINT32 VAL_RULE_D_EXT_1         = VAL_RULE_D_ENCODING_BASE + 0x01A1;
const UINT32 VAL_RULE_D_EXT_2         = VAL_RULE_D_ENCODING_BASE + 0x01A2;
const UINT32 VAL_RULE_D_EXT_3         = VAL_RULE_D_ENCODING_BASE + 0x01A3;
const UINT32 VAL_RULE_D_EXT_4         = VAL_RULE_D_ENCODING_BASE + 0x01A4;
const UINT32 VAL_RULE_D_EXT_5         = VAL_RULE_D_ENCODING_BASE + 0x01A5;
const UINT32 VAL_RULE_D_EXT_6         = VAL_RULE_D_ENCODING_BASE + 0x01A6;
const UINT32 VAL_RULE_D_EXT_7         = VAL_RULE_D_ENCODING_BASE + 0x01A7;
const UINT32 VAL_RULE_D_EXT_8         = VAL_RULE_D_ENCODING_BASE + 0x01A8;
const UINT32 VAL_RULE_D_EXT_9         = VAL_RULE_D_ENCODING_BASE + 0x01A9;
const UINT32 VAL_RULE_D_EXT_10        = VAL_RULE_D_ENCODING_BASE + 0x01AA;

// Length odd - should be even
const UINT32 VAL_RULE_D_ODDLEN_1      = VAL_RULE_D_ENCODING_BASE + 0x01B0;

// Rules regarding value range
const UINT32 VAL_RULE_D_RANGE_1       = VAL_RULE_D_RANGE_BASE + 0x0001;
const UINT32 VAL_RULE_D_RANGE_2       = VAL_RULE_D_RANGE_BASE + 0x0002;
const UINT32 VAL_RULE_D_RANGE_3       = VAL_RULE_D_RANGE_BASE + 0x0003;

// Rules regarding attribute presence
const UINT32 VAL_RULE_D_PRESENCE_1    = VAL_RULE_D_PRESENCE_BASE + 0x0001;
const UINT32 VAL_RULE_D_PRESENCE_2    = VAL_RULE_D_PRESENCE_BASE + 0x0002;
const UINT32 VAL_RULE_D_PRESENCE_3    = VAL_RULE_D_PRESENCE_BASE + 0x0003;
const UINT32 VAL_RULE_D_PRESENCE_4    = VAL_RULE_D_PRESENCE_BASE + 0x0004;
const UINT32 VAL_RULE_D_PRESENCE_5    = VAL_RULE_D_PRESENCE_BASE + 0x0005;
const UINT32 VAL_RULE_D_PRESENCE_6    = VAL_RULE_D_PRESENCE_BASE + 0x0006;
const UINT32 VAL_RULE_D_PRESENCE_7    = VAL_RULE_D_PRESENCE_BASE + 0x0007;
const UINT32 VAL_RULE_D_PRESENCE_8    = VAL_RULE_D_PRESENCE_BASE + 0x0008;
const UINT32 VAL_RULE_D_PRESENCE_9    = VAL_RULE_D_PRESENCE_BASE + 0x0009;
const UINT32 VAL_RULE_D_PRESENCE_10   = VAL_RULE_D_PRESENCE_BASE + 0x000A;
const UINT32 VAL_RULE_D_PRESENCE_11   = VAL_RULE_D_PRESENCE_BASE + 0x000B;
const UINT32 VAL_RULE_D_PRESENCE_12   = VAL_RULE_D_PRESENCE_BASE + 0x000C;
const UINT32 VAL_RULE_D_PRESENCE_13   = VAL_RULE_D_PRESENCE_BASE + 0x000D;
const UINT32 VAL_RULE_D_PRESENCE_14   = VAL_RULE_D_PRESENCE_BASE + 0x000E;

// Rules regarding the pixel data length
const UINT32 VAL_RULE_PIXEL_DATA_1	  = VAL_RULE_PIXEL_DATA_BASE +0x0001;
const UINT32 VAL_RULE_PIXEL_DATA_2	  = VAL_RULE_PIXEL_DATA_BASE +0x0002;
const UINT32 VAL_RULE_PIXEL_DATA_3	  = VAL_RULE_PIXEL_DATA_BASE +0x0003;
const UINT32 VAL_RULE_PIXEL_DATA_4	  = VAL_RULE_PIXEL_DATA_BASE +0x0004;
const UINT32 VAL_RULE_PIXEL_DATA_5	  = VAL_RULE_PIXEL_DATA_BASE +0x0005;
const UINT32 VAL_RULE_PIXEL_DATA_6	  = VAL_RULE_PIXEL_DATA_BASE +0x0006;

// Rules regarding ACSE parameters
const UINT32 VAL_RULE_D_PARAM_1       = VAL_RULE_ACSE_BASE + 0x0001;
const UINT32 VAL_RULE_D_PARAM_2       = VAL_RULE_ACSE_BASE + 0x0002;
const UINT32 VAL_RULE_D_PARAM_3       = VAL_RULE_ACSE_BASE + 0x0003;
const UINT32 VAL_RULE_D_PARAM_4       = VAL_RULE_ACSE_BASE + 0x0004;
const UINT32 VAL_RULE_D_PARAM_5       = VAL_RULE_ACSE_BASE + 0x0005;
const UINT32 VAL_RULE_D_PARAM_6       = VAL_RULE_ACSE_BASE + 0x0006;
const UINT32 VAL_RULE_D_PARAM_7       = VAL_RULE_ACSE_BASE + 0x0007;

// Rules regarding private attributes
const UINT32 VAL_RULE_PRIVATE_1		  = VAL_RULE_PRIVATE_BASE + 0x0001;
const UINT32 VAL_RULE_PRIVATE_2		  = VAL_RULE_PRIVATE_BASE + 0x0002;

//
// Rules regarding checks against definition objects
//
const UINT32 VAL_RULE_DEF_COMMAND_1     = VAL_RULE_DEF_COMMAND_BASE + 0x0001;
const UINT32 VAL_RULE_DEF_COMMAND_2     = VAL_RULE_DEF_COMMAND_BASE + 0x0002;
const UINT32 VAL_RULE_DEF_COMMAND_3     = VAL_RULE_DEF_COMMAND_BASE + 0x0003;

const UINT32 VAL_RULE_DEF_DEFINITION_1  = VAL_RULE_DEF_DEFINITION_BASE + 0x0001;
const UINT32 VAL_RULE_DEF_DEFINITION_2  = VAL_RULE_DEF_DEFINITION_BASE + 0x0002;
const UINT32 VAL_RULE_DEF_DEFINITION_3  = VAL_RULE_DEF_DEFINITION_BASE + 0x0003;
const UINT32 VAL_RULE_DEF_DEFINITION_4  = VAL_RULE_DEF_DEFINITION_BASE + 0x0004;
const UINT32 VAL_RULE_DEF_DEFINITION_5  = VAL_RULE_DEF_DEFINITION_BASE + 0x0005;
const UINT32 VAL_RULE_DEF_DEFINITION_6  = VAL_RULE_DEF_DEFINITION_BASE + 0x0006;
const UINT32 VAL_RULE_DEF_DEFINITION_7  = VAL_RULE_DEF_DEFINITION_BASE + 0x0007;


//
// Rules regarding checks against the reference object
//
// Codes have prefix R_
//

// Rules regarding value range
const UINT32 VAL_RULE_R_VALUE_1       = VAL_RULE_R_REF_BASE + 0x0001;
const UINT32 VAL_RULE_R_VALUE_2       = VAL_RULE_R_REF_BASE + 0x0002;

// Rules regarding value representation
const UINT32 VAL_RULE_R_VR_1          = VAL_RULE_R_REF_BASE + 0x0011;
const UINT32 VAL_RULE_R_VR_2          = VAL_RULE_R_REF_BASE + 0x0012;

// Rules regarding value multiplicity
const UINT32 VAL_RULE_R_VM_1          = VAL_RULE_R_REF_BASE + 0x0021;

// Rules regarding attribute presence
const UINT32 VAL_RULE_R_PRESENCE_1    = VAL_RULE_R_REF_BASE + 0x0031;

// Rules regarding ACSE reference presence
const UINT32 VAL_RULE_R_PARAM_1       = VAL_RULE_R_REF_BASE + 0x0041;
const UINT32 VAL_RULE_R_PARAM_2       = VAL_RULE_R_REF_BASE + 0x0042;
const UINT32 VAL_RULE_R_PARAM_3       = VAL_RULE_R_REF_BASE + 0x0043;

// Additional validation rules 
//
// Codes have prefix A_
//
const UINT32 VAL_RULE_A_MEDIA_1    = VAL_RULE_A_MEDIA_BASE + 0x0001;
const UINT32 VAL_RULE_A_MEDIA_2    = VAL_RULE_A_MEDIA_BASE + 0x0002;
const UINT32 VAL_RULE_A_MEDIA_3    = VAL_RULE_A_MEDIA_BASE + 0x0003;
const UINT32 VAL_RULE_A_MEDIA_4    = VAL_RULE_A_MEDIA_BASE + 0x0004;
const UINT32 VAL_RULE_A_MEDIA_5    = VAL_RULE_A_MEDIA_BASE + 0x0005;
const UINT32 VAL_RULE_A_MEDIA_6    = VAL_RULE_A_MEDIA_BASE + 0x0006;
const UINT32 VAL_RULE_A_MEDIA_7    = VAL_RULE_A_MEDIA_BASE + 0x0007;
const UINT32 VAL_RULE_A_MEDIA_8    = VAL_RULE_A_MEDIA_BASE + 0x0008;
const UINT32 VAL_RULE_A_MEDIA_9    = VAL_RULE_A_MEDIA_BASE + 0x0009;
const UINT32 VAL_RULE_A_MEDIA_A    = VAL_RULE_A_MEDIA_BASE + 0x000A;
const UINT32 VAL_RULE_A_MEDIA_B    = VAL_RULE_A_MEDIA_BASE + 0x000B;
const UINT32 VAL_RULE_A_MEDIA_C    = VAL_RULE_A_MEDIA_BASE + 0x000C;

const UINT32 VAL_RULE_A_MEDIA_SOP_1 = VAL_RULE_A_MEDIA_BASE + 0x0011;
const UINT32 VAL_RULE_A_MEDIA_SOP_2 = VAL_RULE_A_MEDIA_BASE + 0x0012;

//
// Validation rules specific for Query/Retrieve
//
const UINT32 VAL_RULE_A_QR_1        = VAL_RULE_A_QR_BASE + 0x0001;     
//
// Messages for internal DVT errors.
//
const UINT32 VAL_RULE_INTERNAL_ERROR_1  = VAL_RULE_INTERNAL_ERROR_BASE + 0x0001;

const UINT32 VAL_RULE_UNKNOWN      = 0xFFFF;

#endif /* VALRULES_H */
