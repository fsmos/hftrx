#ifndef SDRAM_H_INCLUDED
#define SDRAM_H_INCLUDED

#include "hardware.h"

#if CPUSTYLE_STM32F

#define assert_param(expr) do { } while (0)
/**
  * @brief  FMC SDRAM Bank address
  */

/**
  * @brief  FMC SDRAM Memory Width
  */
/* #define SDRAM_MEMORY_WIDTH   FMC_SDMemory_Width_8b  */
#define SDRAM_MEMORY_WIDTH    FMC_SDMemory_Width_16b

/**
  * @brief  FMC SDRAM CAS Latency
  */
/* #define SDRAM_CAS_LATENCY   FMC_CAS_Latency_2  */
#define SDRAM_CAS_LATENCY    FMC_CAS_Latency_3

/**
  * @brief  FMC SDRAM Memory clock period
  */
#define SDCLOCK_PERIOD    FMC_SDClock_Period_2        /* Default configuration used with LCD */
/* #define SDCLOCK_PERIOD    FMC_SDClock_Period_3 */

/**
  * @brief  FMC SDRAM Memory Read Burst feature
  */
#define SDRAM_READBURST    FMC_Read_Burst_Disable    /* Default configuration used with LCD */
/* #define SDRAM_READBURST    FMC_Read_Burst_Enable  */

/**
  * @brief  FMC SDRAM Bank Remap
  */
/* #define SDRAM_BANK_REMAP */



/**
 * @brief Uncomment the line below if you want to use user defined Delay function
 *        (for precise timing), otherwise default _delay_ function defined within
 *         this driver is used (less precise timing).
 */

/* #define USE_Delay */

#ifdef USE_Delay
  #define __Delay     Delay      /*  User can provide more timing precise __Delay function
                                    (with 10ms time base), using SysTick for example */
#else
  #define __Delay     local_delay_ms      /*  Default __Delay function with less precise timing */
#endif

/**
  * @brief  FMC SDRAM Mode definition register defines
  */
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)

/**
  * @}
  */

/** @defgroup STM32429I_DISCO_SDRAM_Exported_Functions
  * @{
  */
void  SDRAM_Init(void);
void  SDRAM_GPIOConfig(void);
void  SDRAM_InitSequence(void);
void  SDRAM_WriteBuffer(uint32_t* pBuffer, uint32_t uwWriteAddress, uint32_t uwBufferSize);
void  SDRAM_ReadBuffer(uint32_t* pBuffer, uint32_t uwReadAddress, uint32_t uwBufferSize);

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  Timing parameters For NOR/SRAM Banks
  */
typedef struct
{
  uint32_t FMC_AddressSetupTime;       /*!< Defines the number of HCLK cycles to configure
                                             the duration of the address setup time.
                                             This parameter can be a value between 0 and 15.
                                             @note This parameter is not used with synchronous NOR Flash memories. */

  uint32_t FMC_AddressHoldTime;        /*!< Defines the number of HCLK cycles to configure
                                             the duration of the address hold time.
                                             This parameter can be a value between 1 and 15.
                                             @note This parameter is not used with synchronous NOR Flash memories.*/

  uint32_t FMC_DataSetupTime;          /*!< Defines the number of HCLK cycles to configure
                                             the duration of the data setup time.
                                             This parameter can be a value between 1 and 255.
                                             @note This parameter is used for SRAMs, ROMs and asynchronous multiplexed NOR Flash memories. */

  uint32_t FMC_BusTurnAroundDuration;  /*!< Defines the number of HCLK cycles to configure
                                             the duration of the bus turnaround.
                                             This parameter can be a value between 0 and 15.
                                             @note This parameter is only used for multiplexed NOR Flash memories. */

  uint32_t FMC_CLKDivision;            /*!< Defines the period of CLK clock output signal, expressed in number of HCLK cycles.
                                             This parameter can be a value between 1 and 15.
                                             @note This parameter is not used for asynchronous NOR Flash, SRAM or ROM accesses. */

  uint32_t FMC_DataLatency;            /*!< Defines the number of memory clock cycles to issue
                                             to the memory before getting the first data.
                                             The parameter value depends on the memory type as shown below:
                                              - It must be set to 0 in case of a CRAM
                                              - It is don't care in asynchronous NOR, SRAM or ROM accesses
                                              - It may assume a value between 0 and 15 in NOR Flash memories
                                                with synchronous burst mode enable */

  uint32_t FMC_AccessMode;             /*!< Specifies the asynchronous access mode.
                                             This parameter can be a value of @ref FMC_Access_Mode */
}FMC_NORSRAMTimingInitTypeDef;

/**
  * @brief  FMC NOR/SRAM Init structure definition
  */
typedef struct
{
  uint32_t FMC_Bank;                /*!< Specifies the NOR/SRAM memory bank that will be used.
                                          This parameter can be a value of @ref FMC_NORSRAM_Bank */

  uint32_t FMC_DataAddressMux;      /*!< Specifies whether the address and data values are
                                          multiplexed on the databus or not.
                                          This parameter can be a value of @ref FMC_Data_Address_Bus_Multiplexing */

  uint32_t FMC_MemoryType;          /*!< Specifies the type of external memory attached to
                                          the corresponding memory bank.
                                          This parameter can be a value of @ref FMC_Memory_Type */

  uint32_t FMC_MemoryDataWidth;     /*!< Specifies the external memory device width.
                                          This parameter can be a value of @ref FMC_NORSRAM_Data_Width */

  uint32_t FMC_BurstAccessMode;     /*!< Enables or disables the burst access mode for Flash memory,
                                          valid only with synchronous burst Flash memories.
                                          This parameter can be a value of @ref FMC_Burst_Access_Mode */

  uint32_t FMC_WaitSignalPolarity;  /*!< Specifies the wait signal polarity, valid only when accessing
                                          the Flash memory in burst mode.
                                          This parameter can be a value of @ref FMC_Wait_Signal_Polarity */

  uint32_t FMC_WrapMode;            /*!< Enables or disables the Wrapped burst access mode for Flash
                                          memory, valid only when accessing Flash memories in burst mode.
                                          This parameter can be a value of @ref FMC_Wrap_Mode */

  uint32_t FMC_WaitSignalActive;    /*!< Specifies if the wait signal is asserted by the memory one
                                          clock cycle before the wait state or during the wait state,
                                          valid only when accessing memories in burst mode.
                                          This parameter can be a value of @ref FMC_Wait_Timing */

  uint32_t FMC_WriteOperation;      /*!< Enables or disables the write operation in the selected bank by the FMC.
                                          This parameter can be a value of @ref FMC_Write_Operation */

  uint32_t FMC_WaitSignal;          /*!< Enables or disables the wait state insertion via wait
                                          signal, valid for Flash memory access in burst mode.
                                          This parameter can be a value of @ref FMC_Wait_Signal */

  uint32_t FMC_ExtendedMode;        /*!< Enables or disables the extended mode.
                                          This parameter can be a value of @ref FMC_Extended_Mode */

  uint32_t FMC_AsynchronousWait;     /*!< Enables or disables wait signal during asynchronous transfers,
                                          valid only with asynchronous Flash memories.
                                          This parameter can be a value of @ref FMC_AsynchronousWait */

  uint32_t FMC_WriteBurst;          /*!< Enables or disables the write burst operation.
                                          This parameter can be a value of @ref FMC_Write_Burst */

  uint32_t FMC_ContinousClock;       /*!< Enables or disables the FMC clock output to external memory devices.
                                          This parameter is only enabled through the FMC_BCR1 register, and don't care
                                          through FMC_BCR2..4 registers.
                                          This parameter can be a value of @ref FMC_Continous_Clock */


  FMC_NORSRAMTimingInitTypeDef* FMC_ReadWriteTimingStruct; /*!< Timing Parameters for write and read access if the  Extended Mode is not used*/

  FMC_NORSRAMTimingInitTypeDef* FMC_WriteTimingStruct;     /*!< Timing Parameters for write access if the  Extended Mode is used*/
}FMC_NORSRAMInitTypeDef;

/**
  * @brief  Timing parameters For FMC NAND and PCCARD Banks
  */
typedef struct
{
  uint32_t FMC_SetupTime;      /*!< Defines the number of HCLK cycles to setup address before
                                     the command assertion for NAND-Flash read or write access
                                     to common/Attribute or I/O memory space (depending on
                                     the memory space timing to be configured).
                                     This parameter can be a value between 0 and 255.*/

  uint32_t FMC_WaitSetupTime;  /*!< Defines the minimum number of HCLK cycles to assert the
                                     command for NAND-Flash read or write access to
                                     common/Attribute or I/O memory space (depending on the
                                     memory space timing to be configured).
                                     This parameter can be a number between 0 and 255 */

  uint32_t FMC_HoldSetupTime;  /*!< Defines the number of HCLK clock cycles to hold address
                                     (and data for write access) after the command de-assertion
                                     for NAND-Flash read or write access to common/Attribute
                                     or I/O memory space (depending on the memory space timing
                                     to be configured).
                                     This parameter can be a number between 0 and 255 */

  uint32_t FMC_HiZSetupTime;   /*!< Defines the number of HCLK clock cycles during which the
                                     databus is kept in HiZ after the start of a NAND-Flash
                                     write access to common/Attribute or I/O memory space (depending
                                     on the memory space timing to be configured).
                                     This parameter can be a number between 0 and 255 */
}FMC_NAND_PCCARDTimingInitTypeDef;

/**
  * @brief  FMC NAND Init structure definition
  */
typedef struct
{
  uint32_t FMC_Bank;              /*!< Specifies the NAND memory bank that will be used.
                                      This parameter can be a value of @ref FMC_NAND_Bank */

  uint32_t FMC_Waitfeature;      /*!< Enables or disables the Wait feature for the NAND Memory Bank.
                                       This parameter can be any value of @ref FMC_Wait_feature */

  uint32_t FMC_MemoryDataWidth;  /*!< Specifies the external memory device width.
                                       This parameter can be any value of @ref FMC_NAND_Data_Width */

  uint32_t FMC_ECC;              /*!< Enables or disables the ECC computation.
                                       This parameter can be any value of @ref FMC_ECC */

  uint32_t FMC_ECCPageSize;      /*!< Defines the page size for the extended ECC.
                                       This parameter can be any value of @ref FMC_ECC_Page_Size */

  uint32_t FMC_TCLRSetupTime;    /*!< Defines the number of HCLK cycles to configure the
                                       delay between CLE low and RE low.
                                       This parameter can be a value between 0 and 255. */

  uint32_t FMC_TARSetupTime;     /*!< Defines the number of HCLK cycles to configure the
                                       delay between ALE low and RE low.
                                       This parameter can be a number between 0 and 255 */

  FMC_NAND_PCCARDTimingInitTypeDef*  FMC_CommonSpaceTimingStruct;   /*!< FMC Common Space Timing */

  FMC_NAND_PCCARDTimingInitTypeDef*  FMC_AttributeSpaceTimingStruct; /*!< FMC Attribute Space Timing */
}FMC_NANDInitTypeDef;

/**
  * @brief  FMC PCCARD Init structure definition
  */

typedef struct
{
  uint32_t FMC_Waitfeature;    /*!< Enables or disables the Wait feature for the Memory Bank.
                                    This parameter can be any value of @ref FMC_Wait_feature */

  uint32_t FMC_TCLRSetupTime;  /*!< Defines the number of HCLK cycles to configure the
                                     delay between CLE low and RE low.
                                     This parameter can be a value between 0 and 255. */

  uint32_t FMC_TARSetupTime;   /*!< Defines the number of HCLK cycles to configure the
                                     delay between ALE low and RE low.
                                     This parameter can be a number between 0 and 255 */


  FMC_NAND_PCCARDTimingInitTypeDef*  FMC_CommonSpaceTimingStruct; /*!< FMC Common Space Timing */

  FMC_NAND_PCCARDTimingInitTypeDef*  FMC_AttributeSpaceTimingStruct;  /*!< FMC Attribute Space Timing */

  FMC_NAND_PCCARDTimingInitTypeDef*  FMC_IOSpaceTimingStruct; /*!< FMC IO Space Timing */
}FMC_PCCARDInitTypeDef;

/**
  * @brief  Timing parameters for FMC SDRAM Banks
  */

typedef struct
{
  uint32_t FMC_LoadToActiveDelay;      /*!< Defines the delay between a Load Mode Register command and
                                            an active or Refresh command in number of memory clock cycles.
                                            This parameter can be a value between 1 and 16. */

  uint32_t FMC_ExitSelfRefreshDelay;   /*!< Defines the delay from releasing the self refresh command to
                                            issuing the Activate command in number of memory clock cycles.
                                            This parameter can be a value between 1 and 16. */

  uint32_t FMC_SelfRefreshTime;        /*!< Defines the minimum Self Refresh period in number of memory clock
                                            cycles.
                                            This parameter can be a value between 1 and 16. */

  uint32_t FMC_RowCycleDelay;          /*!< Defines the delay between the Refresh command and the Activate command
                                            and the delay between two consecutive Refresh commands in number of
                                            memory clock cycles.
                                            This parameter can be a value between 1 and 16. */

  uint32_t FMC_WriteRecoveryTime;      /*!< Defines the Write recovery Time in number of memory clock cycles.
                                            This parameter can be a value between 1 and 16. */

  uint32_t FMC_RPDelay;                /*!< Defines the delay between a Precharge Command and an other command
                                            in number of memory clock cycles.
                                            This parameter can be a value between 1 and 16. */

  uint32_t FMC_RCDDelay;               /*!< Defines the delay between the Activate Command and a Read/Write command
                                            in number of memory clock cycles.
                                            This parameter can be a value between 1 and 16. */

}FMC_SDRAMTimingInitTypeDef;

/**
  * @brief  Command parameters for FMC SDRAM Banks
  */


typedef struct
{
  uint32_t FMC_CommandMode;            /*!< Defines the command issued to the SDRAM device.
                                            This parameter can be a value of @ref FMC_Command_Mode. */

  uint32_t FMC_CommandTarget;          /*!< Defines which bank (1 or 2) the command will be issued to.
                                            This parameter can be a value of @ref FMC_Command_Target. */

  uint32_t FMC_AutoRefreshNumber;      /*!< Defines the number of consecutive auto refresh command issued
                                            in auto refresh mode.
                                            This parameter can be a value between 1 and 16. */

  uint32_t FMC_ModeRegisterDefinition; /*!< Defines the SDRAM Mode register content */

}FMC_SDRAMCommandTypeDef;

/**
  * @brief  FMC SDRAM Init structure definition
  */

typedef struct
{
  uint32_t FMC_Bank;                   /*!< Specifies the SDRAM memory bank that will be used.
                                          This parameter can be a value of @ref FMC_SDRAM_Bank */

  uint32_t FMC_ColumnBitsNumber;       /*!< Defines the number of bits of column address.
                                            This parameter can be a value of @ref FMC_ColumnBits_Number. */

  uint32_t FMC_RowBitsNumber;          /*!< Defines the number of bits of column address..
                                            This parameter can be a value of @ref FMC_RowBits_Number. */

  uint32_t FMC_SDMemoryDataWidth;        /*!< Defines the memory device width.
                                            This parameter can be a value of @ref FMC_SDMemory_Data_Width. */

  uint32_t FMC_InternalBankNumber;     /*!< Defines the number of bits of column address.
                                            This parameter can be of @ref FMC_InternalBank_Number. */

  uint32_t FMC_CASLatency;             /*!< Defines the SDRAM CAS latency in number of memory clock cycles.
                                            This parameter can be a value of @ref FMC_CAS_Latency. */

  uint32_t FMC_WriteProtection;        /*!< Enables the SDRAM bank to be accessed in write mode.
                                            This parameter can be a value of @ref FMC_Write_Protection. */

  uint32_t FMC_SDClockPeriod;          /*!< Define the SDRAM Clock Period for both SDRAM Banks and they allow to disable
                                            the clock before changing frequency.
                                            This parameter can be a value of @ref FMC_SDClock_Period. */

  uint32_t FMC_ReadBurst;              /*!< This bit enable the SDRAM controller to anticipate the next read commands
                                            during the CAS latency and stores data in the Read FIFO.
                                            This parameter can be a value of @ref FMC_Read_Burst. */

  uint32_t FMC_ReadPipeDelay;          /*!< Define the delay in system clock cycles on read data path.
                                            This parameter can be a value of @ref FMC_ReadPipe_Delay. */

  FMC_SDRAMTimingInitTypeDef* FMC_SDRAMTimingStruct;   /*!< Timing Parameters for write and read access*/

}FMC_SDRAMInitTypeDef;


/* Exported constants --------------------------------------------------------*/

/** @defgroup FMC_Exported_Constants
  * @{
  */

/** @defgroup FMC_NORSRAM_Bank
  * @{
  */
#define FMC_Bank1_NORSRAM1                      ((uint32_t)0x00000000)
#define FMC_Bank1_NORSRAM2                      ((uint32_t)0x00000002)
#define FMC_Bank1_NORSRAM3                      ((uint32_t)0x00000004)
#define FMC_Bank1_NORSRAM4                      ((uint32_t)0x00000006)

#define IS_FMC_NORSRAM_BANK(BANK) (((BANK) == FMC_Bank1_NORSRAM1) || \
                                   ((BANK) == FMC_Bank1_NORSRAM2) || \
                                   ((BANK) == FMC_Bank1_NORSRAM3) || \
                                   ((BANK) == FMC_Bank1_NORSRAM4))
/**
  * @}
  */

/** @defgroup FMC_NAND_Bank
  * @{
  */
#define FMC_Bank2_NAND                          ((uint32_t)0x00000010)
#define FMC_Bank3_NAND                          ((uint32_t)0x00000100)

#define IS_FMC_NAND_BANK(BANK) (((BANK) == FMC_Bank2_NAND) || \
                                ((BANK) == FMC_Bank3_NAND))
/**
  * @}
  */

/** @defgroup FMC_PCCARD_Bank
  * @{
  */
#define FMC_Bank4_PCCARD                        ((uint32_t)0x00001000)
/**
  * @}
  */

/** @defgroup FMC_SDRAM_Bank
  * @{
  */
#define FMC_Bank1_SDRAM                    ((uint32_t)0x00000000)
#define FMC_Bank2_SDRAM                    ((uint32_t)0x00000001)

#define IS_FMC_SDRAM_BANK(BANK) (((BANK) == FMC_Bank1_SDRAM) || \
                                 ((BANK) == FMC_Bank2_SDRAM))

/**
  * @}
  */


/** @defgroup FMC_NOR_SRAM_Controller
  * @{
  */

/** @defgroup FMC_Data_Address_Bus_Multiplexing
  * @{
  */

#define FMC_DataAddressMux_Disable                ((uint32_t)0x00000000)
#define FMC_DataAddressMux_Enable                 ((uint32_t)0x00000002)

#define IS_FMC_MUX(MUX) (((MUX) == FMC_DataAddressMux_Disable) || \
                         ((MUX) == FMC_DataAddressMux_Enable))
/**
  * @}
  */

/** @defgroup FMC_Memory_Type
  * @{
  */

#define FMC_MemoryType_SRAM                     ((uint32_t)0x00000000)
#define FMC_MemoryType_PSRAM                    ((uint32_t)0x00000004)
#define FMC_MemoryType_NOR                      ((uint32_t)0x00000008)

#define IS_FMC_MEMORY(MEMORY) (((MEMORY) == FMC_MemoryType_SRAM) || \
                               ((MEMORY) == FMC_MemoryType_PSRAM)|| \
                               ((MEMORY) == FMC_MemoryType_NOR))
/**
  * @}
  */

/** @defgroup FMC_NORSRAM_Data_Width
  * @{
  */

#define FMC_NORSRAM_MemoryDataWidth_8b                  ((uint32_t)0x00000000)
#define FMC_NORSRAM_MemoryDataWidth_16b                 ((uint32_t)0x00000010)
#define FMC_NORSRAM_MemoryDataWidth_32b                 ((uint32_t)0x00000020)

#define IS_FMC_NORSRAM_MEMORY_WIDTH(WIDTH) (((WIDTH) == FMC_NORSRAM_MemoryDataWidth_8b)  || \
                                            ((WIDTH) == FMC_NORSRAM_MemoryDataWidth_16b) || \
                                            ((WIDTH) == FMC_NORSRAM_MemoryDataWidth_32b))
/**
  * @}
  */

/** @defgroup FMC_Burst_Access_Mode
  * @{
  */

#define FMC_BurstAccessMode_Disable             ((uint32_t)0x00000000)
#define FMC_BurstAccessMode_Enable              ((uint32_t)0x00000100)

#define IS_FMC_BURSTMODE(STATE) (((STATE) == FMC_BurstAccessMode_Disable) || \
                                  ((STATE) == FMC_BurstAccessMode_Enable))
/**
  * @}
  */

/** @defgroup FMC_AsynchronousWait
  * @{
  */
#define FMC_AsynchronousWait_Disable            ((uint32_t)0x00000000)
#define FMC_AsynchronousWait_Enable             ((uint32_t)0x00008000)

#define IS_FMC_ASYNWAIT(STATE) (((STATE) == FMC_AsynchronousWait_Disable) || \
                                 ((STATE) == FMC_AsynchronousWait_Enable))
/**
  * @}
  */

/** @defgroup FMC_Wait_Signal_Polarity
  * @{
  */
#define FMC_WaitSignalPolarity_Low              ((uint32_t)0x00000000)
#define FMC_WaitSignalPolarity_High             ((uint32_t)0x00000200)

#define IS_FMC_WAIT_POLARITY(POLARITY) (((POLARITY) == FMC_WaitSignalPolarity_Low) || \
                                         ((POLARITY) == FMC_WaitSignalPolarity_High))
/**
  * @}
  */

/** @defgroup FMC_Wrap_Mode
  * @{
  */
#define FMC_WrapMode_Disable                    ((uint32_t)0x00000000)
#define FMC_WrapMode_Enable                     ((uint32_t)0x00000400)

#define IS_FMC_WRAP_MODE(MODE) (((MODE) == FMC_WrapMode_Disable) || \
                                 ((MODE) == FMC_WrapMode_Enable))
/**
  * @}
  */

/** @defgroup FMC_Wait_Timing
  * @{
  */
#define FMC_WaitSignalActive_BeforeWaitState    ((uint32_t)0x00000000)
#define FMC_WaitSignalActive_DuringWaitState    ((uint32_t)0x00000800)

#define IS_FMC_WAIT_SIGNAL_ACTIVE(ACTIVE) (((ACTIVE) == FMC_WaitSignalActive_BeforeWaitState) || \
                                            ((ACTIVE) == FMC_WaitSignalActive_DuringWaitState))
/**
  * @}
  */

/** @defgroup FMC_Write_Operation
  * @{
  */
#define FMC_WriteOperation_Disable                     ((uint32_t)0x00000000)
#define FMC_WriteOperation_Enable                      ((uint32_t)0x00001000)

#define IS_FMC_WRITE_OPERATION(OPERATION) (((OPERATION) == FMC_WriteOperation_Disable) || \
                                            ((OPERATION) == FMC_WriteOperation_Enable))
/**
  * @}
  */

/** @defgroup FMC_Wait_Signal
  * @{
  */
#define FMC_WaitSignal_Disable                  ((uint32_t)0x00000000)
#define FMC_WaitSignal_Enable                   ((uint32_t)0x00002000)

#define IS_FMC_WAITE_SIGNAL(SIGNAL) (((SIGNAL) == FMC_WaitSignal_Disable) || \
                                      ((SIGNAL) == FMC_WaitSignal_Enable))
/**
  * @}
  */

/** @defgroup FMC_Extended_Mode
  * @{
  */
#define FMC_ExtendedMode_Disable                ((uint32_t)0x00000000)
#define FMC_ExtendedMode_Enable                 ((uint32_t)0x00004000)

#define IS_FMC_EXTENDED_MODE(MODE) (((MODE) == FMC_ExtendedMode_Disable) || \
                                     ((MODE) == FMC_ExtendedMode_Enable))
/**
  * @}
  */

/** @defgroup FMC_Write_Burst
  * @{
  */

#define FMC_WriteBurst_Disable                  ((uint32_t)0x00000000)
#define FMC_WriteBurst_Enable                   ((uint32_t)0x00080000)

#define IS_FMC_WRITE_BURST(BURST) (((BURST) == FMC_WriteBurst_Disable) || \
                                    ((BURST) == FMC_WriteBurst_Enable))
/**
  * @}
  */

/** @defgroup FMC_Continous_Clock
  * @{
  */

#define FMC_CClock_SyncOnly                     ((uint32_t)0x00000000)
#define FMC_CClock_SyncAsync                    ((uint32_t)0x00100000)

#define IS_FMC_CONTINOUS_CLOCK(CCLOCK) (((CCLOCK) == FMC_CClock_SyncOnly) || \
                                        ((CCLOCK) == FMC_CClock_SyncAsync))
/**
  * @}
  */

/** @defgroup FMC_Address_Setup_Time
  * @{
  */
#define IS_FMC_ADDRESS_SETUP_TIME(TIME) ((TIME) <= 15)
/**
  * @}
  */

/** @defgroup FMC_Address_Hold_Time
  * @{
  */
#define IS_FMC_ADDRESS_HOLD_TIME(TIME) (((TIME) > 0) && ((TIME) <= 15))
/**
  * @}
  */

/** @defgroup FMC_Data_Setup_Time
  * @{
  */
#define IS_FMC_DATASETUP_TIME(TIME) (((TIME) > 0) && ((TIME) <= 255))
/**
  * @}
  */

/** @defgroup FMC_Bus_Turn_around_Duration
  * @{
  */
#define IS_FMC_TURNAROUND_TIME(TIME) ((TIME) <= 15)
/**
  * @}
  */

/** @defgroup FMC_CLK_Division
  * @{
  */
#define IS_FMC_CLK_DIV(DIV) (((DIV) > 0) && ((DIV) <= 15))
/**
  * @}
  */

/** @defgroup FMC_Data_Latency
  * @{
  */
#define IS_FMC_DATA_LATENCY(LATENCY) ((LATENCY) <= 15)
/**
  * @}
  */

/** @defgroup FMC_Access_Mode
  * @{
  */
#define FMC_AccessMode_A                        ((uint32_t)0x00000000)
#define FMC_AccessMode_B                        ((uint32_t)0x10000000)
#define FMC_AccessMode_C                        ((uint32_t)0x20000000)
#define FMC_AccessMode_D                        ((uint32_t)0x30000000)

#define IS_FMC_ACCESS_MODE(MODE) (((MODE) == FMC_AccessMode_A)  || \
                                   ((MODE) == FMC_AccessMode_B) || \
                                   ((MODE) == FMC_AccessMode_C) || \
                                   ((MODE) == FMC_AccessMode_D))
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup FMC_NAND_PCCARD_Controller
  * @{
  */

/** @defgroup FMC_Wait_feature
  * @{
  */
#define FMC_Waitfeature_Disable                 ((uint32_t)0x00000000)
#define FMC_Waitfeature_Enable                  ((uint32_t)0x00000002)

#define IS_FMC_WAIT_FEATURE(FEATURE) (((FEATURE) == FMC_Waitfeature_Disable) || \
                                       ((FEATURE) == FMC_Waitfeature_Enable))
/**
  * @}
  */

/** @defgroup FMC_NAND_Data_Width
  * @{
  */
#define FMC_NAND_MemoryDataWidth_8b             ((uint32_t)0x00000000)
#define FMC_NAND_MemoryDataWidth_16b            ((uint32_t)0x00000010)

#define IS_FMC_NAND_MEMORY_WIDTH(WIDTH) (((WIDTH) == FMC_NAND_MemoryDataWidth_8b) || \
                                         ((WIDTH) == FMC_NAND_MemoryDataWidth_16b))
/**
  * @}
  */

/** @defgroup FMC_ECC
  * @{
  */
#define FMC_ECC_Disable                         ((uint32_t)0x00000000)
#define FMC_ECC_Enable                          ((uint32_t)0x00000040)

#define IS_FMC_ECC_STATE(STATE) (((STATE) == FMC_ECC_Disable) || \
                                  ((STATE) == FMC_ECC_Enable))
/**
  * @}
  */

/** @defgroup FMC_ECC_Page_Size
  * @{
  */
#define FMC_ECCPageSize_256Bytes                ((uint32_t)0x00000000)
#define FMC_ECCPageSize_512Bytes                ((uint32_t)0x00020000)
#define FMC_ECCPageSize_1024Bytes               ((uint32_t)0x00040000)
#define FMC_ECCPageSize_2048Bytes               ((uint32_t)0x00060000)
#define FMC_ECCPageSize_4096Bytes               ((uint32_t)0x00080000)
#define FMC_ECCPageSize_8192Bytes               ((uint32_t)0x000A0000)

#define IS_FMC_ECCPAGE_SIZE(SIZE) (((SIZE) == FMC_ECCPageSize_256Bytes)   || \
                                    ((SIZE) == FMC_ECCPageSize_512Bytes)  || \
                                    ((SIZE) == FMC_ECCPageSize_1024Bytes) || \
                                    ((SIZE) == FMC_ECCPageSize_2048Bytes) || \
                                    ((SIZE) == FMC_ECCPageSize_4096Bytes) || \
                                    ((SIZE) == FMC_ECCPageSize_8192Bytes))
/**
  * @}
  */

/** @defgroup FMC_TCLR_Setup_Time
  * @{
  */
#define IS_FMC_TCLR_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_TAR_Setup_Time
  * @{
  */
#define IS_FMC_TAR_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_Setup_Time
  * @{
  */
#define IS_FMC_SETUP_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_Wait_Setup_Time
  * @{
  */
#define IS_FMC_WAIT_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_Hold_Setup_Time
  * @{
  */
#define IS_FMC_HOLD_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/** @defgroup FMC_HiZ_Setup_Time
  * @{
  */
#define IS_FMC_HIZ_TIME(TIME) ((TIME) <= 255)
/**
  * @}
  */

/**
  * @}
  */


/** @defgroup FMC_NOR_SRAM_Controller
  * @{
  */

/** @defgroup FMC_ColumnBits_Number
  * @{
  */
#define FMC_ColumnBits_Number_8b           ((uint32_t)0x00000000)
#define FMC_ColumnBits_Number_9b           ((uint32_t)0x00000001)
#define FMC_ColumnBits_Number_10b          ((uint32_t)0x00000002)
#define FMC_ColumnBits_Number_11b          ((uint32_t)0x00000003)

#define IS_FMC_COLUMNBITS_NUMBER(COLUMN) (((COLUMN) == FMC_ColumnBits_Number_8b)  || \
                                          ((COLUMN) == FMC_ColumnBits_Number_9b)  || \
                                          ((COLUMN) == FMC_ColumnBits_Number_10b) || \
                                          ((COLUMN) == FMC_ColumnBits_Number_11b))

/**
  * @}
  */

/** @defgroup FMC_RowBits_Number
  * @{
  */
#define FMC_RowBits_Number_11b             ((uint32_t)0x00000000)
#define FMC_RowBits_Number_12b             ((uint32_t)0x00000004)
#define FMC_RowBits_Number_13b             ((uint32_t)0x00000008)

#define IS_FMC_ROWBITS_NUMBER(ROW) (((ROW) == FMC_RowBits_Number_11b) || \
                                    ((ROW) == FMC_RowBits_Number_12b) || \
                                    ((ROW) == FMC_RowBits_Number_13b))

/**
  * @}
  */

/** @defgroup FMC_SDMemory_Data_Width
  * @{
  */
#define FMC_SDMemory_Width_8b                ((uint32_t)0x00000000)
#define FMC_SDMemory_Width_16b               ((uint32_t)0x00000010)
#define FMC_SDMemory_Width_32b               ((uint32_t)0x00000020)

#define IS_FMC_SDMEMORY_WIDTH(WIDTH) (((WIDTH) == FMC_SDMemory_Width_8b)  || \
                                      ((WIDTH) == FMC_SDMemory_Width_16b) || \
                                      ((WIDTH) == FMC_SDMemory_Width_32b))

/**
  * @}
  */

/** @defgroup FMC_InternalBank_Number
  * @{
  */
#define FMC_InternalBank_Number_2          ((uint32_t)0x00000000)
#define FMC_InternalBank_Number_4          ((uint32_t)0x00000040)

#define IS_FMC_INTERNALBANK_NUMBER(NUMBER) (((NUMBER) == FMC_InternalBank_Number_2) || \
                                            ((NUMBER) == FMC_InternalBank_Number_4))

/**
  * @}
  */


/** @defgroup FMC_CAS_Latency
  * @{
  */
#define FMC_CAS_Latency_1                  ((uint32_t)0x00000080)
#define FMC_CAS_Latency_2                  ((uint32_t)0x00000100)
#define FMC_CAS_Latency_3                  ((uint32_t)0x00000180)

#define IS_FMC_CAS_LATENCY(LATENCY) (((LATENCY) == FMC_CAS_Latency_1) || \
                                     ((LATENCY) == FMC_CAS_Latency_2) || \
                                     ((LATENCY) == FMC_CAS_Latency_3))

/**
  * @}
  */

/** @defgroup FMC_Write_Protection
  * @{
  */
#define FMC_Write_Protection_Disable       ((uint32_t)0x00000000)
#define FMC_Write_Protection_Enable        ((uint32_t)0x00000200)

#define IS_FMC_WRITE_PROTECTION(WRITE) (((WRITE) == FMC_Write_Protection_Disable) || \
                                        ((WRITE) == FMC_Write_Protection_Enable))

/**
  * @}
  */


/** @defgroup FMC_SDClock_Period
  * @{
  */
#define FMC_SDClock_Disable                ((uint32_t)0x00000000)
#define FMC_SDClock_Period_2               ((uint32_t)0x00000800)
#define FMC_SDClock_Period_3               ((uint32_t)0x00000C00)

#define IS_FMC_SDCLOCK_PERIOD(PERIOD) (((PERIOD) == FMC_SDClock_Disable) || \
                                       ((PERIOD) == FMC_SDClock_Period_2) || \
                                       ((PERIOD) == FMC_SDClock_Period_3))

/**
  * @}
  */

/** @defgroup FMC_Read_Burst
  * @{
  */
#define FMC_Read_Burst_Disable             ((uint32_t)0x00000000)
#define FMC_Read_Burst_Enable              ((uint32_t)0x00001000)

#define IS_FMC_READ_BURST(RBURST) (((RBURST) == FMC_Read_Burst_Disable) || \
                                   ((RBURST) == FMC_Read_Burst_Enable))

/**
  * @}
  */

/** @defgroup FMC_ReadPipe_Delay
  * @{
  */
#define FMC_ReadPipe_Delay_0               ((uint32_t)0x00000000)
#define FMC_ReadPipe_Delay_1               ((uint32_t)0x00002000)
#define FMC_ReadPipe_Delay_2               ((uint32_t)0x00004000)

#define IS_FMC_READPIPE_DELAY(DELAY) (((DELAY) == FMC_ReadPipe_Delay_0) || \
                                      ((DELAY) == FMC_ReadPipe_Delay_1) || \
                                      ((DELAY) == FMC_ReadPipe_Delay_2))

/**
  * @}
  */

/** @defgroup FMC_LoadToActive_Delay
  * @{
  */
#define IS_FMC_LOADTOACTIVE_DELAY(DELAY) (((DELAY) > 0) && ((DELAY) <= 16))
/**
  * @}
  */

/** @defgroup FMC_ExitSelfRefresh_Delay
  * @{
  */
#define IS_FMC_EXITSELFREFRESH_DELAY(DELAY) (((DELAY) > 0) && ((DELAY) <= 16))
/**
  * @}
  */

/** @defgroup FMC_SelfRefresh_Time
  * @{
  */
#define IS_FMC_SELFREFRESH_TIME(TIME) (((TIME) > 0) && ((TIME) <= 16))
/**
  * @}
  */

/** @defgroup FMC_RowCycle_Delay
  * @{
  */
#define IS_FMC_ROWCYCLE_DELAY(DELAY) (((DELAY) > 0) && ((DELAY) <= 16))
/**
  * @}
  */

/** @defgroup FMC_Write_Recovery_Time
  * @{
  */
#define IS_FMC_WRITE_RECOVERY_TIME(TIME) (((TIME) > 0) && ((TIME) <= 16))
/**
  * @}
  */

/** @defgroup FMC_RP_Delay
  * @{
  */
#define IS_FMC_RP_DELAY(DELAY) (((DELAY) > 0) && ((DELAY) <= 16))
/**
  * @}
  */

/** @defgroup FMC_RCD_Delay
  * @{
  */
#define IS_FMC_RCD_DELAY(DELAY) (((DELAY) > 0) && ((DELAY) <= 16))

/**
  * @}
  */

/** @defgroup FMC_Command_Mode
  * @{
  */
#define FMC_Command_Mode_normal            ((uint32_t)0x00000000)
#define FMC_Command_Mode_CLK_Enabled       ((uint32_t)0x00000001)
#define FMC_Command_Mode_PALL              ((uint32_t)0x00000002)
#define FMC_Command_Mode_AutoRefresh       ((uint32_t)0x00000003)
#define FMC_Command_Mode_LoadMode          ((uint32_t)0x00000004)
#define FMC_Command_Mode_Selfrefresh       ((uint32_t)0x00000005)
#define FMC_Command_Mode_PowerDown         ((uint32_t)0x00000006)

#define IS_FMC_COMMAND_MODE(COMMAND) (((COMMAND) == FMC_Command_Mode_normal)      || \
                                      ((COMMAND) == FMC_Command_Mode_CLK_Enabled) || \
                                      ((COMMAND) == FMC_Command_Mode_PALL)        || \
                                      ((COMMAND) == FMC_Command_Mode_AutoRefresh) || \
                                      ((COMMAND) == FMC_Command_Mode_LoadMode)    || \
                                      ((COMMAND) == FMC_Command_Mode_Selfrefresh) || \
                                      ((COMMAND) == FMC_Command_Mode_PowerDown))

/**
  * @}
  */

/** @defgroup FMC_Command_Target
  * @{
  */
#define FMC_Command_Target_bank2           ((uint32_t)0x00000008)
#define FMC_Command_Target_bank1           ((uint32_t)0x00000010)
#define FMC_Command_Target_bank1_2         ((uint32_t)0x00000018)

#define IS_FMC_COMMAND_TARGET(TARGET) (((TARGET) == FMC_Command_Target_bank1) || \
                                       ((TARGET) == FMC_Command_Target_bank2) || \
                                       ((TARGET) == FMC_Command_Target_bank1_2))

/**
  * @}
  */

/** @defgroup FMC_AutoRefresh_Number
  * @{
  */
#define IS_FMC_AUTOREFRESH_NUMBER(NUMBER) (((NUMBER) > 0) && ((NUMBER) <= 16))

/**
  * @}
  */

/** @defgroup FMC_ModeRegister_Definition
  * @{
  */
#define IS_FMC_MODE_REGISTER(CONTENT) ((CONTENT) <= 8191)

/**
  * @}
  */


/** @defgroup FMC_Mode_Status
  * @{
  */
#define FMC_NormalMode_Status                     ((uint32_t)0x00000000)
#define FMC_SelfRefreshMode_Status                FMC_SDSR_MODES1_0
#define FMC_PowerDownMode_Status                  FMC_SDSR_MODES1_1

#define IS_FMC_MODE_STATUS(STATUS) (((STATUS) == FMC_NormalMode_Status)       || \
                                    ((STATUS) == FMC_SelfRefreshMode_Status)  || \
                                    ((STATUS) == FMC_PowerDownMode_Status))


/**
  * @}
  */

/**
  * @}
  */

/** @defgroup FMC_Interrupt_sources
  * @{
  */
#define FMC_IT_RisingEdge                       ((uint32_t)0x00000008)
#define FMC_IT_Level                            ((uint32_t)0x00000010)
#define FMC_IT_FallingEdge                      ((uint32_t)0x00000020)
#define FMC_IT_Refresh                          ((uint32_t)0x00004000)

#define IS_FMC_IT(IT) ((((IT) & (uint32_t)0xFFFFBFC7) == 0x00000000) && ((IT) != 0x00000000))
#define IS_FMC_GET_IT(IT) (((IT) == FMC_IT_RisingEdge)  || \
                           ((IT) == FMC_IT_Level)       || \
                           ((IT) == FMC_IT_FallingEdge) || \
                           ((IT) == FMC_IT_Refresh))

#define IS_FMC_IT_BANK(BANK) (((BANK) == FMC_Bank2_NAND)   || \
                              ((BANK) == FMC_Bank3_NAND)   || \
                              ((BANK) == FMC_Bank4_PCCARD) || \
                              ((BANK) == FMC_Bank1_SDRAM)  || \
                              ((BANK) == FMC_Bank2_SDRAM))
/**
  * @}
  */

/** @defgroup FMC_Flags
  * @{
  */
#define FMC_FLAG_RisingEdge                     ((uint32_t)0x00000001)
#define FMC_FLAG_Level                          ((uint32_t)0x00000002)
#define FMC_FLAG_FallingEdge                    ((uint32_t)0x00000004)
#define FMC_FLAG_FEMPT                          ((uint32_t)0x00000040)
#define FMC_FLAG_Refresh                        FMC_SDSR_RE
#define FMC_FLAG_Busy                           FMC_SDSR_BUSY

#define IS_FMC_GET_FLAG(FLAG) (((FLAG) == FMC_FLAG_RisingEdge)       || \
                               ((FLAG) == FMC_FLAG_Level)            || \
                               ((FLAG) == FMC_FLAG_FallingEdge)      || \
                               ((FLAG) == FMC_FLAG_FEMPT)            || \
                               ((FLAG) == FMC_FLAG_Refresh)          || \
                               ((FLAG) == FMC_SDSR_BUSY))

#define IS_FMC_GETFLAG_BANK(BANK) (((BANK) == FMC_Bank2_NAND)    || \
                                   ((BANK) == FMC_Bank3_NAND)    || \
                                   ((BANK) == FMC_Bank4_PCCARD)  || \
                                   ((BANK) == FMC_Bank1_SDRAM)   || \
                                   ((BANK) == FMC_Bank2_SDRAM)   || \
                                   ((BANK) == (FMC_Bank1_SDRAM | FMC_Bank2_SDRAM)))

#define IS_FMC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFFF8) == 0x00000000) && ((FLAG) != 0x00000000))


/**
  * @}
  */

/** @defgroup FMC_Refresh_count
  * @{
  */
#define IS_FMC_REFRESH_COUNT(COUNT) ((COUNT) <= 8191)

/* ********************************* FSMC *********************************************  */

/**
  * @brief  Timing parameters For NOR/SRAM Banks
  */
typedef struct
{
  uint32_t FSMC_AddressSetupTime;       /*!< Defines the number of HCLK cycles to configure
                                             the duration of the address setup time.
                                             This parameter can be a value between 0 and 0xF.
                                             @note This parameter is not used with synchronous NOR Flash memories. */

  uint32_t FSMC_AddressHoldTime;        /*!< Defines the number of HCLK cycles to configure
                                             the duration of the address hold time.
                                             This parameter can be a value between 0 and 0xF.
                                             @note This parameter is not used with synchronous NOR Flash memories.*/

  uint32_t FSMC_DataSetupTime;          /*!< Defines the number of HCLK cycles to configure
                                             the duration of the data setup time.
                                             This parameter can be a value between 0 and 0xFF.
                                             @note This parameter is used for SRAMs, ROMs and asynchronous multiplexed NOR Flash memories. */

  uint32_t FSMC_BusTurnAroundDuration;  /*!< Defines the number of HCLK cycles to configure
                                             the duration of the bus turnaround.
                                             This parameter can be a value between 0 and 0xF.
                                             @note This parameter is only used for multiplexed NOR Flash memories. */

  uint32_t FSMC_CLKDivision;            /*!< Defines the period of CLK clock output signal, expressed in number of HCLK cycles.
                                             This parameter can be a value between 1 and 0xF.
                                             @note This parameter is not used for asynchronous NOR Flash, SRAM or ROM accesses. */

  uint32_t FSMC_DataLatency;            /*!< Defines the number of memory clock cycles to issue
                                             to the memory before getting the first data.
                                             The parameter value depends on the memory type as shown below:
                                              - It must be set to 0 in case of a CRAM
                                              - It is don't care in asynchronous NOR, SRAM or ROM accesses
                                              - It may assume a value between 0 and 0xF in NOR Flash memories
                                                with synchronous burst mode enable */

  uint32_t FSMC_AccessMode;             /*!< Specifies the asynchronous access mode.
                                             This parameter can be a value of @ref FSMC_Access_Mode */
}FSMC_NORSRAMTimingInitTypeDef;

/**
  * @brief  FSMC NOR/SRAM Init structure definition
  */
typedef struct
{
  uint32_t FSMC_Bank;                /*!< Specifies the NOR/SRAM memory bank that will be used.
                                          This parameter can be a value of @ref FSMC_NORSRAM_Bank */

  uint32_t FSMC_DataAddressMux;      /*!< Specifies whether the address and data values are
                                          multiplexed on the data bus or not.
                                          This parameter can be a value of @ref FSMC_Data_Address_Bus_Multiplexing */

  uint32_t FSMC_MemoryType;          /*!< Specifies the type of external memory attached to
                                          the corresponding memory bank.
                                          This parameter can be a value of @ref FSMC_Memory_Type */

  uint32_t FSMC_MemoryDataWidth;     /*!< Specifies the external memory device width.
                                          This parameter can be a value of @ref FSMC_Data_Width */

  uint32_t FSMC_BurstAccessMode;     /*!< Enables or disables the burst access mode for Flash memory,
                                          valid only with synchronous burst Flash memories.
                                          This parameter can be a value of @ref FSMC_Burst_Access_Mode */

  uint32_t FSMC_AsynchronousWait;     /*!< Enables or disables wait signal during asynchronous transfers,
                                          valid only with asynchronous Flash memories.
                                          This parameter can be a value of @ref FSMC_AsynchronousWait */

  uint32_t FSMC_WaitSignalPolarity;  /*!< Specifies the wait signal polarity, valid only when accessing
                                          the Flash memory in burst mode.
                                          This parameter can be a value of @ref FSMC_Wait_Signal_Polarity */

  uint32_t FSMC_WrapMode;            /*!< Enables or disables the Wrapped burst access mode for Flash
                                          memory, valid only when accessing Flash memories in burst mode.
                                          This parameter can be a value of @ref FSMC_Wrap_Mode */

  uint32_t FSMC_WaitSignalActive;    /*!< Specifies if the wait signal is asserted by the memory one
                                          clock cycle before the wait state or during the wait state,
                                          valid only when accessing memories in burst mode.
                                          This parameter can be a value of @ref FSMC_Wait_Timing */

  uint32_t FSMC_WriteOperation;      /*!< Enables or disables the write operation in the selected bank by the FSMC.
                                          This parameter can be a value of @ref FSMC_Write_Operation */

  uint32_t FSMC_WaitSignal;          /*!< Enables or disables the wait state insertion via wait
                                          signal, valid for Flash memory access in burst mode.
                                          This parameter can be a value of @ref FSMC_Wait_Signal */

  uint32_t FSMC_ExtendedMode;        /*!< Enables or disables the extended mode.
                                          This parameter can be a value of @ref FSMC_Extended_Mode */

  uint32_t FSMC_WriteBurst;          /*!< Enables or disables the write burst operation.
                                          This parameter can be a value of @ref FSMC_Write_Burst */

  FSMC_NORSRAMTimingInitTypeDef* FSMC_ReadWriteTimingStruct; /*!< Timing Parameters for write and read access if the  Extended Mode is not used*/

  FSMC_NORSRAMTimingInitTypeDef* FSMC_WriteTimingStruct;     /*!< Timing Parameters for write access if the  Extended Mode is used*/
}FSMC_NORSRAMInitTypeDef;

/**
  * @brief  Timing parameters For FSMC NAND and PCCARD Banks
  */
typedef struct
{
  uint32_t FSMC_SetupTime;      /*!< Defines the number of HCLK cycles to setup address before
                                     the command assertion for NAND Flash read or write access
                                     to common/Attribute or I/O memory space (depending on
                                     the memory space timing to be configured).
                                     This parameter can be a value between 0 and 0xFF.*/

  uint32_t FSMC_WaitSetupTime;  /*!< Defines the minimum number of HCLK cycles to assert the
                                     command for NAND Flash read or write access to
                                     common/Attribute or I/O memory space (depending on the
                                     memory space timing to be configured).
                                     This parameter can be a number between 0x00 and 0xFF */

  uint32_t FSMC_HoldSetupTime;  /*!< Defines the number of HCLK clock cycles to hold address
                                     (and data for write access) after the command de-assertion
                                     for NAND Flash read or write access to common/Attribute
                                     or I/O memory space (depending on the memory space timing
                                     to be configured).
                                     This parameter can be a number between 0x00 and 0xFF */

  uint32_t FSMC_HiZSetupTime;   /*!< Defines the number of HCLK clock cycles during which the
                                     data bus is kept in HiZ after the start of a NAND Flash
                                     write access to common/Attribute or I/O memory space (depending
                                     on the memory space timing to be configured).
                                     This parameter can be a number between 0x00 and 0xFF */
}FSMC_NAND_PCCARDTimingInitTypeDef;

/**
  * @brief  FSMC NAND Init structure definition
  */
typedef struct
{
  uint32_t FSMC_Bank;              /*!< Specifies the NAND memory bank that will be used.
                                      This parameter can be a value of @ref FSMC_NAND_Bank */

  uint32_t FSMC_Waitfeature;      /*!< Enables or disables the Wait feature for the NAND Memory Bank.
                                       This parameter can be any value of @ref FSMC_Wait_feature */

  uint32_t FSMC_MemoryDataWidth;  /*!< Specifies the external memory device width.
                                       This parameter can be any value of @ref FSMC_Data_Width */

  uint32_t FSMC_ECC;              /*!< Enables or disables the ECC computation.
                                       This parameter can be any value of @ref FSMC_ECC */

  uint32_t FSMC_ECCPageSize;      /*!< Defines the page size for the extended ECC.
                                       This parameter can be any value of @ref FSMC_ECC_Page_Size */

  uint32_t FSMC_TCLRSetupTime;    /*!< Defines the number of HCLK cycles to configure the
                                       delay between CLE low and RE low.
                                       This parameter can be a value between 0 and 0xFF. */

  uint32_t FSMC_TARSetupTime;     /*!< Defines the number of HCLK cycles to configure the
                                       delay between ALE low and RE low.
                                       This parameter can be a number between 0x0 and 0xFF */

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;   /*!< FSMC Common Space Timing */

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct; /*!< FSMC Attribute Space Timing */
}FSMC_NANDInitTypeDef;

/**
  * @brief  FSMC PCCARD Init structure definition
  */

typedef struct
{
  uint32_t FSMC_Waitfeature;    /*!< Enables or disables the Wait feature for the Memory Bank.
                                    This parameter can be any value of @ref FSMC_Wait_feature */

  uint32_t FSMC_TCLRSetupTime;  /*!< Defines the number of HCLK cycles to configure the
                                     delay between CLE low and RE low.
                                     This parameter can be a value between 0 and 0xFF. */

  uint32_t FSMC_TARSetupTime;   /*!< Defines the number of HCLK cycles to configure the
                                     delay between ALE low and RE low.
                                     This parameter can be a number between 0x0 and 0xFF */


  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct; /*!< FSMC Common Space Timing */

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;  /*!< FSMC Attribute Space Timing */

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_IOSpaceTimingStruct; /*!< FSMC IO Space Timing */
}FSMC_PCCARDInitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup FSMC_Exported_Constants
  * @{
  */

/** @defgroup FSMC_NORSRAM_Bank
  * @{
  */
#define FSMC_Bank1_NORSRAM1                      ((uint32_t)0x00000000)
#define FSMC_Bank1_NORSRAM2                      ((uint32_t)0x00000002)
#define FSMC_Bank1_NORSRAM3                      ((uint32_t)0x00000004)
#define FSMC_Bank1_NORSRAM4                      ((uint32_t)0x00000006)
/**
  * @}
  */

/** @defgroup FSMC_NAND_Bank
  * @{
  */
#define FSMC_Bank2_NAND                          ((uint32_t)0x00000010)
#define FSMC_Bank3_NAND                          ((uint32_t)0x00000100)
/**
  * @}
  */

/** @defgroup FSMC_PCCARD_Bank
  * @{
  */
#define FSMC_Bank4_PCCARD                        ((uint32_t)0x00001000)
/**
  * @}
  */

#define IS_FSMC_NORSRAM_BANK(BANK) (((BANK) == FSMC_Bank1_NORSRAM1) || \
                                    ((BANK) == FSMC_Bank1_NORSRAM2) || \
                                    ((BANK) == FSMC_Bank1_NORSRAM3) || \
                                    ((BANK) == FSMC_Bank1_NORSRAM4))

#define IS_FSMC_NAND_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
                                 ((BANK) == FSMC_Bank3_NAND))

#define IS_FSMC_GETFLAG_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
                                    ((BANK) == FSMC_Bank3_NAND) || \
                                    ((BANK) == FSMC_Bank4_PCCARD))

#define IS_FSMC_IT_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
                               ((BANK) == FSMC_Bank3_NAND) || \
                               ((BANK) == FSMC_Bank4_PCCARD))

/** @defgroup FSMC_NOR_SRAM_Controller
  * @{
  */

/** @defgroup FSMC_Data_Address_Bus_Multiplexing
  * @{
  */

#define FSMC_DataAddressMux_Disable                ((uint32_t)0x00000000)
#define FSMC_DataAddressMux_Enable                 ((uint32_t)0x00000002)
#define IS_FSMC_MUX(MUX) (((MUX) == FSMC_DataAddressMux_Disable) || \
                          ((MUX) == FSMC_DataAddressMux_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Memory_Type
  * @{
  */

#define FSMC_MemoryType_SRAM                     ((uint32_t)0x00000000)
#define FSMC_MemoryType_PSRAM                    ((uint32_t)0x00000004)
#define FSMC_MemoryType_NOR                      ((uint32_t)0x00000008)
#define IS_FSMC_MEMORY(MEMORY) (((MEMORY) == FSMC_MemoryType_SRAM) || \
                                ((MEMORY) == FSMC_MemoryType_PSRAM)|| \
                                ((MEMORY) == FSMC_MemoryType_NOR))
/**
  * @}
  */

/** @defgroup FSMC_Data_Width
  * @{
  */

#define FSMC_MemoryDataWidth_8b                  ((uint32_t)0x00000000)
#define FSMC_MemoryDataWidth_16b                 ((uint32_t)0x00000010)
#define IS_FSMC_MEMORY_WIDTH(WIDTH) (((WIDTH) == FSMC_MemoryDataWidth_8b) || \
                                     ((WIDTH) == FSMC_MemoryDataWidth_16b))
/**
  * @}
  */

/** @defgroup FSMC_Burst_Access_Mode
  * @{
  */

#define FSMC_BurstAccessMode_Disable             ((uint32_t)0x00000000)
#define FSMC_BurstAccessMode_Enable              ((uint32_t)0x00000100)
#define IS_FSMC_BURSTMODE(STATE) (((STATE) == FSMC_BurstAccessMode_Disable) || \
                                  ((STATE) == FSMC_BurstAccessMode_Enable))
/**
  * @}
  */

/** @defgroup FSMC_AsynchronousWait
  * @{
  */
#define FSMC_AsynchronousWait_Disable            ((uint32_t)0x00000000)
#define FSMC_AsynchronousWait_Enable             ((uint32_t)0x00008000)
#define IS_FSMC_ASYNWAIT(STATE) (((STATE) == FSMC_AsynchronousWait_Disable) || \
                                 ((STATE) == FSMC_AsynchronousWait_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Wait_Signal_Polarity
  * @{
  */
#define FSMC_WaitSignalPolarity_Low              ((uint32_t)0x00000000)
#define FSMC_WaitSignalPolarity_High             ((uint32_t)0x00000200)
#define IS_FSMC_WAIT_POLARITY(POLARITY) (((POLARITY) == FSMC_WaitSignalPolarity_Low) || \
                                         ((POLARITY) == FSMC_WaitSignalPolarity_High))
/**
  * @}
  */

/** @defgroup FSMC_Wrap_Mode
  * @{
  */
#define FSMC_WrapMode_Disable                    ((uint32_t)0x00000000)
#define FSMC_WrapMode_Enable                     ((uint32_t)0x00000400)
#define IS_FSMC_WRAP_MODE(MODE) (((MODE) == FSMC_WrapMode_Disable) || \
                                 ((MODE) == FSMC_WrapMode_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Wait_Timing
  * @{
  */
#define FSMC_WaitSignalActive_BeforeWaitState    ((uint32_t)0x00000000)
#define FSMC_WaitSignalActive_DuringWaitState    ((uint32_t)0x00000800)
#define IS_FSMC_WAIT_SIGNAL_ACTIVE(ACTIVE) (((ACTIVE) == FSMC_WaitSignalActive_BeforeWaitState) || \
                                            ((ACTIVE) == FSMC_WaitSignalActive_DuringWaitState))
/**
  * @}
  */

/** @defgroup FSMC_Write_Operation
  * @{
  */
#define FSMC_WriteOperation_Disable                     ((uint32_t)0x00000000)
#define FSMC_WriteOperation_Enable                      ((uint32_t)0x00001000)
#define IS_FSMC_WRITE_OPERATION(OPERATION) (((OPERATION) == FSMC_WriteOperation_Disable) || \
                                            ((OPERATION) == FSMC_WriteOperation_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Wait_Signal
  * @{
  */
#define FSMC_WaitSignal_Disable                  ((uint32_t)0x00000000)
#define FSMC_WaitSignal_Enable                   ((uint32_t)0x00002000)
#define IS_FSMC_WAITE_SIGNAL(SIGNAL) (((SIGNAL) == FSMC_WaitSignal_Disable) || \
                                      ((SIGNAL) == FSMC_WaitSignal_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Extended_Mode
  * @{
  */
#define FSMC_ExtendedMode_Disable                ((uint32_t)0x00000000)
#define FSMC_ExtendedMode_Enable                 ((uint32_t)0x00004000)

#define IS_FSMC_EXTENDED_MODE(MODE) (((MODE) == FSMC_ExtendedMode_Disable) || \
                                     ((MODE) == FSMC_ExtendedMode_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Write_Burst
  * @{
  */

#define FSMC_WriteBurst_Disable                  ((uint32_t)0x00000000)
#define FSMC_WriteBurst_Enable                   ((uint32_t)0x00080000)
#define IS_FSMC_WRITE_BURST(BURST) (((BURST) == FSMC_WriteBurst_Disable) || \
                                    ((BURST) == FSMC_WriteBurst_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Address_Setup_Time
  * @{
  */
#define IS_FSMC_ADDRESS_SETUP_TIME(TIME) ((TIME) <= 0xF)
/**
  * @}
  */

/** @defgroup FSMC_Address_Hold_Time
  * @{
  */
#define IS_FSMC_ADDRESS_HOLD_TIME(TIME) ((TIME) <= 0xF)
/**
  * @}
  */

/** @defgroup FSMC_Data_Setup_Time
  * @{
  */
#define IS_FSMC_DATASETUP_TIME(TIME) (((TIME) > 0) && ((TIME) <= 0xFF))
/**
  * @}
  */

/** @defgroup FSMC_Bus_Turn_around_Duration
  * @{
  */
#define IS_FSMC_TURNAROUND_TIME(TIME) ((TIME) <= 0xF)
/**
  * @}
  */

/** @defgroup FSMC_CLK_Division
  * @{
  */
#define IS_FSMC_CLK_DIV(DIV) ((DIV) <= 0xF)
/**
  * @}
  */

/** @defgroup FSMC_Data_Latency
  * @{
  */
#define IS_FSMC_DATA_LATENCY(LATENCY) ((LATENCY) <= 0xF)
/**
  * @}
  */

/** @defgroup FSMC_Access_Mode
  * @{
  */
#define FSMC_AccessMode_A                        ((uint32_t)0x00000000)
#define FSMC_AccessMode_B                        ((uint32_t)0x10000000)
#define FSMC_AccessMode_C                        ((uint32_t)0x20000000)
#define FSMC_AccessMode_D                        ((uint32_t)0x30000000)
#define IS_FSMC_ACCESS_MODE(MODE) (((MODE) == FSMC_AccessMode_A) || \
                                   ((MODE) == FSMC_AccessMode_B) || \
                                   ((MODE) == FSMC_AccessMode_C) || \
                                   ((MODE) == FSMC_AccessMode_D))
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup FSMC_NAND_PCCARD_Controller
  * @{
  */

/** @defgroup FSMC_Wait_feature
  * @{
  */
#define FSMC_Waitfeature_Disable                 ((uint32_t)0x00000000)
#define FSMC_Waitfeature_Enable                  ((uint32_t)0x00000002)
#define IS_FSMC_WAIT_FEATURE(FEATURE) (((FEATURE) == FSMC_Waitfeature_Disable) || \
                                       ((FEATURE) == FSMC_Waitfeature_Enable))
/**
  * @}
  */


/** @defgroup FSMC_ECC
  * @{
  */
#define FSMC_ECC_Disable                         ((uint32_t)0x00000000)
#define FSMC_ECC_Enable                          ((uint32_t)0x00000040)
#define IS_FSMC_ECC_STATE(STATE) (((STATE) == FSMC_ECC_Disable) || \
                                  ((STATE) == FSMC_ECC_Enable))
/**
  * @}
  */

/** @defgroup FSMC_ECC_Page_Size
  * @{
  */
#define FSMC_ECCPageSize_256Bytes                ((uint32_t)0x00000000)
#define FSMC_ECCPageSize_512Bytes                ((uint32_t)0x00020000)
#define FSMC_ECCPageSize_1024Bytes               ((uint32_t)0x00040000)
#define FSMC_ECCPageSize_2048Bytes               ((uint32_t)0x00060000)
#define FSMC_ECCPageSize_4096Bytes               ((uint32_t)0x00080000)
#define FSMC_ECCPageSize_8192Bytes               ((uint32_t)0x000A0000)
#define IS_FSMC_ECCPAGE_SIZE(SIZE) (((SIZE) == FSMC_ECCPageSize_256Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_512Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_1024Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_2048Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_4096Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_8192Bytes))
/**
  * @}
  */

/** @defgroup FSMC_TCLR_Setup_Time
  * @{
  */
#define IS_FSMC_TCLR_TIME(TIME) ((TIME) <= 0xFF)
/**
  * @}
  */

/** @defgroup FSMC_TAR_Setup_Time
  * @{
  */
#define IS_FSMC_TAR_TIME(TIME) ((TIME) <= 0xFF)
/**
  * @}
  */

/** @defgroup FSMC_Setup_Time
  * @{
  */
#define IS_FSMC_SETUP_TIME(TIME) ((TIME) <= 0xFF)
/**
  * @}
  */

/** @defgroup FSMC_Wait_Setup_Time
  * @{
  */
#define IS_FSMC_WAIT_TIME(TIME) ((TIME) <= 0xFF)
/**
  * @}
  */

/** @defgroup FSMC_Hold_Setup_Time
  * @{
  */
#define IS_FSMC_HOLD_TIME(TIME) ((TIME) <= 0xFF)
/**
  * @}
  */

/** @defgroup FSMC_HiZ_Setup_Time
  * @{
  */
#define IS_FSMC_HIZ_TIME(TIME) ((TIME) <= 0xFF)
/**
  * @}
  */

/** @defgroup FSMC_Interrupt_sources
  * @{
  */
#define FSMC_IT_RisingEdge                       ((uint32_t)0x00000008)
#define FSMC_IT_Level                            ((uint32_t)0x00000010)
#define FSMC_IT_FallingEdge                      ((uint32_t)0x00000020)
#define IS_FSMC_IT(IT) ((((IT) & (uint32_t)0xFFFFFFC7) == 0x00000000) && ((IT) != 0x00000000))
#define IS_FSMC_GET_IT(IT) (((IT) == FSMC_IT_RisingEdge) || \
                            ((IT) == FSMC_IT_Level) || \
                            ((IT) == FSMC_IT_FallingEdge))
/**
  * @}
  */

/** @defgroup FSMC_Flags
  * @{
  */
#define FSMC_FLAG_RisingEdge                     ((uint32_t)0x00000001)
#define FSMC_FLAG_Level                          ((uint32_t)0x00000002)
#define FSMC_FLAG_FallingEdge                    ((uint32_t)0x00000004)
#define FSMC_FLAG_FEMPT                          ((uint32_t)0x00000040)
#define IS_FSMC_GET_FLAG(FLAG) (((FLAG) == FSMC_FLAG_RisingEdge) || \
                                ((FLAG) == FSMC_FLAG_Level) || \
                                ((FLAG) == FSMC_FLAG_FallingEdge) || \
                                ((FLAG) == FSMC_FLAG_FEMPT))

#define IS_FSMC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFFF8) == 0x00000000) && ((FLAG) != 0x00000000))

#define BCR_MBKEN_SET          ((uint32_t)0x00000001)
#define BCR_MBKEN_RESET        ((uint32_t)0x000FFFFE)
#define BCR_FACCEN_SET         ((uint32_t)0x00000040)

/* FSMC PCRx Mask */
#define PCR_PBKEN_SET          ((uint32_t)0x00000004)
#define PCR_PBKEN_RESET        ((uint32_t)0x000FFFFB)
#define PCR_ECCEN_SET          ((uint32_t)0x00000040)
#define PCR_ECCEN_RESET        ((uint32_t)0x000FFFBF)
#define PCR_MEMORYTYPE_NAND    ((uint32_t)0x00000008)

#elif CPUSTYLE_STM32MP157A || CPUSTYLE_STM32MP157D

#endif

#endif /* SDRAM_H_INCLUDED */
