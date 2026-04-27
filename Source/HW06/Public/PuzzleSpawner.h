
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuzzleSpawner.generated.h"

UCLASS()
class HW06_API APuzzleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	APuzzleSpawner();

protected:
	virtual void BeginPlay() override;

	// 배열(TArray)로 선언해서 여러 개 배치할 수 있도록 설정
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TArray<TSubclassOf<AActor>> PlatformClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	int32 SpawnCount = 5;
};
