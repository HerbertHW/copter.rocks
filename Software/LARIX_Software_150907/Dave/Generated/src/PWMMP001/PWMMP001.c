/*******************************************************************************
**  DAVE App Name : PWMMP001       App Version: 1.0.20               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[PWMMP001.c]*/

/*******************************************************************************
 Copyright (c) 2014, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : DAVE App Developer                                              **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Feb 17, 2014                                           **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** KS           DAVE App Developer                                            **
*******************************************************************************/

/**
 * @file  PWMMP001.c
 *
 * @brief This file contains implementations of all Public functions
 *        of PWMMP001 APP.
 *        This is the Multiphase PWM app and can generate 2, 3 or 4 phase PWM as
 *        per user configuration. 
 *        It works in centre-aligned asymmetric mode and supports simultaneous
 *        start of the phases.
 *        User can connect the interrupts of the last slice to the NVIC002 app 
 *        and write their own interrupt handler to achieve synchronous duty update
 *        and for error handling.
 *
 */
/* Revision History
 * 01 Jan 2013   v1.0.10   taken as base version
 * 25 Apr 2013   v1.0.12   Constrains for PDR register generation are added
 *                         Redundant spaces are removed & Spell corrections done.
 * 17 Feb 2014   v1.0.20   1.Error codes are added in various functions, that 
 *                           can be logged with DBG002 App.                        
 */

/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include <DAVE3.h>
#include "../../inc/PWMMP001/PWMMP001.h"
#include "../../inc/LIBS/CCU8PWMLIB.h"
#include "../../inc/CCU8GLOBAL/CCU8GLOBAL.h"

/**
 * @cond INTERNAL_DOCS
 */
#define APP_GID DBG002_GID_PWMMP001

#define PWMMP001_STATUS_LEN 4U

  
/*****************************************************************************
              DUMMY DEFINITIONS OF DEBUG LOG MACROS
*****************************************************************************/
/*These definitions are included here to avoid compilation errors,
 since the DBG002 app is not part of the project. All the macros are defined
 as empty*/ 
#ifndef _DBG002_H_

#define DBG002_RegisterCallBack(A,B,C)
#define DBG002_I(e) 
#define DBG002_IG(e,g) 
#define DBG002_IH(e,h) 
#define DBG002_IP(e,p) 
#define DBG002_IGH(e,g,h) 
#define DBG002_IGP(e,g,p) 
#define DBG002_IHP(e,h,p) 
#define DBG002_IGHP(e,g,h,p) 
#define DBG002_N(e) 
#define DBG002_NG(e,g) 
#define DBG002_NH(e,h) 
#define DBG002_NP(e,p) 
#define DBG002_NGH(e,g,h) 
#define DBG002_NGP(e,g,p) 
#define DBG002_NHP(e,h,p) 
#define DBG002_NGHP(e,g,h,p) 
#define DBG002_ID(e) 
#define DBG002_IS(e) 
#define DBG002_ISG(e,g) 
#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)
#define DBG002_CRITICAL(groupid,messageid,length,value)
#define DBG002_INFO(groupid,messageid,length,value)
#define DBG002_WARNING(groupid,messageid,length,value)
#define DBG002_INFO(groupid,messageid,length,value)
#define DBG002_TRACE(groupid,messageid,length,value)
#define DBG002_FUNCTION_ENTRY(GID, Status) 
#define DBG002_FUNCTION_EXIT(GID, Status) 
#define DBG002_MESSAGEID_LITERAL 

#endif/* End of definitions of dummy Debug Log macros*/

/**
 * @brief This function is used to initialize the APP.
 * It will configure CCU8_CCy slice registers with the selected PWM parameters.
 * @param[in]   HandlePtr Pointer to PWMMP001_HandleType structure
 * @return status_t\n
 * DAVEApp_SUCCESS: if function is successful\n
 * PWMMP001_OPER_NOT_ALLOWED_ERROR: If this function is called in the state
 * other than PWMMP001_UNINITIALIZED.
 */
status_t PWMMP001_lInit(const PWMMP001_HandleType* HandlePtr);

/*******************************************************************************
**                 Function definitions                                       **
*******************************************************************************/

///   


/**
 * This function initializes all instances of the PWMMP001 App.
 */
void PWMMP001_Init(void)
{
  status_t Status;
  /*Clock initialization - if it is not already done by DAVE3.h */
  CLK001_Init();
  /* CCU8 global init to start the prescalar and de-assert the module */
  CCU8GLOBAL_Init();
  Status = PWMMP001_lInit(&PWMMP001_Handle0);
  if(Status == (uint32_t)DAVEApp_SUCCESS)
  {
    if (PWMMP001_Handle0.StartControl == (uint8_t)SET)
    {
      Status = PWMMP001_Start(&PWMMP001_Handle0);
      DBG002_N(Status != DAVEApp_SUCCESS);
    }
  }
  else
  {
    DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }	  
	        
    /* Configuration of Phase 1 Direct Output Pin 1.14 based on User configuration */
  PORT1->PDR1 &= (~((uint32_t)PORT1_PDR1_PD14_Msk));
  PORT1->PDR1 |= (((uint32_t)0U << (uint32_t)PORT1_PDR1_PD14_Pos) & \
                               (uint32_t)PORT1_PDR1_PD14_Msk);
  PORT1->IOCR12  &= (~((uint32_t)PORT_IOCR_PC2_PO_Msk));
  PORT1->IOCR12  |= (((uint32_t)0U << (uint32_t)PORT_IOCR_PC2_PO_Pos) & \
                               (uint32_t)PORT_IOCR_PC2_PO_Msk);   
    /* Configuration of Phase 1 Inverted Output Pin 1.11 based on User configuration */
  PORT1->PDR1 &= (~((uint32_t)PORT1_PDR1_PD11_Msk));
  PORT1->PDR1 |= (((uint32_t)0U << (uint32_t)PORT1_PDR1_PD11_Pos) & \
                             (uint32_t)PORT1_PDR1_PD11_Msk);
  PORT1->IOCR8  &= (~((uint32_t)PORT_IOCR_PC3_PO_Msk));
  PORT1->IOCR8  |= (((uint32_t)0U << (uint32_t)PORT_IOCR_PC3_PO_Pos) & \
                               (uint32_t)PORT_IOCR_PC3_PO_Msk);
    /* Configuration of Phase 2 Direct Output Pin 1.4 based on User configuration */
  PORT1->PDR0  &= (~(PORT1_PDR0_PD4_Msk));
  PORT1->PDR0  |= ((0 << PORT1_PDR0_PD4_Pos) & \
                             PORT1_PDR0_PD4_Msk);
  PORT1->IOCR4  &= (~((uint32_t)PORT_IOCR_PC0_PO_Msk));
  PORT1->IOCR4  |= (((uint32_t)0U << (uint32_t)PORT_IOCR_PC0_PO_Pos) & \
                               (uint32_t)PORT_IOCR_PC0_PO_Msk);
    /* Configuration of Phase 2 Inverted Output Pin 1.10 based on User configuration */
  PORT1->PDR1 &= (~(PORT1_PDR1_PD10_Msk));
  PORT1->PDR1 |= ((0 << PORT1_PDR1_PD10_Pos) & \
                             PORT1_PDR1_PD10_Msk);
  PORT1->IOCR8  &= (~((uint32_t)PORT_IOCR_PC2_PO_Msk));
  PORT1->IOCR8  |= (((uint32_t)0U << (uint32_t)PORT_IOCR_PC2_PO_Pos) & \
                               (uint32_t)PORT_IOCR_PC2_PO_Msk);
}

/**
 * This function initializes all instances of the PWMMP001 app and changes state to INITIALIZED.
 */
/*<<<DD_PWMMP001_API_1>>>*/
status_t PWMMP001_lInit(const PWMMP001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = 0U;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);
  do
  {
/*<<<DD_PWMMP001_API_1_1>>>*/
    if (HandlePtr->DynamicHandle->State != PWMMP001_UNINITIALIZED)
    {
      break;
    }
/*<<<DD_PWMMP001_API_1_1>>>*/
    do
    {
      Status = CCU8PWMLIB_Init(HandlePtr->PhaseHandlePtr[PhaseNumber]);
      /* Enable multi channel mode */
      if (HandlePtr->kMultiChanModeSupport == 1U)
      {
        SET_BIT(HandlePtr->PhaseHandlePtr[PhaseNumber]->CC8yRegsPtr->TC,
              CCU8_CC8_TC_MCME1_Pos);
        HandlePtr->PhaseHandlePtr[PhaseNumber]->CC8yKernRegsPtr->GCTRL |= 
          (uint32_t)1U << ((uint32_t)HandlePtr->PhaseHandlePtr[PhaseNumber]->FirstSlice + (uint32_t)10U);
      }
      PhaseNumber++;
    } while ((PhaseNumber < HandlePtr->kNumPhases) && (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));

    HandlePtr->DynamicHandle->State = PWMMP001_INITIALIZED;
    Status = (uint32_t)DAVEApp_SUCCESS;
  } while (0);
  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_2>>>*/
/**
 * This function de-initializes the PWMMP001 app. 
 */
status_t PWMMP001_Deinit(const PWMMP001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = 0U;

/*<<<DD_PWMMP001_API_2_1>>>*/
    if (HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED)
    {
      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
    }
/*<<<DD_PWMMP001_API_2_2>>>*/
    else
    {
      do
      {
        Status = CCU8PWMLIB_Deinit(HandlePtr->PhaseHandlePtr[PhaseNumber]);
        PhaseNumber++;
      } while ( (PhaseNumber < HandlePtr->kNumPhases) && (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));      
      HandlePtr->DynamicHandle->State = PWMMP001_UNINITIALIZED;
      Status = (uint32_t)DAVEApp_SUCCESS;
    }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}
/*
 * This will clear the respective CCU8 module bit in the CCUCON register.
 */
void PWMMP001_DisableGlobalStart(const PWMMP001_HandleType* HandlePtr)
{
  CLR_BIT(SCU_GENERAL->CCUCON, (((uint32_t)HandlePtr->kModuleNo + 8U)));
}
/*
 * This will set the respective CCU8 module bit in the CCUCON register.
 */
void PWMMP001_EnableGlobalStart(const PWMMP001_HandleType* HandlePtr)    
{
	SET_BIT(SCU_GENERAL->CCUCON,(((uint32_t)HandlePtr->kModuleNo + 8U)));
}

/*<<<DD_PWMMP001_API_3>>>*/
/** 
 * This function starts the PWMMP001 App. 
 * It enables the interrupts and clears
 * IDLE mode of the CCU8 slices by calling CCU8PWMLIB_Start API.
 * It sets the CCUCON bit to 1 for simultaneous start of the slices.
 */
status_t PWMMP001_Start(const PWMMP001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

/*<<<DD_PWMMP001_API_3_1>>>*/
  if ((HandlePtr->DynamicHandle->State != PWMMP001_INITIALIZED) &&
      (HandlePtr->DynamicHandle->State != PWMMP001_STOPPED))
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else
  {
    if(HandlePtr->SCUSyncStart == 0U)
    {
      do
      {
        Status = CCU8PWMLIB_Start(HandlePtr->PhaseHandlePtr[PhaseNumber]);
        PhaseNumber++;
      } while ((PhaseNumber < HandlePtr->kNumPhases) &&
               (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
    }
    else
    {
      PWMMP001_DisableGlobalStart(HandlePtr);
      do
      {
        Status = CCU8PWMLIB_EnableExtStart(HandlePtr->PhaseHandlePtr[PhaseNumber]);
        Status = CCU8PWMLIB_Start(HandlePtr->PhaseHandlePtr[PhaseNumber]);
        PhaseNumber++;
      } while ((PhaseNumber < HandlePtr->kNumPhases) &&
               (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));

      /*<<<DD_PWMMP001_API_3_2>>>*/
      /* Set the CCUCON register bit and then immediately reset to 
       * avoid spurious start
       */ 
      PWMMP001_EnableGlobalStart(HandlePtr);
      PWMMP001_DisableGlobalStart(HandlePtr);
      PhaseNumber = 0U;
      /* Disable External start feature to avoid spurious restarting of the slices */
      do
      {
        Status = CCU8PWMLIB_DisableExtStart(HandlePtr->PhaseHandlePtr[PhaseNumber]);
        PhaseNumber++;
      } while ((PhaseNumber < HandlePtr->kNumPhases) &&
               (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
    }
    HandlePtr->DynamicHandle->State = PWMMP001_RUNNING;
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_4>>>*/
/**
 * This function stops the PWMMP001 app. 
 * It clears all the interrupts, clears the RUN bit of the required slices by
 * calling CCU8PWMLIB_Stop API.
 */
status_t PWMMP001_Stop(const PWMMP001_HandleType* HandlePtr)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

/*<<<DD_PWMMP001_API_4_1>>>*/
  if ((HandlePtr->DynamicHandle->State != PWMMP001_RUNNING))
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else
  {
    do
    {
      Status = CCU8PWMLIB_Stop(HandlePtr->PhaseHandlePtr[PhaseNumber]);
      PhaseNumber++;
    } while ((PhaseNumber < HandlePtr->kNumPhases) &&
             (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));

/*<<<DD_PWMMP001_API_4_2>>>*/
    HandlePtr->DynamicHandle->State = PWMMP001_STOPPED;
    Status = (uint32_t)DAVEApp_SUCCESS;
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_15>>>*/
/**
 * This function changes the duty cycle of the PWM waveforms. Duty cycle is given 
 * in terms of the compare register 1 value and compare register 2 value.
 */
status_t PWMMP001_SetCompare
(
  const PWMMP001_HandleType* HandlePtr,
  const PWMMP001_DutyCycleType* DutyCyclePtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  uint8_t Index = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

  do
  {
/*<<<DD_PWMMP001_API_15_1>>>*/
    if ((HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED))
    {
      break;
    }
/*<<<DD_PWMMP001_API_15_2>>>*/
/*<<<DD_PWMMP001_API_15_3>>>*/
/*Call CCU8PWMLIB_SetCompare() API from CCU8_PWMSinglePhaseDT_CCU8PWMLIB*/
    PhaseNumber  = 0U;
    do
    {
      Status = CCU8PWMLIB_SetCompare(
               HandlePtr->PhaseHandlePtr[PhaseNumber],
               DutyCyclePtr->CompReg[Index],
               DutyCyclePtr->CompReg[Index+1U]
              );
      Index = Index + 2U;
      PhaseNumber++;
    } while ((PhaseNumber < HandlePtr->kNumPhases) &&
             (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
  } while (0);
  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_5>>>*/
/**
 * This function changes the duty cycle of the PWM waveforms. Duty cycle is given 
 * in terms of the % duty cycle value, offset and the sign of the offset.
 * Offset is needed to get the asymmetric waveform where ON time is shifted with respect
 * to central line.
 */
status_t PWMMP001_SetDutyCycle
(
  const PWMMP001_HandleType* HandlePtr,
  const PWMMP001_DutyCycleType* DutyCyclePtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

  if(HandlePtr->DynamicHandle->State != PWMMP001_UNINITIALIZED)
  {
    /*<<<DD_PWMMP001_API_5_1>>>*/
    /*<<<DD_PWMMP001_API_5_2>>>*/
    for (PhaseNumber = 0U; PhaseNumber < HandlePtr->kNumPhases; ++PhaseNumber)
    {
      /* check if duty cycle is within 0 to 100 */
      if ((DutyCyclePtr->DutyCycle[PhaseNumber] > (float)100.0) ||
          (DutyCyclePtr->DutyCycle[PhaseNumber] < (float)0.0))
      {
        Status  = (uint32_t)PWMMP001_INVALID_PARAM_ERROR;
        break;
      }
    }
    if (Status != (uint32_t)PWMMP001_INVALID_PARAM_ERROR)
    {

      /*<<<DD_PWMMP001_API_5_3>>>*/
      /*Call CCU8PWMLIB_SetDutyCycle() API from CCU8_PWMSinglePhaseDT_CCU8PWMLIB*/
      PhaseNumber  = 0U;
      do
      {
        Status = CCU8PWMLIB_SetDutyCenterAlignAsymmetric(
                 (const void*)HandlePtr->PhaseHandlePtr[PhaseNumber],
                 DutyCyclePtr->DutyCycle[PhaseNumber],
                 DutyCyclePtr->Offset[PhaseNumber],
                 DutyCyclePtr->Sign[PhaseNumber]);
                 PhaseNumber++;
      } while ((PhaseNumber < HandlePtr->kNumPhases) &&
               (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
    }
  }

  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}


/**
 * This function changes the PWM frequency and duty cycle. 
 * 
 */
status_t PWMMP001_SetPwmFreqAndDutyCycle
(
  const PWMMP001_HandleType* HandlePtr,
  float PwmFreq,
  const PWMMP001_DutyCycleType* DutyCyclePtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

  if(HandlePtr->DynamicHandle->State != PWMMP001_UNINITIALIZED)
  {
    /*<<<DD_PWMMP001_API_16_1>>>*/
    /*<<<DD_PWMMP001_API_16_2>>>*/
    /* check if frequency is not zero */
    if (PwmFreq == (float)RESET)
    {
      Status = (uint32_t)PWMMP001_INVALID_PARAM_ERROR;
    }
    else
    {
      /*<<<DD_PWMMP001_API_16_2>>>*/
      for (PhaseNumber = 0U; PhaseNumber < HandlePtr->kNumPhases; ++PhaseNumber)
      {
        /* check if duty cycle is within 0 to 100 */
        if ((DutyCyclePtr->DutyCycle[PhaseNumber] > (float)100.0) ||
            (DutyCyclePtr->DutyCycle[PhaseNumber] < (float)0.0))
        {
          Status  = (uint32_t)PWMMP001_INVALID_PARAM_ERROR;
          break;
        }
      }
      if (Status != (uint32_t)PWMMP001_INVALID_PARAM_ERROR)
      {
        PhaseNumber  = 0U;
    /*<<<DD_PWMMP001_API_16_3>>>*/
        do
        {
          Status = CCU8PWMLIB_SetPwmFreqAndDutyCycle(
                      HandlePtr->PhaseHandlePtr[PhaseNumber],
                      PwmFreq,
                      DutyCyclePtr->DutyCycle[PhaseNumber],
                      DutyCyclePtr->Offset[PhaseNumber],
                      DutyCyclePtr->Sign[PhaseNumber]
                      );
                      PhaseNumber++;
        } while ((PhaseNumber < HandlePtr->kNumPhases) &&
                 (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
      }
    }
  }
  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_16>>>*/
/**
 * This function changes the PWM frequency. Frequency is given in hertz.
 * 
 */
status_t PWMMP001_SetPwmFreq
(
  const PWMMP001_HandleType* HandlePtr,
  float PwmFreq
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

  if ((HandlePtr->DynamicHandle->State != PWMMP001_UNINITIALIZED))
  {
    /*<<<DD_PWMMP001_API_16_1>>>*/
    
    /*<<<DD_PWMMP001_API_16_2>>>*/
    /* check if frequency is not zero */
    if (PwmFreq == (float)0.0)
    {
      Status = (uint32_t)PWMMP001_INVALID_PARAM_ERROR;
    }
    else
    {
      /*<<<DD_PWMMP001_API_16_3>>>*/
      do
      {
        Status = CCU8PWMLIB_SetPwmFreq(HandlePtr->PhaseHandlePtr[PhaseNumber],
                 PwmFreq);
        PhaseNumber++;
      } while ((PhaseNumber < HandlePtr->kNumPhases) &&
               (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
    }
  }
  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/**
 * This function changes the PWM frequency and duty cycle. 
 * Frequency is given in terms of the period register value
 * and duty cycle in terms of the compare register value.
 *  
 */
status_t PWMMP001_SetPeriodAndCompare
(
  const PWMMP001_HandleType* HandlePtr,
  uint32_t PwmFreq,
  const PWMMP001_DutyCycleType* DutyCyclePtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  uint8_t Index = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

  if(HandlePtr->DynamicHandle->State != PWMMP001_UNINITIALIZED)
  {

    /*<<<DD_PWMMP001_API_6_2>>>*/
    if ((PwmFreq > (uint32_t)PWMMP001_MAXVAL) || (PwmFreq == (uint32_t)RESET))
    {
      Status = (uint32_t)PWMMP001_INVALID_PARAM_ERROR;
    }
    else
    {
      do
      {
        Status = CCU8PWMLIB_SetPeriodAndCompare(
                      HandlePtr->PhaseHandlePtr[PhaseNumber],
                      PwmFreq,
                      DutyCyclePtr->CompReg[Index],
                      DutyCyclePtr->CompReg[Index+1U]
                      );
        Index = Index + 2U; 
        PhaseNumber++;
        /*HandlePtr->DynamicHandle->PeriodReg = PwmFreq;*/
      } while ((PhaseNumber < HandlePtr->kNumPhases) &&
               (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
    }
  } 
  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}


/*<<<DD_PWMMP001_API_6>>>*/
/**
 * This function changes the PWM frequency. Frequency is given in terms of the
 * period register value.
 */
status_t PWMMP001_SetPeriod
(
  const PWMMP001_HandleType* HandlePtr,
  uint32_t PwmFreq
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

  if(HandlePtr->DynamicHandle->State != PWMMP001_UNINITIALIZED)
  {
/*<<<DD_PWMMP001_API_6_2>>>*/
    if ((PwmFreq > (uint32_t)PWMMP001_MAXVAL) || (PwmFreq == (uint32_t)RESET))
    {
      Status = (uint32_t)PWMMP001_INVALID_PARAM_ERROR;
    }
    else
    {

      /*<<<DD_PWMMP001_API_6_3>>>*/
      do
      {
        Status = CCU8PWMLIB_SetPeriod(HandlePtr->PhaseHandlePtr[PhaseNumber],
                 PwmFreq);
        PhaseNumber++;
        /*HandlePtr->DynamicHandle->PeriodReg = PwmFreq;*/
      } while ((PhaseNumber < HandlePtr->kNumPhases) &&
               (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
    }
  }
  if (Status != (uint32_t)DAVEApp_SUCCESS)
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_7>>>*/
/**
 * This function loads the CCU8 timer with the given value when timer is not running.
 */
status_t PWMMP001_SetTimerVal
(
  const PWMMP001_HandleType* HandlePtr,
  uint32_t TimerVal
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

/*<<<DD_PWMMP001_API_7_1>>>*/
  if ((HandlePtr->DynamicHandle->State == PWMMP001_RUNNING) ||
      (HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED))
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
/*<<<DD_PWMMP001_API_7_2>>>*/
  else
  {
    do
    {
      Status = CCU8PWMLIB_SetTimerVal(HandlePtr->PhaseHandlePtr[PhaseNumber], TimerVal);
      PhaseNumber++;
    }while ((PhaseNumber < HandlePtr->kNumPhases) &&
        (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));

    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
    }
  }

  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_8>>>*/
/** 
 * This function reads the timer status - RUNNING or IDLE.
 */
status_t PWMMP001_GetTimerStatus
(
  const PWMMP001_HandleType* HandlePtr,
  uint32_t * TimerStatusPtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  uint32_t LocalTimerStatusPtr = (uint32_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

/*<<<DD_PWMMP001_API_8_1>>>*/
  if ((HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED))
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
/*<<<DD_PWMMP001_API_8_2>>>*/
  else
  {
    do
    {
      if (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL)
      {
      /* Read the timer status of all the phases. */  
        Status = CCU8PWMLIB_GetTimerStatus(
                 HandlePtr->PhaseHandlePtr[PhaseNumber],
                 &LocalTimerStatusPtr);
        *TimerStatusPtr = LocalTimerStatusPtr;
      }
      else
      {
        Status = (uint32_t)PWMMP001_INVALID_PARAM_ERROR;
        DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
        break;
      }
      PhaseNumber++;
    } while ((PhaseNumber < HandlePtr->kNumPhases) &&
             (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
  }
  return Status;
}

/*<<<DD_PWMMP001_API_9>>>*/
/**
 * This function reads the period register, compare register and 
 * timer register value.
 */
status_t PWMMP001_GetTimerRegsVal
(
  const PWMMP001_HandleType * HandlePtr,
  CCU8PWMLIB_TimerRegsType * const*TimerRegsPtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

/*<<<DD_PWMMP001_API_9_1>>>*/
  if ((HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED))
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else
  {
/*<<<DD_PWMMP001_API_9_2>>>*/
    do
    {
      if (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL)
      {
        Status = CCU8PWMLIB_GetTimerRegsVal(
                                      HandlePtr->PhaseHandlePtr[PhaseNumber],
                                      TimerRegsPtr[PhaseNumber]);
      }
      else
      {
        Status = (uint32_t)PWMMP001_INVALID_PARAM_ERROR;
        DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
        break;
      }
      PhaseNumber++;
    } while ((PhaseNumber < HandlePtr->kNumPhases) &&
             (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_10>>>*/
/**
 * This function initiates the shadow transfer for the period and compare register
 */
status_t PWMMP001_SWRequestShadowTransfer
(
  const PWMMP001_HandleType* HandlePtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;

  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

/*<<<DD_PWMMP001_API_10_1>>>*/
  if ((HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED))
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }

/*<<<DD_PWMMP001_API_10_2>>>*/
  else
  {
    /* Call the last phase shadow transfer API which will initiate
     * shadow transfer for all the phases to ensure concurrent update.
     */
    Status = CCU8PWMLIB_SWRequestShadowTransfer
        (HandlePtr->PhaseHandlePtr[HandlePtr->kNumPhases - 1U]);
  }

  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_15>>>*/
/**
 * This function reads the period register value which will be needed to 
 * find out the compare register values to get the required duty cycle.
 */
status_t PWMMP001_GetPeriodReg
(
  const PWMMP001_HandleType * HandlePtr,
  uint32_t * PeriodRegPtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint32_t LocalPeriod = 0U;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

/*<<<DD_PWMMP001_API_15_1>>>*/
  if ((HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED))
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
/*<<<DD_PWMMP001_API_15_2>>>*/
  else
  {
    Status = CCU8PWMLIB_GetPeriodReg(HandlePtr->PhaseHandlePtr[0], &LocalPeriod);
    *PeriodRegPtr = LocalPeriod;
  }

  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/*<<<DD_PWMMP001_API_13>>>*/
/**
 * This function clears the trap state of all the phases if exit control 
 * from trap state is SW exit.
 */
status_t PWMMP001_ResetTrapFlag
(
  const PWMMP001_HandleType* HandlePtr
)
{
  status_t Status = (uint32_t)PWMMP001_OPER_NOT_ALLOWED_ERROR;
  uint8_t PhaseNumber = (uint8_t)0;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_ENTRY);

/*<<<DD_PWMMP001_API_13_1>>>*/
  if ((HandlePtr->DynamicHandle->State == PWMMP001_RUNNING) ||
      (HandlePtr->DynamicHandle->State == PWMMP001_INITIALIZED))
  {
	DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
/*<<<DD_PWMMP001_API_13_2>>>*/
  else
  {
    do
    {
      Status = CCU8PWMLIB_ResetTrapFlag(
                      HandlePtr->PhaseHandlePtr[PhaseNumber]);
      PhaseNumber++;
    } while((PhaseNumber < HandlePtr->kNumPhases) &&
            (Status == (uint32_t)DAVEApp_SUCCESS)&& (HandlePtr->PhaseHandlePtr[PhaseNumber] != NULL));

    if (Status != (uint32_t)DAVEApp_SUCCESS)
    {
      DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
    }
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, (uint32_t)PWMMP001_FUNCTION_EXIT);
  return Status;
}

/**
 * This function sets the enable event bit for the event given in the argument.
 */
status_t PWMMP001_EnableEvent
(
     const PWMMP001_HandleType * HandlePtr,
     const PWMMP001_PhaseType PhaseNo,
     const PWMMP001_EventNameType Event
)
 {
   status_t Status =(uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
   DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_ENTRY);

   if (HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED)
   {
     Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
     DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
   }
   else if(HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U] == NULL)
   {
	 Status = (uint32_t) PWMMP001_INVALID_PARAM_ERROR;
	 DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
   }   
   else
   {
      Status = CCU8PWMLIB_EnableEvent(
          HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U], 
          (CCU8PWMLIB_EventNameType)Event);
   }
   DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_EXIT);
   return (Status);
 }

 /**
  * This function clears the enable event bit for the event given in the argument.
  */
status_t PWMMP001_DisableEvent
(
    const PWMMP001_HandleType * HandlePtr,
    const PWMMP001_PhaseType PhaseNo,
    const PWMMP001_EventNameType Event
)
{
  status_t Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED)
  {
    Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
    DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else if(HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U] == NULL)
  {
	 Status = (uint32_t) PWMMP001_INVALID_PARAM_ERROR;
	 DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }  
  else
  {
    Status = CCU8PWMLIB_DisableEvent( 
        HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U], 
        (CCU8PWMLIB_EventNameType)Event);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_EXIT);
  return (Status);
}

/**
 * This function clears the interrupt by software.
 */
status_t PWMMP001_ClearPendingEvent
(
    const PWMMP001_HandleType * HandlePtr,
    const PWMMP001_PhaseType PhaseNo,
    const PWMMP001_EventNameType Event
)
{
  status_t Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED)
  {
    Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
    DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else if(HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U] == NULL)
  {
	 Status = (uint32_t) PWMMP001_INVALID_PARAM_ERROR;
	 DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else
  {
    Status = CCU8PWMLIB_ClearPendingEvent(
        HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U], 
         (CCU8PWMLIB_EventNameType)Event);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_EXIT);
  return (Status);
}

/**
 * This function sets the interrupt by software Interrupt pulse is generated
 * if source is enabled.
 */
status_t PWMMP001_SetPendingEvent
(
    const PWMMP001_HandleType * HandlePtr,
    const PWMMP001_PhaseType PhaseNo,
    const PWMMP001_EventNameType Event
)
{
  status_t Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED)
  {
    Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
    DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else if(HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U] == NULL)
  {
	 Status = (uint32_t) PWMMP001_INVALID_PARAM_ERROR;
	 DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else
  {
    Status = CCU8PWMLIB_SetPendingEvent(
                 HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U], 
                 (CCU8PWMLIB_EventNameType)Event);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_EXIT);
  return (Status);
}

/**
 * This function checks whether given interrupt is set
 */
status_t PWMMP001_GetPendingEvent
(
    const PWMMP001_HandleType * HandlePtr,
    const PWMMP001_PhaseType PhaseNo,
    const PWMMP001_EventNameType Event,
    uint8_t* EvtStatus
)
{
  status_t Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
  DBG002_FUNCTION_ENTRY(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_ENTRY);

  if (HandlePtr->DynamicHandle->State == PWMMP001_UNINITIALIZED)
  {
    Status = (uint32_t) PWMMP001_OPER_NOT_ALLOWED_ERROR;
    DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else if(HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U] == NULL)
  {
	 Status = (uint32_t) PWMMP001_INVALID_PARAM_ERROR;
	 DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, PWMMP001_STATUS_LEN, &Status);
  }
  else
  {
    Status = CCU8PWMLIB_GetPendingEvent(
                 HandlePtr->PhaseHandlePtr[(uint32_t)PhaseNo -1U], 
                 (CCU8PWMLIB_EventNameType)Event, EvtStatus);
  }
  DBG002_FUNCTION_EXIT(DBG002_GID_PWMMP001, PWMMP001_FUNCTION_EXIT);
  return (Status);
}

/**
 * @endcond
 */
/*CODE_BLOCK_END*/

