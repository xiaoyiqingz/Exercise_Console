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
8*8λ�÷�8�����ӣ��� ÿ�� ÿ�� �϶�ֻ��һ��
*/

static int board[BOARD_SIZE];

//һ���ж��������
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
	// �������ڵ�n��ʱ���Ƿ���֮ǰn-1���г�ͻ����ʱ���õ�n�У�����n+1���Ժ���û�ж����ģ�����Ҫ���
	for (int i=0; i < n; i++) {
		//��i�� �� ��n�� �����õ�����ͬ�� �������� ��ֵ����ֵ���(������ б�� ������������ֱ�Ǳ����)
		//��Ϊ���õ�ʱ�� ÿ��ֻ��һ�� ������ ͬ�в�������ͬ���
		if (board[i] == board[n] || (n - i) == abs(board[i]- board[n]))
			return true;
	}
	return false;
}

static bool PutChess(int n) 
{
	for (int i=0; i < BOARD_SIZE; i++) {
		//��n�� ���õ�λ����8�֣� �� 0 ��ʼ�� ��ʾ��0�з����˵�i��
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

/*  ��ά���鴫������   int ��*board��[] �Լ�ʹ��  (*(board+tmpx))[tmpy]
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