#pragma once
#include "DxLib.h"
#include "Common.h"
#include "Phase.h"
#include "Camera.h"
#include "Map.h"

class Boss
{
public:
	static const int PARTS_MASS_X = 5;
	static const int PARTS_MASS_Y = 5;
	static const int PARTS_MASS_ALL = PARTS_MASS_X * PARTS_MASS_Y;
	static const int EMISSION_STEP = 12;
	const int PARTS_SIZE_W = 32;
	const int PARTS_SIZE_H = 32;
	const int FLOAT_BLOCK_MASS = 3;			//���u���b�N�����V�����邩
	const int ANGER_COUNT = 500;
	const int SPRIT_COUNT = 800;
	const int CLOSE_COUNT = 2000;			//�{�X�S���􂩂牽�~���b��Ƀ{�X�p�̕��������邩
	const int TIME_LIMIT = 180000;
	const int TIME_OUT_COUNT = 3000;
	const int BONUS_SCORE = 10000;
	const float GRAPH_EXTEND_RATE = 3.0f;
	const float POSITION_X = 29300;

	int bossGraph[PARTS_MASS_ALL];
	int angerGraph[PARTS_MASS_ALL];
	int angerTime;						//�u�U�����ʂ���摜�v�ɍ����ւ������Ԃ��i�[
	int appearTime;						//�o���������Ԃ��i�[
	int spritTime;						//���􂷂�^�C�~���O���v�邽�߂Ɏg�p���鎞�Ԃ̕ϐ�
	int allSpritTime;
	int existEnemyPartsMass;			//�����̃G�l�~�[����ʏ�ɑ��݂��鐔
	int emissionInTheStep;				//���̔r�o�i�K�ɂ����ĉ��̔r�o������
	int spritMass;						//���􂵂���
	int emissionMass[EMISSION_STEP];	//�ڕW�Ƃ���G�l�~�[�̔r�o��
	float x, y;
	bool sprit[PARTS_MASS_ALL];
	bool angerFlag;							//�{��摜�ɍ����ւ���Ƃ�true
	bool emission;						//���􂷂ׂ�����true
	bool allEmission;					//���ׂẴ{�X�����G�l�~�[��r�o������true��
	bool alive;

	void Init(Map *map, int replayCnt);
	void Update(Enemy **enemy, Game *game, Map *map);
	void Anger();
	bool CheckEnemyOnBossArea(Enemy **enemy);			//�G�l�~�[���{�X�G���A��ɂ��邩�ǂ����̃`�F�b�N�@true--->����
	void Draw(Camera *camera);
	void TimeOut(Game *game);
};