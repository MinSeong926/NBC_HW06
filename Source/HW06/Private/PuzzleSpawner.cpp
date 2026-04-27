
#include "PuzzleSpawner.h"
#include "Math/UnrealMathUtility.h"
#include "MovingActor.h"
#include "RotatingActor.h"

APuzzleSpawner::APuzzleSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

}

void APuzzleSpawner::BeginPlay()
{
	Super::BeginPlay();

    // 등록된 클래스가 없으면 실행 취소
    if (PlatformClass.IsEmpty()) return;

    for (int32 i = 0; i < SpawnCount; i++)
    {
        // 배열에 등록된 클래스 중 하나를 무작위로 선택
        int32 RandomIndex = FMath::RandRange(0, PlatformClass.Num() - 1);
        TSubclassOf<AActor> SelectedClass = PlatformClass[RandomIndex];

        if (!SelectedClass) continue;

        // Z축 범위를 20.0 ~ 100.0으로 무작위 좌표 생성
        FVector RandomLocation(
            FMath::RandRange(-1500.f, 1500.f),
            FMath::RandRange(-1500.f, 1500.f),
            FMath::RandRange(20.f, 100.f)
        );

        FRotator RandomRotation(0.f, FMath::RandRange(0.f, 360.f), 0.f);

        // 액터 스폰
        AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(SelectedClass, RandomLocation, RandomRotation);

        // 스폰된 액터가 AMovingActor일 경우, 헤더에 정의된 변수들에 랜덤 속성 부여
        if (AMovingActor* MovingActor = Cast<AMovingActor>(SpawnedActor))
        {
            MovingActor->MoveSpeed = FMath::RandRange(100.f, 150.f); // 이동 속도 랜덤 설정
            MovingActor->MaxRange = FMath::RandRange(1000.f, 8000.f); // 최대 이동 거리 랜덤 설정
        }
    }
}

