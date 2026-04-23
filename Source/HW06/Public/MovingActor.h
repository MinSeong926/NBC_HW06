
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class HW06_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:
	AMovingActor();

	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Body;

	float MoveDirection; // 이동하려는 방향

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor")
	float MoveSpeed; // 이동 속도

	float AccumulatedDistance; // 이동 거리

	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MovingActor")
	float MaxRange;
};
