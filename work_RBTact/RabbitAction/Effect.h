#pragma once
#include <math.h>
#include "DxLib.h"
#include "Common.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"

class Effect
{
public:
	//////////////////////////////////////
	//　固定値
	//////////////////////////////////////
	//キック関連固定値
	const double DEFAULT_KICK_GRAPH_EXTEND_RATE = 1.0;		//エフェクトの表示倍率の初期値
	const double INCRESE_EXTEND_MASS			= 1.0;		//エフェクトの表示倍率の変化量
	const int MAX_KICK_EFFECT_EXTEND_RATE		= 40;		//エフェクトの表示倍率の限界値
	//彗星キック関連固定値
	static const int METEO_EFFECT_ANIMATION_MASS = 9;
	static const int HIT_METEO_EFFECT_ANIMATION_MASS = 10;
	const float METEO_EFFECT_START_DISTANCE = 250.0f;			//エフェクトの描画をする距離
	const float HIT_METEO_EFFECT_OFFSET = 350.0f;				//爆発エフェクトをどのくらい大きくするか
	const double METEO_EFFECT_EXTEND_RATE = 0.5;
	//エネミー被ダメージ関連固定値
	static const int STAR_MAX_MASS = 10;						//一度の被ダメージで使う星の最大数
	const int STAR_NORMAL_MASS = 3;							//通常の踏み付け時に使う星の数
	const int STAR_MAX_VELOCITY = 30;
	const int STAR_MAX_VELOCITY_OFFSET = STAR_MAX_VELOCITY / 2;
	const float STAR_GRAVITY = 1.5f;
	//エネミー撃破関連固定値
	static const int SMOKE_MAX_MASS = 2;					//煙エフェクトの最大表示数
	//コイン獲得関連固定値
	static const int COIN_EFFECT_ANIMATION_MASS = 10;
	const float COIN_EFFECT_EXTEND_RATE = 2.75f;

	//////////////////////////////////////
	//　変数
	//////////////////////////////////////
	//プレイヤーのキックに使うもの
	int kickEff;
	double kickEffExtend;

	//キックが一定のスピードに至った時に使うもの（彗星キックと呼称する）
	int meteoEff[METEO_EFFECT_ANIMATION_MASS];
	int meteoAnimNum;

	//彗星キックヒット時に使うもの
	int hitMeteoEff[HIT_METEO_EFFECT_ANIMATION_MASS];
	int hitMeteoAnimNum;
	int drawCnt;			//同じコマを描画した回数
	float exploreX;
	float exploreY;
	bool drawExploreFlag;

	//エネミーの被ダメージ時、プレイヤーHP0時に使うもの
	int starEff;
	float starX[STAR_MAX_MASS];
	float starY[STAR_MAX_MASS];
	float starVelX[STAR_MAX_MASS];
	float starVelY[STAR_MAX_MASS];
	bool criticalEffectFlag;

	//プレイヤーHP0時に使うもの
	int blackSqrGraph;
	int gameOverTime;
	int blackOutRate;
	bool gameOverSetFlag;

	//エネミーのHPが０になったときに使うもの
	int smokeEff[10];
	int smokeAnimNum[SMOKE_MAX_MASS];	//エフェクトのアニメーション番号
	int smokeTimer[SMOKE_MAX_MASS];		//エフェクト描画に使うタイマー
	int smokeNumber;	//エフェクトの番号。SMOKE_MAX_MASS分だけ描画を可能にするため。
	float smokeX[SMOKE_MAX_MASS];
	float smokeY[SMOKE_MAX_MASS];
	bool smokeFlag[SMOKE_MAX_MASS];

	//プレイヤーの被ダメージ時に使うもの
	int damageEff;
	float damageEffX;
	float damageEffY;

	//コイン獲得時に使うもの
	int coinEff[COIN_EFFECT_ANIMATION_MASS];
	int coinEffAnimNum;
	bool coinEffTimeFlag;		//true時にエフェクト再生

	//ゲームクリア時に使うもの
	int whiteSqrGraph;
	int gameClearTime;
	int whiteOutRate;
	bool gameClearSetFlag;

	//////////////////////////////////////
	//　関数
	//////////////////////////////////////
	//キック関連関数群
	void InitKickEffect(int replayCnt);
	void DrawKickEffect(Player *player, Camera *camera);

	//彗星キック関連関数軍
	void InitMeteoEffect(int replayCnt);
	void DrawMeteoEffect(Player *player, Camera *camera);
	void SetHitMeteoEffect(Enemy *enemy, Player *player);
	void DrawHitMeteoEffect(Enemy *enemy, Camera *camera);

	//エネミー被ダメージ関連関数群
	void InitStarEffect(int replayCnt);
	void SetRandomStarVelocities();
	void SetStarXY4Enemy(Enemy *enemy, Player *player);
	void UpdateStar();
	void DrawStarEffect(Camera *camera);

	//エネミー撃破関連関数群
	void InitSmokeEffect(int replayCnt);
	void SetSmokeEffect(Enemy *enemy);
	void UpdateSmoke(EnemyControl *enemyCtrl);
	void DrawSmokeEffect(Camera *camera);

	//プレイヤー被ダメージ関連関数群
	void InitDamageEffect(int replayCnt);
	void SetDamageEffect(Player *player);
	void DrawDamageEffect(Player *player, Camera *camera);

	//プレイヤーHP0関連関数群
	void InitPlayerDown();
	void SetPlayerDown(Player *player);
	void UpdatePlayerDown(StateFlags *state, Game *game, Camera *camera);

	//コイン獲得関連関数群
	void InitCoinEffect(int replayCnt);
	void UpdateCoinEffect();
	void DrawCoinEffect(Player *player, Camera *camera);

	//ゲームクリア関連関数群
	void InitGameClear();
	void SetGameClear();
	void UpdateGameClear(StateFlags *state, Game *game);
};