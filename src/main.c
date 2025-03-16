 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

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
#include "mcc_generated_files/system/system.h"

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    uint8_t character_uart_1 = 0;
    uint8_t character_uart_2 = 0;
    
    UART1_TransmitEnable();
    UART1_ReceiveEnable();
    UART2_TransmitEnable();
    UART2_ReceiveEnable();

    TRISCbits.TRISC7 = 1;
    ANSELCbits.ANSELC7 = 0;
    TRISCbits.TRISC6 = 0;
    TRISBbits.TRISB5 = 1;
    ANSELBbits.ANSELB3 = 0;
    TRISBbits.TRISB4 = 0;
    
    U1CON2bits.TXPOL = 0;
    U2CON2bits.TXPOL = 0;
    U1CON2bits.RXPOL = 0;
    U2CON2bits.RXPOL = 0;

    /* RC6 is TX1 */
    RC6PPS = 0x13;
    /* RC7 is RX1*/
    U1RXPPS = 0x17;
    
    /* RB4 is TX2 */
    RB4PPS = 0x16;
    /* RB5 is RX2*/
    U2RXPPS = 0x0D;

    /* High Baud Rate Select */
    U1CON0bits.BRGS = 1;
    U2CON0bits.BRGS = 1;


    /* 16-bit Baud Rate Generator is used */
    //BAUD2CONbits.BRG16 = 1;

    /* Baud rate 9600 */
    U1BRGL = 25;
    U1BRGH = 0;
    U2BRGL = 25;
    U2BRGH = 0;

    /* Serial Port Enable */
    UART1_Enable();
    UART2_Enable();

    UART1_Write('1');
    UART2_Write('2');
    
    UART1_ReceiveInterruptEnable();
    UART2_ReceiveInterruptEnable();
    
    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 
    
    while(1)
    {
        if (UART1_IsRxReady()) {
            character_uart_1 = UART1_Read();
            if (UART1_IsTxReady())
            {
                UART1_Write(character_uart_1);
            }
            if (UART2_IsTxReady())
            {
                UART2_Write(character_uart_1);
            }
        }

        if (UART2_IsRxReady()) {
/*            character_uart_2 = UART2_Read();
            if (UART1_IsTxReady())
            {
                UART1_Write('a');//character_uart_2);
            }
            //if (UART2_IsTxReady())
            {
                UART2_Write('b');//character_uart_2);
            }
        }
*/        character_uart_2 = UART2_Read();
        if (character_uart_2 != 0)
        {
            UART1_Write(character_uart_2);
            UART2_Write(character_uart_2);
            character_uart_2 = 0;
        }            
    }    
}
}