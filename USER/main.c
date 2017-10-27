#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"


//ALIENTEK 探索者STM32F407开发板 实验10
//输入捕获实验 -库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
 
 
 
extern u8  TIM5CH1_CAPTURE_STA;		//输入捕获状态		    				
extern u32	TIM5CH1_CAPTURE_VAL;	//输入捕获值  
u32 fre;
  
	
int main(void)
{ 
	long long temp=0;  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);//初始化串口波特率为115200
  
	TIM3_Int_Init(5000-1,8400-1); 
 	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1); //以1Mhz的频率计数 
   	while(1)
	{
 		delay_ms(1000);
    TIM_Cmd(TIM5,DISABLE ); 	//关闭定时器5	
    TIM_Cmd(TIM3,DISABLE ); 	//关闭定时器3
    fre = 10*TIM5_COUNTER/(TIM3_COUNTER+TIM3_CUR/1000);
    printf("%d\r\n",fre);
    TIM5_COUNTER=0;
    TIM3_COUNTER=0;
    TIM_SetCounter(TIM3,0);
    TIM_Cmd(TIM5,ENABLE ); 	//使能定时器5	
 		TIM_Cmd(TIM3,ENABLE ); 	//使能定时器5	
	}
}
