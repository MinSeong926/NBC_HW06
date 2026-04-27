// MovingActor.cpp
#include "MovingActor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Math/UnrealMathUtility.h"

AMovingActor::AMovingActor()
{
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));

	PrimaryActorTick.bCanEverTick = true;

	MoveDirection = 1.f;
	//MoveDirection = -1.f;
	MoveSpeed = 1.f;
	AccumulatedDistance = 0.0f;

	StartLocation = GetActorLocation();
	MaxRange = 100.f;
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//AddActorLocalOffset(FVector(0.f, MoveSpeed * MoveDirection, 0.f));

	AccumulatedDistance += MoveSpeed;
	if (MaxRange < AccumulatedDistance) {
		MoveDirection *= -1.f;
		AccumulatedDistance = 0.f;
	}

	AddActorLocalOffset(FVector(0.f, MoveSpeed * MoveDirection * DeltaTime, 0.f));
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	// 3초마다 TeleportRandomly 함수 실행
	GetWorld()->GetTimerManager().SetTimer(TeleportTimerHandle, this, &AMovingActor::TeleportRandomly, 3.0f, true);
}

void AMovingActor::TeleportRandomly()
{
	FVector NewLocation(
		FMath::RandRange(-1500.f, 1500.f),
		FMath::RandRange(-1500.f, 1500.f),
		FMath::RandRange(20.f, 100.f)
	);
	SetActorLocation(NewLocation);
}