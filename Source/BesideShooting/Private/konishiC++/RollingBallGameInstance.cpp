// Fill out your copyright notice in the Description page of Project Settings.


#include "konishiC++/RollingBallGameInstance.h"

void URollingBallGameInstance::Initialize()
{
	// �����l���������N���X��DefaultObject���擾����
	const URollingBallGameInstance* DefaultObject = GetDefault<URollingBallGameInstance>();

	// �����l��ݒ肷��
	this->TotalCoins = DefaultObject->TotalCoins;
	this->TotalLifes = DefaultObject->TotalLifes;
}