#include "EightQuee.h"

#include <assert.h>
#include <iostream>
#include <memory>

#define  BOARD_SIZE 8
#define  HAS_QUEE   2
#define  CAN_HAS_QUEE 0
#define  CANNOR_HAS_QUEE 1

namespace test{

/*
8*8位置放8个棋子，则 每行 每列 肯定只有一个
*/

static int board[BOARD_SIZE];

//一共有多少种情况
static int nCout = 0;

static void Print()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
	    std::cout << "(" << i << "," << board[i] << ")";
		std::cout << " ";
	}
	std::cout<< std::endl;
	nCout++;
}

static bool CheckSameLine(int n)
{
	// 检查放置在第n行时，是否与之前n-1行有冲突，此时放置第n行，所以n+1行以后是没有东西的，不需要检查
	for (int i=0; i < n; i++) {
		//第i行 与 第n行 所放置的列相同， 或者行列 差值绝对值相等(正方形 斜线 构成三角形两直角边相等)
		//因为放置的时候 每行只放一个 ，所以 同行不存在相同情况
		if (board[i] == board[n] || (n - i) == abs(board[i]- board[n]))
			return true;
	}
	return false;
}

static bool PutChess(int n) 
{
	for (int i=0; i < BOARD_SIZE; i++) {
		//第n行 放置的位置有8种， 从 0 开始， 表示第0行放在了第i列
		board[n] = i;
		if (!CheckSameLine(n)) {
			if (n == BOARD_SIZE-1) 
				Print();
			else PutChess(n+1);
		}
	}	
	return true;
}

void EightQuee() {
	PutChess(0);
	
	std::cout << nCout << std::endl;
}

/*  二维数组传参问题   int （*board）[] 以及使用  (*(board+tmpx))[tmpy]
static bool CalDonotHas(int board[BOARD_SIZE][BOARD_SIZE], const int xSize, const int x ,const int y)
{
	assert((x > -1 && x < BOARD_SIZE) && (y > -1 && y < BOARD_SIZE));

	int tmpx;
	int tmpy; 

	if ((tmpx = x-1) > -1 && (tmpy = y-1) > -1 && (*(board+tmpx))[tmpy] != CANNOR_HAS_QUEE) {
	 	if ((*(board+tmpx))[tmpy] == HAS_QUEE) {
			return false;
		} else {
			(*(board+tmpx))[tmpy] = CANNOR_HAS_QUEE;
		}
		//std::cout << tmpx << " " << tmpy << std::endl;
	}

	tmpy = y;
	if ((tmpx = x-1) > -1 && (*(board+tmpx))[tmpy] != CANNOR_HAS_QUEE){
		if ((*(board+tmpx))[tmpy] == HAS_QUEE) {
			return false;
		} else {
			(*(board+tmpx))[tmpy] = CANNOR_HAS_QUEE;
		}
		//std::cout << tmpx << " " << tmpy << std::endl;
	}

	if ((tmpx = x-1) > -1 && (tmpy = y+1) < BOARD_SIZE && (*(board+tmpx))[tmpy] != CANNOR_HAS_QUEE) {
		if ((*(board+tmpx))[tmpy] == HAS_QUEE) {
			return false;
		} else {
			(*(board+tmpx))[tmpy] = CANNOR_HAS_QUEE;
		}
		//std::cout << tmpx << " " << tmpy << std::endl;
	} 
	
	tmpx = x;
	if ((tmpy = y-1) > -1 && (*(board+tmpx))[tmpy] != CANNOR_HAS_QUEE) {
		if ((*(board+tmpx))[tmpy] == HAS_QUEE) {
			return false;
		} else {
			(*(board+tmpx))[tmpy] = CANNOR_HAS_QUEE;
		}
		//std::cout << tmpx << " " << tmpy << std::endl;
	} 

	tmpx = x;
	if ((tmpy = y+1) < BOARD_SIZE && (*(board+tmpx))[tmpy] != CANNOR_HAS_QUEE) {
		if ((*(board+tmpx))[tmpy] == HAS_QUEE) {
			return false;
		} else {
			(*(board+tmpx))[tmpy] = CANNOR_HAS_QUEE;
		}
		//std::cout << tmpx << " " << tmpy << std::endl;
	} 
	
	if ((tmpx = x+1) < BOARD_SIZE && (tmpy = y-1) > -1 && (*(board+tmpx))[tmpy] != CANNOR_HAS_QUEE) {
		if ((*(board+tmpx))[tmpy] == HAS_QUEE) {
			return false;
		} else {
			(*(board+tmpx))[tmpy] = CANNOR_HAS_QUEE;
		}
		//std::cout << tmpx << " " << tmpy << std::endl;
	}

	tmpy = y;
	if ((tmpx = x+1) < BOARD_SIZE && (*(board+tmpx))[tmpy] != CANNOR_HAS_QUEE) {
		if ((*(board+tmpx))[tmpy] == HAS_QUEE) {
			return false;
		} else {
			(*(board+tmpx))[tmpy] = CANNOR_HAS_QUEE;
		}
		//std::cout << tmpx << " " << tmpy << std::endl;
	}

	if ((tmpx = x+1) < BOARD_SIZE && (tmpy = y+1) < BOARD_SIZE && (*(board+tmpx))[tmpy] != CANNOR_HAS_QUEE) {
		if ((*(board+tmpx))[tmpy] == HAS_QUEE) {
			return false;
		} else {
			(*(board+tmpx))[tmpy] = CANNOR_HAS_QUEE;
		}
		//std::cout << tmpx << " " << tmpy << std::endl;
	}

	return true;
}

void EightQuee()
{
	int quee_board[BOARD_SIZE][BOARD_SIZE];
	//memset(quee_board, CAN_HAS_QUEE, sizeof(quee_board));

	for (int i=0; i < 8; i++) {
		memset(quee_board, CAN_HAS_QUEE, sizeof(quee_board));
		quee_board[0][i] = HAS_QUEE;
		if (!CalDonotHas(quee_board, BOARD_SIZE, 0, i)) 
			continue;


	}

	std::cout << "hehe" << std::endl;
}*/

} //namespace test