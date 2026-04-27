
#include "TeleportingPlatform.h"

ATeleportingPlatform::ATeleportingPlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	// 액터가 이동할 수 있도록 모빌리티를 Movable로 설정
	MeshComp->SetMobility(EComponentMobility::Movable);
}

void ATeleportingPlatform::BeginPlay()
{
    Super::BeginPlay();

    // 게임 시작 시 3초마다 TeleportRandomly 함수를 반복(true) 실행
    GetWorld()->GetTimerManager().SetTimer(TeleportTimerHandle, this, &ATeleportingPlatform::TeleportRandomly, 3.0f, true);
}

void ATeleportingPlatform::TeleportRandomly()
{
    // 이동할 새로운 무작위 좌표 생성 (Z축은 20 ~ 100 사이)
    FVector NewLocation(
        FMath::RandRange(-1500.f, 1500.f),
        FMath::RandRange(-1500.f, 1500.f),
        FMath::RandRange(20.f, 100.f)
    );

    // 액터의 위치를 생성한 좌표로 순간이동
    SetActorLocation(NewLocation);
}

