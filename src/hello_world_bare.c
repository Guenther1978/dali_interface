/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/* Disable Watch Dog Timer */
#pragma config WDTE = OFF   
/* Low voltage programming enabled , RE3 pin is MCLR */
#pragma config LVP = ON

#include <xc.h>
#include <stdint.h>
#include <string.h>

static void CLK_init(void);
static void EUSART1_init(void);
static void EUSART2_init(void);
static void PPS_init(void);
static void PORT_init(void);
static void EUSART1_write(uint8_t txData);
static void EUSART2_write(uint8_t txData);

static void CLK_init(void)
{   
    /* Set HFINTOSC as new oscillator source */
    OSCCON1bits.NOSC = 0b110;

    /* Set HFFRQ to 1 MHz */
    OSCFRQbits.HFFRQ = 0;
}

static void EUSART1_init(void)
{
    /* Receive Enable */
    U1CON0bits.RXEN = 1;
    /* Transmit Enable */
    U1CON0bits.TXEN = 1;
    /* High Baud Rate Select */
    U1CON0bits.BRGS = 1;

    /* 16-bit Baud Rate Generator is used */
    //BAUD2CONbits.BRG16 = 1;

    /* Baud rate 9600 */
    U1BRGL = 25;
    U1BRGH = 0;

    /* Serial Port Enable */
    U1CON1bits.ON = 1;
}

static void EUSART2_init(void)
{
    /* Receive Enable */
    U2CON0bits.RXEN = 1;
     /* Transmit Enable */
    U2CON0bits.TXEN = 1;
    /* High Baud Rate Select */
    U2CON0bits.BRGS = 1;

    /* 16-bit Baud Rate Generator is used */
    //BAUD2CONbits.BRG16 = 1;

    /* Baud rate 9600 */
    U2BRGL = 25;
    U2BRGH = 0;

    /* Serial Port Enable */
    U2CON1bits.On = 1;
}

static void PPS_init(void) 
{
    /* RC7 is RX1*/
    U1RXPPS = 0x17;

    /* RC6 is TX1 */
    RC6PPS = 0x13;

    /* RC1 is RX2*/
    U2RXPPS = 0x11;

    /* RC0 is TX2 */
    RC0PPS = 0x16;
}

static void PORT_init(void)
{
    /* Configure RC6 as output. */
    TRISCbits.TRISC6 = 0;

    /* Configure RC7 as input. */
    TRISCbits.TRISC7 = 1;
    ANSELCbits.ANSELC7 = 0;

    /* Configure RC0 as output. */
    TRISCbits.TRISC0 = 0;

    /* Configure RC1 as input. */
    TRISCbits.TRISC1 = 1;
    ANSELCbits.ANSELC1 = 0;
}

static void EUSART1_write(uint8_t txData)
{
    while(0 == PIR3bits.U1TXIF)
    {
        ;
    }

    U1TXB = txData;
}

static void EUSART2_write(uint8_t txData)
{
    while(0 == PIR7bits.U2TXIF)
    {
        ;
    }

    U2TXB = txData;
}

uint8_t EUSART1_read(void)
{
    while(0 == PIR3bits.U1RXIF)
    {
        ;
    }

    return U1RXB;
}

uint8_t EUSART2_read(void)
{
    while(0 == PIR7bits.U2RXIF)
    {
        ;
    }

    return U2RXB;
}

void putch1(char txData)
{
    EUSART1_write(txData);
}

void putch2(char txData)
{
    EUSART2_write(txData);
}

char getch1(void)
{
    return EUSART1_read();
}

char getch2(void)
{
    return EUSART2_read();
}



void main(void)
{
    char msg[] = "Hello World\r\n";
    char msg2[] = "Hallo Welt\r\n";

    char c1 = ' ';
    char c2 = ' ';

    CLK_init();
    EUSART1_init();
    EUSART2_init();  
    PPS_init();   
    PORT_init();

    for(uint8_t i = 0; i < strlen(msg); i++)
    {
        EUSART1_write(msg2[i]);
        EUSART2_write(msg[i]);
    }
    
    while(1) 
    {
        c1 = getch1();
        putch2(c1);
        c2 = getch2();
        putch1(c2);
    }
}