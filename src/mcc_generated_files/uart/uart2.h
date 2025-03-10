/**
 * UART2 Generated Driver API Header File
 * 
 * @file uart2.h
 * 
 * @defgroup uart2 UART2
 * 
 * @brief This file contains API prototypes and other data types for the the Universal Asynchronous Receiver and Transmitter (UART) module.
 *
 * @version UART2 Driver Version 3.0.6
*/
/*
� [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef UART2_H
#define UART2_H


#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "../system/system.h"
#include "uart_drv_interface.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

#define UART2_interface UART2


#define UART2_Initialize     UART2_Initialize
#define UART2_Deinitialize   UART2_Deinitialize
#define UART2_Write          UART2_Write
#define UART2_Read           UART2_Read
#define UART2__IsRxReady     UART2_IsRxReady
#define UART2_IsTxReady      UART2_IsTxReady
#define UART2_IsTxDone       UART2_IsTxDone

#define UART2_TransmitEnable       UART2_TransmitEnable
#define UART2_TransmitDisable      UART2_TransmitDisable
#define UART2_AutoBaudSet          UART2_AutoBaudSet
#define UART2_AutoBaudQuery        UART2_AutoBaudQuery
#define UART2_AutoBaudDetectCompleteReset  UART2_AutoBaudDetectCompleteReset
#define UART2_IsAutoBaudDetectOverflow     UART2_IsAutoBaudDetectOverflow
#define UART2_AutoBaudDetectOverflowReset  UART2_AutoBaudDetectOverflowReset
#define UART2_BRGCountSet               (NULL)
#define UART2_BRGCountGet               (NULL)
#define UART2_BaudRateSet               (NULL)
#define UART2_BaudRateGet               (NULL)
#define UART2__AutoBaudEventEnableGet   (NULL)
#define UART2_ErrorGet             UART2_ErrorGet

#define UART2_TxCompleteCallbackRegister     UART2_TxCompleteCallbackRegister
#define UART2_RxCompleteCallbackRegister      UART2_RxCompleteCallbackRegister
#define UART2_TxCollisionCallbackRegister  (NULL)
#define UART2_FramingErrorCallbackRegister UART2_FramingErrorCallbackRegister
#define UART2_OverrunErrorCallbackRegister UART2_OverrunErrorCallbackRegister
#define UART2_ParityErrorCallbackRegister  UART2_ParityErrorCallbackRegister
#define UART2_EventCallbackRegister        (NULL)

/**
 @ingroup uart2
 @struct uart2_status_t
 @brief This is an instance of UART2_STATUS for UART2 module
 */
typedef union {
    struct {
        uint8_t perr : 1;     /**<This is a bit field for Parity Error status*/
        uint8_t ferr : 1;     /**<This is a bit field for Framing Error status*/
        uint8_t oerr : 1;     /**<This is a bit field for Overfrun Error status*/
        uint8_t reserved : 5; /**<Reserved*/
    };
    size_t status;            /**<Group byte for status errors*/
}uart2_status_t;


/**
 * @ingroup uart2
 * @brief External object for uart_drv_interface.
 */
extern const uart_drv_interface_t UART2;

/**
 * @ingroup uart2
 * @brief Initializes the UART2 module. This routine is called
 *        only once during system initialization, before calling other APIs.
 * @param None.
 * @return None.
 */
void UART2_Initialize(void);

/**
 * @ingroup uart2
 * @brief Deinitializes and disables the UART2 module.

 * @param None.
 * @return None.
 */
void UART2_Deinitialize(void);

/**
 * @ingroup uart2
 * @brief Enables the UART2 module.     
 * @param None.
 * @return None.
 */
inline void UART2_Enable(void);

/**
 * @ingroup uart2
 * @brief Disables the UART2 module.
 * @param None.
 * @return None.
 */
inline void UART2_Disable(void);

/**
 * @ingroup uart2
 * @brief Enables the UART2 transmitter. This routine also enables
 *        UART2 to send bytes over the TX pin.
 * @param None.
 * @return None.
 */
inline void UART2_TransmitEnable(void);

/**
 * @ingroup uart2
 * @brief Disables the UART2 transmitter.
 * @param None.
 * @return None.
 */
inline void UART2_TransmitDisable(void);

/**
 * @ingroup uart2
 * @brief Enables the UART2 receiver. This routine also enables
 *        UART2 to send bytes over the RX pin.
 * @param None.
 * @return None.
 */
inline void UART2_ReceiveEnable(void);

/**
 * @ingroup uart2
 * @brief Disables the UART2 receiver.
 * @param None.
 * @return None.
 */
inline void UART2_ReceiveDisable(void);

/**
 * @ingroup uart2
 * @brief Enables the UART2 Send Break Control bit.
 * @param None.
 * @return None.
 */
inline void UART2_SendBreakControlEnable(void);

/**
 * @ingroup uart2
 * @brief Disables the UART2 Send Break Control bit.
 * @param None.
 * @return None.
 */
inline void UART2_SendBreakControlDisable(void);

/**
 * @ingroup uart2
 * @brief Enables the UART2 transmitter interrupt.
 * @param None.
 * @return None.
 */
inline void UART2_TransmitInterruptEnable(void);

/**
 * @ingroup uart2
 * @brief Disables the UART2 transmitter interrupt.
 * @param None.
 * @return None.
 */
inline void UART2_TransmitInterruptDisable(void);

/**
 * @ingroup uart2
 * @brief Enables the UART2 receiver interrupt.
 * @param None.
 * @return None.
 */
inline void UART2_ReceiveInterruptEnable(void);

/**
 * @ingroup uart2
 * @brief Disables the UART2 receiver interrupt.
 * @param None.
 * @return None.
 */
inline void UART2_ReceiveInterruptDisable(void);

/**
 * @ingroup uart2
 * @brief Enables the UART2 Auto-Baud Detection bit.
 * @param bool enable
 * @return None.
 */
inline void UART2_AutoBaudSet(bool enable);


/**
 * @ingroup uart2
 * @brief Reads the UART2 Auto-Baud Detection Complete bit.
 * @param None.
 * @return None.
 */
inline bool UART2_AutoBaudQuery(void);

/**
 * @ingroup uart2
 * @brief Resets the UART2 Auto-Baud Detection Complete bit.
 * @param None.
 * @return None.
 */
inline void UART2_AutoBaudDetectCompleteReset(void);

/**
 * @ingroup uart2
 * @brief Reads the UART2 Auto-Baud Detection Overflow bit.
 * @param None.
 * @return None.
 */
inline bool UART2_IsAutoBaudDetectOverflow(void);

/**
 * @ingroup uart2
 * @brief Resets the UART2 Auto-Baud Detection Overflow bit.
 * @param None.
 * @return None.
 */
inline void UART2_AutoBaudDetectOverflowReset(void);

/**
 * @ingroup uart2
 * @brief Checks if the UART2 receiver has received data and is ready to be read.
 * @param None.
 * @retval True - UART2 receiver FIFO has data
 * @retval False - UART2 receiver FIFO is empty
 */
bool UART2_IsRxReady(void);

/**
 * @ingroup uart2
 * @brief Checks if the UART2 transmitter is ready to accept a data byte.
 * @param None.
 * @retval True -  The UART2 transmitter FIFO has at least a one byte space
 * @retval False - The UART2 transmitter FIFO is full
 */
bool UART2_IsTxReady(void);

/**
 * @ingroup uart2
 * @brief Returns the status of the Transmit Shift Register (TSR).
 * @param None.
 * @retval True - Data completely shifted out from the TSR
 * @retval False - Data is present in Transmit FIFO and/or in TSR
 */
bool UART2_IsTxDone(void);

/**
 * @ingroup uart2
 * @brief Gets the error status of the last read byte. Call 
 *        this function before calling UART2_Read().
 * @pre Call UART2_RxEnable() to enable RX before calling this API.
 * @param None.
 * @return Status of the last read byte. See the uart2_status_t struct for more details.
 */
size_t UART2_ErrorGet(void);

/**
 * @ingroup uart2
 * @brief Reads the eight bits from the Receiver FIFO register.
 * @pre Check the transfer status to see if the receiver is not empty before calling this function. Check 
 *      UART2_IsRxReady() in if () before calling this API.
 * @param None.
 * @return 8-bit data from the RX FIFO register
 */
uint8_t UART2_Read(void);

/**
 * @ingroup uart2
 * @brief Writes a byte of data to the Transmitter FIFO register.
 * @pre Check the transfer status to see if the transmitter is not empty before calling this function. Check
 *      UART2_IsTxReady() in if () before calling this API.
 * @param txData  - Data byte to write to the TX FIFO
 * @return None.
 */
void UART2_Write(uint8_t txData);

/**
 * @ingroup uart2
 * @brief Calls the function upon UART2 framing error.
 * @param callbackHandler - Function pointer called when the framing error condition occurs
 * @return None.
 */
void UART2_FramingErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart2
 * @brief Calls the function upon UART2 overrun error.
 * @param callbackHandler - Function pointer called when the overrun error condition occurs
 * @return None.
 */
void UART2_OverrunErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart2
 * @brief Calls the function upon UART2 parity error.
 * @param callbackHandler - Function pointer called when the parity error condition occurs
 * @return None.
 */
void UART2_ParityErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart2
 * @brief Pointer to the function called when the transmitter interrupt occurs.
 * @pre Initialize the UART2 module with the transmit interrupt enabled.
 * @param None.
 * @return None.
 */
void (*UART2_TxInterruptHandler)(void);

/**
 * @ingroup uart2
 * @brief Registers the function to be called when the transmitter interrupt occurs.
 * @param callbackHandler - Function pointer called when the transmitter interrupt condition occurs
 * @return None.
 */
void UART2_TxCompleteCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart2
 * @brief Implements the Interrupt Service Routine (ISR) for the UART2 transmitter interrupt.
 * @param None.
 * @return None.
 */
void UART2_TransmitISR(void);

/**
 * @ingroup uart2
 * @brief Pointer to the function called when the receiver interrupt occurs.
 * @pre Initialize the UART2 module with the receive interrupt enabled.
 * @param None.
 * @return None.
 */
void (*UART2_RxInterruptHandler)(void);
/**
 * @ingroup uart2
 * @brief Registers the function to be called when the receiver interrupt occurs
 * @param callbackHandler - Function pointer called when the receiver interrupt condition occurs
 * @return None.
 */
void UART2_RxCompleteCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart2
 * @brief Implements the ISR for the UART2 receiver interrupt.
 * @param void.
 * @return None.
 */
void UART2_ReceiveISR(void);

#ifdef __cplusplus  // Provide C++ Compatibility


    }

#endif

#endif  // UART2_H
