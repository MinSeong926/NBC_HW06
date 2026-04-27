// RotatingActor.cpp

#include "RotatingActor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Math/UnrealMathUtility.h"

ARotatingActor::ARotatingActor()
{
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));

	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.f, 1.f, 0.f));
}

void ARotatingActor::BeginPlay()
{
    Super::BeginPlay();

    // 3초마다 TeleportRandomly 함수 실행
    GetWorld()->GetTimerManager().SetTimer(TeleportTimerHandle, this, &ARotatingActor::TeleportRandomly, 3.0f, true);
}

void ARotatingActor::TeleportRandomly()
{
    FVector NewLocation(
        FMath::RandRange(-1500.f, 1500.f),
        FMath::RandRange(-1500.f, 1500.f),
        FMath::RandRange(20.f, 100.f)
    );
    SetActorLocation(NewLocation);
}