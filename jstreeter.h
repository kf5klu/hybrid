#ifndef J_Streeter_Header	//Header already included??
#define J_Streeter_Header  	//No?  Ok...include it now

#include "hyglobals.h"

#ifndef Only_Once
#define	Only_Once
unsigned int RunningAverage[2] = {0,0};
#endif

//char setup_array(int channel, unsigned short adc_data) {
//    int math(unsigned short, unsigned char[]); /*http://www.google.com/*/
//    unsigned char uart_data[5] = {0x5, 0, 0, 0, 0x42}; //Setup the Array to send to the Kellys
//
//    switch (channel) {
//        case 0:
//        {
//            uart_data[1] = 1; //Setup or the math and the TX
//            if (math(adc_data, uart_data)) {
//                TX(uart_data); //Go Fast Right
//                uart_data[1] = 2;
//                TX(uart_data); //Go Fast Left
//            }
//            return 0;
//            break;
//        }
//        case 1:
//        {
//            uart_data[1] = 0;
//            if (math(adc_data, uart_data)) {
//                TX(uart_data); //Brake Right
//                uart_data[1] = 3;
//                TX(uart_data); //Brake Left
//            }
//            return 0;
//            break;
//        }
//        case 2:
//        {
//            TX(uart_data); //Clutch Is engaged Turn Off Go Fast Right
//            TX(uart_data); //Clutch Is engaged Turn Off Go Fast Left
//            return 0;
//            break;
//        }
//    }
//    //add o shit here
//    return (1);
//}
//
//int math(unsigned short raw_data, unsigned char p_Data[]) {
//    u32b b; //Temp
//    unsigned int Old_Average, test_point;
//    u8b i;
//    i = p_Data[1];
//    Old_Average = RunningAverage[i];
//
//    b = ((unsigned int) raw_data); //TypeCast to a bigger type
//    b = b << 8; //Shift To the left by 8 bits
//    RunningAverage[i] = ((RunningAverage[i] * 15) / 16) + (b / 16); //MAke a running average
//    b = RunningAverage[i] >> 8; //Shift back to a 16 bit
//    raw_data = (unsigned short) b; //Type cast to 16bit
//
//    if ((Old_Average >> 8) > (RunningAverage[i] >> 8)) {
//        test_point = (Old_Average >> 8) - (RunningAverage[i] >> 8);
//    } else {
//        test_point = (RunningAverage[i] >> 8) - (Old_Average >> 8);
//    }
//    printf("Old = %6d  New = %6d\n", (Old_Average >> 8), (RunningAverage[i] >> 8));
//    if (test_point < Hysteresis) {
//        RunningAverage[i] = Old_Average; //AS to not move the point yet
//        //Testing
//        printf("NOT sending\n");
//        return (0); //Don'T Send
//    }
//    p_Data[3] = (unsigned char) raw_data; //LSB
//    p_Data[2] = ((unsigned char) (raw_data >> 8)); //MSB
//    printf("sending\n");
//    return (1); //SEND						//IT worked
//}
#endif//Done
