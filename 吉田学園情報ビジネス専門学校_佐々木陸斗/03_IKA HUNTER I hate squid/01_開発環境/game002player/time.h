#pragma once

#ifndef _TIME_H_
#define _TIME_H_

#define MAX_TIME				(3)		//読み込むサイズ



#include "main.h"

//プロトタイプ宣言
void lnitTime(void);
void UninitTime(void);
void UpdateTime(void);
void DrawTime(void);
void SetTime(int nTime);
void AddTime(int nValue);





#endif 