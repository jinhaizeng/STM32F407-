#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"


//ALIENTEK ̽����STM32F407������ ʵ��10
//���벶��ʵ�� -�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
 
 
 
extern u8  TIM5CH1_CAPTURE_STA;		//���벶��״̬		    				
extern u32	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ  
u32 fre;
  
	
int main(void)
{ 
	long long temp=0;  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
  
	TIM3_Int_Init(5000-1,8400-1); 
 	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1); //��1Mhz��Ƶ�ʼ��� 
   	while(1)
	{
 		delay_ms(1000);
    TIM_Cmd(TIM5,DISABLE ); 	//�رն�ʱ��5	
    TIM_Cmd(TIM3,DISABLE ); 	//�رն�ʱ��3
    fre = 10*TIM5_COUNTER/(TIM3_COUNTER+TIM3_CUR/1000);
    printf("%d\r\n",fre);
    TIM5_COUNTER=0;
    TIM3_COUNTER=0;
    TIM_SetCounter(TIM3,0);
    TIM_Cmd(TIM5,ENABLE ); 	//ʹ�ܶ�ʱ��5	
 		TIM_Cmd(TIM3,ENABLE ); 	//ʹ�ܶ�ʱ��5	
	}
}
