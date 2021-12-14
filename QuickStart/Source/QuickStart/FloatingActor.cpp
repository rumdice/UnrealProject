// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * MoveSpeed; // ���Կ� ���� ��ġ �� (Ʈ������)�� ������ �󿡼� ���� ����
	
	float DeltaWidth = (FMath::Sin(RunningTime + 0.6) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaWidth * 20.0f; // ������ ��
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

