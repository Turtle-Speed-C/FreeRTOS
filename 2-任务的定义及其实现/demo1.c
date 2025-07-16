// Demo 1: 基础任务创建与运行
// 重点：展示最基本的任务创建和运行
// 特色：3个不同闪烁频率的LED任务，演示并发执行
// 学习要点：任务函数结构、堆栈分配、任务控制块的使用

#include "FreeRTOS.h"
#include "task.h"

//这里定义了三个任务的句柄，分别用于管理红色、绿色、蓝色 LED 的任务。
//LED_STACK_SIZE 设置了任务堆栈的大小。每个任务都需要一个堆栈来存储局部变量和任务状态。
TaskHadle_t RedLED_Handle;
TaskHadle_t GreenLED_Handle;
TaskHadle_t BlueLED_Handle;


//任务堆栈大小定义
#define LED_STACK_SIZE 128;


//任务堆栈
StackType_t RedLEDStack[LED_STACK_SIZE];
StackType_t GreenLEDStack[LED_STACK_SIZE];
StackType_t BlueLEDStack[LED_STACK_SIZE];


//任务控制块
TCB_t RedLEDTCB;
TCB_t GreenLEDTCB;
TCB_t RedLEDTCB;


//模拟LED状态的全局变量
volatile uint8_t ren_led_state=0;
volatile uint8_t green_led_state=0;
volatile uint8_t blue_led_state=0;


//延时函数
void delay_ms(uint32_t ms){

    for(uint32_t i=0;i<100;i++);

}


//红色LED任务——快速闪烁
